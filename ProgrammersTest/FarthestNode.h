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
		for (const auto PrevLvElem : LvElems_1) // 1�� ����ִ�.
		{
			for (const auto NextLvElem : (*Neighbors.find(PrevLvElem)).second) // 1�� ����� ��� ���� ��ȸ
			{
				if (true == (*PathBuf.find(NextLvElem)).second) continue; // �̹� ��ȸ�ߴ� ���� �н�

				LvElems_2.insert(NextLvElem); // ���� ��ȸ���� ���� ���� �ι�° ť�� Ǫ��
				(*PathBuf.find(NextLvElem)).second = true; // ��ȸ�ߴٴ� ǥ�����ֱ�
			}
		}

		if (LvElems_2.empty()) 
			break;

		LvElems_1.clear();
		for (const auto PrevLvElem : LvElems_2)
		{
			for (const auto NextLvElem : (*Neighbors.find(PrevLvElem)).second) // 2, 3�� ����� ��� ���� (1, 4, 5, 6) ��ȸ
			{
				if (true == (*PathBuf.find(NextLvElem)).second) continue;

				LvElems_1.insert(NextLvElem); // LvElem�� 2�϶��� 4, 5 Ǫ��
				(*PathBuf.find(NextLvElem)).second = true; // 4, 5 ��ŷ
			}
		}
	}

	return LvElems_1.size() + LvElems_2.size();
}
