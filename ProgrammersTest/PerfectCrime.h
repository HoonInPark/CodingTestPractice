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
    
    vector<bool> Flags(info.size()); // a�� ������ �ε����� true�� ��� ����.
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
                // TODO : ���� ������ ���°� �������� �䱸�ϴ� �ٷ� �װ����� Ȯ���ϰ� �����ϴ� ������ ���� �Ѵ�. 
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

