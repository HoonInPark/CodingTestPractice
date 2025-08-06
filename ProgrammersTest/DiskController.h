#pragma once
/*
* https://school.programmers.co.kr/learn/courses/30/lessons/42627
*/
#include <vector>
#include <queue>

using namespace std;

struct Task
{
    Task()
    {
        SetEmpty();
    }

    Task(
        int _InRequestedTime, 
        int _InRequiredTime, 
        int _InTaskNum)
        : m_RequestedTime(_InRequestedTime)
        , m_RequiredTime(_InRequiredTime)
        , m_TaskNum(_InTaskNum)
    {}

    inline bool IsEmpty()
    {
        return -1 == m_RequestedTime;
    }
    inline void SetEmpty()
    {
        m_RequestedTime = -1;
        m_RequiredTime = -1;
        m_TaskNum = -1;
        m_ActualStartTime = -1;
        m_ActualEndTime = -1;
    }

    Task& operator=(const Task& _InTask)
    {
        this->m_RequestedTime = _InTask.m_RequestedTime;
        this->m_RequiredTime = _InTask.m_RequiredTime;
        this->m_TaskNum = _InTask.m_TaskNum;

        this->m_ActualStartTime = _InTask.m_ActualStartTime;
        this->m_ActualEndTime = _InTask.m_ActualEndTime;

        return *this;
    }

    bool operator<(const Task& _InTask) const
    {
        if (m_RequiredTime != _InTask.m_RequiredTime)
            return this->m_RequiredTime > _InTask.m_RequiredTime;
        else if (m_RequestedTime != _InTask.m_RequestedTime)
            return this->m_RequestedTime > _InTask.m_RequestedTime;
        else
            return this->m_TaskNum > _InTask.m_TaskNum;
    }

    int m_RequiredTime;
    int m_RequestedTime;
    int m_TaskNum;

    int m_ActualStartTime;
    int m_ActualEndTime;
};

int solution(vector<vector<int>> jobs)
{
    priority_queue<Task> TaskQ;
    queue<Task> RecordQ;

    int CurTime = 0; // Timer Tick 같은 변수.
    int JobsCnt = 0; // jobs에서 몇개의 원소를 순회했는지. 모두 순회했는지 확인하려고 둔 변수임.
    Task CurTask;

    for (;;)
    {
        for (int i = 0; i < jobs.size(); ++i)
        {
            if (jobs[i][0] == CurTime)
            {
                TaskQ.push(Task(jobs[i][0], jobs[i][1], i));
                JobsCnt++;
            }
        }

        if (CurTask.IsEmpty())
        {
            if (!TaskQ.empty())
            {
                CurTask = TaskQ.top();
                TaskQ.pop();
                CurTask.m_ActualStartTime = CurTime;
            }
            else
            {
                if (jobs.size() == JobsCnt)
                    break;
            }
        }
        else if (CurTime == CurTask.m_ActualStartTime + CurTask.m_RequiredTime)
        {
            // 기록 및 실행 종료
            CurTask.m_ActualEndTime = CurTime;
            RecordQ.push(CurTask);
            CurTask.SetEmpty();

            if (!TaskQ.empty())
            {
                CurTask = TaskQ.top();
                TaskQ.pop();
                CurTask.m_ActualStartTime = CurTime;
            }
            else
            {
                if (jobs.size() == JobsCnt)
                    break;
            }
        }

        CurTime++;
    }

    int answer = 0;
    while (!RecordQ.empty())
    {
        const auto& TaskTmp = RecordQ.front();
        answer += TaskTmp.m_ActualEndTime - TaskTmp.m_RequestedTime;
        RecordQ.pop();
    }

    return answer / jobs.size();
}
