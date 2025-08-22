#pragma once

#include <vector>
#include <unordered_map>

using namespace std;

struct Node
{
	Node(int _InNodeNum)
		: m_NodeNum(_InNodeNum)
	{
	}

	int m_NodeNum = 0;
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



	return vector<int>();
}
