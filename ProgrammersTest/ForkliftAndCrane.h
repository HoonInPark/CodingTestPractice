#pragma once

/*
* https://school.programmers.co.kr/learn/courses/30/lessons/388353
*/

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <functional>

using namespace std;

int solution(vector<string> storage, vector<string> requests)
{
	const int n = storage.size();
	const int m = storage[0].size();
	const vector<int> Dirs = { 1, -1, m, -m };

	unordered_map<int, int> Status;
	for (int i = 0; i < n * m; ++i)
		Status.insert(make_pair(i, 1)); // ���� ��ȸ���� �ʾ����� 0, ���� ��ȸ������ -1, ������ 1, �ִµ� �ܰ��� �ִٰ� ��ȸ�ϸ鼭 Ȯ�������� 2
	
	unordered_set<int> Outsiders;

	// �ʱ�ȭ
	for (int j = 0; j < m; ++j)
	{
		Status[j] = 2;
		Status[m * n - 1 - j] = 2;

		Outsiders.insert(j);
		Outsiders.insert(m * n - 1 - j);
	}

	for (int k = 1; k < n - 1; ++k)
	{
		Status[m * k] = 2;
		Status[m * k + m - 1] = 2;

		Outsiders.insert(m * k);
		Outsiders.insert(m * k + m - 1);
	}

	function<void(int)> PathFinder =
		[&](int _InInitNum)
		{
			stack<int> PathStack;
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

	for (const auto& ReqStr : requests)
	{
		if (1 == ReqStr.size())
		{
			// �ܰ��� �ִ� �� ����
			for (int l = 0; l < Status.size(); ++l)
				if (2 == Status[l] && ReqStr[0] == storage[l / m][l % m])
					Status[l] = 0;
		}
		else
		{
			// �ܰ� �ƴϾ �ϴ� ���� ���ĺ��̸� ����.
			for (int l = 0; l < Status.size(); ++l)
				if (ReqStr[0] == storage[l / m][l % m])
					Status[l] = 0;
		}

		// ���ο� �ܰ� �����̳� ��� ������Ʈ
		for (int l = 0; l < Status.size(); ++l)
			if (0 == Status[l] && Outsiders.end() != Outsiders.find(l))
				PathFinder(l);

		// '���ο� �ܰ� �����̳� ��� ������Ʈ' �ϸ鼭 -1�� �ٲ� �͵� 0���� rollback
		for (int l = 0; l < Status.size(); ++l)
			if (-1 == Status[l])
				Status[l] = 0;
	}

	int Answer = 0;
	for (int p = 0; p < Status.size(); ++p)
	{
		if (Status[p] > 0)
			++Answer;
	}

	return Answer;
}
