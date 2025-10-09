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

	unordered_map<int, bool> Status;
	for (int i = 0; i < n * m; ++i)
		Status.insert(make_pair(i, true));

	unordered_set<int> Outsiders; // 외곽 컨테이너들을 담는 자료형. 라운드마다 갱신됨.
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
						NxtNum < n * m	&&			// 만약 해당 정수가 유효한 인덱스이고
						false == Status[NxtNum])	// 그 자리가 비어 있으면
					{
						Path.push(NxtNum);
					}
				}
			}
		};

	return -1;
}
