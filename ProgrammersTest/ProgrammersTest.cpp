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
//#include "ServerIncrementCount.h"
//#include "PerfectCrime.h"
//#include "SealedSpell.h"
//#include "ForkliftAndCrane.h"
//#include "FlexibleWork.h"
//#include "VideoPlayer.h"
//#include "RecoverMathod.h"
#include "Knapsack.h"

int main()
{
	vector<vector<int>> test =
	{
		{ 4, 3 },
		{ 2, 1 },
		{ 5, 6 },
		{ 6, 5 },
		{ 1, 2 },
		{ 3, 3 }
	};
	
	int Res = solution(test, 6);
	cout << Res << endl;
}
