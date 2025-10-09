#pragma once

/*
* https://school.programmers.co.kr/learn/courses/30/lessons/388353
*/

#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<string> storage, vector<string> requests)
{
	int answer = 0;

	const int m = storage[0].size();
	const int n = storage.size();

	vector<vector<bool>> Status(n, vector<bool>(m, true));
	unordered_set<string> OutsideStuffSet;

	for (int i = 0; i < m; ++i)
	{
		string IdxPair(2, 0);

		IdxPair[1] = i;
		OutsideStuffSet.insert(IdxPair);

		IdxPair[0] = n - 1;
		OutsideStuffSet.insert(IdxPair);
	}

	for (int j = 1; j < n - 1; ++j)
	{
		string IdxPair(2, 0);

		IdxPair[0] = j;
		OutsideStuffSet.insert(IdxPair);

		IdxPair[1] = m - 1;
		OutsideStuffSet.insert(IdxPair);
	}

	// do something
	for (const auto& ReqStr : requests)
	{
		if (1 == ReqStr.size())
		{
			unordered_set<string> Buf;
			auto Iter = OutsideStuffSet.begin();

			for (int k = 0; k < OutsideStuffSet.size(); ++k)
			{
				auto& IdxPair = *Iter;

				if (ReqStr[0] == storage[IdxPair[0]][IdxPair[1]])
				{
					if (IdxPair[0] - 1 < n	&&
						IdxPair[0] - 1 >= 0 &&
						OutsideStuffSet.end() == OutsideStuffSet.find({char(IdxPair[0] - 1) , char(IdxPair[1])}))
						Buf.insert({ char(IdxPair[0] - 1) , char(IdxPair[1]) });
					if (IdxPair[0] + 1 < n	&&
						IdxPair[0] + 1 >= 0 &&
						OutsideStuffSet.end() == OutsideStuffSet.find({ char(IdxPair[0] + 1) , char(IdxPair[1]) }))
						Buf.insert({ char(IdxPair[0] + 1) , char(IdxPair[1]) });
					if (IdxPair[1] - 1 < m	&&
						IdxPair[1] - 1 >= 0 &&
						OutsideStuffSet.end() == OutsideStuffSet.find({ char(IdxPair[0]) , char(IdxPair[1] - 1) }))
						Buf.insert({ char(IdxPair[0]) , char(IdxPair[1] - 1) });
					if (IdxPair[1] + 1 < m	&&
						IdxPair[1] + 1 >= 0 &&
						OutsideStuffSet.end() == OutsideStuffSet.find({ char(IdxPair[0]) , char(IdxPair[1] + 1) }))
						Buf.insert({ char(IdxPair[0]) , char(IdxPair[1] + 1) });

					Status[IdxPair[0]][IdxPair[1]] = false;
				}
				else
				{
					Buf.insert(IdxPair);
				}

				++Iter;
			}

			OutsideStuffSet = Buf;

			/*
			for (auto Iter = OutsideStuffSet.begin(); Iter != OutsideStuffSet.end(); ++Iter)
				cout << storage[(*Iter)[0]][(*Iter)[1]] << endl;			
			*/
		}
		else
		{

		}
	}

	return answer;
}
