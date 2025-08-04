#pragma once
/*
* https://school.programmers.co.kr/learn/courses/30/lessons/12977
*/
#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

bool isPrime(int n)
{
    if (n < 2)
        return false;

    for (int i = 2; i <= sqrt(n); ++i)
    {
        if (n % i == 0)
            return false;
    }

    return true;
}

int solution(vector<int> nums) 
{
    int answer = 0;

    vector<int> buf;

    int max_num = 0;

    for (int i = 0; i < nums.size() - 2; ++i)
    {
        for (int j = i + 1; j < nums.size() - 1; ++j)
        {
            for (int k = j + 1; k < nums.size(); ++k)
            {
                int res = nums[i] + nums[j] + nums[k];

                if (isPrime(res))
                    answer++;
                /*
                if (max_num < res)
                    max_num = res;

                buf.push_back(res);
                */
            }
        }
    }
    /*
    unordered_set<int> prime_set;
    prime_set.insert(2);

    for (int l = 3; l < max_num + 1; ++l)
    {
        bool bIsPrime = true;
        for (const auto elem : prime_set)
        {
            if (l % elem == 0)
            {
                bIsPrime = false;
                break;
            }
        }

        if (bIsPrime)
            prime_set.insert(l);
    }

    for (const auto& elem : buf)
    {
        auto it = prime_set.find(elem);
        if (prime_set.end() != it)
            answer++;
    }
    */

    return answer;
}
