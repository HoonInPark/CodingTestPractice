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
	int m_ChildrenNumOfThisTree = 0;

	bool m_bIsChecked = false;
	vector<Node*> m_Neighbors;
};

int DFS(Node*);

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

	}

	DFS(MapOfNodes[1]);

	return vector<int>();
}

int DFS(Node* _pInNode)
{
	int ChildrenNum = 0;
	_pInNode->m_bIsChecked = true;

	for (auto pNode : _pInNode->m_Neighbors)
	{
		if (pNode->m_bIsChecked) continue;

		++ChildrenNum;
		ChildrenNum += DFS(pNode);
	}

	cout << "NodeNum : " << _pInNode->m_NodeNum << " ChildrenNum : " << ChildrenNum << endl;

	return ChildrenNum;
}

