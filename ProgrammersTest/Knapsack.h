#pragma once

#include <vector>
#include <algorithm> 
#include <functional>

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

�����ϸ�...
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

	// �Ѱ��� ���� �� �ִ� ������ �α�.
	RetVec.push_back(0);
	int PrevSumOfVal = _InItems[0][0];

	// �ΰ� ��� �ͺ��� �����ϱ�.
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
		return _InFormer[1] < _InLater[1]; // ���� ���� �����ϸ� ���� ���� ��������
	else
		return _InFormer[0] > _InLater[0]; // �ε��� 0 ���� ��������
}
