//���� 15922�� �ƿ��� ������̾�!!
//line sweeping �˰����� �� ������ ���ؼ� ó�� ���ϰ� �Ǿ���.
//�̾����ų� ��ġ�� ���е��� �ƿ� �� �������� ��ģ��.
//�̾���� �� �ִ� �� �ִ��� �̾���̴ٰ� �� �̾���� �� ������ �̹� ������ ���̸� ����� ���Ѵ�.

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
		//�ø� �� ������ �ø��� �Ŵ�. ó���� �׳� e = arr[i].second;��� �ؼ� Ʋ��
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