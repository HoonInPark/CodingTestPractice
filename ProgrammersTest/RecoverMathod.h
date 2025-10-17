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
                Methods[i][3].push_back(Ex[j] - 48);
        }
    }

    vector<string> answer;
    for (int NumSys = 2; NumSys < 10; ++NumSys)
    {
        bool bIsEachDigitFitForNumSys = true;
        bool bIsEachEqIsValid = true;

        vector<int> MethodIdxsToSolve;
        vector<vector<int>> MethodNumsToSolve;

        for (int k = 0; k < Methods.size(); ++k)
        {
            const auto& Method = Methods[k];

            for (int l = 1; l < 4; ++l)
            {
                for (int p = 0; p < Method[l].size(); ++p)
                {
                    if (Method[l][p] >= NumSys)
                    {
                        bIsEachDigitFitForNumSys = false;
                        continue;
                    }
                }
            }

            if (false == bIsEachDigitFitForNumSys)
                break;

            vector<int> Nums(3, 0);
            for (int l = 1; l < 4; ++l)
            {
                int Digit = 1;

                for (int p = Method[l].size() - 1; p >= 0; --p)
                {
                    Nums[l - 1] += Method[l][p] * Digit;
                    Digit *= NumSys;
                }
            }

            if (Nums[2] > 0) // if it doesn't have 'X'
            {
                // check if equation of basic operation is valid
                if (Nums[2] != (Nums[0] + Nums[1]))
                    bIsEachEqIsValid = false;
            }
            else // if it has 'X'
            {
                MethodIdxsToSolve.push_back(k);
                MethodNumsToSolve.push_back(Nums);
            }

            if (false == bIsEachEqIsValid)
                break;
        }

        if (true == bIsEachEqIsValid)
            continue;

        for (int q = 0; q < MethodIdxsToSolve.size(); ++q)
        {
            auto& Ex = expressions[q];
            const auto& Nums = MethodNumsToSolve[q];

            Ex.pop_back();

            const int ResNum = Nums[0] + Nums[1];

            int Digit = NumSys;
            int DigitNum = 1;

            while (ResNum / Digit != 0)
            {
                Digit *= NumSys;
                ++DigitNum;
            }

            string StrX;
            for (int r = 0; r < DigitNum; ++r)
            {
                
            }
        }
    }

    return answer;
}
