// ProgrammersTest.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

//#include "PseudoCantorBitArray.h"
//#include "EnglishWordChain.h"
//#include "PrimeNumGen.h"
#include "FarthestNode.h"

int main()
{
	vector<vector<int>> test;
	test.push_back({ 3, 6 }); // 0
	test.push_back({ 4, 3 }); // 1
	test.push_back({ 3, 2 }); // 2
	test.push_back({ 1, 3 }); // 3
	test.push_back({ 1, 2 }); // 4
	test.push_back({ 2, 4 }); // 5
	test.push_back({ 5, 2 }); // 6

	solution(6, test);
}

/*
[3, 6], 
[4, 3], 
[3, 2], 
[1, 3], 
[1, 2], 
[2, 4], 
[5, 2]
*/