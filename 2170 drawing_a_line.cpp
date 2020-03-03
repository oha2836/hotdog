//백준 2170번 선긋기
//백준 15922번 아우으 우아으이야!! 와 거의 똑같은 문제
//백준 15922번 아우으 우아으이야!! 코드를 그냥 제출했을 때 시간초과가 발생했다.
//배열에 넣을 때 작은거가 L[i].first가 되도록 하고 sort를 해주었더니 맞았다.
#include <stdio.h>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;
int n, ans;
P L[1000001];

bool cmp(const P &a, const P &b)
{
	if ( a.first == b.first )
		return a.second < b.second;
	else
		return a.first < b.first;
}

int main()
{
	scanf("%d", &n);
	for ( int i = 0; i < n; i++ )
	{
		int a, b;
		scanf("%d %d", &a, &b);
		//
		if ( a < b )
			L[i] = P(a, b);
		else
			L[i] = P(b, a);
	}

	sort(L, L + n, cmp);//

	int s = L[0].first, e = L[0].second;

	for ( int i = 1; i < n; i++ )
	{
		if ( e < L[i].first )
		{
			ans += e - s;
			s = L[i].first, e = L[i].second;
		}
		else
			e = max(e, L[i].second);
	}
	ans += e - s;
	printf("%d\n", ans);

	return 0;
}