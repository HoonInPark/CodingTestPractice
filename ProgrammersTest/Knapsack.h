#pragma once

#include <vector>
#include <algorithm> 

using namespace std;

/*
�賶 ũ�� : 6
���� �� �ִ� ���� ��� : (�ε��� 0�� ��, 1�� ����)
{
	{ 4, 3 },
	{ 2, 1 },
	{ 5, 6 },
	{ 6, 5 },
	{ 1, 2 },
	{ 3, 3 }
}
*/

inline bool Cmp(const vector<int>& _InFormer, const vector<int>& _InLater);

vector<vector<int>> solution(vector<vector<int>> _InItems)
{
	sort(_InItems.begin(), _InItems.end(), Cmp);

	vector<vector<int>> RetVec;
	RetVec.reserve(6);

	for (int ItemNum = 1; ItemNum <= 6; ++ItemNum)
	{
		
	}

	return RetVec;
}

inline bool Cmp(const vector<int>& _InFormer, const vector<int>& _InLater)
{
	return _InFormer[0] > _InLater[0]; // �ε��� 0 ���� ��������
}
