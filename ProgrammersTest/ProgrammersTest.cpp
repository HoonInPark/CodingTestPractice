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
#include "PathFinder.h"

int main()
{
	vector<vector<int>> test;
	test.push_back({ 5,3 });
	test.push_back({ 11,5 });
	test.push_back({ 13,3 });
	test.push_back({ 3,5 });
	test.push_back({ 6,1 });
	test.push_back({ 1,3 });
	test.push_back({ 8,6 });
	test.push_back({ 7,2 });
	test.push_back({ 2,2 });

	solution(test);
}

/*
[5,3],
[11,5],
[13,3],
[3,5],
[6,1],
[1,3],
[8,6],
[7,2],
[2,2]
*/
