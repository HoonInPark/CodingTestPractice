#pragma once

/*
* https://school.programmers.co.kr/learn/courses/30/lessons/49189
*/

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

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

	queue<int> LvElems_1;
	queue<int> LvElems_2;
	
	LvElems_1.push(1);
	(*PathBuf.find(1)).second = true;

	for (;;)
	{
		while (!LvElems_1.empty()) // 1이 들어있다.
		{
			for (const auto LvElem : (*Neighbors.find(LvElems_1.front())).second) // 1과 연결된 노드 집합 순회
			{
				if (true == (*PathBuf.find(LvElem)).second) continue; // 이미 순회했던 노드면 패스

				LvElems_2.push(LvElem); // 아직 순회하지 않은 노드면 두번째 큐에 푸시
				(*PathBuf.find(LvElem)).second = true; // 순회했다는 표시해주기
			}

			LvElems_1.pop(); // 첫번째 큐에서 빼주기
		}
		while (!LvElems_2.empty()) // 2, 3이 들어있다. 
		{
			for (const auto LvElem : (*Neighbors.find(LvElems_2.front())).second) // 2, 3과 연결된 노드 집합 (1, 4, 5, 6) 순회
			{
				if (true == (*PathBuf.find(LvElem)).second) continue;

				LvElems_1.push(LvElem); // LvElem이 2일때는 4, 5 푸시
				(*PathBuf.find(LvElem)).second = true; // 4, 5 마킹
			}

			LvElems_2.pop(); // 2 순회했으면 3 팝.
		}
	}

	return answer;
}
