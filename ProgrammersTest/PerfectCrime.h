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
* 1. 모두 훔쳐야 한다.
* 2. 경찰에 잡히면 안된다. 
* 3. 잡히는 조건은 흔적 총 합이 A는 n개 이상, B는 m개 이상일 때.
* 4. 반환값은 A가 최소로 남기는 흔적 수
* 
* A는 최소가 되게 훔치고, B는 붙잡히면 안됨. 
* 이 로직으로 해도 붙잡히면, -1 반환.
* 
* 1 2 2
* 2 3 1
* 
*/

