/*
* https://school.programmers.co.kr/learn/courses/30/lessons/389480
*/

#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int solution(vector<vector<int>> info, int n, int m)
{
    // 두번째 인수는 B에게 남은 여유 흔적 수이고, 
    // 리턴 값은 A가 남기는 흔적의 최소 수이다. 
    function<int(int, int)> GetMinTraceOfA =
        [&](int _InIdx, int _InT) mutable
        {
            if (0 == _InIdx)
            {
                int MinVal = 2147483647;
                for (const auto& Item : info)
                {
                    //MinVal = min(MinVal, Item[i][]);
                }
            }

            int WhenStealerB = GetMinTraceOfA(_InIdx - 1, _InT);
            if (info[_InIdx][1] < _InT)
            {
                int WhenStealerA = info[_InIdx][0] + GetMinTraceOfA(_InIdx - 1, _InT - info[_InIdx][1]);
                return min(WhenStealerA, WhenStealerB);
            }
            else
            {
                return WhenStealerB;
            }
        };

    return GetMinTraceOfA(info.size() - 1, m);
}
