//���� 10158�� ����
//������ x,y��ǥ�� �и��ؼ� ����.
//x��ǥ�� ���� ��� ���� ���̴� �ð�t���� 0~w���� �պ� �̵��Ѵ�.
#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;

int w, h, p, q, t, ansx, ansy;

int main()
{
	scanf("%d %d", &w, &h);
	scanf("%d %d", &p, &q);
	scanf("%d", &t);

	int x = (p + t) / w;
	//x=���̰� p��ġ���� t�ʵ��� �ʺ� w�� ��� ���������� ����� ��
	if ( x % 2 == 0 )
		ansx = (p + t) % w;
	//x�� ¦���̸� ������ x��ǥ�� 0 + (p+t)%w�̴�.
	else
		ansx = w - (p + t) % w;
	//x�� Ȧ���̸� ������ x��ǥ�� w - (p+t)%w�̴�.

	//y��ǥ�� ���� ������� �Ѵ�.
	int y = (q + t) / h;
	if ( y % 2 == 0 )
		ansy = (q + t) % h;
	else
		ansy = h - (q + t) % h;

	printf("%d %d", ansx, ansy);
	return 0;
}