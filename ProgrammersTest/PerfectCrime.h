#pragma once

/*
* https://school.programmers.co.kr/learn/courses/30/lessons/389480
*/

#include <vector>
#include <algorithm> 

using namespace std;

bool cmp(const vector<int>& _InFormer, const vector<int>& _InLater);

int solution(vector<vector<int>> info, int n, int m)
{
    sort(info.begin(), info.end(), cmp);

    for (int a = 0; a < info.size(); ++a)
    {

    }
    
    return -1;
}

bool cmp(const vector<int>& _InFormer, const vector<int>& _InLater)
{
    return _InFormer[0] < _InLater[0];
}


/*
* 1. ��� ���ľ� �Ѵ�.
* 2. ������ ������ �ȵȴ�. 
* 3. ������ ������ ���� �� ���� A�� n�� �̻�, B�� m�� �̻��� ��.
* 4. ��ȯ���� A�� �ּҷ� ����� ���� ��
* 
* A�� �ּҰ� �ǰ� ��ġ��, B�� �������� �ȵ�. 
* �� �������� �ص� ��������, -1 ��ȯ.
* 
* 1 2 2
* 2 3 1
* 
*/

