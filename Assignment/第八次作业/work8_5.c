/************************************

  **���ݣ��ڰ˴��ϻ���ҵ������
  **���ߣ��ռ��ѧ����ѧԺʵ��� ����ǿ
  **ʱ�䣺2014��12��9��
  **���䣺18607571914@163.com
  
************************************/
#include <stdio.h>
int main (void)
{
	int				i_var=1;
	double			d_var=2.0;
	char			ch_var='a';

	int				*pi;
	double			*pd;
	char			*pc;

	pi=&i_var;
	pd=&d_var;
	pc=&ch_var;
	
	printf("Original:\n");
	printf("i_var    = %#d\n",i_var);
	printf("d_var    = %f\n",d_var);
	printf("ch_var   = %c\n",ch_var);
	printf("pi       = %p\n",pi);
	printf("pd       = %p\n",pd);
	printf("pc       = %p\n",pc);

	printf("\n");

	printf("&i_var   = %p\n",&i_var);
	printf("&d_var   = %p\n",&d_var);
	printf("&ch_var  = %p\n",&ch_var);
	printf("&pi      = %p\n",&pi);
	printf("&pd      = %p\n",&pd);
	printf("&pc      = %p\n",&pc);

	printf("\n");

	printf("Ha~I can use pointer:)\n");

	*pi=2;
	*pd=3.0;
	*pc='b';


	printf("i_var    = %d\n",i_var);
	printf("d_var    = %f\n",d_var);
	printf("ch_var   = %c\n",ch_var);







	return 0;
}
