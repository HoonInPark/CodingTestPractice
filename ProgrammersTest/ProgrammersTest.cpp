// ProgrammersTest.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

//#include "PseudoCantorBitArray.h"
//#include "EnglishWordChain.h"
//#include "PrimeNumGen.h"
//#include "FarthestNode.h"
//#include "DiskController.h"
//#include "ElectricalGridDivide.h"
//#include "HanoiTower.h"
//#include "PathFinder.h"
//#include "HyundaiMobisSim.h"
//#include "SooPoja.h"
//#include "FillThePuzzle.h"
//#include "PullOutPackage.h"
#include "OddEvenTree.h"

int main()
{
	vector<int> nodes = { 9, 15, 14, 7, 6, 1, 2, 4, 5, 11, 8, 10 };
	vector<vector<int>> edges =
	{
		{5, 14},
		{1, 4},
		{9, 11},
		{2, 15},
		{2, 5},
		{9, 7},
		{8, 1},
		{6, 4},
	};

	solution(nodes, edges);

}

/*
	vector<vector<int>> game_board =
	{
		{1, 1, 0, 0, 1, 0},
		{0, 0, 1, 0, 1, 0},
		{0, 1, 1, 0, 0, 1},
		{1, 1, 0, 1, 1, 1},
		{1, 0, 0, 0, 1, 0},
		{0, 1, 1, 1, 0, 0}
	};

	vector<vector<int>> table =
	{
		{1, 0, 0, 1, 1, 0},
		{1, 0, 1, 0, 1, 0},
		{0, 1, 1, 0, 1, 1},
		{0, 0, 1, 0, 0, 0},
		{1, 1, 0, 1, 1, 0},
		{0, 1, 0, 0, 0, 0}
	};

	solution(game_board, table);

[5, 14], 
[1, 4], 
[9, 11], 
[2, 15], 
[2, 5], 
[9, 7], 
[8, 1], 
[6, 4]
*/
