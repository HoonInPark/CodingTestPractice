#pragma once

#include <vector>

using namespace std;

int solution(vector<vector<int>> game_board, vector<vector<int>> table) 
{
    int answer = -1;

    // �ϴ� ���� ������ �¾� ���������� Ȯ��. �װ� ������ ��������� �������� �����սô�.
    for (int i = 0; i < table.size(); ++i) // i�� y��ǥ
    {
        for (int j = 0; j < table[i].size(); ++j) // j�� x��ǥ
        {
            if (table[i][j])
            {
                // ���⼭ �ʺ� �켱 Ž��.
                while (true)
                { 
                    
                }
            }
        }
    }

    return answer;
}