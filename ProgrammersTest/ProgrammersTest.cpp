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
#include "FillThePuzzle.h"

int main()
{
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
}

/*
[1,1,0,0,1,0],
[0,0,1,0,1,0],
[0,1,1,0,0,1],
[1,1,0,1,1,1],
[1,0,0,0,1,0],
[0,1,1,1,0,0]

[1,0,0,1,1,0],
[1,0,1,0,1,0],
[0,1,1,0,1,1],
[0,0,1,0,0,0],
[1,1,0,1,1,0],
[0,1,0,0,0,0]
*/
