#pragma once

#include <vector>
#include <queue>

using namespace std;

int solution(vector<vector<int>> game_board, vector<vector<int>> table)
{
	int answer = -1;

	// �ϴ� ���� ������ �¾� ���������� Ȯ��. �װ� ������ ��������� �������� �����սô�.
	for (int i = 0; i < table.size(); ++i) // i�� y��ǥ
	{
		for (int j = 0; j < table[i].size(); ++j) // j�� x��ǥ
		{
			if (!table[i][j]) continue;

			queue<vector<int>> YX;
			YX.push({ i, j });

			// ���⼭ �ʺ� �켱 Ž��.
			// �� while���� ������ �ϳ��� ���� ������ ��� ��ȸ��.
			while (!YX.empty())
			{
				vector<int> FrontPt = YX.front();
				YX.pop();

				table[FrontPt[0]][FrontPt[1]] = 0; // ��ȸ������ 0���� ǥ��.

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
