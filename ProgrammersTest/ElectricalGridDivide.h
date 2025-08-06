#pragma once

/*
* https://school.programmers.co.kr/learn/courses/30/lessons/86971
*/

#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <functional>
#include <stdlib.h>


using namespace std;

int solution1(int n, vector<vector<int>> wires)
{
	int answer = INT_MAX;

	unordered_map<int, unordered_set<int>> Neighbors;
	for (int i = 1; i < n + 1; ++i)
		Neighbors.insert(make_pair(i, unordered_set<int>()));

	for (const auto& Wire : wires)
	{
		Neighbors[Wire[0]].insert(Wire[1]);
		Neighbors[Wire[1]].insert(Wire[0]);
	}

	// 순회하는 기능 필요.
	unordered_map<int, bool> CheckMap;
	for (int j = 1; j < n + 1; ++j)
		CheckMap.insert(make_pair(j, false));

	stack<int> StackBuf;
	int PushCnt;

	for (int k = 0; k < wires.size(); ++k) // 제외할 전선 하나의 인덱스 == j
	{
		PushCnt = 0;

		// 전선 끊고
		Neighbors[wires[k][0]].erase(wires[k][1]);
		Neighbors[wires[k][1]].erase(wires[k][0]);

		// 임의의 출발점
		StackBuf.push(1);
		PushCnt++;
		CheckMap[1] = true;

		// 그래프 순회
		while (!StackBuf.empty())
		{
			int TopNum = StackBuf.top();
			StackBuf.pop();
			CheckMap[TopNum] = true;

			for (const int NextNum : Neighbors[TopNum])
			{
				if (!CheckMap[NextNum])
				{
					StackBuf.push(NextNum);
					PushCnt++;
				}
			}
		}

		// 여기까지 왔을 때 한쪽의 그래프 내 노드 총 갯수가 나온다. 원래 전체 숫자 n에서 빼면 두 개가 어떻게 나뉘는지 알 수 있음.
		if (abs(PushCnt - (n - PushCnt)) < answer)
		{
			answer = abs(PushCnt - (n - PushCnt));
		}

		// 초기화
		for (auto& CheckMapPair : CheckMap)
			CheckMapPair.second = false;

		// 다시 연결
		Neighbors[wires[k][0]].insert(wires[k][1]);
		Neighbors[wires[k][1]].insert(wires[k][0]);
	}

	return answer;
}

int solution2(int n, vector<vector<int>> wires)
{
	vector<vector<int>> graph(n + 1);
	for (int i = 0; i < (int)wires.size(); i++) {
		int u = wires[i][0];
		int v = wires[i][1];
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	vector<int> siz(n + 1);
	function<void(int, int)> dfs = [&](int cur, int prev)  -> void {
		siz[cur] = 1;
		for (int nxt : graph[cur]) {
			if (nxt == prev) continue;
			dfs(nxt, cur);
			siz[cur] += siz[nxt];
		}
		};
	dfs(1, -1);
	int answer = INT_MAX;
	for (int i = 1; i <= n; i++) {
		for (int j : graph[i]) {
			int l = siz[j];
			int r = n - siz[j];
			answer = min(answer, abs(l - r));
		}
	}
	return answer;
}