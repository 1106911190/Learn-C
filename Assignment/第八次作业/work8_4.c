/************************************

  **���ݣ��ڰ˴��ϻ���ҵ������
  **���ߣ��ռ��ѧ����ѧԺʵ��� ����ǿ
  **ʱ�䣺2014��12��9��
  **���䣺18607571914@163.com
  
************************************/
#include<stdio.h>
#include"is_perfect_num.h"

int main (void)
{
	int			a;
	int			i;

	for(i=1;i<1000;i++)
	{
		a=is_perfect_num(i);
		if(a)
			printf("%4d\n",i);
	}
		
	return 0;

}


