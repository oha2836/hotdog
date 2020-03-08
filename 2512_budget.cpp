//���� 2512�� ����
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;

int n, m, left, right, mid, result;
int money[10001];

int main()
{
	scanf("%d", &n);

	for ( int i = 0; i < n; i++ )
		scanf("%d", &money[i]);
	
	scanf("%d", &m);

	sort(money, money + n);

	left = 0, right = money[n - 1];
	//left=money[0]�̶�� �ߴٰ� Ʋ�ȴ�.
	//0���� �����Ǿ ������ �����Ѵ�.

	while ( left <= right )
	{
		mid = (left + right) / 2;

		int sum = 0;
		for ( int i = 0; i < n; i++ )
			sum += min(money[i], mid);
		//money[i]�� mid���� Ŭ �� money[i]�� mid�� ���� ��Ų �ڿ� ���Ϸ��� �ߴ��� ��������.

		if ( sum <= m )
		{
			result = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}

	printf("%d\n", result);
	return 0;
}