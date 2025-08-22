#pragma once

#include <vector>

using namespace std;

int solution(int n, int w, int num) 
{
    int answer = 0;

    // num이 몇층에 있는지 아는 법
    int FloorNum = (num - 1) / w;

    vector<int> PlusNumToGoNextFloor;
    for (int i = 0; i < w; ++i)
        PlusNumToGoNextFloor.push_back(2 * i + 1);



    while (true)
    {

    }

    return answer;
}
