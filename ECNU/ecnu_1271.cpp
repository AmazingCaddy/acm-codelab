#include<iostream>
using namespace std;
int a[100][3];
int h[100];
int com(const void*a,const void *b)
{
	int *c=(int*)a;
	int *d=(int*)b;
	return (*(c+1))*(*c)-(*(d+1))*(*d);
}
int main()
{
	int i,j,t,n,x,y,z,r;
	cin>>n;r=1;
	while( n )
	{
		memset(h,0,sizeof(h));
		for(i=0;i<n;i++)
		{
			cin>>x>>y>>z;
			a[3*i][0]=x;a[3*i][1]=y;a[3*i][2]=z;
			a[3*i+1][0]=x;a[3*i+1][1]=z;a[3*i+1][2]=y;
			a[3*i+2][0]=y;a[3*i+2][1]=z;a[3*i+2][2]=x;
		}
		qsort(a,3*n,3*sizeof(int),com);
		h[0]=a[0][2];
		for(i=1;i<3*n;i++)
		{
			for(j=0;j<i;j++)
			{
				if(a[j][0]<a[i][0]&&a[j][1]<a[i][1]||a[j][0]<a[i][1]&&a[j][1]<a[i][0])
				{
					if(h[j]>h[i])h[i]=h[j];
				}
			}
			h[i]+=a[i][2];
		}
		t=0;
		for(i=0;i<3*n;i++)
			if(h[i]>t)t=h[i];
		cout<<"Case "<<r<<": maximum height = "<<t<<endl;
		cin>>n;r++;
	}
	return 0;
}