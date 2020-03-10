//백준 7562번 나이트의 이동
//BFS
#include<cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#define INF 987654321
using namespace std;

int t, l, x, y, nextx, nexty;
int visit[301][301];
int cnt[301][301];

int dx[8] = { -2, -1, 1, 2, -2, -1, 1, 2 };
int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };


int bfs(int a, int b)
{
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	visit[b][a] = 1;
	cnt[b][a] = 0;

	while ( !q.empty() )
	{
		pair<int, int> now = q.front();
		q.pop();

		if ( now.second == nextx && now.first == nexty )
		{
			return cnt[nexty][nextx];
		}
		for ( int i = 0; i < 8; i++ )
		{
			int movx = now.second + dx[i];
			int movy = now.first + dy[i];

			if ( movx < 0 || movy < 0 || movx >= l || movy >= l )
				continue;
			if ( !visit[movy][movx] )
			{
				q.push(make_pair(movy, movx));
				visit[movy][movx] = 1;
				cnt[movy][movx] = min(cnt[movy][movx], cnt[now.first][now.second] + 1);
				//다음 위치에 저장되어 있는 움직인 횟수와 현재 지점까지 움직인 횟수+1 중에서 최소값
			}
		}
	}
}

int main(void)
{
	scanf("%d", &t);
	while ( t-- )
	{
		memset(visit, 0, sizeof(visit));
		for ( int i = 0; i < 301; i++ )
			for ( int j = 0; j < 301; j++ )
				cnt[i][j] = INF;
		scanf("%d", &l);
		scanf("%d %d", &x, &y);
		scanf("%d %d", &nextx, &nexty);
		printf("%d\n", bfs(x, y));
	}

	return 0;
}