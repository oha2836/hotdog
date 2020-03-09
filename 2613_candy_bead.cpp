//���� 2613�� ���ڱ���
//�ִ밪�� �ּҰ��� ã�� ����-> �̺� Ž��
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
				cnt++;//sum�� num[i]�� �ִ� �Ͱ� cnt++�� ���ÿ� ���־�� �Ѵ�.
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
			result = min(max(mid, MAX), result);//mid�� MAX���� �۾����� ��찡 �߻��� �� �����Ƿ� max(mid, MAX)
			vec2 = vec;//vec�� �ʱ�ȭ �ǹǷ� vec2���ٰ� ��� ������ �д�.
			right = mid - 1;
		}
	}
	printf("%d\n", result);

	for ( int i = 0; i < m; i++ )
		printf("%d ", vec2[i]);
	return 0;
}
//��Ʋ �ɸ� ����