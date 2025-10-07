#pragma once

/*
* https://school.programmers.co.kr/learn/courses/30/lessons/389481?language=cpp
*/

#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long Pow26(int exp);

string solution(long long n, vector<string> bans)  // 1부터 시작하는 카운팅
{
    string ResStr;

    // 전부 0으로부터 시작하는 수로 변환
    for (const auto& BanStr : bans)
    {
        for (int i = 0; i < BanStr.size(); ++i)
        {

        }
    }

    return ResStr;
}

long long Pow26(int exp)
{
    long long res = 1;

    for (int i = 0; i < exp; ++i)
        res *= 26;

    return res;
}
