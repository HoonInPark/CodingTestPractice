#pragma once

#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

struct VectorHash // functor, �Լ� ��ü
{
	size_t operator()(const vector<int>& v) const noexcept 
	{
		hash<int> hasher;
		size_t seed = 0;
		for (int x : v)
		{
			// boost::hash_combine ��Ÿ�Ϸ� �ؽ� �ռ�
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
		return a == b; // unordered_set�� == �����ڰ� ���ǵǾ� ����
	}
};


int solution(vector<vector<int>> game_board, vector<vector<int>> table)
{
	int answer = -1;

	vector<unordered_set<vector<int>, VectorHash>> Puzzles; // ȸ���� ������� ���� ��� ��. �����������κ����� �����ġ�� ��´�.
	queue<vector<int>> YX;

	// �ϴ� ���� ������ �¾� ���������� Ȯ��.
	for (int i = 0; i < table.size(); ++i) // i�� y��ǥ
	{
		for (int j = 0; j < table[i].size(); ++j) // j�� x��ǥ
		{
			if (!table[i][j]) continue;

			YX.push({ i, j });

			unordered_set<vector<int>, VectorHash> Puzzle;

			// ���⼭ �ʺ� �켱 Ž��.
			// �� while���� ������ �ϳ��� ���� ������ ��� ��ȸ��.
			while (!YX.empty())
			{
				vector<int> FrontPt = YX.front();
				YX.pop();

				Puzzle.insert({ FrontPt[0] - i, FrontPt[1] - j }); // ���� �� �� ĭ�� �迭�� �ִ´�.

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
			
			for (const auto& Piece : Puzzle)
				table[Piece[0] + i][Piece[1] + j] = 1;

			unordered_set<vector<int>, VectorHash> PuzzleRearanged;

			// ȸ���ذ��� �װ��� ������ Ǫ�� ��.
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


	for (int i = 0; i < game_board.size(); ++i) // i�� y��ǥ
	{
		for (int j = 0; j < game_board[i].size(); ++j) // j�� x��ǥ
		{
			if (game_board[i][j]) continue;

			YX.push({ i, j });

			unordered_set<vector<int>, VectorHash> Void;

			// ���⼭ �ʺ� �켱 Ž��.
			// �� while���� ������ �ϳ��� ���� ������ ��� ��ȸ��.
			while (!YX.empty())
			{
				vector<int> FrontPt = YX.front();
				YX.pop();

				Void.insert({ FrontPt[0] - i, FrontPt[1] - j }); // ���� �� �� ĭ�� �迭�� �ִ´�.

				game_board[FrontPt[0]][FrontPt[1]] = 1; // ��ȸ������ 1�� ǥ��.

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
