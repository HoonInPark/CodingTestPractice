#pragma once

/*
* https://school.programmers.co.kr/learn/courses/30/lessons/42892
*/

#include <vector>
#include <algorithm>

using namespace std;

bool Comp(const vector<int>&, const vector<int>&);

struct Node
{
	Node(int _InNodeNum)
		: m_NodeNum(_InNodeNum)
	{}

	int m_NodeNum = -1;
	Node* m_pChild_L = nullptr;
	Node* m_pChild_R = nullptr;
};

vector<vector<int>> solution(vector<vector<int>> nodeinfo)
{
	for (int i = 0; i < nodeinfo.size(); i++)
		nodeinfo[i].push_back(i + 1); // nodeinfo[i][2]�� ���� �ش� ����� �ε��� ��. ���Ҵ� �ʿ� ������ �������

	// �̷��� �ϸ� �� ���� �ִ� ��� ������, ���ʿ� �ִ� ��� ������ ���ĵȴ�. 
	sort(nodeinfo.begin(), nodeinfo.end(), Comp);
	const auto& NodeInfos = nodeinfo;

	// �տ������� �ϳ��� �����鼭 ��ǥ����� �����ϴ� �������� ����ٰ� ��������. 
	// ���� �ִ� ��带 �������� ���� �������� ����Ʈ�� ��ο��� ������ ��ģ��.
	int CurHeight = -1;
	int CurIdx = 0;

	vector<Node*> Nodes; // �ε����� NodeInfos�� �����ϰ� ������.
	for (int j = 0; j < NodeInfos.size(); j++)
		Nodes.push_back(new Node(NodeInfos[j][2])); // ���� ����� ��ȣ ����ϱ�

	vector<int> NodeIdxBuf;

	while (CurIdx < NodeInfos.size())
	{
		NodeIdxBuf.clear();

		do
		{
			NodeIdxBuf.push_back(CurIdx);

			CurHeight = NodeInfos[CurIdx][1];
			CurIdx++;

		} while (CurIdx < NodeInfos.size() && CurHeight <= NodeInfos[CurIdx][1]);

		// do something
		for (int k = 0; k < NodeIdxBuf.size(); k++)
		{
			for (int l = 0; l < NodeIdxBuf[0]; l++)
			{
				NodeInfos[l][0];
			}
		}
	}

	return nodeinfo;
}

bool Comp(const vector<int>& _InFormer, const vector<int>& _InLater)
{
	if (_InFormer[1] == _InLater[1])
		return _InFormer[0] < _InLater[0];
	else
		return _InFormer[1] > _InLater[1];
}

/*
[[5,3],[11,5],[13,3],[3,5],[6,1],[1,3],[8,6],[7,2],[2,2]]
-> �� ������ �ε����� �� ��尡 ���� ��ȣ��.
*/