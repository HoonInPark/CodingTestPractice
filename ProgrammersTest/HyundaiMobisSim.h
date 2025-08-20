#pragma once

/*
* https://programmers.co.kr/skill_checks/603242?challenge_id=16769
*/

#include <vector>
#include <unordered_map>

using namespace std;

struct Node
{
	Node(int _InNodeNum)
		: m_NodeNum(_InNodeNum)
	{
	}

	vector<Node*> m_NextNodes;
	int m_NodeNum = -1;
	bool m_bIsVisited = false;
};

int solution(int n, vector<vector<int>> roads)
{
	int RetNum = 0;

	unordered_map<int, Node*> MapOfNodes;

	for (const auto& road : roads)
	{
		auto pNode_0 = MapOfNodes[road[0]];
		auto pNode_1 = MapOfNodes[road[1]];
		if (!pNode_0)
			MapOfNodes[road[0]] = new Node(road[0]);
		if (!pNode_1)
			MapOfNodes[road[1]] = new Node(road[1]);
		
		MapOfNodes[road[0]]->m_NextNodes.push_back(MapOfNodes[road[1]]);
	}

	auto pNode = MapOfNodes[1];



	for (const auto NodePair : MapOfNodes)
		delete NodePair.second;

	return RetNum;
}
