#include <stdio.h>
#include <Windows.h>
#include <time.h>


int promising(int i, int weight, int total);		//������ ���� �Ǻ��ϱ� ���� �Լ�
int estimate_sum_of_subsets(int n);  //����Į�� �˰������ ����Ͽ� ������ ����

/*���� 13�� ���� ������ ���� ����*/
int w[7] = { 0,2,10,13,17,22,42 };		//������ ����
int W = 52;		// ���� �Ǵ� ����
int n = 6;		//������ ����
int total = 0; // ���� �������� �� ���Ը� �����ϴ� ����
int weight = 0;		// ���� i�� ��������� ���Ե� ������ ��



int main()
{
	int i;
	int numnodes;//�� ����� ������ ��
	int total_numnodes = 0;//�� ����� ������ ���� ����� ���ϱ� ���� �հ�

	/*ó�� total�� �ʱⰪ�� ��� ������ �հ� ����*/
	for (i = 1; i < 7; i++)
	{
		total += w[i];
	}

	printf("******************���� 17�� ���� ����Դϴ�(���� 13���� ���� ���)******************\n\n");
	for (i = 0; i < 20; i++)
	{

		numnodes = estimate_sum_of_subsets(n);//����Į�� ����ġ ���ϱ�
		printf("%d : ����� ���� -> %d\n",i+1, numnodes);
		weight = 0;		//���� �ٽ� �ʱ�ȭ
		total = 106;
		Sleep(500);
		total_numnodes += numnodes;

	}
	printf("��� ����ġ -> %d\n", (total_numnodes / 20));
	return 0;
}

/*������ ���� �Ǻ��ϱ� ���� �Լ�
���� ���̸� 1�� ��ȯ, ������ ���̸� 0�� ��ȯ�Ѵ�*/
int promising(int i, int weight, int total)
{
	/*������ �����ϸ� �������� ��ȯ������ �����ش�
	//������ ���Կ� ������ ������ ���� ä�� ������ �պ��� ũ��
	���� ���԰� ��� �����ϰų� Ȥ�� ���� ���Կ� ���� ������ ���� ä����� �ϴ� ���� ���� ������
	�������� �̿��Ѵ�.*/
	if ((weight + total >= W) && (weight == W || weight + w[i + 1] <= W))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


/*����Į�� ����ġ ���ϱ�*/
int estimate_sum_of_subsets(int n)
{
	int i, j; //i���°��� Ʈ�� ����, j:�����ڽ��� �������� ������ ���� ����
	int m; // ������ �ڽĸ����� ����
	int mprod; // �� ���ؿ��� ������� m0*m1....m(i-1)�� ǥ��
	int numnodes; // ����ģ ���°���Ʈ������ ������ ���� ����ġ
	int a[2] = { 0, }; //�ش� �Ѹ����� ��带 �������� ���� ���� ���� �����ϱ� ���� �迭�� ����

	
	i = 0;	//�Ѹ������� ���� ���� Ʈ��
	numnodes = 1;
	m = 1;
	mprod = 1;

	while (m != 0 && i != n && weight != W)
	{
	
		mprod = mprod * m;// �� ���ؿ��� ������� m0*m1....m(i-1)�� ǥ���� �������
		numnodes = numnodes + mprod * 2; //�˻��� ������ ����
		i++;					 //���°���Ʈ�������� �Ѵܰ� �÷���
		m = 0;

		if (promising(i, weight + w[i], total - w[i])) //�ش� �Ѹ����� ���Ը� ���� �� �ڽ��� �������� �˻�		
		{
			a[0] = 1; //���� �ڽ��� üũ
			m++;
		}

		if (promising(i, weight, total - w[i])) // �ش� �Ѹ����� ���Ը� ���� �ʾ����� �ڽ��� �������� �˻�
		{
			a[1] = 1; //������ �ڽ��� üũ
			m++;
		}

		if (m != 0) //�ڽĸ��� �����Ѵٸ� ��� ���� �������� ������ �۾�
		{
			if (a[0] == 1 && a[1] == 1)	//�����ϴ� ���� �������� �ʴ� ��츦 �� �����ϴ� ���
			{
				srand((unsigned int)time(NULL));
				j = rand() % 2 + 1; //������ ���� ����				
			}
			else if (a[0] == 1 && a[1] != 1) //�����ϴ� ��츸 �����ϴ� ���(���� ���)
			{
				j = 1;
			}
			else if (a[0] != 1 && a[1] == 1) //�������� �ʴ� ��츸 �����ϴ� ���(������ ���)
			{
				j = 2;
			}
		}

		if (j == 1) // �����Ͽ��� ���
		{
			weight = weight + w[i];
			total = total - w[i];
		}

		if (j == 2)  // �������� �ʾ��� ���
		{
			weight = weight;
			total = total - w[i];
		}

		a[0] = 0; //�迭�� ���� �ʱ�ȭ �۾�
		a[1] = 0;		
	}
	return numnodes;
}