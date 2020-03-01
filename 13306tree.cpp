//���� 13306�� Ʈ��
//Union Find�� �̿��ϴ� ������� ���� �˾����� �ð��ʰ� �߻� -> �߻��� ��ȯ �ʿ�
//������ ������ �������� ���鼭 �����Ǵ� ���� Union�� �����־ ���Ǹ� ������ Ȯ���Ѵ�.
//�׸��� �̸� �������� ����ϸ� ���� ã�� �� �ִ�.
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