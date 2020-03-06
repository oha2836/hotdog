//����3079�� �Ա��ɻ�
//�ּ����� �ð��� ���ϱ� ���� �ִ����� ������ ���� ����, �� ���� �ȿ� m���� ����� �ɻ簡 �����ϴٸ� �ð��� �ٿ����� �������� �ʴٸ� �ð��� �÷����� ���Ѵ�.
#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;

int n, m;
long long int left, right, mid, result;
long long int t[100001];

int main()
{
	scanf("%d %d", &n, &m);
	for ( int i = 0; i < n; i++ )
		scanf("%lld", &t[i]);

	sort(t, t + n);

	left = 1, right = t[n - 1] * m, result = t[n - 1] * m;
	while ( left <= right )
	{
		mid = (left + right) / 2;
		long long int sum = 0;
		for ( int i = 0; i < n; i++ )
			sum += (mid / t[i]);
		//���� �ɸ� �ð��� �ȴٸ� ����� ������ �� �ִ��� �� �� �ִ�.
		
		if ( sum >= m )
		{
			right = mid - 1;
			result = min(result, mid);
			//������ ����� m���� ũ�ų� ���ٸ� �����ϰ� ���⼭ �ּҰ��� ����
		}
		else
			left = mid + 1;
	}

	printf("%lld\n", result);
	return 0;
}

//�� t�迭�� long long int�� ����������� "�¾ҽ��ϴ�!!"�� �ߴ°� ���ذ� ���� �ʾƼ� int�� �ٲٰ� typecasting�� ���־����� �¾Ҵ�.
#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;

int n, m;
long long int left, right, mid, result;
int t[100001];

int main()
{
	scanf("%d %d", &n, &m);
	for ( int i = 0; i < n; i++ )
		scanf("%d", &t[i]);

	sort(t, t + n);

	left = 1, right = (long long int)t[n - 1] * (long long int)m, result = (long long int)t[n - 1] * (long long int)m;
	//right = (long long int)t[n - 1] * m, result = (long long int)t[n - 1] * m; �̰͵� �´�.
	//right = t[n - 1] * (long long int)m, result = t[n - 1] * (long long int)m; �̰͵� �´�.

	while ( left <= right )
	{
		mid = (left + right) / 2;
		long long int sum = 0;
		for ( int i = 0; i < n; i++ )
			sum += (mid / t[i]);
		if ( sum >= m )
		{
			right = mid - 1;
			result = min(result, mid);
		}
		else
			left = mid + 1;
	}

	printf("%lld\n", result);
	return 0;
}