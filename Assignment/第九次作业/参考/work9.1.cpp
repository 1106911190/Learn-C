#include <stdio.h>

void sta_stu(double * pscore,int size,double * pmax,double * pmin,double * pave)
{
	int         i;
	double   sum = 0;
	
	*pmax = *pscore;
	*pmin = *pscore;

	for(i= 0;i<size;i++)
	{
		
		if(*pmax< *(pscore+i))
			*pmax = *(pscore+i);
	}

	for(i= 0;i<size;i++)
	{
		if(*pmin > *(pscore+i))
			*pmin = *(pscore+i);
			
	}

	for(i= 0;i<size;i++)
	{
		sum += *(pscore+i);
	}
	
	*pave = sum / size;

	return    ;

}

int main(void)
{
	double    scores[] = {80,95.5,82,92,88.5 };
	int			size;
	double		max = 0;
	double      min = 0;
	double      ave = 0;


	size = sizeof(scores)/sizeof(scores[0]);
	
	sta_stu(scores,size,&max,&min,&ave);

	printf("max = %.2f\nmin = %.2f\nave = %.2f\n",max,min,ave);


	return 0;
}

