#pragma once

#include <vector>
#include <queue>

using namespace std;

int solution(vector<vector<int>> game_board, vector<vector<int>> table)
{
	int answer = -1;

	// 일단 퍼즐 조각이 맞아 들어가는지부터 확인. 그게 최적의 경우인지는 다음으로 생각합시다.
	for (int i = 0; i < table.size(); ++i) // i는 y좌표
	{
		for (int j = 0; j < table[i].size(); ++j) // j는 x좌표
		{
			if (!table[i][j]) continue;

			queue<vector<int>> YX;
			YX.push({ i, j });

			// 여기서 너비 우선 탐색.
			// 이 while문이 끝나면 하나의 퍼즐 조각을 모두 순회함.
			while (!YX.empty())
			{
				vector<int> FrontPt = YX.front();
				YX.pop();

				table[FrontPt[0]][FrontPt[1]] = 0; // 순회했으니 0으로 표기.

				if (FrontPt[0] - 1 > -1 && table[FrontPt[0] - 1][FrontPt[1]])
					YX.push({ FrontPt[0] - 1, FrontPt[1] });

				if (FrontPt[0] + 1 < table.size() && table[FrontPt[0] + 1][FrontPt[1]])
					YX.push({ FrontPt[0] + 1, FrontPt[1] });

				if (FrontPt[1] - 1 > -1 && table[FrontPt[0]][FrontPt[1] - 1])
					YX.push({ FrontPt[0], FrontPt[1] - 1 });

				if (FrontPt[1] + 1 < table.size() && table[FrontPt[0]][FrontPt[1] + 1])
					YX.push({ FrontPt[0], FrontPt[1] + 1 });
			}
		}
	}

	return answer;
}
