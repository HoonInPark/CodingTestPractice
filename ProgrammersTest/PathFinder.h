#pragma once

/*
* https://school.programmers.co.kr/learn/courses/30/lessons/42892
*/

#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>

using namespace std;

struct Node;

bool CmpOfVec(const vector<int>&, const vector<int>&);

void Preorder(vector<int>&, Node*);
void Postorder(vector<int>&, Node*);

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
	unordered_map<int, Node*> NodeMap;

	nodeinfo.push_back({ -1, 10001 });
	nodeinfo.push_back({ 10001, 10002 });

	for (int i = 0; i < nodeinfo.size(); i++)
		nodeinfo[i].push_back(i + 1); // nodeinfo[i][2]는 원래 해당 노드의 인덱스 값. 재할당 필요 없지롱 쿠쿠루삥뽕

	// 이렇게 하면 맨 위에 있는 노드 순으로, 왼쪽에 있는 노드 순으로 정렬된다. 
	sort(nodeinfo.begin(), nodeinfo.end(), CmpOfVec);
	const auto& NodeInfos = nodeinfo;

	// 앞에서부터 하나씩 꺼내면서 좌표평면을 분할하는 수직선을 만든다고 생각하자. 
	// 위에 있는 노드를 기준으로 그은 수직선은 서브트리 모두에게 영향을 미친다.
	int CurHeight = -1;
	int CurIdx = 3; // 맨 위에 세개(인덱스 0, 1, 2)는 연결할 필요가 없으니 패스

	vector<int> NodeIdxBuf; // 이거 원래 인덱스 아니고 정렬된 기준이니 주의 요망.

	auto CmpOfSet = [&NodeInfos](int _InFormer, int _InLater)
		{
			return NodeInfos[_InFormer][0] < NodeInfos[_InLater][0];
		};
	set<int, decltype(CmpOfSet)> NodeIdxRounded(CmpOfSet); // 정렬된 기준 인덱스를 내가 원하는 순서로 담은 set
	NodeIdxRounded.insert(0);
	NodeIdxRounded.insert(1);
	NodeIdxRounded.insert(2);

	NodeMap.insert(make_pair(2, new Node(NodeInfos[2][2]))); // 루트. key는 정렬된 기준 인덱스.

	while (CurIdx < NodeInfos.size())
	{
		for (const auto NodeIdx : NodeIdxBuf)
			NodeIdxRounded.insert(NodeIdx);

		NodeIdxBuf.clear();

		do
		{
			NodeIdxBuf.push_back(CurIdx);

			CurHeight = NodeInfos[CurIdx][1];
			CurIdx++;

		} while (CurIdx < NodeInfos.size() && CurHeight <= NodeInfos[CurIdx][1]);

		for (const auto NodeIdx : NodeIdxBuf)
		{
			const int X = NodeInfos[NodeIdx][0];
			for (auto iter = NodeIdxRounded.begin(); iter != prev(NodeIdxRounded.end()); iter++)
			{
				int FormerX = NodeInfos[*iter][0];
				int LaterX = NodeInfos[*next(iter)][0];
				if (FormerX < X && X < LaterX)
				{
					auto pNode = new Node(NodeInfos[NodeIdx][2]);

					if (NodeInfos[*iter][1] < NodeInfos[*next(iter)][1])
						NodeMap[*iter]->m_pChild_R = pNode;
					else
						NodeMap[*next(iter)]->m_pChild_L = pNode;

					NodeMap.insert(make_pair(NodeIdx, pNode));

					break;
				}
			}
		}
	}

	vector<vector<int>> RetVec(2);
	Node* pCurNode = NodeMap[2];

	// 전위
	Preorder(RetVec[0], pCurNode);

	pCurNode = NodeMap[2];

	// 후위
	Postorder(RetVec[1], pCurNode);

	return RetVec;
}

bool CmpOfVec(const vector<int>& _InFormer, const vector<int>& _InLater)
{
	if (_InFormer[1] == _InLater[1])
		return _InFormer[0] < _InLater[0];
	else
		return _InFormer[1] > _InLater[1];
}

void Preorder(vector<int>& _InRecord, Node* _pInNode)
{
	if (!_pInNode) return;

	_InRecord.push_back(_pInNode->m_NodeNum);

	Preorder(_InRecord, _pInNode->m_pChild_L);
	Preorder(_InRecord, _pInNode->m_pChild_R);
}

void Postorder(vector<int>& _InRecord, Node* _pInNode)
{
	if (!_pInNode) return;

	Postorder(_InRecord, _pInNode->m_pChild_L);
	Postorder(_InRecord, _pInNode->m_pChild_R);

	_InRecord.push_back(_pInNode->m_NodeNum);
}

/*
[[5,3],[11,5],[13,3],[3,5],[6,1],[1,3],[8,6],[7,2],[2,2]]
-> 이 벡터의 인덱스는 곧 노드가 가진 번호다.
*/
