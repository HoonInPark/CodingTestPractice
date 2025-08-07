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
	int m_NodeNum;
	Node* m_pChild_L;
	Node* m_pChild_R;
};

vector<vector<int>> solution(vector<vector<int>> nodeinfo)
{
	for (int i = 0; i < nodeinfo.size(); i++)
		nodeinfo[i].push_back(i + 1); // nodeinfo[i][2]는 원래 해당 노드의 인덱스 값. 재할당 필요 없지롱 쿠쿠루삥뽕

	sort(nodeinfo.begin(), nodeinfo.end(), Comp);

	int CurHeight = -1;
	int CurIdx = 0;

	vector<int> NodeBuf_Former, NodeBuf_Later;

	while (CurIdx < nodeinfo.size())
	{
		NodeBuf_Former = NodeBuf_Later;
		NodeBuf_Later.clear();

		while(1)
		{
			NodeBuf_Later.push_back(CurIdx);

			CurHeight = nodeinfo[CurIdx][1];
			CurIdx++;

			if (CurIdx >= nodeinfo.size() || CurHeight > nodeinfo[CurIdx][1])
				break;
		}

		// do something
		for (auto FormerX : NodeBuf_Former)
		{

		}

		NodeBuf_Former.clear();
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