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

    // ������ ������ '/'�� �� �ΰ��� ����
    const vector<int> Dirs1 = { -1, -m };
    const vector<int> Dirs2 = { 1, m };

    // ������ ������ '\'�� �� �ΰ��� ����
    const vector<int> Dirs3 = { -1, m };
    const vector<int> Dirs4 = { 1, -m };

    unordered_map<int, int> Status;
    /*
    * 0 -> ���� ��ȸ �� ��
    * 1, 2, 3, 4�� ���� ������ / Ȥ�� \�� �� �ΰ��� ���̽� �� ��� ������� ĥ�ϴ����� ��Ÿ��. 
    * �̴� ���� ��ο��� ĥ���� �� ������ ���� �����ȴ�. 
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

                // ���� ������ ĥ�� ��, ��� ������� ĥ���� �������� �� ���� �ΰ����� ���ؼ���.
                // 1. ���� ������ ĥ�� ����� 1~4 �� ��������
                // 2. ���� ĥ�Ϸ��� ������ 1���� -1����
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

    // ��ü ��ȸ
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
