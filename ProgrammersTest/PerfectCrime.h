#pragma once

/*
* https://school.programmers.co.kr/learn/courses/30/lessons/389480
*/

#include <vector>
#include <algorithm> 

using namespace std;

bool cmp(const vector<int>& _InFormer, const vector<int>& _InLater);

int solution(vector<vector<int>> info, int n, int m)
{
    sort(info.begin(), info.end(), cmp);

    for (int a = 0; a < info.size(); ++a)
    {

    }
    
    return -1;
}

bool cmp(const vector<int>& _InFormer, const vector<int>& _InLater)
{
    return _InFormer[0] < _InLater[0];
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

