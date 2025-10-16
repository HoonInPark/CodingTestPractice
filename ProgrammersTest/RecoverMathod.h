#pragma once

#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> expressions)
{
    // basic op in ascii num, 1st num, 2nd num, res num
    // and each num is stored as vector<int>.
    vector<vector<vector<int>>> Methods(expressions.size(), vector<vector<int>>(4)); 

    for (int i = 0; i < expressions.size(); ++i)
    {
        const auto& Ex = expressions[i];

        // 만약 찾지 못했으면 string::npos == -1 리턴
        int IdxOfBasicOp = Ex.find('+', 2) + Ex.find('-', 2) + 1;
        int IdxOfEqual = Ex.find('=', 6);

        Methods[i][0].push_back(Ex[IdxOfBasicOp]);

        Methods[i][1].push_back(Ex[0] - 48);
        if (3 == IdxOfBasicOp) // if 1st num is two digits
            Methods[i][1].push_back(Ex[1] - 48);

        Methods[i][2].push_back(Ex[IdxOfBasicOp + 2] - 48);
        if (5 == IdxOfEqual - IdxOfBasicOp) // if 1st num is two digits
            Methods[i][2].push_back(Ex[IdxOfBasicOp + 3] - 48);

        if ('X' == Ex.back())
        {
            // if 'X', we mark as -1
            Methods[i][3].push_back(-1);
        }
        else
        {
            // res num doesn't have limit in digit
            for (int j = IdxOfEqual + 2; j < Ex.size(); ++j)
                Methods[i][3].push_back(Ex[j]);
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
