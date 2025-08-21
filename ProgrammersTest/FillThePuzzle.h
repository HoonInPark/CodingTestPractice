#pragma once

#include <vector>

using namespace std;

int solution(vector<vector<int>> game_board, vector<vector<int>> table) 
{
    int answer = -1;

    // 일단 퍼즐 조각이 맞아 들어가는지부터 확인. 그게 최적의 경우인지는 다음으로 생각합시다.
    for (int i = 0; i < table.size(); ++i) // i는 y좌표
    {
        for (int j = 0; j < table[i].size(); ++j) // j는 x좌표
        {
            if (table[i][j])
            {
                // 여기서 너비 우선 탐색.
                while (true)
                { 
                    
                }
            }
        }
    }

    return answer;
}