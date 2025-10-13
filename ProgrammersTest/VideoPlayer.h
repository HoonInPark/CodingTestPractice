#pragma once

#include <string>
#include <vector>

using namespace std;

int ParseTo10(string);

string solution(
	string video_len,
	string pos,
	string op_start,
	string op_end,
	vector<string> commands)
{
	const int VideoLen10 = ParseTo10(video_len);
	const int OpStart10 = ParseTo10(op_start);
	const int OpEnd10 = ParseTo10(op_end);

	int Pos10 = ParseTo10(pos);

	if (OpStart10 <= Pos10 &&
		OpEnd10 >= Pos10)
		Pos10 = OpEnd10;

	for (const auto& Command : commands)
	{
		if ('n' == Command[0])
		{
			if (Pos10 + 10 > VideoLen10)
				Pos10 = VideoLen10;
			else
				Pos10 += 10;
		}
		else
		{
			if (Pos10 - 10 < 0)
				Pos10 = 0;
			else
				Pos10 -= 10;
		}

		if (OpStart10 <= Pos10 &&
			OpEnd10 >= Pos10)
			Pos10 = OpEnd10;
	}

	string answer(5, 0);
	answer[0] = 48 + (Pos10 / 60) / 10;
	answer[1] = 48 + (Pos10 / 60) % 10;
	answer[2] = ':';
	answer[3] = 48 + (Pos10 % 60) / 10;
	answer[4] = 48 + (Pos10 % 60) % 10;

	return answer;
}

int ParseTo10(string _InTime)
{
	return 60 * ((_InTime[0] - 48) * 10 + (_InTime[1] - 48)) + ((_InTime[3] - 48) * 10 + (_InTime[4] - 48));
}
