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
	* 일단 생각하고 있는 방법은...
	* 일반화된 규칙을 찾는 건 불가능하다. 다른 사람의 풀이를 봐도 가능한 모든 경우의 수를 고려한다. 
	* 따라서, pNode로부터 시작하여서 true == m_NextNodes.empty()일 때까지 다음 노드를 찾아 
	* m_bIsVisited를 true로 바꾸면서 순회하고, 
	* 한 줄 순회가 끝나면 MapOfNodes 중 아직 순회하지 않은 노드를 찾는다. ... (1)
	* 근데 찾은 그 노드가 m_PrevNodes 중 아직 순회하지 않은 노드(즉, false == m_NextNodes.empty())가 있으면 
	* 찾아 올라간다.
	* 이걸 반복하며 순회하지 않은 노드 중 첫번째부터 다시 위 과정을 반복한다. 
	* 이렇게 순회 방법의 케이스 하나가 나오는 것임. 
	* 물론 순회하면서 (1)에서 '빠른 이동' 횟수를 세야 한다. 
	* 모든 경우의 수를 고려하며 이 횟수가 가장 적은 걸 선택하면 되는 문제.
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

	solution(7, test); // 정답은 1
}
*/