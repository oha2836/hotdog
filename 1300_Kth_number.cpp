//백준 1300번 K번째수
#include<cstdio>
#include <algorithm>
using namespace std;

int n, k, left, right, mid, result;

int main(void)
{
	scanf("%d", &n);
	scanf("%d", &k);
	left = 1, right = k;
	//구하려는 K번째수가 K보다 작은 수라는 것을 인지하지 못해서 처음 right의 값을 정할 때 n*n이라고 해서 틀렸다.

	while ( left <= right )
	{
		mid = (left + right) / 2;
		int sum = 0;
		for ( int i = 1; i <= n; i++ )
		{
			sum += min(mid / i, n);
			//숫자는 i*j로 이루어졌으며로 숫자/i를 할 경우 숫자보다 작은 i번째 행에 있는 수의 개수를 알 수 있다.
			//이때 mid/i가 n보다 클 경우가 나올 수 있기 때문에 n과 mid/i중 작은 값을 더한다.
			//행에 있는 수의 최대 개수는 n이므로
		}
		if ( sum < k )
			left = mid + 1;
		//k보다 sum이 작으면 구하려는 숫자를 키운다.
		else{
			result = mid;
			right = mid - 1;
			//중복되는 수가 있어서 sum이 k보다 클 경우에도 답이 될 수 있다.
		}
	}
			printf("%d",result);
	
	return 0;
}