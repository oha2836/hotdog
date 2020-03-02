//백준 1931번 회의실배정
//그리디 알고리즘 문제
//그리디 알고리즘 해결부분을 이중 for문으로 했다가 TLE(Time Limit Exceeded:시간 제한을 초과하였다.)가 발생했다.

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, ans;

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
	if ( a.first == b.first )
		return a.second < b.second;
	// 끝나는 시간이 같을 시 시작 시작을 기준으로 정렬해줘야된다는 부분을 생각하지 못했다.
	else
		return a.first < b.first;
}

int main()
{
	scanf("%d", &n);
	vector<pair<int, int>>vec(n);
	int a, b;
	for ( int i = 0; i < n; i++ )
	{
		scanf("%d %d", &vec[i].second, &vec[i].first);
	}
	
	sort(vec.begin(), vec.end(), cmp);
	
	int now = 0;
	
	for ( int i = 0; i < n; i++ )
	{
		if ( now <= vec[i].second )
		{
			ans++;
			now = vec[i].first;//
		}
	}

	printf("%d\n", ans);
	return 0;
}

//MLE : Memory Limit Exceeded
//WA : Wrong Answer
//AC : Accepted code
