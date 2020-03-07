//백준 2792번 보석 상자
//스스로 풀어서 맞은 문제!! 너무 기쁘다ㅠㅠㅎㅎ
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;

int n, m, left, right, mid, result;
int color[300001];

int main()
{
	scanf("%d %d", &n, &m);

	for ( int i = 0; i < m; i++ )
		scanf("%d", &color[i]);

	sort(color, color + m);

	left = 0, right = color[m - 1], result=color[m-1];
	while ( left <= right )
	{
		mid = (left + right) / 2;
		
		int sum = 0;
		for (int i = 0; i < m; i++ )
		{
			//color의 개수를 mid로 나누었을 때
			//나누어 떨어지면 몫을 sum에 더하고
			if ( color[i] % mid == 0 )
				sum += color[i] / mid;
			
			//나누어 떨어지지 않으면 몫+1을 sum에 더한다.
			else
				sum += ((color[i] / mid) + 1);
		}

		//sum이 n보다 작거나 같으면 더 작은 질투심의 값이 나올 수 있는지 확인
		if ( sum <= n )
		{
			result = min(result, mid);
			right = mid - 1;
		}

		else
			left = mid + 1;
	}

	printf("%d\n", result);
	return 0;
}