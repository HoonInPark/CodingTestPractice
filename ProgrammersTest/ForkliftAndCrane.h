#pragma once

/*
* https://school.programmers.co.kr/learn/courses/30/lessons/388353
*/

#include <string>
#include <vector>

using namespace std;

int solution(vector<string> storage, vector<string> requests) 
{
    int answer = 0;

    int m = storage[0].size();
    int n = storage.size();

    vector<vector<bool>> Status;
    Status.push_back(vector<bool>(m, true));
    for (int i = 0; i < n - 2; ++i)
    {
        vector<bool> Mid(m, false);

        Mid[0] = true;
        Mid[m - 1] = true;

        Status.push_back(Mid);
    }
    Status.push_back(vector<bool>(m, true));

    for (int j = 0; j < requests.size(); ++j)
    {
        if (requests[j].size() == 1) // 지게차
        {

        }
        else // 크레인 
        {

        }
    }

    return answer;
}