#pragma once

/*
* https://school.programmers.co.kr/learn/courses/30/lessons/388351
*/

#include <vector>

using namespace std;

int ParseTo10(int);

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) 
{
    vector<int> Scores(schedules.size(), 0);

    for (int i = 0; i < timelogs.size(); ++i)
    {
        int Schedule = schedules[i];

        int NewStartDay = 6 - startday;
        if (6 - startday < 0)
            NewStartDay += 7;

        for (int j = 0; j < timelogs[i].size(); ++j)
        {
            if (NewStartDay != j &&
                7 - startday != j &&
                ParseTo10(timelogs[i][j]) <= ParseTo10(Schedule) + 10)
                ++Scores[i];
        }
    }

    int Answer = 0;
    for (int k = 0; k < Scores.size(); ++k)
    {
        if (5 == Scores[k])
            ++Answer;
    }

    return Answer;
}

int ParseTo10(int _In60)
{
    return (_In60 / 100) * 60 + (_In60 % 100);
}
