#pragma once

#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, int w, int num) 
{
    int answer = 0;

    vector<vector<int>> Boxes((n - 1) / w + 1);

    for (int i = 0; i < Boxes.size(); ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            if (i * w + j + 1 <= n)
                Boxes[i].push_back(i * w + j + 1);
            else
                Boxes[i].push_back(0);
        }

        if (i % 2 == 1)
            reverse(Boxes[i].begin(), Boxes[i].end());
    }

    int FloorNum = (num - 1) / w;
    auto it = find(Boxes[FloorNum].begin(), Boxes[FloorNum].end(), num);
    int ColIdx = distance(Boxes[FloorNum].begin(), it);

    for (int k = FloorNum; k < Boxes.size(); ++k)
    {
        if (Boxes[k][ColIdx])
            answer++;
    }

    return answer;
}
