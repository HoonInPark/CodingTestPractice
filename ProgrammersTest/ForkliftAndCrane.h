#pragma once

/*
* https://school.programmers.co.kr/learn/courses/30/lessons/388353
*/

#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <functional>

using namespace std;

int solution(vector<string> storage, vector<string> requests)
{
	const int n = storage.size();
	const int m = storage[0].size();
	const vector<int> Dirs = { 1, -1, m, -m };

	/*
	* �����̳ʴ� �� ������ ������.
	* 1. ���µ� ���ʿ� �ִ� �����̳�
	* 2. ���µ� �ٱ��� �ִ� �����̳�
	* 3. �ִµ� ���ʿ� �ִ� �����̳�
	* 4. �ִµ� �ٱ��� �ִ� �����̳�
	* 
	* ���� �� �������� ����Ͽ� �ٱ��� ���� �� �ִ��� ��θ� Ž���ϴ� ������ �ʿ�.
	* ���� �� �ִٸ�, ���� ��θ��� ������ '�ִ�' �����̳ʸ� �ٱ��鿡 ���ϴ� �����̳ʷ� ���.
	* �� ��, �̹� �� �� ��θ� ��� �ߺ����� �ʰ� BFS�� ���������� ����.
	*/

	unordered_map<int, bool> Status;
	for (int i = 0; i < n * m; ++i)
		Status.insert(make_pair(i, true));

	unordered_set<int> Outsiders; // �ܰ� �����̳ʵ��� ��� �ڷ���. ���帶�� ���ŵ�.
	stack<int> Path;

	function<void(int)> PathFinder =
		[&](int _InInitNum)
		{
			Path.push(_InInitNum);

			while (false == Path.empty())
			{
				int TopNum = Path.top();
				Path.pop();

				for (const auto Dir : Dirs)
				{
					int NxtNum = TopNum + Dir;

					if (NxtNum >= 0		&&
						NxtNum < n * m	&&			// ���� �ش� ������ ��ȿ�� �ε����̰�
						false == Status[NxtNum])	// �� �ڸ��� ��� ������
					{
						Path.push(NxtNum);
					}
				}
			}
		};

	return -1;
}
