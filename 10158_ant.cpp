//백준 10158번 개미
//개미의 x,y좌표를 분리해서 보자.
//x좌표만 따로 떼어서 보면 개미는 시간t동안 0~w까지 왕복 이동한다.
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
	//x=개미가 p위치에서 t초동안 너비 w를 몇번 움직였는지 계산한 값
	if ( x % 2 == 0 )
		ansx = (p + t) % w;
	//x가 짝수이면 개미의 x좌표는 0 + (p+t)%w이다.
	else
		ansx = w - (p + t) % w;
	//x가 홀수이면 개미의 x좌표는 w - (p+t)%w이다.

	//y좌표도 같은 방법으로 한다.
	int y = (q + t) / h;
	if ( y % 2 == 0 )
		ansy = (q + t) % h;
	else
		ansy = h - (q + t) % h;

	printf("%d %d", ansx, ansy);
	return 0;
}