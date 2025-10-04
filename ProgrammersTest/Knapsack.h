#pragma once

#include <vector>
#include <algorithm> 

using namespace std;

/*
배낭 크기 : 6
넣을 수 있는 물건 목록 : (인덱스 0은 값, 1는 무게)
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
	return _InFormer[0] > _InLater[0]; // 인덱스 0 기준 내림차순
}
