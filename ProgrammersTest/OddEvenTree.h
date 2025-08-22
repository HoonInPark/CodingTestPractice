#pragma once

/*
* https://school.programmers.co.kr/learn/courses/30/lessons/388354
*/

#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

struct Node
{
	Node(int _InNodeNum)
		: m_NodeNum(_InNodeNum)
	{
	}

	int m_NodeNum = 0;
	int m_ChildrenNum = 0;

	bool m_bIsChecked = false;
	vector<Node*> m_Neighbors;
};

vector<int> solution(vector<int> nodes, vector<vector<int>> edges)
{
	unordered_map<int, Node*> MapOfNodes;

	for (const auto NodeNum : nodes)
	{
		auto pNode = new Node(NodeNum);
		MapOfNodes[NodeNum] = pNode;
	}

	for (const auto& Edge : edges)
	{
		MapOfNodes[Edge[0]]->m_Neighbors.push_back(MapOfNodes[Edge[1]]);
		MapOfNodes[Edge[1]]->m_Neighbors.push_back(MapOfNodes[Edge[0]]);
	}

	// 자식 노드 수 카운트 
	for (auto& NodePair : MapOfNodes)
	{
		queue<Node*> Q;
		Q.push(NodePair.second);
		NodePair.second->m_bIsChecked = true;

		while (!Q.empty())
		{
			auto pNode = Q.front();
			Q.pop();
			////////////////////////////////////////////////////////////////////////////
			++NodePair.second->m_ChildrenNum;
			////////////////////////////////////////////////////////////////////////////

			for (const auto pNeighbor : pNode->m_Neighbors)
			{
				if (pNeighbor->m_bIsChecked) continue;
				Q.push(pNeighbor);
				pNeighbor->m_bIsChecked = true;
			}
		}

		for (auto& NodePairForReset : MapOfNodes)
			NodePairForReset.second->m_bIsChecked = false;

		--NodePair.second->m_ChildrenNum;
	}

	int OddEvenNumTree = 0;
	int ReverseOddEvenNumTree = 0;

	for (auto& NodePair : MapOfNodes)
	{
		int OddEvenNum = 0;
		int ReverseOddEvenNum = 0;

		queue<Node*> Q;
		Q.push(NodePair.second);
		NodePair.second->m_bIsChecked = true;

		while (!Q.empty())
		{
			auto pNode = Q.front();
			Q.pop();

			////////////////////////////////////////////////////////////////////////////
			if (pNode->m_NodeNum % 2 == pNode->m_ChildrenNum % 2)
				++OddEvenNum;
			else
				++ReverseOddEvenNum;
			////////////////////////////////////////////////////////////////////////////

			for (const auto pNeighbor : pNode->m_Neighbors)
			{
				if (pNeighbor->m_bIsChecked) continue;
				Q.push(pNeighbor);
				pNeighbor->m_bIsChecked = true;
			}
		}

		for (auto& NodePairForReset : MapOfNodes)
			NodePairForReset.second->m_bIsChecked = false;

		if (0 == OddEvenNum * ReverseOddEvenNum)
		{
			if (OddEvenNum)
				++OddEvenNumTree;
			else if (ReverseOddEvenNum)
				++ReverseOddEvenNumTree;
		}
	}

	return { OddEvenNumTree , ReverseOddEvenNumTree };
}
