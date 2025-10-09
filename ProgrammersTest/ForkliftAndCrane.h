#pragma once

/*
* https://school.programmers.co.kr/learn/courses/30/lessons/388353
*/

#include <string>
#include <vector>
#include <unordered_set>
#include <queue>
#include <functional>

using namespace std;

int solution(vector<string> storage, vector<string> requests)
{
	const char n = storage.size();
	const char m = storage[0].size();

	unordered_set<string> Outsiders;
	vector<vector<bool>> Status(n, vector<bool>(m, true));

	function<void()> GetOutsiders =
		[&]()
		{
			Outsiders.clear();

			for (char i = 0; i < n; ++i)
			{
				for (char j = 0; j < m; ++j)
				{
					if (true == Status[i][j])
					{
						Outsiders.insert({ i, j });
						break;
					}
				}
			}
			for (char i = 0; i < n; ++i)
			{
				for (char j = m - 1; j >= 0; --j)
				{
					if (true == Status[i][j])
					{
						Outsiders.insert({ i, j });
						break;
					}
				}
			}
			for (char j = 0; j < m; ++j)
			{
				for (char i = 0; i < n; ++i)
				{
					if (true == Status[i][j])
					{
						Outsiders.insert({ i, j });
						break;
					}
				}
			}
			for (char j = 0; j < m; ++j)
			{
				for (char i = n - 1; i >= 0; --i)
				{
					if (true == Status[i][j])
					{
						Outsiders.insert({ i, j });
						break;
					}
				}
			}
		};

	GetOutsiders();

	for (const auto& ReqStr : requests)
	{
		if (1 == ReqStr.size())
		{
			for (const auto& Outsider : Outsiders)
			{
				if (ReqStr[0] == storage[Outsider[0]][Outsider[1]])
					Status[Outsider[0]][Outsider[1]] = false;
			}
		}
		else
		{
			for (char i = 0; i < n; ++i)
			{
				for (char j = 0; j < m; ++j)
				{
					if (ReqStr[0] == storage[i][j])
						Status[i][j] = false;
				}
			}
		}

		GetOutsiders();
	}

	int answer = 0;
	for (char i = 0; i < n; ++i)
	{
		for (char j = 0; j < m; ++j)
		{
			if (true == Status[i][j])
				++answer;
		}
	}

	return answer;
}
