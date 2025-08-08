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
		nodeinfo[i].push_back(i + 1); // nodeinfo[i][2]는 원래 해당 노드의 인덱스 값. 재할당 필요 없지롱 쿠쿠루삥뽕

	// 이렇게 하면 맨 위에 있는 노드 순으로, 왼쪽에 있는 노드 순으로 정렬된다. 
	sort(nodeinfo.begin(), nodeinfo.end(), Comp);
	const auto& NodeInfos = nodeinfo;

	// 앞에서부터 하나씩 꺼내면서 좌표평면을 분할하는 수직선을 만든다고 생각하자. 
	// 위에 있는 노드를 기준으로 그은 수직선은 서브트리 모두에게 영향을 미친다.
	int CurHeight = -1;
	int CurIdx = 0;

	vector<Node*> Nodes; // 인덱스는 NodeInfos와 동일하게 대응됨.
	for (int j = 0; j < NodeInfos.size(); j++)
		Nodes.push_back(new Node(NodeInfos[j][2])); // 원래 노드의 번호 기록하기

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
-> 이 벡터의 인덱스는 곧 노드가 가진 번호다.
*/