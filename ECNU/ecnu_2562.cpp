#include<string>
#include<iostream>
#include<map>
using namespace std;
#define N 200001
map<string,int> s;
string n1,n2;
int pre[N],size[N];
int find( int x )
{
	if( pre[x]==x ) return x;
	pre[x]=find( pre[x] );
	return pre[x];
}
void merge( int x, int y )
{
	int kx=find(x),ky=find(y);
	if( kx != ky )
	{
		if( size[kx]<size[ky] )
		{
			pre[kx]=ky;
			size[ky]+=size[kx];
		}
		else
		{
			pre[ky]=kx;
			size[kx]+=size[ky];
		}
	}
}
 
int main()
{
	int T,F,i,num;
	scanf("%d",&T);
	while(T--)
	{
		
		scanf("%d",&F);
		for( i=0; i<2*F; i++ ) 
		{ 
			pre[i]=i;
			size[i]=1;
		}
		num=0;
		for( i=0; i<F; i++ )
		{
			cin>>n1>>n2;
			//将人的名字与数字对应起来
			if( s.find(n1)==s.end() )
				s[n1]=num++;				
			if( s.find(n2)==s.end() )
				s[n2]=num++;
			merge(s[n1],s[n2]);
			printf("%d\n",size[find(s[n1])]);
		}
	}
    return 0;
}