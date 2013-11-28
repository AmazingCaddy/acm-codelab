#include<stdio.h>
#include<string.h>
#include<malloc.h>
#define MAXN 10005
typedef struct node
{
	char data;
	struct node *lnext,*rnext;
}NODE;
char str[MAXN];
NODE * creat_tree( char str[], int n )  
{
	int i,top=0;
	NODE* stack[MAXN],*p,*q,*r;
	p=(NODE*)malloc(sizeof(NODE));
	q=(NODE*)malloc(sizeof(NODE));
	p->data=str[0];
	p->lnext=p->rnext=NULL;
	q->data=str[1];
	q->lnext=q->rnext=NULL;
	stack[0]=p;
	stack[1]=q;
	top=2;
	for( i=2; i<n; i++ )
	{
		r=(NODE*)malloc(sizeof(NODE));
		r->data=str[i];
		r->lnext=r->rnext=NULL;
		if( r->data<'a' || r->data>'z' )
		{
			p=stack[--top];
			q=stack[--top];
			stack[top++]=r;
			r->lnext=q;
			r->rnext=p;
		}
		else stack[top++]=r;
	}
	return r;
}

void print( NODE * head )
{
	NODE *r;
	NODE * que[MAXN];
	int qb=0,qe=1,k=0,i;
	que[0]=head;
	while( qb!=qe )
	{
		r=que[qb++];
		str[k++]=r->data;
		/*printf("%c",r->data);*/
		if( r->lnext != NULL )
			que[qe++]=r->lnext;
		if( r->rnext != NULL)
			que[qe++]=r->rnext;
	}
	for( i=k-1; i>=0; i-- )
		printf("%c",str[i]);
}

void Delete( NODE * head )
{
	NODE *p,*q,*r;
	r=head;
	if( r==NULL ) return;
	p=r->lnext;
	q=r->rnext;
	free(r);
	Delete( p );
	Delete( q );
}

int main( )
{
	NODE *head;
	int n,t;
	scanf("%d",&t);
	while( t-- )
	{
		scanf("%s",str);
		n=strlen(str);
		head=creat_tree( str, n );
		print( head );
		printf("\n");
		Delete( head );
	}
	return 0;
}