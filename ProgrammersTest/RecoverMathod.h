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
        // ���� ã�� �������� string::npos == -1 ����
        int IdxOfBasicOp = Ex.find('+', 2) + Ex.find('-', 2) + 1;
        int IdxOfEqual = Ex.find('=', 6);

        
    }

    for (int NumSys = 2; NumSys < 10; ++NumSys)
    {

    }

    return answer;
}
