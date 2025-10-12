#pragma once

/*
* https://school.programmers.co.kr/learn/courses/30/lessons/388353
*/

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <functional>

using namespace std;

int solution(vector<string> storage, vector<string> requests)
{
	const int n = storage.size();
	const int m = storage[0].size();
	const vector<int> Dirs = { 1, -1, m, -m };

	unordered_map<int, int> Status;
	for (int i = 0; i < n * m; ++i)
		Status.insert(make_pair(i, 1)); // 없고 순회하지 않았으면 0, 없고 순회했으면 -1, 있으면 1, 있는데 외곽에 있다고 순회하면서 확인했으면 2
	
	unordered_set<int> Outsiders;

	// 초기화
	for (int j = 0; j < m; ++j)
	{
		Status[j] = 2;
		Status[m * n - 1 - j] = 2;

		Outsiders.insert(j);
		Outsiders.insert(m * n - 1 - j);
	}

	for (int k = 1; k < n - 1; ++k)
	{
		Status[m * k] = 2;
		Status[m * k + m - 1] = 2;

		Outsiders.insert(m * k);
		Outsiders.insert(m * k + m - 1);
	}

	function<void(int)> PathFinder =
		[&](int _InInitNum)
		{
			stack<int> PathStack;
			PathStack.push(_InInitNum);

			while (false == PathStack.empty())
			{
				int TopNum = PathStack.top();
				PathStack.pop();

				for (const auto Dir : Dirs)
				{
					int NxtNum = TopNum + Dir;

					if (NxtNum >= 0 &&
						NxtNum < n * m)
					{
						switch (Status[NxtNum])
						{
						case 0: // 없고 순회 아직 안했으면
						{
							Status[NxtNum] = -1;
							PathStack.push(NxtNum);
							break;
						}
						case 1: // 있고 순회 아직 안했으면
						{
							Status[NxtNum] = 2; // 순회했다고 표시하는데, 이는 곧 바깥에 있음을 의미.
							break;
						}
						default:
							break;
						}
					}
				}
			}
		};

	for (const auto& ReqStr : requests)
	{
		if (1 == ReqStr.size())
		{
			// 외곽에 있는 거 빼기
			for (int l = 0; l < Status.size(); ++l)
				if (2 == Status[l] && ReqStr[0] == storage[l / m][l % m])
					Status[l] = 0;
		}
		else
		{
			// 외곽 아니어도 일단 같은 알파벳이면 빵꾸.
			for (int l = 0; l < Status.size(); ++l)
				if (ReqStr[0] == storage[l / m][l % m])
					Status[l] = 0;
		}

		// 새로운 외곽 컨테이너 목록 업데이트
		for (int l = 0; l < Status.size(); ++l)
			if (0 == Status[l] && Outsiders.end() != Outsiders.find(l))
				PathFinder(l);

		// '새로운 외곽 컨테이너 목록 업데이트' 하면서 -1로 바꾼 것들 0으로 rollback
		for (int l = 0; l < Status.size(); ++l)
			if (-1 == Status[l])
				Status[l] = 0;
	}

	int Answer = 0;
	for (int p = 0; p < Status.size(); ++p)
	{
		if (Status[p] > 0)
			++Answer;
	}

	return Answer;
}
