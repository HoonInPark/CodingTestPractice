#pragma once

/*
* https://school.programmers.co.kr/learn/courses/30/lessons/389480
*/

#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int solution(vector<vector<int>> info, int n, int m)
{
    const int MaxNum = 2147483647;
    vector<vector<int>> DP(info.size(), vector<int>(m, MaxNum));

    // 두번째 인수는 B에게 남은 여유 흔적 수이고, 
    // 리턴 값은 A가 남기는 흔적의 최소 수이다. 
    function<int(int, int)> GetMinTraceOfA =
        [&](int _InIdx, int _InTrace) mutable
        {
            if (DP[_InIdx][_InTrace] < MaxNum)
                return DP[_InIdx][_InTrace];

            if (0 == _InIdx)
            {
                if (info[0][1] <= _InTrace)
                    return 0;
                else
                    return info[0][0];
            }

            int StealerA = info[_InIdx][0] + GetMinTraceOfA(_InIdx - 1, _InTrace); // B가 훔치지 않고 A가 훔치는 경우
            if (info[_InIdx][1] <= _InTrace) // B가 훔칠 수 있는 경우
            {
                int StealerB = GetMinTraceOfA(_InIdx - 1, _InTrace - info[_InIdx][1]);
                DP[_InIdx][_InTrace] = min(StealerA, StealerB);
                
                return DP[_InIdx][_InTrace];
            }
            else
            {
                DP[_InIdx][_InTrace] = StealerA;
                
                return DP[_InIdx][_InTrace];
            }
        };

    int ResNum = GetMinTraceOfA(info.size() - 1, m - 1);
    if (ResNum >= n)
        return -1;
    else
        return ResNum;
}
