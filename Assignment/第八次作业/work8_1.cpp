/************************************

  **���ݣ��ڰ˴��ϻ���ҵ��һ��
  **���ߣ��ռ��ѧ����ѧԺʵ��� ����ǿ
  **ʱ�䣺2014��12��9��
  **���䣺18607571914@163.com
  
************************************/


#include<stdio.h>

int	factor(int n);
double sum_factor(int n);

int main (void)
{
	int				a;
	double			sum;



	printf("Please input n (0 to exit):\n");
	scanf("%d",&a);

	if(a<13)
	{

	sum=sum_factor(a);

	printf("%f\n",sum);
	}
	else
	printf("Your input is wrong\n");


	return 0;
}

int factor(int n)
{
	int			x=1;
	int			i;

	for(i=1;i<=n;i++)
		x*=i;

	return x;

}

double sum_factor (int n)
{
	double			m=0;
	int				i;
	double			r;
	
	for(i=1;i<=n;i++)
	{
		r=(double)1/(factor(i));
		m=(double)r+m;	
		
	}
	
	return m;



}