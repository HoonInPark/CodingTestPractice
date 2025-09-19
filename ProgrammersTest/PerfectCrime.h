#pragma once

/*
* https://school.programmers.co.kr/learn/courses/30/lessons/389480
*/

#include <vector>
#include <algorithm> 
#include<cassert>

using namespace std;

bool Cmp(const vector<int>& _InFormer, const vector<int>& _InLater);
void CombHelper(const vector<int>& arr, int n, int start, vector<int>& current, vector<vector<int>>& result);
vector<vector<int>> GenComb(const vector<int>& arr, int n);

int solution(vector<vector<int>> info, int n, int m)
{
    int FootPrintB = 0;
    for (const auto Stuff : info)
        FootPrintB += Stuff[1];

    if (FootPrintB < m)
        return 0;
    else
        FootPrintB = 0;

    sort(info.begin(), info.end(), Cmp);

    for (int a = 1; a <= info.size(); ++a)
    {

    }
    
    return -1;
}

bool Cmp(const vector<int>& _InFormer, const vector<int>& _InLater)
{
    return _InFormer[0] < _InLater[0];
}

// Backtracking algo
void CombHelper(const vector<int>& arr, int n, int start, vector<int>& current, vector<vector<int>>& result)
{
    if (current.size() == n) 
    {
        result.push_back(current);
        return;
    }

    for (int i = start; i < arr.size(); i++) 
    {
        current.push_back(arr[i]);
        CombHelper(arr, n, i + 1, current, result);
        current.pop_back(); // backtrack
    }
}

vector<vector<int>> GenComb(const vector<int>& arr, int n)
{
    vector<vector<int>> result;
    vector<int> current;
    CombHelper(arr, n, 0, current, result);
    return result;
}

/*
* 1. ��� ���ľ� �Ѵ�.
* 2. ������ ������ �ȵȴ�. 
* 3. ������ ������ ���� �� ���� A�� n�� �̻�, B�� m�� �̻��� ��.
* 4. ��ȯ���� A�� �ּҷ� ����� ���� ��
* 
* A�� �ּҰ� �ǰ� ��ġ��, B�� �������� �ȵ�. 
* �� �������� �ص� ��������, -1 ��ȯ.
* 
* 1 2 2
* 2 3 1
* 
*/

