#include<iostream>
#include<cstdlib>
using namespace std;
struct node
{
	int mark,num,win,lose;
};

int compare( const void *a, const void *b )
{
	node *q=(node*)b,*p=(node*)a;
	if( p->mark!=q->mark )return q->mark-p->mark;
	else if( p->win!=q->win )return q->win-p->win;
	else if( p->lose!=q->lose )return p->lose-q->lose;
	else return p->num-q->num;
}

int main()
{
	int n,m,i,a,b,c;
	node v[11];
	while( scanf("%d%d",&n,&m) && n!=0 )
	{
		for( i=0; i<n; i++ )
		{
			v[i].lose=v[i].mark=v[i].win=0;
			v[i].num=i+1;
		}
		for( i=0; i<m; i++ )
		{
			scanf("%d%d%d",&a,&b,&c);
			if( c==1 )
			{
				v[a-1].mark+=3;
				v[a-1].win+=1;
				v[b-1].mark-=1;
				v[b-1].lose+=1;
			}
			if( c==0 )
			{
				v[a-1].mark+=1;
				v[b-1].mark+=1;
			}
			if( c==-1 )
			{
				v[a-1].lose+=1;
				v[a-1].mark-=1;
				v[b-1].win+=1;
				v[b-1].mark+=3;
			}
		}
		qsort( v, n, sizeof(node), compare );
		for( i=0; i<n; i++ )
			printf("%d ",v[i].num);
		printf("\n");
	}
	return 0;
}