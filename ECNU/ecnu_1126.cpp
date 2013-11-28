#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
/*      �洢��Ľṹ    */
typedef struct
{
	float x,y;      //    ���x,y����
}POINT;
/* �����ĵ�ṹ */
typedef struct
{
	int index;      //    ����X�����е��±�
	float x, y;     //   ���x,y����
}A_POINT;
/* �Ե���е���˳������ıȽ� */
bool compareX(POINT a, POINT b)
{
	return b.x>a.x;
}
/* �Ը�������е�������ıȽ� */
bool compareY(A_POINT a, A_POINT b)
{
	return b.y>a.y;
}
/* ������������ƽ�� */
float dist(POINT a, POINT b)
{
	float dx, dy;
	dx = a.x - b.x, dy = a.y - b.y;
	return (dx*dx+dy*dy);
}
/************************************************************************
* ��ƽ��㼯�����Եķ����㷨
*
* ���룺���ƽ��㼯�������X[]������������Y[]����������±�low���յ��±�high
* �����������a,b������d
**********************************************************************/
void closest( POINT X[], A_POINT Y[], int low, int high, POINT &a, POINT &b, float &d )
{
	int i,j,k,m;
	POINT al,bl,ar,br;
	float dl,dr;
	if( ( high-low ) == 1 )
		a = X[low], b = X[high], d = dist( X[low], X[high] ); //    ��n=2ʱֱ�Ӽ���
	else if( ( high-low ) == 2 ) //    ��n=3ʱֱ�Ӽ���
	{     
		dl = dist( X[low], X[low+1] );
		dr = dist( X[low], X[low+2] );
		d = dist( X[low+1], X[low+2] );
		if( ( dl<=dr ) && ( dl<=d ) ) a = X[low], b = X[low+1], d = dl;
		else if( dr<=d ) a = X[low], b = X[low+2], d= dr;
		else a = X[low+1], b = X[low+2];
	}
	else   // ��n>3ʱ���з���
	{        
		A_POINT *SL = new A_POINT[(high-low)/2+1];
		A_POINT *SR = new A_POINT[(high-low)/2];
		m = (high-low)/2 + low;                     //  ��x������mΪ�绮��Ϊ����
		j = k = 0;
		for( i=0; i<=high-low; i++ )
		{     
			if(Y[i].index<=m) SL[j++] = Y[i];       //  �ռ�����Ӽ��е�������
			else SR[k++] = Y[i];                    //  �ռ��ұ��Ӽ��е�������
		}
		closest( X, SL, low, m, al, bl, dl );       //  ��������Ӽ���������
		closest( X, SR, m+1, high, ar, br, dr );    //  �����ұ��Ӽ���������
		if(dl<dr) a = al, b = bl, d = dl;           //  ��ϲ��õ������Ӽ��е����̾���d
		else a = ar, b = br, d = dr;
		POINT *Z = new POINT[high-low+1];
		k = 0;
		// �ռ��������߾���С��d��Ԫ�أ����浽����Z����Y���鰴y�����������Z����Ҳһ����    
		for( i=0; i<=high-low; i++ )    
			if( fabs( X[m].x - Y[i].x ) < d ) 
				Z[k].x = Y[i].x, Z[k++].y = Y[i].y;
		for( i=0; i<k; i++)
		{
			for( j=i+1; (j<k) && ( Z[j].y-Z[i].y<d ); j++ )
			{     //   ��ǰ������y��ľ��볬��d�򲻿���ʹ����С��d���˳�
				dl = dist( Z[i], Z[j] );                  //     ����ǰ������ľ���
				if( dl<d ) a = Z[i], b = Z[j], d = dl;  //     ��С��d�������
			}
		}
		delete SL;
		delete SR;
		delete Z;
	}
}

/**********************************************
* ��ƽ��㼯�����Եķ����㷨
*
* ���룺���ƽ��㼯�������X[]����ĸ���n
* �����������a,b������d
**********************************************/
void closest_pair(POINT X[], int n, POINT &a, POINT &b, float &d)
{
	if(n<2)
	{        //      ���㼯����С��2ʱ������������
		d = 0;
	}
	else
	{
		sort(X,X+n, compareX);      //        ��x������е�������
		A_POINT *Y = new A_POINT[n];    //  ��ʼ������������Y
		for( int i = 0 ; i < n ;i ++)
		{
			Y[i].index = i;
			Y[i].x = X[i].x;
			Y[i].y = X[i].y;
		}
		sort(Y,Y+n, compareY);      //        ��y������е�������
		closest(X,Y,0,n-1,a,b,d);              //     �����ܵ��
		d = sqrt(d);                //  ���õ���d��ƽ����������������ľ���
		delete Y;
	}
}

int main(){
	int n;

	cout<<"������������";
	cin>>n;

	cout<<"���������������꣺"<<endl;
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
		printf("�����������ԣ�\n");
	}

	delete X;
	return 0;
}