//���� 10800�� �÷���
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, sum, j;
int dp[200001], sub[200001];

struct cball
{
	int c, s, idx;
}ball[200001];

bool cmp(const cball &a, const cball &b)
{
	return a.s < b.s;
}

int main()
{
	scanf("%d", &n);
	
	
	for ( int i = 0; i < n; i++ )
	{
		scanf("%d %d", &ball[i].c, &ball[i].s);
		ball[i].idx = i+1;
	}

	sort(ball, ball+n, cmp);

	for ( int i = 0; i < n; i++ )
	{
		for ( ; ball[j].s < ball[i].s;j++ )
		{
			sum += ball[j].s;//�÷����� ũ���� ������
			sub[ball[j].c] += ball[j].s; //�ڰ��� ���� �÷����� ũ���� ������
		}
		dp[ball[i].idx] = sum - sub[ball[i].c];
	}

	for ( int i = 1; i <= n; i++ )
	{
		printf("%d\n", dp[i]);
	}
	return 0;
}
