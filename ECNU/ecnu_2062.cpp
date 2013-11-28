#include<stdio.h>
int main()
{
	char cow[2005],a[2005];
	int i,j,m,n,k,l;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf(" %c",&a[i]);
	i=0;j=n-1;k=0;
	while(i<j)
	{
		if(a[i]>a[j])
		{
			cow[k]=a[j];
			j--;
		}
		else if(a[i]<a[j])
		{
			cow[k]=a[i];
			i++;
		}
		else 
		{
			m=i+1;l=j-1;
			while(m<l&&a[m]==a[l])
			{
				m++;
				l--;
			}
			if(m>=l){cow[k]=a[i];i++;}
			else 
			{
				if(a[m]<a[l]){cow[k]=a[i];i++;}
				else {cow[k]=a[j];j--;}
			}
		}
		k++;
	}
	cow[k]=a[i];
	for(i=0;i<n;i++)
	{
		if(i%80==0&&i!=0)printf("\n");
		printf("%c",cow[i]);
	}
	printf("\n");
	return 0;
}