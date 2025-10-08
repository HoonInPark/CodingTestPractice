#pragma once

/*
* https://school.programmers.co.kr/learn/courses/30/lessons/389481?language=cpp
*/

#include <string>
#include <vector>

using namespace std;

long long Pow26(long long exp);

string solution(long long n, vector<string> bans)
{
    vector<long long> BanStrIdxs;

    for (const auto& BanStr : bans)
    {
        long long ResNum = 0;
        for (long long i = 0; i < BanStr.size() - 1; ++i)
        {
            ResNum += Pow26(BanStr.size() - 1 - i) * (BanStr[i] - 96);
        }

        ResNum += BanStr[BanStr.size() - 1] - 97;
        BanStrIdxs.push_back(ResNum);
    }

    --n;
    long long ResNum = 0;

    for (long long j = n; j <= n + bans.size(); ++j)
    {
        long long FormerNumCnt = 0;
        for (const auto BanStrIdx : BanStrIdxs)
        {
            if (BanStrIdx < j)
                ++FormerNumCnt;
        }

        if (FormerNumCnt + n == j)
        {
            ResNum = j;
            break;
        }
    }

    long long k = 1;
    while (true)
    {
        if (ResNum < Pow26(k))
            break;
        else
            ++k;
    }

    --k;
    string ResStr(k + 1, 'a');
    for (long long l = k; l > 0; --l)
    {
        long long DigitNum = ResNum / Pow26(l);
        ResNum -= DigitNum * Pow26(l);
        ResStr[k - l] = 97 + DigitNum - 1;
    }

    ResStr[k] = 97 + ResNum;

    return ResStr;
}

long long Pow26(long long exp)
{
    long long res = 1;

    for (long long i = 0; i < exp; ++i)
        res *= 26;

    return res;
}
