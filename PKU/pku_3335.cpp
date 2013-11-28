//// poj 3335 
//// 可以同时处理顺时针和逆时针输入，效率(n^2)
//#include<iostream>
//#include<cmath>
//#define MAXN 800
//#define eps 1e-10
//using namespace std;
//struct point{ double x,y; };
//struct polygon{ int n; point p[MAXN]; };
//
//double xmult( point p1, point p2, point p0 ) 
//{
//	return ( p1.x-p0.x )*( p2.y-p0.y )-( p2.x-p0.x )*( p1.y-p0.y );
//}
//int same_side( point p1, point p2, point l1, point l2 )
//{ 
//	return xmult( l1, p1, l2 )*xmult( l1, p2, l2 )>eps;
//}
//bool equal_point( point p1, point p2 )
//{
//	return ( fabs(p1.x-p2.x)<eps && fabs( p1.y-p2.y )<eps );
//}
//point intersection( point u1, point u2, point v1, point v2 )
//{
//	point ret=u1;
//	double t=((u1.x-v1.x)*(v1.y-v2.y)-(u1.y-v1.y)*(v1.x-v2.x))
//		/((u1.x-u2.x)*(v1.y-v2.y)-(u1.y-u2.y)*(v1.x-v2.x));
//	ret.x+=(u2.x-u1.x)*t;
//	ret.y+=(u2.y-u1.y)*t;
//	return ret;
//}
//// 多边形的点是顺时针的
//polygon polygon_cut( point p1, point p2, const polygon &poly )
//{
//	int i,j;
//	double t1,t2;
//	polygon ret;
//	point pp;
//	ret.n=0;
//	for( i=0; i<poly.n; i++ )
//	{
//		j=i+1;
//		t1=xmult( p2, poly.p[i], p1 ); //p1p2 * p1p[i]
//		t2=xmult( p2, poly.p[j], p1 );
//		if( t1<eps && t2<eps ) 
//		{
//			ret.p[ret.n++]=poly.p[i];
//			ret.p[ret.n++]=poly.p[j];
//		}
//		else if( t1>eps && t2>eps )continue;
//		else
//		{
//			pp=intersection( p1, p2, poly.p[i], poly.p[j] );
//			if( t1<eps )
//			{
//				ret.p[ret.n++]=poly.p[i];
//				ret.p[ret.n++]=pp;
//			}
//			else 
//			{
//				ret.p[ret.n++]=pp;
//				ret.p[ret.n++]=poly.p[j];
//			}
//		}
//	}
//	if( ret.n==0 )return ret;
//	for( j=i=1; i<ret.n; i++ )
//		if( !equal_point( ret.p[i], ret.p[i-1] ) )
//			ret.p[j++]=ret.p[i];
//
//	ret.n=j;
//	if( ret.n!=1 && equal_point( ret.p[ret.n-1], ret.p[0] ) ) ret.n--;
//	ret.p[ret.n] = ret.p[0];	
//	return ret;
//}
//
//double polygonArea( polygon p )
//{
//    int i, n=p.n;
//    double area=0;
//    for( i=1; i<=n; i++ )
//        area+=( p.p[i-1].x*p.p[i%n].y-p.p[i%n].x*p.p[i-1].y );
//	return area;
//}
//
//void ChangeClockwise( polygon &poly )
//{
//	point tmp;
//	int i;
//	for( i=0; i<=(poly.n-1)/2; i++ )
//	{
//		tmp=poly.p[i];
//		poly.p[i]=poly.p[poly.n-1-i];
//		poly.p[poly.n-1-i]=tmp;			
//	}
//}
//int main( )
//{
//	int t,i;
//	polygon ret,input;
//	scanf("%d",&t);
//	while( t-- )
//	{
//		scanf("%d",&input.n);
//		for( i=0; i<input.n; i++ )
//			scanf("%lf%lf",&input.p[i].x,&input.p[i].y);
//
//		//若是逆时针转化为顺时针
//		if( polygonArea(input)>0 ) ChangeClockwise( input );
//		input.p[input.n]=input.p[0];
//		ret=input;
//		for( i=0; i<input.n; i++ )
//			ret=polygon_cut( input.p[i], input.p[i+1], ret );
//		if( ret.n>=1 )printf("YES\n");
//		else printf("NO\n");
//	}
//	return 0;
//}

