#pragma once

/*
* https://school.programmers.co.kr/learn/courses/30/lessons/389480
*/

#include <vector>
#include <algorithm> 
#include <cassert>
#include <functional>

using namespace std;

bool Cmp(const vector<int>& _InFormer, const vector<int>& _InLater);

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

    int Res = INT_MAX;
    
    vector<bool> Flags(info.size()); // a가 선택한 인덱스엔 true가 들어 있음.
    fill(Flags.begin(), Flags.end(), false);

    // DFS...
    function<void(const vector<vector<int>>&, vector<int>&, int)> FindComb =
        [&](const vector<vector<int>>& _InArr, vector<int>& _InCurStack, int _InStartNum) mutable -> void
        {
            for (int i = _InStartNum; i < _InArr.size(); ++i)
            {
                _InCurStack.push_back(i);
                Flags[i] = true;

                ///////////////////////////////////////////////////////////////////////////////////////////
                // TODO : 현재 스택의 상태가 문제에서 요구하는 바로 그것인지 확인하고 리턴하는 로직이 들어가야 한다. 
                int A = 0;
                int B = 0;

                for (int j = 0; j < _InArr.size(); ++j)
                {
                    if (Flags[j])
                        A += info[j][0];
                    else
                        B += info[j][1];
                }

                if (A < n && B < m)
                {
                    Res = min(Res, A);
                }
                ///////////////////////////////////////////////////////////////////////////////////////////
                ///////////////////////////////////////////////////////////////////////////////////////////

                FindComb(_InArr, _InCurStack, i + 1);

                Flags[_InCurStack.back()] = false;
                _InCurStack.pop_back();
            }
        };
    
    vector<int> Buf;
    Buf.reserve(info.size());

    FindComb(info, Buf, 0);

    if (INT_MAX == Res) return -1;
    else return Res;
}

bool Cmp(const vector<int>& _InFormer, const vector<int>& _InLater)
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

