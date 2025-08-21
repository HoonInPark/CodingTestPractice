#pragma once

#include <vector>

using namespace std;

int Grading(const vector<int>&, const vector<int>&);

vector<int> solution(vector<int> answers)
{
    vector<int> Soopoja_1 = { 1, 2, 3, 4, 5 };
    vector<int> Soopoja_2 = { 2, 1, 2, 3, 2, 4, 2, 5 };
    vector<int> Soopoja_3 = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

    vector<int> Grades;
    Grades.push_back(Grading(answers, Soopoja_1));
    Grades.push_back(Grading(answers, Soopoja_2));
    Grades.push_back(Grading(answers, Soopoja_3));

    vector<int> answer;

    const int MaxNum = max(Grades[0], max(Grades[1], Grades[2]));
    for (int i = 0; i < Grades.size(); ++i)
    {
        if (MaxNum == Grades[i])
            answer.push_back(i + 1);
    }

    return answer;
}

int Grading(const vector<int>& _InAnswer, const vector<int>& _InStudentAnswer)
{
    int RetNum = 0;

    for (int i = 0; i < _InAnswer.size(); ++i)
    {
        if (_InAnswer[i] == _InStudentAnswer[i % _InStudentAnswer.size()])
            RetNum++;
    }

    return RetNum;
}