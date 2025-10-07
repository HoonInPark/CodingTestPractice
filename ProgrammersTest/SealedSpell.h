#pragma once

/*
* https://school.programmers.co.kr/learn/courses/30/lessons/389481?language=cpp
*/

#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long Pow26(long long exp);

string solution(long long n, vector<string> bans)  // 1부터 시작하는 카운팅
{
    string ResStr;

    vector<long long> BanStrIdxs;

    // 전부 0으로부터 시작하는 수로 변환
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
    for (long long j = n; j <= n + bans.size(); ++j)
    {

    }

    return ResStr;
}

long long Pow26(long long exp)
{
    long long res = 1;

    for (long long i = 0; i < exp; ++i)
        res *= 26;

    return res;
}
