#pragma once

#include <vector>
#include <queue>

using namespace std;

int solution(vector<vector<int>> game_board, vector<vector<int>> table)
{
	int answer = -1;

	vector<vector<vector<int>>> Puzzles; // 회전한 퍼즐까지 전부 담는 곳. 시작지점으로부터의 상대위치를 담는다.
	queue<vector<int>> YX;

	// 일단 퍼즐 조각이 맞아 들어가는지부터 확인.
	for (int i = 0; i < table.size(); ++i) // i는 y좌표
	{
		for (int j = 0; j < table[i].size(); ++j) // j는 x좌표
		{
			if (!table[i][j]) continue;

			YX.push({ i, j });

			vector<vector<int>> Puzzle;

			// 여기서 너비 우선 탐색.
			// 이 while문이 끝나면 하나의 퍼즐 조각을 모두 순회함.
			while (!YX.empty())
			{
				vector<int> FrontPt = YX.front();
				YX.pop();

				Puzzle.push_back({ FrontPt[0] - i, FrontPt[1] - j }); // 퍼즐 내 한 칸을 배열에 넣는다.

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

			// 회전해가며 네개의 퍼즐을 푸시 백.
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

	for (int i = 0; i < game_board.size(); ++i) // i는 y좌표
	{
		for (int j = 0; j < game_board[i].size(); ++j) // j는 x좌표
		{
			if (game_board[i][j]) continue;

			YX.push({ i, j });

			vector<vector<int>> Void;

			// 여기서 너비 우선 탐색.
			// 이 while문이 끝나면 하나의 퍼즐 조각을 모두 순회함.
			while (!YX.empty())
			{
				vector<int> FrontPt = YX.front();
				YX.pop();

				Void.push_back({ FrontPt[0] - i, FrontPt[1] - j }); // 퍼즐 내 한 칸을 배열에 넣는다.

				game_board[FrontPt[0]][FrontPt[1]] = 1; // 순회했으니 1로 표기.

				if (FrontPt[0] - 1 > -1 && !game_board[FrontPt[0] - 1][FrontPt[1]])
					YX.push({ FrontPt[0] - 1, FrontPt[1] });

				if (FrontPt[0] + 1 < game_board.size() && !game_board[FrontPt[0] + 1][FrontPt[1]])
					YX.push({ FrontPt[0] + 1, FrontPt[1] });

				if (FrontPt[1] - 1 > -1 && !game_board[FrontPt[0]][FrontPt[1] - 1])
					YX.push({ FrontPt[0], FrontPt[1] - 1 });

				if (FrontPt[1] + 1 < game_board.size() && !game_board[FrontPt[0]][FrontPt[1] + 1])
					YX.push({ FrontPt[0], FrontPt[1] + 1 });
			}
			/**/
			for (const auto& Puzzle : Puzzles)
			{
				if (Puzzle == Void)
				{
					cout << "good" << endl;
				}
			}
		}
	}

	return answer;
}
