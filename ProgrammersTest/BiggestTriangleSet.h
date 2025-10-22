#pragma once

/*
* https://school.programmers.co.kr/learn/courses/30/lessons/340210
*/

#include <string>
#include <vector>
#include <functional>
#include <unordered_map>
#include <stack>

using namespace std;

int solution(vector<vector<int>> grid)
{
    const int n = grid.size();
    const int m = grid[0].size();

    // 정방향 슬래시 '/'일 때 두가지 방향
    const vector<int> Dirs1 = { -1, -m };
    const vector<int> Dirs2 = { 1, m };

    // 역방향 슬래시 '\'일 때 두가지 방향
    const vector<int> Dirs3 = { -1, m };
    const vector<int> Dirs4 = { 1, -m };

    unordered_map<int, int> Status;
    /*
    * 0 -> 아직 순회 안 함
    * 1, 2, 3, 4는 각각 슬래시 / 혹은 \의 각 두가지 케이스 중 어느 방식으로 칠하는지를 나타냄. 
    * 이는 직전 경로에서 칠해진 게 뭔지에 따라 결정된다. 
    */
    for (int i = 0; i < n * m; ++i)
        Status.insert(make_pair(i, 0)); 

    function<void(int, int)> PathFinder =
        [&](int _InInitNum, int _InWhichCase) mutable
        {
            stack<int> PathStack;
            PathStack.push(_InInitNum);
            Status[_InInitNum] = _InWhichCase;

            vector<int> Dirs;

            while (false == PathStack.empty())
            {
                int TopNum = PathStack.top();
                PathStack.pop();

                // 인접 영역을 칠할 때, 어느 모양으로 칠할지 정해지는 건 다음 두가지에 의해서다.
                // 1. 이전 영역에 칠한 방식이 1~4 중 뭐였는지
                // 2. 지금 칠하려는 영역이 1인지 -1인지
                switch (Status[TopNum])
                {
                case 1:
                    Dirs = Dirs1;
                    break;
                case 2:
                    Dirs = Dirs2;
                    break;
                case 3:
                    Dirs = Dirs3;
                    break;
                case 4:
                    Dirs = Dirs4;
                    break;
                default:
                    break;
                }

                for (const auto Dir : Dirs)
                {
                    int NxtNum = TopNum + Dir;

                    if (NxtNum >= 0 &&
                        NxtNum < n * m)
                    {
                        PathStack.push(NxtNum);
                        grid[NxtNum / m][NxtNum % m];
                        //Status[NxtNum] = ;
                    }
                }
            }

            for (auto& Cell : Status)
                Cell.second = 0;
        };

    // 전체 순회
    for (int i = 0; i < grid.size(); ++i)
    {
        for (int j = 0; j < grid[0].size(); ++j)
        {
            if (1 == grid[i][j])
            {
                PathFinder(m * i + j, 1);
                PathFinder(m * i + j, 2);
            }
            else
            {
                PathFinder(m * i + j, 3);
                PathFinder(m * i + j, 4);
            }
        }
    }

    return -1;
}
