//백준 2667번 단지번호붙이기
//스스로 푼 문제!!
#include<cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
#include <string>
using namespace std;

int n, num;
int visit[26][26];
int arr[26][26];
int cnt[340];//처음에 cnt배열의 크기를 26으로 해서 틀렸었다.
//단지의 집 개수 : (n*n/2) +1개
//대각선은 이어진게 아니므로 크기가 n일때 집의 최대 개수

string str;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void bfs(int y, int x)
{
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	visit[y][x] = 1;

	while ( !q.empty() )
	{
		pair<int, int> now = q.front();
		q.pop();

		for ( int i = 0; i < 4; i++ )
		{
			int movy = now.first + dy[i];
			int movx = now.second + dx[i];
			
			if ( movy < 0 || movx < 0 || movx >= n || movy >= n )
				continue;

			if ( (!visit[movy][movx]) && arr[movy][movx]==1 )
			{
				q.push(make_pair(movy, movx));
				visit[movy][movx] = 1;
				cnt[num]++;
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for ( int i = 0; i < n; i++ )
	{
		cin >> str;//숫자들이 붙어있어서 문자열로 입력 받은뒤에 arr배열에 넣어주었다.
		for ( int j = 0; j < n; j++ )
		{
			if ( str[j] == '1' )
				arr[i][j] = 1;
		}
	}
	//하지만 더 간편한 방법 : scanf("%1d", &arr[i][j]);
	//붙어 있어도 한번에 한개씩 입력 받을 수 있다.
	//내 코드보다 좋은 코드가 있나 찾아보다가 알게 되었다. 역시 검색을 하면 많은 것을 알게 되는 거 같다.

	for(int i=0;i<n;i++ )
		for ( int j = 0; j < n; j++ )
		{
			if ( arr[i][j] == 1 && visit[i][j] == 0 )
			{
				bfs(i, j);
				num++;
			}
		}

	cout << num<<"\n";
	sort(cnt, cnt + num);
	for ( int i = 0; i < num; i++ )
		cout << cnt[i]+1 << "\n";
	return 0;
}