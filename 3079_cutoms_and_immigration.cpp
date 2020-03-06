//백준3079번 입국심사
//최소한의 시간을 구하기 위해 최대한의 범위를 잡은 다음, 그 범위 안에 m명의 사람이 심사가 가능하다면 시간을 줄여가고 가능하지 않다면 시간을 늘려가며 구한다.
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
		//최종 걸린 시간을 안다면 몇명이 지나갈 수 있는지 알 수 있다.
		
		if ( sum >= m )
		{
			right = mid - 1;
			result = min(result, mid);
			//지나간 사람이 m보다 크거나 같다면 저장하고 여기서 최소값이 정답
		}
		else
			left = mid + 1;
	}

	printf("%lld\n", result);
	return 0;
}

//왜 t배열을 long long int를 선언해줘야지 "맞았습니다!!"가 뜨는게 이해가 되지 않아서 int로 바꾸고 typecasting을 해주었더니 맞았다.
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
	//right = (long long int)t[n - 1] * m, result = (long long int)t[n - 1] * m; 이것도 맞다.
	//right = t[n - 1] * (long long int)m, result = t[n - 1] * (long long int)m; 이것도 맞다.

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