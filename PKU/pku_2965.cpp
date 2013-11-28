#include<iostream>
#define MAXN 65540
using namespace std;
int map[16][2]={{3,3},{3,2},{3,1},{3,0},{2,3},{2,2},{2,1},{2,0},
                {1,3},{1,2},{1,1},{1,0},{0,3},{0,2},{0,1},{0,0}};
bool visit[MAXN];
struct node 
{
	int from;
	int num,step;
}que[MAXN];
int way[MAXN];
int flag;
int change( int num, int k )
{
	int i,j;
	num^=(1<<k);
	for( i=15-map[k][0]*4; i>15-(map[k][0]+1)*4; i-- )
		num^=(1<<i);
	for( j=15-map[k][1]; j>=0; j=j-4 )
		num^=(1<<j);
	return num;
}

int BFS( int num )
{
	int nnum,mnum,step;
	int qb=0,qe=1,i;
	memset( visit, false, sizeof(visit) );
	que[qe].num=num;
	que[qe].step=0;
	way[qe]=-1;
	visit[num]=true;
	while( qb<qe )
	{
		qb++;
		step=que[qb].step+1;
		mnum=que[qb].num;
		for( i=15; i>=0; i-- )
		{
			nnum=change( mnum, i );
			if( nnum==0 )
			{
				qe++;
				flag=qe;
				que[qe].from=i;
				way[qe]=qb;
				return step;
			}
			if( !visit[nnum] )
			{	
				qe++;
				que[qe].from=i;
				que[qe].num=nnum;
				que[qe].step=step;
				visit[nnum]=true;
				way[qe]=qb;
			}
		}
	}
	return -1;
}

void print( int x )
{
	int y;
	if( way[way[x]]==-1 )
	{
		y=que[x].from;
		printf("%d %d\n",map[y][0]+1,map[y][1]+1);
		return ;
	}
	else print( way[x] );
	y=que[x].from;
	printf("%d %d\n",map[y][0]+1,map[y][1]+1);
}
	
int main( )
{
	int i,j,cnt=0,ans,x=0;;
	char mat[5];
	while( scanf("%s",mat) != EOF )
	{
		for( i=0; i<4; i++ )
		{
			x<<=1;
			if( mat[i]=='+' )
				x+=1;
		}
		cnt++;
		if( cnt==4 )
		{
			cnt=0;
			ans=BFS( x );
			printf("%d\n",ans);
			print( flag );
			x=0;
		}
	}
	return 0;
}


//#include <iostream>
//#include <vector>
//#include <stack>
//
//using namespace std;
//
//bool visit[65540];
//struct Node{
//    int x;
//    int steps;
//    int par;
//    int cha;
//};
//vector<Node> nums;
//
//int Change(int num,int x){
//    int i,j;
//    i = x/4;
//    num^=(1<<i*4);
//    num^=(1<<i*4+1);
//    num^=(1<<i*4+2);
//    num^=(1<<i*4+3);
//    i = x%4;
//    num^=(1<<i);
//    num^=(1<<i+4);
//    num^=(1<<i+8);
//    num^=(1<<i+12);
//    num^=(1<<x);   
//    return num;
//}//右值改变，倒着搜的
//
//Node Bfs(int s){   
//    int i;
//    int j,k;
//    Node a,b;
//    memset(visit,false,sizeof(visit));
//    a.x = s,a.steps=0,a.par=-1,a.cha=-1;
//    nums.push_back(a);
//    visit[a.x] = true;
//    for(j=0;j<nums.size();j++){
//        a = nums[j];
//        if(0==a.x)
//            return a;
//        b.par=j;
//        b.steps = a.steps+1;
//        for(i=0;i<=15;i++){
//            b.x = Change(a.x,i);
//            if(visit[b.x]==false){
//                b.cha=i;
//                visit[b.x] = true;
//                nums.push_back(b);
//            }
//        }
//    }       
//}
//
//
//int main()
//{
//    int x, //存储状态
//        i,j;
//    int counts=0;
//    int t;  
//    char input[4][5];
//    while(scanf("%s", input[0]) != EOF){
//        for(i = 1; i < 4; ++i)
//            scanf("%s", input[i]);
//        x= 0;
//        for(i = 0; i < 4; ++i){
//            for(j = 0; j < 4; ++j)
//                if(input[i][j] == '+')
//                    x |= (1 << i * 4 + j);
//        }
//
//    //solve
//        Node a;
//        a=Bfs(x);
//        cout<<a.steps<<endl;
//       
//        stack<Node> output;
//        output.push(a);
//        do{
//            a=nums[a.par];
//            output.push(a);           
//        }while(a.par!=-1);
//        output.pop();
//        while(!output.empty()){
//            cout<<(output.top().cha)/4+1<<" "<<(output.top().cha)%4+1<<endl;
//            output.pop();
//        }
//    }
//    return 0;
//}