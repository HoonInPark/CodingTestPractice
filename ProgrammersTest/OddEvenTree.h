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

void Dfs(Node*, int&, int&);

vector<int> solution(vector<int> nodes, vector<vector<int>> edges)
{
	unordered_map<int, Node*> MapOfNodes;

	for (const auto NodeNum : nodes)
		MapOfNodes[NodeNum] = new Node(NodeNum);

	for (const auto& Edge : edges)
	{
		MapOfNodes[Edge[0]]->m_Neighbors.push_back(MapOfNodes[Edge[1]]);
		MapOfNodes[Edge[1]]->m_Neighbors.push_back(MapOfNodes[Edge[0]]);
	}

	int ResNum_1 = 0;
	int ResNum_2 = 0;

	int OddEvenNum;
	int RevOddEvenNum;

	// 자식 노드 수 카운트 
	for (const auto& NodePair : MapOfNodes)
	{
		if (NodePair.second->m_bIsChecked) continue;

		OddEvenNum = 0;
		RevOddEvenNum = 0;

		Dfs(NodePair.second, OddEvenNum, RevOddEvenNum);

		if (1 == OddEvenNum)
			++ResNum_1;
		if (1 == RevOddEvenNum)
			++ResNum_2;
	}

	for (auto& NodePair : MapOfNodes)
		delete NodePair.second;

	return { ResNum_1 , ResNum_2 };
}

void Dfs(Node* _pInNode, int& _InOddEvenNum, int& _InRevOddEvenNum)
{
	_pInNode->m_bIsChecked = true;

	for (auto pNode : _pInNode->m_Neighbors)
	{
		if (pNode->m_bIsChecked) continue;
		Dfs(pNode, _InOddEvenNum, _InRevOddEvenNum);
	}

	if (_pInNode->m_NodeNum % 2 == _pInNode->m_Neighbors.size() % 2)
		++_InOddEvenNum;
	else
		++_InRevOddEvenNum;
}
