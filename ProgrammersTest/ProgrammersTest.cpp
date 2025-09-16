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
//#include "OddEvenTree.h"
#include "ServerIncrementCount.h"

int main()
{
	vector<int> test = { 0, 2, 3, 3, 1, 2, 0, 0, 0, 0, 4, 2, 0, 6, 0, 4, 2, 13, 3, 5, 10, 0, 1, 5 };
	solution(test, 3, 5);
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
