#pragma once

/*
* https://school.programmers.co.kr/learn/courses/30/lessons/12946
*/

#include <vector>

using namespace std;

void Hanoi(vector<vector<int>>& _InRec, int _InNum, int _InFrom, int _InBy, int _InTo);

vector<vector<int>> solution(int n)
{
	int PathNum = 0;
	for (int i = 0; i < n; i++)
	{
		PathNum = 2 * PathNum + 1;
	}

	vector<vector<int>> Res;
	Res.reserve(PathNum);

	Hanoi(Res, n, 1, 2, 3);

	return Res;
}

void Hanoi(vector<vector<int>>& _InRec, int _InNum, int _InFrom, int _InBy, int _InTo)
{
	if (1 == _InNum)
	{
		_InRec.push_back({ _InFrom, _InTo });
	}
	else
	{
		Hanoi(_InRec, _InNum - 1, _InFrom, _InTo, _InBy);
		_InRec.push_back({ _InFrom, _InTo });
		Hanoi(_InRec, _InNum - 1, _InBy, _InFrom, _InTo);
	}
}
