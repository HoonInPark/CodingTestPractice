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
#include "HyundaiMobisSim.h"

int main()
{
	vector<vector<int>> test;
	test.push_back({1, 2});
	test.push_back({1, 3});
	test.push_back({1, 4});
	test.push_back({2, 5});
	test.push_back({4, 5});
	test.push_back({5, 6});
	test.push_back({5, 7});
	test.push_back({6, 9});
	test.push_back({7, 9});
	test.push_back({5, 8});

	solution(9, test); // 정답은 3
}

/*
[
[1, 2], 
[1, 3], 
[1, 4], 
[2, 5], 
[4, 5], 
[5, 6], 
[5, 7], 
[6, 9], 
[7, 9], 
[5, 8]
]
*/
