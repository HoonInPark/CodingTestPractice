#pragma once

/*
* https://school.programmers.co.kr/learn/courses/30/lessons/42892
*/

#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>

using namespace std;

bool CmpOfVec(const vector<int>&, const vector<int>&);

struct Node
{
	Node(int _InNodeNum)
		: m_NodeNum(_InNodeNum)
	{
	}

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
		nodeinfo[i].push_back(i + 1); // nodeinfo[i][2]�� ���� �ش� ����� �ε��� ��. ���Ҵ� �ʿ� ������ �������

	// �̷��� �ϸ� �� ���� �ִ� ��� ������, ���ʿ� �ִ� ��� ������ ���ĵȴ�. 
	sort(nodeinfo.begin(), nodeinfo.end(), CmpOfVec);
	const auto& NodeInfos = nodeinfo;

	// �տ������� �ϳ��� �����鼭 ��ǥ����� �����ϴ� �������� ����ٰ� ��������. 
	// ���� �ִ� ��带 �������� ���� �������� ����Ʈ�� ��ο��� ������ ��ģ��.
	int CurHeight = -1;
	int CurIdx = 3; // �� ���� ����(�ε��� 0, 1, 2)�� ������ �ʿ䰡 ������ �н�

	vector<int> NodeIdxBuf; // �̰� ���� �ε��� �ƴϰ� ���ĵ� �����̴� ���� ���.

	auto CmpOfSet = [&NodeInfos](int _InFormer, int _InLater)
		{
			return NodeInfos[_InFormer][0] < NodeInfos[_InLater][0];
		};
	set<int, decltype(CmpOfSet)> NodeIdxRounded(CmpOfSet); // ���ĵ� ���� �ε����� ���� ���ϴ� ������ ���� set
	NodeIdxRounded.insert(0);
	NodeIdxRounded.insert(1);
	NodeIdxRounded.insert(2);

	NodeMap.insert(make_pair(2, new Node(NodeInfos[2][2]))); // ��Ʈ. key�� ���ĵ� ���� �ε���.

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
					break;
				}
			}
		}
	}

	return nodeinfo;
}

bool CmpOfVec(const vector<int>& _InFormer, const vector<int>& _InLater)
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
