//백준 2613번 숫자구슬
//최대값의 최소값을 찾는 문제-> 이분 탐색
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;

int n, m, left, right, mid, result, MAX;
int num[301];
vector<int> vec;
vector<int> vec2;

int main()
{
	scanf("%d %d", &n, &m);

	for ( int i = 0; i < n; i++ )
	{
		scanf("%d", &num[i]);
		MAX = max(MAX, num[i]);
	}

	left = 1, right = MAX * n, result = MAX * n;
	while ( left <= right )
	{
		vec.clear();
		mid = (left + right) / 2;

		int sum = num[0], cnt = 1;
		for ( int i = 1; i < n; i++ )
		{
			if ( (sum + num[i]) <= mid )
			{
				sum += num[i];
				cnt++;//sum에 num[i]를 넣는 것과 cnt++를 동시에 해주어야 한다.
			}
			else
			{
				vec.push_back(cnt);
				sum = num[i];
				cnt = 1;
			}
			if ( i == n - 1 )
				vec.push_back(cnt);
		}
		if ( vec.size() < m )
			right = mid - 1;
		else if ( vec.size() > m )
			left = mid + 1;
		else
		{
			result = min(max(mid, MAX), result);//mid가 MAX보다 작아지는 경우가 발생할 수 있으므로 max(mid, MAX)
			vec2 = vec;//vec가 초기화 되므로 vec2에다가 잠시 저장해 둔다.
			right = mid - 1;
		}
	}
	printf("%d\n", result);

	for ( int i = 0; i < m; i++ )
		printf("%d ", vec2[i]);
	return 0;
}
//이틀 걸린 문제