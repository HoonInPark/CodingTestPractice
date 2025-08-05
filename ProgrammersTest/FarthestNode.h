#pragma once

/*
* https://school.programmers.co.kr/learn/courses/30/lessons/49189
*/

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int solution(int n, vector<vector<int>> edge) 
{
	int answer = 0;

	// branch-leaf 형태의 map이 만들 것임.
	unordered_map<int, unordered_set<int>> PathFinder;
	for (int i = 1; i < n + 1; ++i)
		PathFinder.insert(make_pair(i, unordered_set<int>()));

	for (int j = 1; j < n + 1; ++j)
	{
		for (int k = 0; k < edge.size(); ++k)
		{
			if (edge[k][0] == j || edge[k][1] == j)
			{
				(*PathFinder.find(j)).second.insert(k);
			}
		}
	}

	for (int l = 2; l < n + 1; ++l)
	{
		
	}

	return answer;
}
