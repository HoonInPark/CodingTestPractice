#pragma once

/*
* https://programmers.co.kr/skill_checks/603242?challenge_id=16769
*/

#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct Node
{
	Node(int _InNodeNum)
		: m_NodeNum(_InNodeNum)
	{
	}

	unordered_set<Node*> m_NextNodes;
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
		
		MapOfNodes[road[0]]->m_NextNodes.insert(MapOfNodes[road[1]]);
	}

	auto pRoot = MapOfNodes[1];

	/*
	* 가장 먼저, 1에서 출발하여 NextNodes.empty()인 노드에 도달할 때까지 
	* m_bIsVisited = true를 마킹하며 계속 순회.
	* 끝에 다다르면, RetNum++;
	* MapOfNodes의 값 중 m_bIsVisited == false인 것부터 출발하여 다시 같은 방식으로 순회.
	* 근데 만약 MapOfNodes 값 모두 m_bIsVisited == true면 모두 종료.
	* 근데, 순회가 하나의 노드만 m_bIsVisited = true 처리하고 끝날 수 있음.
	*/

	

	for (const auto NodePair : MapOfNodes)
		delete NodePair.second;

	return RetNum;
}
