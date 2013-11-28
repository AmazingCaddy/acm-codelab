#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
/*      存储点的结构    */
typedef struct
{
	float x,y;      //    点的x,y坐标
}POINT;
/* 辅助的点结构 */
typedef struct
{
	int index;      //    点在X数组中的下标
	float x, y;     //   点的x,y坐标
}A_POINT;
/* 对点进行递增顺序排序的比较 */
bool compareX(POINT a, POINT b)
{
	return b.x>a.x;
}
/* 对辅助点进行递增排序的比较 */
bool compareY(A_POINT a, A_POINT b)
{
	return b.y>a.y;
}
/* 计算两点距离的平方 */
float dist(POINT a, POINT b)
{
	float dx, dy;
	dx = a.x - b.x, dy = a.y - b.y;
	return (dx*dx+dy*dy);
}
/************************************************************************
* 求平面点集最近点对的分治算法
*
* 输入：存放平面点集点的数组X[]、辅助点数组Y[]，数组起点下标low与终点下标high
* 输出：最近点对a,b及距离d
**********************************************************************/
void closest( POINT X[], A_POINT Y[], int low, int high, POINT &a, POINT &b, float &d )
{
	int i,j,k,m;
	POINT al,bl,ar,br;
	float dl,dr;
	if( ( high-low ) == 1 )
		a = X[low], b = X[high], d = dist( X[low], X[high] ); //    当n=2时直接计算
	else if( ( high-low ) == 2 ) //    当n=3时直接计算
	{     
		dl = dist( X[low], X[low+1] );
		dr = dist( X[low], X[low+2] );
		d = dist( X[low+1], X[low+2] );
		if( ( dl<=dr ) && ( dl<=d ) ) a = X[low], b = X[low+1], d = dl;
		else if( dr<=d ) a = X[low], b = X[low+2], d= dr;
		else a = X[low+1], b = X[low+2];
	}
	else   // 当n>3时进行分治
	{        
		A_POINT *SL = new A_POINT[(high-low)/2+1];
		A_POINT *SR = new A_POINT[(high-low)/2];
		m = (high-low)/2 + low;                     //  把x数组以m为界划分为两半
		j = k = 0;
		for( i=0; i<=high-low; i++ )
		{     
			if(Y[i].index<=m) SL[j++] = Y[i];       //  收集左边子集中的最近点对
			else SR[k++] = Y[i];                    //  收集右边子集中的最近点对
		}
		closest( X, SL, low, m, al, bl, dl );       //  计算左边子集的最近点对
		closest( X, SR, m+1, high, ar, br, dr );    //  计算右边子集的最近点对
		if(dl<dr) a = al, b = bl, d = dl;           //  组合步得到左右子集中点的最短距离d
		else a = ar, b = br, d = dr;
		POINT *Z = new POINT[high-low+1];
		k = 0;
		// 收集距离中线距离小于d的元素，保存到数组Z（因Y数组按y坐标递增排序，Z数组也一样）    
		for( i=0; i<=high-low; i++ )    
			if( fabs( X[m].x - Y[i].x ) < d ) 
				Z[k].x = Y[i].x, Z[k++].y = Y[i].y;
		for( i=0; i<k; i++)
		{
			for( j=i+1; (j<k) && ( Z[j].y-Z[i].y<d ); j++ )
			{     //   若前后两点y轴的距离超过d则不可能使距离小于d，退出
				dl = dist( Z[i], Z[j] );                  //     计算前后两点的距离
				if( dl<d ) a = Z[i], b = Z[j], d = dl;  //     若小于d，则更新
			}
		}
		delete SL;
		delete SR;
		delete Z;
	}
}

/**********************************************
* 求平面点集最近点对的分治算法
*
* 输入：存放平面点集点的数组X[]，点的个数n
* 输出：最近点对a,b及距离d
**********************************************/
void closest_pair(POINT X[], int n, POINT &a, POINT &b, float &d)
{
	if(n<2)
	{        //      当点集个数小于2时不存在最近点对
		d = 0;
	}
	else
	{
		sort(X,X+n, compareX);      //        对x数组进行递增排序
		A_POINT *Y = new A_POINT[n];    //  初始化辅助点数组Y
		for( int i = 0 ; i < n ;i ++)
		{
			Y[i].index = i;
			Y[i].x = X[i].x;
			Y[i].y = X[i].y;
		}
		sort(Y,Y+n, compareY);      //        对y数组进行递增排序
		closest(X,Y,0,n-1,a,b,d);              //     求亲密点对
		d = sqrt(d);                //  将得到的d开平方才是两点间真正的距离
		delete Y;
	}
}

int main(){
	int n;

	cout<<"请输入点个数：";
	cin>>n;

	cout<<"请输入各个点的坐标："<<endl;
	POINT *X = new POINT[n];
	for(int i=0; i<n; i++)
	{
		cin>>X[i].x>>X[i].y;
	}

	POINT a,b;
	float d;
	closest_pair(X,n,a,b,d);

	if(n>=2)
	{
		printf("(%.2f,%.2f) - (%.2f,%.2f) : %.2f\n", a.x, a.y, b.x, b.y, d);
	}
	else
	{
		printf("不存在最近点对！\n");
	}

	delete X;
	return 0;
}