#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define MAX 100
int minmult(int n, int d[], int P[][MAX]);   //���� ��� �������� �ּ� ���� ���� ���ϴ� �Լ�
void order(int i, int j);     //����� ������ ���� ���� ������ִ� �Լ�
int minimum(int i, int j, int k, int M[][MAX], int d[]);   //�ּҰ��� ��ȯ���ִ� �Լ�

int P[MAX][MAX] = { 0, }; //���P�� ���� �� �ʱ�ȭ
int d[MAX] = { 0, }; //���� ��� ���������� ��ĵ��� ���� ���� ������ �����͸� ���� �迭�� ����


int main()
{
	int num = 0;
	int num2 = 0;
	int i;
	printf("*******���� ��� ���� �˰������� �����մϴ�********\n");
	printf("����� ������ �Է��� �ּ���: ");     //��� ����� �� �� ������ ������ ��
	scanf("%d", &num);
	printf("����� ��� ���� ���� ������ �Է��� �ּ���(%d ���� ���ڸ� �Է��ϼ���): ",num+1);
	for (i = 0; i <= num; i++)
	{
		scanf("%d", &d[i]);
	}
	num2 =minmult(num, d, P);                            //����� ������ ���� ���� ���ϱ� ���� ���M�� ���P�� ���ϴ� �Լ�
	printf("\n------------------------------------------------\n");
	printf("������� ������ ���� ������ ���� ���Դϴ� -> ");
	order(1, num);              //��������� ���� ���� ���� ����ϴ� �Լ�
	printf("\n�ּ� ������ ���� ������ �����ϴ�->%d\n", num2);
	printf("\n");
	return 0;
}

/*�ּҰ��� ��ȯ���ִ� �Լ��� ����(������� ���� �˰����� ���)*/
/*��ȯ�ϴ� ���� �ּҰ� �� ���� k ���� ��ȯ�Ѵ�.*/
int minimum(int i, int j, int k, int M[][MAX],int d[])
{
	/*���� ��ľȿ� ������ ������ �Ǿ� �������� ù��° �� ����� ��Ŀ� �־��ش�.*/
	if (k == i)
	{
		/*k�� �߽����� �� ����� ���Ͽ������� ������ ���� ���ϴ� ��Ͱ�����̴�.*/
		M[i][j] = M[i][k] + M[k + 1][j] + d[i - 1] * d[k] * d[j];
		/*�̶��� k���� ��ȯ*/
		return k;
	}

	if (k != i)
	{
		/*���� ���ο� k�� �߽����� �ɰ��� ������ ���� �Ͽ����� �� ���� �� ������ ������ ���� �����Ͽ� �ش�.*/
		if (M[i][j] > M[i][k] + M[k + 1][j] + d[i - 1] * d[k] * d[j])
		{
			/*k�� �߽����� �� ����� ���Ͽ������� ������ ���� ���ϴ� ��Ͱ�����̴�.*/
			M[i][j] = M[i][k] + M[k + 1][j] + d[i - 1] * d[k] * d[j];
			/*�̶�k ���� ��ȯ */
			return k;
		}
	}
	return P[i][j];
}

/*���� ��� �������� �ּ� ���� ���� ���ϴ� �Լ�*/
 /*�̶� ��ȯ���� ���1���� ���n���� ���ϴµ� �ּ� ���� ���̴�.*/
int minmult(int n, int d[], int P[][MAX])
{
	int i, j, k, diagonal,knum;
	/*����� �ּ� ������ ��� ���� �迭�� ����*/
	int M[MAX][MAX] = { 0, };
	/*�迭�� �ʱ�ȭ*/
	for (i = 0; i <= n; i++)
	{
		M[i][i] = 0;
	}

	/*���� ��� ���� ������ ���� ���� ���ϴ� �˰�����*/
	for (diagonal = 1; diagonal <= n - 1; diagonal++)
	{
		for (i = 1; i <= n - diagonal; i++)
		{
			j = i + diagonal;
			for (k = i; k <= j - 1; k++)
			{
				knum = minimum(i, j, k, M,d);   //�ּҰ��� ã����
				P[i][j] = knum;           //���P���ٰ� ���ŵǸ� k�� �׷��� ������ ���� �����Ͽ� �־���
			}
		}
	}

    /*���M�� ���*/
	printf("\n���� ��İ��� �˰����� ���M ���ϱ�\n");

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			printf("%5d", M[i][j]);
		}
		printf("\n");
	}
	printf("\n------------------------------------------------\n");
	printf("\n");
	/*���P�� ���*/
	printf("���� ��İ��� �˰����� ���P ���ϱ�\n");
	
	for (i = 1; i < n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			printf("%3d", P[i][j]);
		}
		printf("\n");
	}
	return M[1][n];
}

/*��������� ������ ���� ���� ������ִ� �Լ�*/
void order(int i, int j)
{
	int k;
	if (i == j)
	{
		printf("A%d", i);
	}
	else
	{
		k = P[i][j];
		printf("(");      //������ �κ��� ������ ��ȣ�� ���� �����ش�.
		order(i, k);
		order(k + 1, j);
		printf(")");     //���̻� ������ �κ��� ������ ��ȣ�� �ݴ´�.
	}
}


