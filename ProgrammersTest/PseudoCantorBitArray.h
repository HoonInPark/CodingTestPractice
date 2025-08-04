#pragma once

#include <vector>

using namespace std;

int solution(int n, long long l, long long r)
{
	int answer = 0;

	l--;
	r--;

	vector<long long> buf;
	buf.reserve(n);

	long long hang_over;
	
	while (l <= r)
	{
		long long l_tmp = l;
		for (int i = n; 0 < i; --i)
		{
			hang_over = l_tmp % 5;
			l_tmp = (l_tmp - hang_over) / 5;

			buf.push_back(hang_over);
		}

		bool bHasZero = false;
		for (auto it = buf.rbegin(); it != buf.rend(); ++it)
		{
			if (2 == *it)
			{
				bHasZero = true;
				break;
			}
		}

		if (!bHasZero)
			answer++;

		buf.clear();
		l++;
	}

	return answer;
}
