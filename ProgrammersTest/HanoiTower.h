#pragma once

/*
* https://school.programmers.co.kr/learn/courses/30/lessons/12946
*/

#include <vector>

using namespace std;

vector<vector<int>> solution(int n) 
{
    if (1 == n) return { {1, 3} };

    // 최단경로 길이 구하기
    int PathNum = 0;
    for (int i = 0; i < n; i++)
    {
        PathNum = 2 * PathNum + 1;
    }

    vector<vector<int>> Res(PathNum);

    const int CenterIdx = PathNum / 2;
    Res[CenterIdx] = { 1, 3 };
    int NumOfPrevPath = 1;

    vector<vector<int>> Buf2Dim;
    Buf2Dim.reserve(PathNum / 2);

    vector<int> Buf1Dim(2);

    for (int j = 2; j <= n; j++)
    {
        // assign은 former <= result < later의 구조.
        Buf2Dim.assign(
            Res.begin() + CenterIdx - NumOfPrevPath / 2, 
            Res.begin() + CenterIdx + NumOfPrevPath / 2 + 1);

        // left
        for (int k = CenterIdx - NumOfPrevPath; k < CenterIdx; k++)
        {
            for (int l = 0; l < 2; l++)
            {
                switch (Buf2Dim[k - (CenterIdx - NumOfPrevPath)][l])
                {
                case 1:
                    Buf1Dim[l] = 1;
                    break;
                case 2:
                    Buf1Dim[l] = 3;
                    break;
                case 3:
                    Buf1Dim[l] = 2;
                    break;
                default:
                    break;
                }
            }

            Res[k] = Buf1Dim;
        }
        // right
        for (int m = CenterIdx + 1; m <= CenterIdx + NumOfPrevPath; m++)
        {
            for (int l = 0; l < 2; l++)
            {
                switch (Buf2Dim[m - (CenterIdx + 1)][l])
                {
                case 1:
                    Buf1Dim[l] = 2;
                    break;
                case 2:
                    Buf1Dim[l] = 1;
                    break;
                case 3:
                    Buf1Dim[l] = 3;
                    break;
                default:
                    break;
                }
            }

            Res[m] = Buf1Dim;
        }

        NumOfPrevPath = NumOfPrevPath * 2 + 1;
    }
    
    return Res;
}
