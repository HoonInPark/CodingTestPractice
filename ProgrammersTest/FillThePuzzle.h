#pragma once

#include <vector>
#include <queue>

using namespace std;

int solution(vector<vector<int>> game_board, vector<vector<int>> table)
{
	int answer = -1;

	vector<vector<vector<int>>> Puzzles; // ȸ���� ������� ���� ��� ��. �����������κ����� �����ġ�� ��´�.

	// �ϴ� ���� ������ �¾� ���������� Ȯ��.
	for (int i = 0; i < table.size(); ++i) // i�� y��ǥ
	{
		for (int j = 0; j < table[i].size(); ++j) // j�� x��ǥ
		{
			if (!table[i][j]) continue;

			queue<vector<int>> YX;
			YX.push({ i, j });

			vector<vector<int>> Puzzle;

			// ���⼭ �ʺ� �켱 Ž��.
			// �� while���� ������ �ϳ��� ���� ������ ��� ��ȸ��.
			while (!YX.empty())
			{
				vector<int> FrontPt = YX.front();
				YX.pop();

				Puzzle.push_back({ FrontPt[0] - i, FrontPt[1] - j }); // ���� �� �� ĭ�� �迭�� �ִ´�.

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

			// ȸ���ذ��� �װ��� ������ Ǫ�� ��.
			Puzzles.push_back(Puzzle);

			for (auto& Piece : Puzzle)
			{
				int SwapBuf = Piece[0];
				Piece[0] = Piece[1];
				Piece[1] = SwapBuf;

				Piece[1] *= -1;
			}
			Puzzles.push_back(Puzzle);

			for (auto& Piece : Puzzle)
			{
				int SwapBuf = Piece[0];
				Piece[0] = Piece[1];
				Piece[1] = SwapBuf;

				Piece[0] *= -1;
			}
			Puzzles.push_back(Puzzle);

			for (auto& Piece : Puzzle)
			{
				Piece[0] *= -1;
				Piece[1] *= -1;
			}
			Puzzles.push_back(Puzzle);
		}
	}

	return answer;
}
