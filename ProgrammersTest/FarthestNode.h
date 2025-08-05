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
		while (!LvElems_1.empty()) // 1�� ����ִ�.
		{
			for (const auto LvElem : (*Neighbors.find(LvElems_1.front())).second) // 1�� ����� ��� ���� ��ȸ
			{
				if (true == (*PathBuf.find(LvElem)).second) continue; // �̹� ��ȸ�ߴ� ���� �н�

				LvElems_2.push(LvElem); // ���� ��ȸ���� ���� ���� �ι�° ť�� Ǫ��
				(*PathBuf.find(LvElem)).second = true; // ��ȸ�ߴٴ� ǥ�����ֱ�
			}

			LvElems_1.pop(); // ù��° ť���� ���ֱ�
		}
		while (!LvElems_2.empty()) // 2, 3�� ����ִ�. 
		{
			for (const auto LvElem : (*Neighbors.find(LvElems_2.front())).second) // 2, 3�� ����� ��� ���� (1, 4, 5, 6) ��ȸ
			{
				if (true == (*PathBuf.find(LvElem)).second) continue;

				LvElems_1.push(LvElem); // LvElem�� 2�϶��� 4, 5 Ǫ��
				(*PathBuf.find(LvElem)).second = true; // 4, 5 ��ŷ
			}

			LvElems_2.pop(); // 2 ��ȸ������ 3 ��.
		}
	}

	return answer;
}
