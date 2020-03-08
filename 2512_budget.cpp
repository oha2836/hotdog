//백준 2512번 예산
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
	//left=money[0]이라고 했다가 틀렸다.
	//0원씩 배정되어도 조건을 만족한다.

	while ( left <= right )
	{
		mid = (left + right) / 2;

		int sum = 0;
		for ( int i = 0; i < n; i++ )
			sum += min(money[i], mid);
		//money[i]가 mid보다 클 때 money[i]를 mid로 갱신 시킨 뒤에 더하려고 했던게 문제였다.

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