#pragma once

/*
* https://school.programmers.co.kr/learn/courses/30/lessons/12981
*/

#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) 
{
    vector<int> answer;

    unordered_set<string> buf;
    buf.insert(words[0]);

    int break_num = 0;
    for (int i = 1; i < words.size(); ++i)
    {
        auto it = buf.find(words[i]);
        if (it != buf.end() || words[i - 1].back() != words[i].front())
        {
            break_num = i;
            break;
        }

        buf.insert(words[i]);
    }

    if (break_num == 0) 
        return { 0, 0 };

    int hang_over = break_num % n;
    
    return { hang_over + 1, (break_num - hang_over) / n  + 1};
}

/*
"tank", "kick", "know", 
"wheel", "land", "dream",
"mother", "robot", "tank"

"hello", "observe", "effect", "take", "either", 
"recognize", "encourage", "ensure", "establish", "hang",
"gather", "refer", "reference", "estimate", "executive"
*/
