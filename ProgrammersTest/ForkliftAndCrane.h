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
	* 컨테이너는 네 종류로 나뉜다.
	* 1. 없는데 안쪽에 있는 컨테이너
	* 2. 없는데 바깥에 있는 컨테이너
	* 3. 있는데 안쪽에 있는 컨테이너
	* 4. 있는데 바깥에 있는 컨테이너
	* 
	* 없는 걸 기준으로 출발하여 바깥에 닿을 수 있는지 경로를 탐색하는 로직이 필요.
	* 닿을 수 있다면, 가는 경로마다 인접한 '있는' 컨테이너를 바깥면에 접하는 컨테이너로 취급.
	* 이 때, 이미 가 본 경로를 어떻게 중복하지 않고 BFS를 실행할지가 관건.
	*/

	unordered_map<int, int> Status;
	for (int i = 0; i < n * m; ++i)
		Status.insert(make_pair(i, 0)); // 없고 순회하지 않았으면 0, 없고 순회했으면 -1, 있으면 1, 있는데 외곽에 있다고 순회하면서 확인했으면 2

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
						case 0: // 없고 순회 아직 안했으면
						{
							Status[NxtNum] = -1;
							PathStack.push(NxtNum);

							break;
						}
						case 1: // 있고 순회 아직 안했으면
						{
							Status[NxtNum] = 2; // 순회했다고 표시하는데, 이는 곧 바깥에 있음을 의미.
							break;
						}
						default:
							break;
						}
					}
				}
			}
		};

	// PathFinder로 모든 순회하지 않은 블록으로부터 출발하여 순회를 시작하고, 그게 다 된 뒤에
	// 없는데 순회됐다고 표시한 것들을 초기화.
	// 그런 다음에야 새로 블록을 빼는 행위가 이루어진다. 

	for (int j = 0; j < Status.size(); ++j)
		if (0 == Status[j])
			PathFinder(j);

	// 끝나면 순회했다고 표시한 거 원복.


	return -1;
}
