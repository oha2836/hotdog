//백준 15922번 아우으 우아으이야!!
//line sweeping 알고리즘을 이 문제를 통해서 처음 접하게 되었다.
//이어지거나 겹치는 선분들은 아예 한 구간으로 합친다.
//이어붙일 수 있는 한 최대한 이어붙이다가 더 이어붙일 수 없으면 이번 구간의 길이를 결과에 더한다.

#include <stdio.h>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;

int n, ans;
P arr[100001];

int main()
{
	scanf("%d", &n);

	for ( int i = 0; i < n; i++ )
	{
		int x, y;
		scanf("%d %d", &x, &y);
		arr[i] = P(x, y);
	}

	int s = arr[0].first, e = arr[0].second;
	for ( int i = 1; i < n; i++ )
	{
		if ( arr[i].first < e )
			e = max(e, arr[i].second);
		//늘릴 수 있으면 늘리는 거다. 처음에 그냥 e = arr[i].second;라고 해서 틀림
		else
		{
			ans += (e - s);
			s = arr[i].first, e = arr[i].second;
		}
	}
	ans += e - s;
	printf("%d\n",ans);
	return 0;
}