#pragma once

/*
* https://school.programmers.co.kr/learn/courses/30/lessons/389479?language=cpp
*/

#include <vector>
#include <deque>
#include <queue>

using namespace std;

int solution(vector<int> players, int m, int k)
{
	for (int i = 0; i < players.size(); ++i)
		players[i] = players[i] / m;

	// 아래와 같은 형태로 단순화. 여기에 폭이 k인 막대를 잘라서 연속되도록 놓기.
	// 0 0 1 1 0 0 0 0 0 0 1 0 0 2 0 1 0 4 1 1 3 0 0 1
	// 서버 증설 횟수는 다음과 같다. 
	// 0 0 1 0 0 0 0 0 0 0 1 0 0 1 0 0 0 3 0 0 0 0 0 1

	deque<int> Servers;
	int CurTime = 0;
	queue<deque<int>::iterator> ItToErase;

	int Res = 0;
	
	while (CurTime < 24)
	{
		const int CurServerSize = Servers.size();
		if (CurServerSize < players[CurTime])
		{
			for (int i = 0; i < players[CurTime] - CurServerSize; ++i)
			{
				Servers.push_back(k);
				++Res;
			}
		}

		for (auto iter = Servers.begin(); iter != Servers.end(); iter++)
		{
			--(*iter);

			if (*iter < 1)
				ItToErase.push(iter);
		}

		while (!ItToErase.empty())
		{
			Servers.erase(ItToErase.front());
			ItToErase.pop();
		}

		++CurTime;
	}

	return Res;
}

/*
만약 어느 시간대의 이용자가 m명 미만이면 n은 0이므로 서버 증설은 필요 없다.
기존에 돌아가는 서버가 m명, 증설한 서버는 한개당 m명의 사용자를 감당하는 설정인 듯?
k는 그 증설한 서버의 수명.

아래 각 숫자를 해당 시간대(인덱스와 동일)에 접속을 시작한 사용자 수라고 생각하자.
 [0, 2, 3, 3, 1, 2, 0, 0, 0, 0, 4, 2, 0, 6, 0, 4, 2, 13, 3, 5, 10, 0, 1, 5]
 0시																		23시

좌우 폭이 k, 높이가 m인 막대를 최소한으로 두어서
각 인덱스에서 요구하는 높이만큼 쌓아올리는 거라고 문제를 바꿔 생각할 수 있음.
난 천재다.
*/
