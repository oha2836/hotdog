//���� 2206�� �� �μ��� �̵��ϱ�
#include<cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
#include <string>
using namespace std;

int n, m, ans=-1;
int arr[1001][1001];
int cnt[1001][1001][2];//[2]->�� �μ��� ����

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void bfs()
{
	queue< pair<pair<int, int>, int>> q; //y, x, �� �μ���
	q.push(make_pair(make_pair(0, 0), 1)); //������, �� �μ��� ����
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
			
			if ( movy < 0 || movx < 0 || movx >= m || movy >= n )//y,x �򰥸��� ����!!
				continue;

			//���� �ְ�, ���� ���� �� �μ̴ٸ�
			if (arr[movy][movx]==1 && block )
			{
				cnt[movy][movx][block - 1] = cnt[y][x][block] + 1;
				q.push(make_pair(make_pair(movy, movx), block-1));
			}

			//���� ���� �湮���� ���� ���̶��
			//�湮 check�� visit�迭�� ������� �ʰ� cnt 3���� �迭�� �̿��ߴٴ� ���� ���ο� ���
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