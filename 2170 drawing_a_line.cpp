//���� 2170�� ���߱�
//���� 15922�� �ƿ��� ������̾�!! �� ���� �Ȱ��� ����
//���� 15922�� �ƿ��� ������̾�!! �ڵ带 �׳� �������� �� �ð��ʰ��� �߻��ߴ�.
//�迭�� ���� �� �����Ű� L[i].first�� �ǵ��� �ϰ� sort�� ���־����� �¾Ҵ�.
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