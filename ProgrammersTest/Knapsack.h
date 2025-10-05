#pragma once

#include <vector>
#include <algorithm> 
#include <functional>

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

정렬하면...
6 5
5 6
4 3
3 3
2 1
1 2
*/

inline bool Cmp(const vector<int>& _InFormer, const vector<int>& _InLater);

vector<vector<int>> solution(vector<vector<int>> _InItems, const int _InCap)
{
	sort(_InItems.begin(), _InItems.end(), Cmp);

	vector<int> RetVec;
	RetVec.reserve(6);

	// 한개만 담을 때 최댓값 저장해 두기.
	RetVec.push_back(0);
	int PrevSumOfVal = _InItems[0][0];

	// 두개 담는 것부터 생각하기.
	vector<int> CombVec;
	CombVec.reserve(6);

	int MaxVal = 0;

	function<void(const int, const int, vector<int>&)> Comb =
		[&](const int _InLeftItemNum, const int _InLowerBound, vector<int>& _OutComb)
		{
			if (_InLeftItemNum < 1)
			{
				// do something for MaxVal
				int Val = 0;
				int Weight = 0;
				for (const auto IdxInComb : _OutComb)
				{
					Val += _InItems[IdxInComb][0];
					Weight += _InItems[IdxInComb][1];
				}

				if (MaxVal < Val && Weight <= _InCap)
				{
					MaxVal = Val;

					RetVec.clear();
					RetVec = _OutComb;
				}

				_OutComb.pop_back();

				return;
			}

			for (int i = _InLowerBound; i < _InItems.size(); ++i)
			{
				_OutComb.push_back(i);
				Comb(_InLeftItemNum - 1, i + 1, _OutComb);
			}

			if (false == _OutComb.empty())
				_OutComb.pop_back();
		};

	for (int i = 2; i <= 6; ++i)
	{
		Comb(i, 0, CombVec);
	}
	
	return vector<vector<int>>();
}

inline bool Cmp(const vector<int>& _InFormer, const vector<int>& _InLater)
{
	if (_InFormer[0] == _InLater[0])
		return _InFormer[1] < _InLater[1]; // 만약 값이 동일하면 무게 기준 오름차순
	else
		return _InFormer[0] > _InLater[0]; // 인덱스 0 기준 내림차순
}
