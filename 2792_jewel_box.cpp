//���� 2792�� ���� ����
//������ Ǯ� ���� ����!! �ʹ� ��ڴ٤ФФ���
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
			//color�� ������ mid�� �������� ��
			//������ �������� ���� sum�� ���ϰ�
			if ( color[i] % mid == 0 )
				sum += color[i] / mid;
			
			//������ �������� ������ ��+1�� sum�� ���Ѵ�.
			else
				sum += ((color[i] / mid) + 1);
		}

		//sum�� n���� �۰ų� ������ �� ���� �������� ���� ���� �� �ִ��� Ȯ��
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