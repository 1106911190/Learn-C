#include<stdio.h>
#include<conio.h>
int main (void)
{	
	int				x;
	int				y;
	double	  		m;
	int				a;

	printf("********************************************\n\n");
	printf("           ASIORS��ѧ������                   \n");
	printf("                        ����ǿ��ƿ���2014��  \n");
	printf("\n********************************************\n");

	// printf("\n");

	// printf("�밴ENTER�Լ�������\n");

	// getchar();

	printf("============================================\n");
	printf("     1   �ӷ�               2    ����         \n");
	printf("     3   �˷�               4    ����         \n");
	printf("     5   ȡ��               6    ȡ��         \n");
	printf("               7  ��������                    \n");
	printf("============================================\n");


	printf("��ܰ��ʾ��ֻ��������7ʱ���ܽ�������:)\n");

	printf("�밴ENTER�Լ�������\n");

	getchar();


	for(;a!=7;)
	{
	printf("\n��ѡ���������:\n");
	scanf("%d",&a);

	if(a<1||a>7)
		printf("���ѡ��������������һ��:\n");
	else
	{

	printf("��ѡ����� : %d\n",a);
	switch(a)
	{
	case 1:
		printf("�ӷ�\n");
		break;
	case 2:
		printf("����\n");
		break;
	case 3:
		printf("�˷�\n");
		break;
	case 4:
		printf("����\n");
		break;
	case 5:
		printf("ȡ��\n");
		break;
	case 6:
		printf("ȡ��\n");
		break;
	case 7:
		printf("����\n");
		printf("��л����ʹ��\n");
		break;

	}

	if(a!=7)
	{
	printf("����������ֵ��\n");
	scanf("%d%d",&x,&y);


	printf("���Ϊ��\n");
	switch(a)
	{
	case 1:
		printf("%d+%d=%d\n",x,y,x+y);
		break;
	case 2:
		printf("%d-%d=%d\n",x,y,x-y);
		break;
	case 3:
		printf("%d*%d=%d\n",x,y,x*y);
		break;
	case 4:
		m=(double)x/y;
		printf("%d/%d=%.2f\n",x,y,m);
		break;
	case 5:

		printf("%d(/)%d=%d\n",x,y,x/y);
		break;
	case 6:
		printf("%d(%)%d=%d",x,y,x%y);
		break;
	}
	}
	}
	}

	printf("�밴ENTER�˳�\n");
	getchar();
	return 0;
}
