#pragma once

#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> expressions)
{
    vector<string> answer(expressions.size());

    vector<vector<int>> Methods(expressions.size(), vector<int>(4));

    for (const auto& Ex : expressions)
    {
        // 만약 찾지 못했으면 string::npos == -1 리턴
        int IdxOfBasicOp = Ex.find('+', 2) + Ex.find('-', 2) + 1;
        int IdxOfEqual = Ex.find('=', 6);

        
    }

    for (int NumSys = 2; NumSys < 10; ++NumSys)
    {

    }

    return answer;
}
