#pragma once

/*
* https://school.programmers.co.kr/learn/courses/30/lessons/389481?language=cpp
*/

#include <string>
#include <vector>
#include <cmath>

using namespace std;

string solution(long long n, vector<string> bans)  // 1부터 시작하는 카운팅
{
    ////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////// 1부터 시작하는 카운팅 //////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////
    vector<int> OriIdxBans;
    OriIdxBans.reserve(bans.size());

    for (const auto& BanStr : bans)
    {
        int OriginalIdx = 0;
        for (int i = 0; i < BanStr.size(); ++i)
            OriginalIdx += (BanStr[i] - 97 + 1) * pow(26, BanStr.size() - 1 - i);

        OriIdxBans.push_back(OriginalIdx); // 1부터 시작하는 카운팅
    }

    long long OriIdxN;
    for (long long OriIdxExp = n;              // 모든 문자열이 구하려는 문자열보다 뒤에 있을 때 
        OriIdxExp <= n + OriIdxBans.size();    // 모든 문자열이 구하려는 문자열보다 앞에 있을 때 
        ++OriIdxExp)
    {
        long long FormerNumCnt = 0;
        for (const auto OriIdx : OriIdxBans)
        {
            if (OriIdx < OriIdxExp)
                ++FormerNumCnt;
        }

        if (OriIdxExp - FormerNumCnt == n)
        {
            OriIdxN = OriIdxExp;
            break;
        }
    }

    long long Pow = 1;
    for (;;)
    {
        if (OriIdxN < pow(26, Pow))
            break;
        else
            ++Pow;
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////// 1부터 시작하는 카운팅 //////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////

    --Pow; // 0부터 시작하는 카운팅

    string ResStr(Pow + 1, 'a'); // 자릿수를 표현해야 하니, 1부터 시작하는 카운팅.
    int StrIdx = 0;

    for (long long Digit = Pow; Digit >= 0; --Digit)    // 0부터 시작하는 카운팅
    {
        long long DigitNum = OriIdxN / pow(26, Digit);  // 1부터 시작하는 카운팅
        ResStr[StrIdx] += DigitNum - 1;                 // 0부터 시작하는 카운팅

        OriIdxN -= DigitNum * pow(26, Digit);
        
        ++StrIdx;
    }

    return ResStr;
}
