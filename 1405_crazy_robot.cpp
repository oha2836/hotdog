//백준 1405번 미친 로봇
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;

int n;
double ans;
bool visit[30][30];

//east, west, north, south 이렇게 단순히 하나씩 받으려고 했다.
//편리하게 배열을 이용해서 for문을 통해 입력 받자.
double percent[4];

//동서남북->좌표로 구현을 생각하지 못했다. 좌표 구현에 익숙해질 필요가 있을 거 같다. 
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void dfs(int x, int y, double cnt)
{
	if ( n == 0 )
	{
		ans += cnt;
		return;
	}

	visit[y][x] = true;
	for ( int i = 0; i < 4; i++ )
	{
		int nextx = x + dx[i];
		int nexty = y + dy[i];

		if ( !visit[nexty][nextx] )
		{
			n--;
			dfs(nextx, nexty, cnt*percent[i]);
			n++;
			visit[nexty][nextx] = false;
		}
	}
}

int main()
{
	scanf("%d", &n);

	for ( int i = 0; i < 4; i++ )
	{
		scanf("%lf", &percent[i]);
		percent[i] *= 0.01;//자연수 입력을 소수로 만들기
	}

	dfs(15, 15, 1.0);

	printf("%.10lf\n", ans);//소수점 10의 자리까지 출력
	return 0;
}