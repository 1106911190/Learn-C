/************************************

  **���ݣ��ڰ˴��ϻ���ҵ������
  **���ߣ��ռ��ѧ����ѧԺʵ��� ����ǿ
  **ʱ�䣺2014��12��9��
  **���䣺18607571914@163.com
  
************************************/

#include<stdio.h>
#include<math.h>
#include"tri_area.h"

int main (void)
{
	int			a,b,c;
	double		m;

	printf("Please input a,b,c:\n");

	scanf("%d%d%d",&a,&b,&c);

	m=tri_area(a,b,c);

	if(m==-1)
		printf("Your input is wrong \n");

	else
	{
		printf("The area is %f \n",m);
	}




	return 0;
}

