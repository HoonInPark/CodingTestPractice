// ProgrammersTest.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

//#include "PseudoCantorBitArray.h"
//#include "EnglishWordChain.h"
//#include "PrimeNumGen.h"
//#include "FarthestNode.h"
#include "DiskController.h"

int main()
{
	vector<vector<int>> test;
	test.push_back({ 0, 3 });
	test.push_back({ 1, 9 });
	test.push_back({ 3, 5 });
	test.push_back({ 19, 2 });

	int res = solution(test);
}
