#pragma once

#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> expressions)
{
    vector<vector<int>> Methods(expressions.size(), vector<int>(4)); // basic op in ascii num, 1st num, 2nd num, res num

    for (int i = 0; i < expressions.size(); ++i)
    {
        const auto& Ex = expressions[i];

        // 만약 찾지 못했으면 string::npos == -1 리턴
        int IdxOfBasicOp = Ex.find('+', 2) + Ex.find('-', 2) + 1;
        int IdxOfEqual = Ex.find('=', 6);

        Methods[i][0] = Ex[IdxOfBasicOp];

        if (3 == IdxOfBasicOp) // if 1st num is two digits
            Methods[i][1] = (Ex[0] - 48) * 10 + (Ex[1] - 48);
        else
            Methods[i][1] = Ex[0] - 48;

        if (5 == IdxOfEqual - IdxOfBasicOp) // if 2nd num is two digits
            Methods[i][2] = (Ex[IdxOfBasicOp + 2] - 48) * 10 + (Ex[IdxOfBasicOp + 3] - 48);
        else
            Methods[i][2] = Ex[IdxOfBasicOp + 2] - 48;

        if ('X' == Ex.back())
        {
            Methods[i][3] = -1; // if 'X', we mark as -1
        }
        else
        {
            // res num doesn't have limit in digit
            int ExResNum = 0;
            int Digit = 1;
            for (int j = Ex.size() - 1; j >= IdxOfEqual + 2; --j)
            {
                ExResNum += (Ex[j] - 48) * Digit;
                Digit *= 10;
            }

            Methods[i][3] = ExResNum;
        }
    }

    vector<string> answer(expressions.size());
    for (int NumSys = 2; NumSys < 10; ++NumSys)
    {
        for (const auto& Method : Methods)
        {

        }
    }

    return answer;
}
