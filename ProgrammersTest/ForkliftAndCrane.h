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

	unordered_map<int, int> Status;
	for (int i = 0; i < n * m; ++i)
		Status.insert(make_pair(i, 0)); // ���� ��ȸ���� �ʾ����� 0, ���� ��ȸ������ -1, ������ 1, �ִµ� �ܰ��� �ִٰ� ��ȸ�ϸ鼭 Ȯ�������� 2

	stack<int> PathStack;

	function<void(int)> PathFinder =
		[&](int _InInitNum)
		{
			PathStack.push(_InInitNum);

			while (false == PathStack.empty())
			{
				int TopNum = PathStack.top();
				PathStack.pop();

				for (const auto Dir : Dirs)
				{
					int NxtNum = TopNum + Dir;

					if (NxtNum >= 0 &&
						NxtNum < n * m)
					{
						switch (Status[NxtNum])
						{
						case 0: // ���� ��ȸ ���� ��������
						{
							Status[NxtNum] = -1;
							PathStack.push(NxtNum);

							break;
						}
						case 1: // �ְ� ��ȸ ���� ��������
						{
							Status[NxtNum] = 2; // ��ȸ�ߴٰ� ǥ���ϴµ�, �̴� �� �ٱ��� ������ �ǹ�.
							break;
						}
						default:
							break;
						}
					}
				}
			}
		};

	// PathFinder�� ��� ��ȸ���� ���� ������κ��� ����Ͽ� ��ȸ�� �����ϰ�, �װ� �� �� �ڿ�
	// ���µ� ��ȸ�ƴٰ� ǥ���� �͵��� �ʱ�ȭ.
	// �׷� �������� ���� ����� ���� ������ �̷������. 

	for (int j = 0; j < Status.size(); ++j)
		if (0 == Status[j])
			PathFinder(j);

	// ������ ��ȸ�ߴٰ� ǥ���� �� ����.


	return -1;
}
