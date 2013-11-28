#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int timecost;
	int deadline;
}DATE;

int compare1(const void *a,const void *b)
{
	return *(int*)a-*(int*)b;
}

int compare(const void *a,const void *b)
{
	return ((DATE*)a)->deadline-((DATE*)b)->deadline;
}

int main()
{
	int time=0,n,i,b[1005];
	DATE a[1005];
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d%d",&a[i].timecost,&a[i].deadline);

	qsort(a,n,sizeof(DATE),compare);

	for(i=0;i<n;i++)
	{
		if(a[i].timecost>a[i].deadline)
		{
			printf("-1\n");
			break;
		}
		else 
		{
			time=time+a[i].timecost;
			b[i]=a[i].deadline-time;
			if(time>a[i].deadline)
			{
				printf("-1\n");
				break;
			}
		}
	}
	if(i==n)
	{
		qsort(b,n,sizeof(int),compare1);
		printf("%d\n",b[0]);
	}
	return 0;
}
