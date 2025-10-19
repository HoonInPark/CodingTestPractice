#pragma once

#include <vector>
#include <functional>
#include <algorithm>
#include <iostream>

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

int solution(vector<vector<int>> _InItems, const int _InCap)
{
	// 2nd idx can be zero to _InCap, so it has (_InCap + 1) num of int
	vector<vector<int>> DP(_InItems.size(), vector<int>(_InCap + 1, 0));

	// int GetMaxValue(int, int)
	function<int(int, int)> GetMaxValue =
		[&](int _InIdx, int _InWeight) mutable
		{
			if (0 == _InIdx)
			{
				int MaxVal = 0;
				for (const auto& Item : _InItems)
				{
					if (Item[1] > _InWeight) continue;
					MaxVal = max(MaxVal, Item[0]);
				}

				return MaxVal;
			}
			
			if (_InWeight < 0)
			{
				return 0;
			}

			DP[_InIdx][_InWeight] = 
				max(GetMaxValue(_InIdx - 1, _InWeight), _InItems[_InIdx][0] + GetMaxValue(_InIdx - 1, _InWeight - _InItems[_InIdx][1]));

			return DP[_InIdx][_InWeight];
		};

	DP[_InItems.size() - 1][_InCap] = GetMaxValue(_InItems.size() - 1, _InCap);

	for (int i = 0; i < DP.size(); ++i)
	{
		for (int j = 0; j < DP[0].size(); ++j)
			cout << DP[i][j] << ' ';

		cout << ' ' << endl;
	}

	return -1;
}
