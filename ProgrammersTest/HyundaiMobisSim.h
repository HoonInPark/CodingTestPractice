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
	* ���� ����, 1���� ����Ͽ� NextNodes.empty()�� ��忡 ������ ������ 
	* m_bIsVisited = true�� ��ŷ�ϸ� ��� ��ȸ.
	* ���� �ٴٸ���, RetNum++;
	* MapOfNodes�� �� �� m_bIsVisited == false�� �ͺ��� ����Ͽ� �ٽ� ���� ������� ��ȸ.
	* �ٵ� ���� MapOfNodes �� ��� m_bIsVisited == true�� ��� ����.
	* �ٵ�, ��ȸ�� �ϳ��� ��常 m_bIsVisited = true ó���ϰ� ���� �� ����.
	*/

	

	for (const auto NodePair : MapOfNodes)
		delete NodePair.second;

	return RetNum;
}
