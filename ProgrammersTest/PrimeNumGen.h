#pragma once
/*
* https://school.programmers.co.kr/learn/courses/30/lessons/12977
*/
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> nums) 
{
    int answer = -1;

    vector<int> buf;

    for (int i = 0; i < nums.size(); ++i)
    {
        for (int j = 0; j < nums.size(); ++j)
        {
            if (i == j) continue;

            for (int k = j + 1; k < nums.size(); ++k)
            {
                if (i == k) continue;
                buf.push_back(nums[j] + nums[k]);
            }
        }
    }

    for (const auto& elem : buf)
    {

    }

    return answer;
}
//
//int IsPrime(const int _InNum)
//{
//    if ()
//    return
//}