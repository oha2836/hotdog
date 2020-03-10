//���� 1300�� K��°��
#include<cstdio>
#include <algorithm>
using namespace std;

int n, k, left, right, mid, result;

int main(void)
{
	scanf("%d", &n);
	scanf("%d", &k);
	left = 1, right = k;
	//���Ϸ��� K��°���� K���� ���� ����� ���� �������� ���ؼ� ó�� right�� ���� ���� �� n*n�̶�� �ؼ� Ʋ�ȴ�.

	while ( left <= right )
	{
		mid = (left + right) / 2;
		int sum = 0;
		for ( int i = 1; i <= n; i++ )
		{
			sum += min(mid / i, n);
			//���ڴ� i*j�� �̷��������� ����/i�� �� ��� ���ں��� ���� i��° �࿡ �ִ� ���� ������ �� �� �ִ�.
			//�̶� mid/i�� n���� Ŭ ��찡 ���� �� �ֱ� ������ n�� mid/i�� ���� ���� ���Ѵ�.
			//�࿡ �ִ� ���� �ִ� ������ n�̹Ƿ�
		}
		if ( sum < k )
			left = mid + 1;
		//k���� sum�� ������ ���Ϸ��� ���ڸ� Ű���.
		else{
			result = mid;
			right = mid - 1;
			//�ߺ��Ǵ� ���� �־ sum�� k���� Ŭ ��쿡�� ���� �� �� �ִ�.
		}
	}
			printf("%d",result);
	
	return 0;
}