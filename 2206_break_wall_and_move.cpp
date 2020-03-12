//백준 2206번 벽 부수고 이동하기
#include<cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
#include <string>
using namespace std;

int n, m, ans=-1;
int arr[1001][1001];
int cnt[1001][1001][2];//[2]->벽 부수기 여부

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void bfs()
{
	queue< pair<pair<int, int>, int>> q; //y, x, 벽 부수기
	q.push(make_pair(make_pair(0, 0), 1)); //시작점, 벽 부수기 가능
	cnt[0][0][1] = 1;

	while ( !q.empty() )
	{
		pair<pair<int, int>, int> now = q.front();
		int y = now.first.first;
		int x = now.first.second;
		int block = now.second;

		q.pop();

		if ( y == n - 1 && x == m - 1 )
		{
			ans = cnt[y][x][block];
			return;
		}

		for ( int i = 0; i < 4; i++ )
		{
			int movy = y + dy[i];
			int movx = x + dx[i];
			
			if ( movy < 0 || movx < 0 || movx >= m || movy >= n )//y,x 헷갈리지 말기!!
				continue;

			//벽이 있고, 벽을 아직 안 부셨다면
			if (arr[movy][movx]==1 && block )
			{
				cnt[movy][movx][block - 1] = cnt[y][x][block] + 1;
				q.push(make_pair(make_pair(movy, movx), block-1));
			}

			//벽이 없고 방문하지 않은 곳이라면
			//방문 check를 visit배열을 사용하지 않고 cnt 3차원 배열을 이용했다는 것이 새로운 방법
			else if ( arr[movy][movx] == 0 && cnt[movy][movx][block] == 0 )
			{
				cnt[movy][movx][block] = cnt[y][x][block] + 1;
				q.push(make_pair(make_pair(movy, movx), block));
			}
		}
	}
}

int main(void)
{
	scanf("%d %d", &n, &m);
	for ( int i = 0; i < n; i++ )
	{
		for ( int j = 0; j < m; j++ )
			scanf("%1d", &arr[i][j]);
	}

	bfs();

	printf("%d\n", ans);
	return 0;
}