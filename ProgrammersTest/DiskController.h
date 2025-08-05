#pragma once

#include <vector>
#include <queue>

using namespace std;

struct Task
{
public:
    Task(
        int _InRequiredTime, 
        int _InRequestedTime, 
        int _InTaskNum)
        : m_RequiredTime(_InRequiredTime)
        , m_RequestedTime(_InRequestedTime)
        , m_TaskNum(_InTaskNum)
    {}

    bool operator<(const Task _InTask) const
    {
        if (m_RequiredTime != _InTask.m_RequiredTime)
            return this->m_RequiredTime > _InTask.m_RequiredTime;
        else if (m_RequestedTime != _InTask.m_RequestedTime)
            return this->m_RequestedTime > _InTask.m_RequestedTime;
        else
            return this->m_TaskNum > _InTask.m_TaskNum;
    }

private:
    int m_RequiredTime;
    int m_RequestedTime;
    int m_TaskNum;
};

int solution(vector<vector<int>> jobs) 
{
    int answer = 0;

    priority_queue<Task> TaskQ;

    for (int i = 0; i < jobs.size(); ++i)
        TaskQ.push(Task(jobs[i][0], jobs[i][1], i));

    while (!TaskQ.empty())
    {

    }

    return answer;
}
