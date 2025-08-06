// ProgrammersTest.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

//#include "PseudoCantorBitArray.h"
//#include "EnglishWordChain.h"
//#include "PrimeNumGen.h"
//#include "FarthestNode.h"
//#include "DiskController.h"
#include "ElectricalGridDivide.h"

int main()
{
	vector<vector<int>> wires;

	wires.push_back({1, 3});
	wires.push_back({2, 3});
	wires.push_back({3, 4});
	wires.push_back({4, 5});
	wires.push_back({4, 6});
	wires.push_back({4, 7});
	wires.push_back({7, 8});
	wires.push_back({7, 9});

	for (int i = 0; i < 100; ++i)
	{
		solution1(9, wires);
	}

	for (int i = 0; i < 100; ++i)
	{
		solution2(9, wires);
	}

	return 0;
}

/*
[1, 3]
[2, 3]
[3, 4]
[4, 5]
[4, 6]
[4, 7]
[7, 8]
[7, 9]
*/ 

/*
[1,2],
[2,3],
[3,4]
*/