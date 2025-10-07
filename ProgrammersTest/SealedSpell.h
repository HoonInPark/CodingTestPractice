#pragma once

/*
* https://school.programmers.co.kr/learn/courses/30/lessons/389481?language=cpp
*/

#include <string>
#include <vector>
#include <cmath>

using namespace std;

string solution(long long n, vector<string> bans)  // 1���� �����ϴ� ī����
{
    ////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////// 1���� �����ϴ� ī���� //////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////
    vector<int> OriIdxBans;
    OriIdxBans.reserve(bans.size());

    for (const auto& BanStr : bans)
    {
        int OriginalIdx = 0;
        for (int i = 0; i < BanStr.size(); ++i)
            OriginalIdx += (BanStr[i] - 97 + 1) * pow(26, BanStr.size() - 1 - i);

        OriIdxBans.push_back(OriginalIdx); // 1���� �����ϴ� ī����
    }

    long long OriIdxN;
    for (long long OriIdxExp = n;              // ��� ���ڿ��� ���Ϸ��� ���ڿ����� �ڿ� ���� �� 
        OriIdxExp <= n + OriIdxBans.size();    // ��� ���ڿ��� ���Ϸ��� ���ڿ����� �տ� ���� �� 
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
    ////////////////////////////////////// 1���� �����ϴ� ī���� //////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////

    --Pow; // 0���� �����ϴ� ī����

    string ResStr(Pow + 1, 'a'); // �ڸ����� ǥ���ؾ� �ϴ�, 1���� �����ϴ� ī����.
    int StrIdx = 0;

    for (long long Digit = Pow; Digit >= 0; --Digit)    // 0���� �����ϴ� ī����
    {
        long long DigitNum = OriIdxN / pow(26, Digit);  // 1���� �����ϴ� ī����
        ResStr[StrIdx] += DigitNum - 1;                 // 0���� �����ϴ� ī����

        OriIdxN -= DigitNum * pow(26, Digit);
        
        ++StrIdx;
    }

    return ResStr;
}
