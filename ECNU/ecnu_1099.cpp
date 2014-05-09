//浮点几何函数库
#include<iostream>
#include<cmath>
#define eps 1e-8
#define zero(x) (((x)>0?(x):-(x))<eps)
struct point{double x,y;};
struct line{point a,b;};
double xmult( point p1, point p2, point p0 )
{
	return ( p1.x-p0.x )*( p2.y-p0.y )-( p2.x-p0.x )*( p1.y-p0.y );
}
double distance( point p1, point p2 )
{
	return sqrt( ( p1.x-p2.x )*( p1.x-p2.x )+( p1.y-p2.y )*( p1.y-p2.y ) );
}
//判两直线平行
int parallel( point u1, point u2, point v1, point v2 )
{
	return zero( ( u1.x-u2.x )*( v1.y-v2.y )-( v1.x-v2.x )*( u1.y-u2.y ) );
}
//计算两直线交点,注意事先判断直线是否平行!
//线段交点请另外判线段相交(同时还是要判断是否平行!)
point intersection( point u1, point u2, point v1, point v2 )
{
	point ret=u1;
	double t=( ( u1.x-v1.x )*( v1.y-v2.y )-( u1.y-v1.y )*( v1.x-v2.x ) )
		/ ( ( u1.x-u2.x )*( v1.y-v2.y )-( u1.y-u2.y )*( v1.x-v2.x ) );
	ret.x+=( u2.x-u1.x )*t;
	ret.y+=( u2.y-u1.y )*t;
	return ret;
}
double disptoline( point p, point l1, point l2 )
{
	return fabs( xmult( p, l1, l2 ) ) / distance( l1, l2 );
}
int main( )
{
	int n;
	point p1,p2,p3,p4,p;
	scanf("%d",&n);
	printf("INTERSECTING LINES OUTPUT\n");
	while( n-- )
	{
		scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&p1.x,&p1.y,&p2.x,&p2.y,&p3.x,&p3.y,&p4.x,&p4.y);
		if( parallel( p1, p2, p3, p4 ) )
		{
			if( zero( disptoline( p3, p1, p2 ) ) )printf("LINE\n");
			else printf("NONE\n");
		}
		else 
		{
			p=intersection( p1, p2, p3, p4 );
			printf("POINT %.2lf %.2lf\n",p.x,p.y);
		}
	}
	printf("END OF OUTPUT\n");
	return 0;
}