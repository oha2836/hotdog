//백준 13306번 트리
//Union Find를 이용하는 문제라는 것을 알았지만 시간초과 발생 -> 발상의 전환 필요
//질의의 내용을 역순으로 돌면서 삭제되는 때에 Union을 시켜주어서 질의를 역으로 확인한다.
//그리고 이를 역순으로 출력하면 답을 찾을 수 있다.
#include <stdio.h>

int n, q, xnum, ansnum = 0;
int root[200001], arr[200001], bnum[400002], cnum[400002], ans[200001];

int find(int x)
{
	if ( root[x] == x )
		return x;
	else
		return root[x] = find(root[x]);
}

int main()
{
	scanf("%d %d", &n, &q);

	root[1] = 1, arr[1] = 1;
	for ( int i = 2; i <= n; i++ )
	{
		scanf("%d", &arr[i]);
		root[i] = i;
	}

	int num = n + q - 1;
	for ( int i = 1; i <= num; i++ )
	{
		scanf("%d", &xnum);
		if ( xnum == 0 )
			scanf("%d", &bnum[i]);

		else
			scanf("%d %d", &bnum[i], &cnum[i]);
	}

	for ( int i = num; i >= 1; i-- )
	{
		if ( cnum[i] )
		{
			if ( find(bnum[i]) == find(cnum[i]) )
				ans[ansnum] = 1;
			else
				ans[ansnum] = 0;
			ansnum++;
		}
		else
			root[bnum[i]] = arr[bnum[i]];
	}

	for ( int i = ansnum - 1; i >= 0; i-- )
	{
		if ( ans[i] )
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}