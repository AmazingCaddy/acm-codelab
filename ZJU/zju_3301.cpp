//#include <iostream>
//#include <algorithm>
//using namespace std;
//#define MAXN 10002
//
//struct node 
//{
//	int val;
//	int num;
//};
//
//bool operator<( const node & a, const node & b ){
//        return a.val < b.val;
//}
//
//node p[MAXN];
//
//int main( )
//{
//	int n,i;
//        bool first = true;
//	while( scanf("%d",&n) != EOF )
//	{
//		for( i=0; i<n; i++ )
//		{
//			scanf("%d",&p[i].val);
//			p[i].num=i+1;
//		}
//		sort( p, p+n );
//                if( first ){
//                        first = false;
//                }
//                else{
//                        printf( "\n" );
//                }
//		for( i=0; i<n; i+=2 )
//			printf("%d %d\n",p[i].num,p[i+1].num);
//	}
//	return 0;
//}