#pragma once

/*
* https://programmers.co.kr/skill_checks/603242?challenge_id=16769
*/

#include <vector>
#include <unordered_map>

using namespace std;

struct Node
{
	Node(int _InNodeNum)
		: m_NodeNum(_InNodeNum)
	{
	}

	int m_NodeNum = -1;
	bool m_bIsVisited = false;
	
	vector<Node*> m_PrevNodes;
	vector<Node*> m_NextNodes;
};

int solution(int n, vector<vector<int>> roads)
{
	int RetNum = 0;

	unordered_map<int, Node*> MapOfNodes;

	for (int i = 1; i <= n; ++i)
		MapOfNodes[i] = new Node(i);
	for (const auto& road : roads)
	{
		MapOfNodes[road[1]]->m_PrevNodes.push_back(MapOfNodes[road[0]]);
		MapOfNodes[road[0]]->m_NextNodes.push_back(MapOfNodes[road[1]]);
	}

	auto pNode = MapOfNodes[1];

	// do something
	/*
	* �ϴ� �����ϰ� �ִ� �����...
	* �Ϲ�ȭ�� ��Ģ�� ã�� �� �Ұ����ϴ�. �ٸ� ����� Ǯ�̸� ���� ������ ��� ����� ���� ����Ѵ�. 
	* ����, pNode�κ��� �����Ͽ��� true == m_NextNodes.empty()�� ������ ���� ��带 ã�� 
	* m_bIsVisited�� true�� �ٲٸ鼭 ��ȸ�ϰ�, 
	* �� �� ��ȸ�� ������ MapOfNodes �� ���� ��ȸ���� ���� ��带 ã�´�. ... (1)
	* �ٵ� ã�� �� ��尡 m_PrevNodes �� ���� ��ȸ���� ���� ���(��, false == m_NextNodes.empty())�� ������ 
	* ã�� �ö󰣴�.
	* �̰� �ݺ��ϸ� ��ȸ���� ���� ��� �� ù��°���� �ٽ� �� ������ �ݺ��Ѵ�. 
	* �̷��� ��ȸ ����� ���̽� �ϳ��� ������ ����. 
	* ���� ��ȸ�ϸ鼭 (1)���� '���� �̵�' Ƚ���� ���� �Ѵ�. 
	* ��� ����� ���� ����ϸ� �� Ƚ���� ���� ���� �� �����ϸ� �Ǵ� ����.
	*/

	for (const auto NodePair : MapOfNodes)
		delete NodePair.second;

	return RetNum;
}

/*
#include "HyundaiMobisSim.h"

int main()
{
	vector<vector<int>> test;
	test.push_back({ 1, 2 });
	test.push_back({ 2, 3 });
	test.push_back({ 3, 4 });
	test.push_back({ 4, 5 });
	test.push_back({ 3, 6 });
	test.push_back({ 1, 7 });
	test.push_back({ 7, 4 });

	solution(7, test); // ������ 1
}
*/