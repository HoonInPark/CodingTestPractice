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
void DfsClear(Node*);

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

	int ResNum_1 = 0;
	int ResNum_2 = 0;

	int OddEvenNum = 0;
	int RevOddEvenNum = 0;

	// �ڽ� ��� �� ī��Ʈ 
	for (const auto& NodePair : MapOfNodes)
	{
		OddEvenNum = 0;
		RevOddEvenNum = 0;

		Dfs(NodePair.second, OddEvenNum, RevOddEvenNum);
		DfsClear(NodePair.second);

		if (0 == OddEvenNum * RevOddEvenNum)
		{
			if (OddEvenNum)
				++ResNum_1;
			else if (RevOddEvenNum)
				++ResNum_2;
		}
	}

	return { ResNum_1 , ResNum_2 };
}

void Dfs(Node* _pInNode, int& _InOddEvenNum, int& _InRevOddEvenNum)
{
	int ChildrenNum = 0;
	_pInNode->m_bIsChecked = true;

	for (auto pNode : _pInNode->m_Neighbors)
	{
		if (pNode->m_bIsChecked) continue;

		++ChildrenNum;
		Dfs(pNode, _InOddEvenNum, _InRevOddEvenNum);
	}

	//cout << "NodeNum : " << _pInNode->m_NodeNum << " ChildrenNum : " << ChildrenNum << endl;
	if (_pInNode->m_NodeNum % 2 == ChildrenNum % 2) // ���� �μ��� ���� _pInNode�� Ȧ�� ��� Ȥ�� ¦�� ����� ���
		++_InOddEvenNum;
	else // ���� �μ��� ���� _pInNode�� ��Ȧ�� ��� Ȥ�� ��¦�� ����� ���
		++_InRevOddEvenNum;
}

// DFSClear �̷��� �����? -> ��ȸ ǥ�� �ʱ�ȭ�ϴ� �Լ�.
void DfsClear(Node* _pInNode)
{
	_pInNode->m_bIsChecked = false;

	for (auto pNode : _pInNode->m_Neighbors)
	{
		if (!pNode->m_bIsChecked) continue;

		DfsClear(pNode);
	}
}
