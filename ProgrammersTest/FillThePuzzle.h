#pragma once

#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

struct VectorHash // functor, 함수 객체
{
	size_t operator()(const vector<int>& v) const noexcept 
	{
		hash<int> hasher;
		size_t seed = 0;
		for (int x : v)
		{
			// boost::hash_combine 스타일로 해시 합성
			seed ^= hasher(x) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
		}

		return seed;
	}
};

struct SetHash 
{
	size_t operator()(const unordered_set<vector<int>, VectorHash>& s) const noexcept 
	{
		size_t seed = 0;
		VectorHash vhash;

		for (const auto& vec : s) 
		{
			size_t h = vhash(vec);
			seed ^= h + 0x9e3779b9 + (seed << 6) + (seed >> 2);
		}
		return seed;
	}
};

struct SetEqual 
{
	bool operator()(const unordered_set<vector<int>, VectorHash>& a,
		const unordered_set<vector<int>, VectorHash>& b) const noexcept 
	{
		return a == b; // unordered_set은 == 연산자가 정의되어 있음
	}
};


int solution(vector<vector<int>> game_board, vector<vector<int>> table)
{
	int answer = -1;

	vector<unordered_set<vector<int>, VectorHash>> Puzzles; // 회전한 퍼즐까지 전부 담는 곳. 시작지점으로부터의 상대위치를 담는다.
	queue<vector<int>> YX;

	// 일단 퍼즐 조각이 맞아 들어가는지부터 확인.
	for (int i = 0; i < table.size(); ++i) // i는 y좌표
	{
		for (int j = 0; j < table[i].size(); ++j) // j는 x좌표
		{
			if (!table[i][j]) continue;

			YX.push({ i, j });

			unordered_set<vector<int>, VectorHash> Puzzle;

			// 여기서 너비 우선 탐색.
			// 이 while문이 끝나면 하나의 퍼즐 조각을 모두 순회함.
			while (!YX.empty())
			{
				vector<int> FrontPt = YX.front();
				YX.pop();

				Puzzle.insert({ FrontPt[0] - i, FrontPt[1] - j }); // 퍼즐 내 한 칸을 배열에 넣는다.

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
			
			for (const auto& Piece : Puzzle)
				table[Piece[0] + i][Piece[1] + j] = 1;

			unordered_set<vector<int>, VectorHash> PuzzleRearanged;

			// 회전해가며 네개의 퍼즐을 푸시 백.
			Puzzles.push_back(Puzzle);

			for (auto& Piece : Puzzle)
				PuzzleRearanged.insert({ -Piece[1], Piece[0] });
			Puzzles.push_back(PuzzleRearanged);

			PuzzleRearanged.clear();
			for (auto& Piece : Puzzle)
				PuzzleRearanged.insert({ Piece[1], -Piece[0] });
			Puzzles.push_back(PuzzleRearanged);

			PuzzleRearanged.clear();
			for (auto& Piece : Puzzle)
				PuzzleRearanged.insert({ -Piece[0], -Piece[1] });
			Puzzles.push_back(PuzzleRearanged);
		}
	}

	using InnerSet = unordered_set<vector<int>, VectorHash>;
	unordered_set<InnerSet, SetHash, SetEqual> ResVec;


	for (int i = 0; i < game_board.size(); ++i) // i는 y좌표
	{
		for (int j = 0; j < game_board[i].size(); ++j) // j는 x좌표
		{
			if (game_board[i][j]) continue;

			YX.push({ i, j });

			unordered_set<vector<int>, VectorHash> Void;

			// 여기서 너비 우선 탐색.
			// 이 while문이 끝나면 하나의 퍼즐 조각을 모두 순회함.
			while (!YX.empty())
			{
				vector<int> FrontPt = YX.front();
				YX.pop();

				Void.insert({ FrontPt[0] - i, FrontPt[1] - j }); // 퍼즐 내 한 칸을 배열에 넣는다.

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

			for (const auto& Puzzle : Puzzles)
			{
				if (Puzzle == Void /*&& ResVec.end() == ResVec.find(Puzzle)*/)
					ResVec.insert(Puzzle);
			}


		}
	}

	return answer;
}
