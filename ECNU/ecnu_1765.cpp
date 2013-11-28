#include <iostream>
#include <cstdlib>
#define N 20000
using namespace std;
typedef struct 
{
	int w;
	int h;
}DOLL;

int compare( const void *a,const void *b )
{
	DOLL *p=(DOLL*)a,*q=(DOLL*)b;
	if( p->w != q->w )return p->w-q->w;
	else return q->h-p->h;
}

int main()
{
	DOLL a[N];
	bool visit[N]={0};
	int i,t,n,j;
	scanf("%d",&t);
	while( t-- )
	{
		scanf("%d",&n);
		for( i=0; i<n; i++ )
			scanf("%d%d",&a[i].w,&a[i].h);

		qsort( a, n, sizeof(DOLL), compare );

		int count=0;
		for( i=0; i<n; i++ )
		{
			if( !visit[i] )
			{
				int maxh=a[i].h , maxw=a[i].w;
				visit[i]=1;
				for( j=i+1; j<n; j++ )
					if( a[j].w>maxw && a[j].h>maxh && !visit[j] )
					{
						visit[j]=1;
						maxw=a[j].w;
						maxh=a[j].h;
					}
				count++;
			}
		}
		printf("%d\n",count);
		memset(visit,0,sizeof(visit));
	}
	return 0;
}