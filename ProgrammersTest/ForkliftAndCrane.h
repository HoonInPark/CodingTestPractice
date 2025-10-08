#pragma once

/*
* https://school.programmers.co.kr/learn/courses/30/lessons/388353
*/

#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<string> storage, vector<string> requests) 
{
    int answer = 0;

    int m = storage[0].size();
    int n = storage.size();

    unordered_set<string> OutsideStuffs;

    for (int i = 0; i < m; ++i)
    {
        string IdxStr(2, 0);

        IdxStr[1] = i;
        OutsideStuffs.insert(IdxStr);

        IdxStr[0] = n - 1;
        OutsideStuffs.insert(IdxStr);
    }

    for (int j = 1; j < n - 1; ++j)
    {
        string IdxStr(2, 0);
        
        IdxStr[0] = j;
        OutsideStuffs.insert(IdxStr);

        IdxStr[1] = m - 1;
        OutsideStuffs.insert(IdxStr);
    }

    // do something
    for (const auto& ReqStr : requests)
    {
        if (1 == ReqStr.size())
        {

        }
        else
        {

        }
    }

    for (auto IdxStr : OutsideStuffs)
    {
        IdxStr[0] += 48;
        IdxStr[1] += 48;

        cout << IdxStr << endl;
    }

    return answer;
}