#pragma once

/*
* https://school.programmers.co.kr/learn/courses/30/lessons/49189
*/

#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int solution(int n, vector<vector<int>> edge) 
{
	int answer = 0;

	unordered_map<int, unordered_set<int>> Neighbors;
	for (int i = 1; i < n + 1; ++i)
		Neighbors.insert(make_pair(i, unordered_set<int>()));

	for (const auto& EdgeElem : edge)
	{
		(*Neighbors.find(EdgeElem[0])).second.insert(EdgeElem[1]);
		(*Neighbors.find(EdgeElem[1])).second.insert(EdgeElem[0]);
	}

	//////////////////////////////////////////////////////////////////////////////
	
	unordered_map<int, bool> PathBuf;
	
	PathBuf.insert(make_pair(1, true));
	for (int j = 2; j < n + 1; ++j)
		PathBuf.insert(make_pair(j, false));

	//////////////////////////////////////////////////////////////////////////////

	unordered_set<int> LvElems_1;
	unordered_set<int> LvElems_2;
	
	LvElems_1.insert(1);
	(*PathBuf.find(1)).second = true;

	LvElems_2.insert(-1); // dummy

	for (;;)
	{
		if (LvElems_1.empty()) 
			break;

		LvElems_2.clear();
		for (const auto PrevLvElem : LvElems_1) // 1이 들어있다.
		{
			for (const auto NextLvElem : (*Neighbors.find(PrevLvElem)).second) // 1과 연결된 노드 집합 순회
			{
				if (true == (*PathBuf.find(NextLvElem)).second) continue; // 이미 순회했던 노드면 패스

				LvElems_2.insert(NextLvElem); // 아직 순회하지 않은 노드면 두번째 큐에 푸시
				(*PathBuf.find(NextLvElem)).second = true; // 순회했다는 표시해주기
			}
		}

		if (LvElems_2.empty()) 
			break;

		LvElems_1.clear();
		for (const auto PrevLvElem : LvElems_2)
		{
			for (const auto NextLvElem : (*Neighbors.find(PrevLvElem)).second) // 2, 3과 연결된 노드 집합 (1, 4, 5, 6) 순회
			{
				if (true == (*PathBuf.find(NextLvElem)).second) continue;

				LvElems_1.insert(NextLvElem); // LvElem이 2일때는 4, 5 푸시
				(*PathBuf.find(NextLvElem)).second = true; // 4, 5 마킹
			}
		}
	}

	return LvElems_1.size() + LvElems_2.size();
}
