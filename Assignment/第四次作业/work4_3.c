#include <stdio.h>
	int main  (void)
{

		float		a;
		float		b;
		float		c;
		float		d;


		printf("����������˷�,���������Լ�����\n");
		scanf("%f%f%f",&a,&b,&c);

		if(b<=0) 
		{ printf("�����������\n");
		}


		else if(b>0&&b<250)
		{ d= a*b*c*(1-0);
			printf("%f\n",d);
		
		}


		else if(b>=250&&b<500)
		{	d= a*b*c*(1-0.02);
			printf("%f\n",d);

		}
		
		else if(b>=500&&b<1000)
		{	 d= a*b*c*(1-0.05);
			printf("%f\n",d);
		}
		
		else if(b>=1000&&b<2000)
		{	d= a*b*c*(1-0.08);
			printf("%f\n",d);

		}
		
		else if(b>=2000&&b<3000) 
		{	 d= a*b*c*(1-0.10);
			printf("%f\n",d);

		}
		
		else if(b>=3000)
		{	 d= a*b*c*(1-0.15);
			printf("%f\n",d);
		}

		
		
	
		return 0;

	}