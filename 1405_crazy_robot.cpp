//���� 1405�� ��ģ �κ�
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;

int n;
double ans;
bool visit[30][30];

//east, west, north, south �̷��� �ܼ��� �ϳ��� �������� �ߴ�.
//���ϰ� �迭�� �̿��ؼ� for���� ���� �Է� ����.
double percent[4];

//��������->��ǥ�� ������ �������� ���ߴ�. ��ǥ ������ �ͼ����� �ʿ䰡 ���� �� ����. 
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
		percent[i] *= 0.01;//�ڿ��� �Է��� �Ҽ��� �����
	}

	dfs(15, 15, 1.0);

	printf("%.10lf\n", ans);//�Ҽ��� 10�� �ڸ����� ���
	return 0;
}