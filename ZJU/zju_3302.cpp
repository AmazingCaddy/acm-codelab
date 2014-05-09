//// Q1: n+1             Q2: (A1*A2...*An*n!) / ( sum...(sum-n+1) )
//// Q3: sum-min+1       Q4: ( min! * cnt ) / ( sum...(sum-min+1) )
//// sum=A1+A2+...+An    cnt 表示A[1..n]中最小值的个数
//
//#include<iostream>
//#define MAXN 101
//using namespace std;
//int bin( int n )
//{
//	int sum=0;
//	while( 1 )
//	{
//		if( n & 1 )break;
//		else sum++;
//		n>>=1;
//	}
//	return sum;
//}
//
//int main( )
//{
//	int a[MAXN];
//	int i,n,sum,min,cnt,num1,num2;
//	bool flag;
//	while( scanf("%d",&n) != EOF )
//	{
//		flag=false;
//		sum=0;
//		min=99999;
//		cnt=0;
//		for( i=0; i<n; i++ )
//		{
//			scanf("%d",&a[i]);
//			if( a[i]>1 )flag=true;
//			if( a[i]<min )
//			{
//				min=a[i];
//				cnt=1;
//			}
//			else if( min==a[i] )
//				cnt++;
//			sum+=a[i];
//		}
//		if( !flag )printf("-1\n0\n");
//		else 
//		{
//			printf("%d\n",n+1);
//			num1=num2=0;
//			for( i=0; i<n; i++ )          // a0*a1*a2...a(n-1)
//				num1=num1+bin( a[i] );
//			for( i=2; i<=n; i++ )         // n!
//				num1=num1+bin( i );
//			for( i=sum-n+1; i<=sum; i++ ) // sum*(sum-1)...(sum-n+1)
//				num2=num2+bin( i );
//			printf("%d\n",num1-num2);
//		}
//		printf("%d\n",sum-min+1);
//		num1=num2=0;
//		for( i=2; i<=min; i++ )           // min!
//			num1=num1+bin( i );
//		num1=num1+bin( cnt );             // cnt  
//		for( i=sum-min+1; i<=sum; i++ )   // (sum-min+1)...sum
//			num2=num2+bin( i );
//		printf("%d\n",num1-num2);
//	}
//	return 0;
//}