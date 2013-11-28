#include<iostream>
#include<algorithm>
#define MAXN 10005
using namespace std;

struct segment
{
	int L,R;
	int len,linenum,cover; 
	// �Ե�ǰ����Ϊ�����������ǵ�������ܳ���,
	// �Ե�ǰ����Ϊ�����������ǵ�������Ŀ����ǰ���䱻���ǵĴ�����
	bool lcover,rcover;
};

struct line
{
	int x;
	int flag;//��¼���ұ�
	bool operator<( const line &a )
	{
		return x<a.x;
	}
};

struct point
{
	int y;
	int num;
	bool operator<( const point & a )
	{
		return y<a.y;
	}
};

segment tree[MAXN*4];
line yline[MAXN];
point Ypoint[MAXN];
point Xpoint[MAXN];
int Xpost[MAXN][2];
int Ypost[MAXN][2];

void make_tree( int v, int l, int r )
{
	int mid;
	tree[v].L=l; tree[v].R=r;
	tree[v].linenum=tree[v].len=0;
	tree[v].lcover=tree[v].rcover=false;
	if( r-l>1 )
	{
		mid=(l+r)>>1;
		make_tree( v<<1, l, mid );
		make_tree( (v<<1)+1, mid, r );
	}
}

void getline( int v ) // ����Ե�ǰ�ӵ�Ϊ�����������ǵ������ܳ���
{
	if( tree[v].cover>0 )tree[v].len=Ypoint[tree[v].R].y-Ypoint[tree[v].L].y;
	else if( tree[v].R-tree[v].L==1 )tree[v].len=0;
	else tree[v].len=tree[v<<1].len+tree[(v<<1)+1].len;
}

void getlinenum( int v ) //����Ե�ǰ�ڵ�Ϊ�������������������������
{
	if( tree[v].cover>0 )
		tree[v].lcover=tree[v].rcover=true,tree[v].linenum=1;
	else if( tree[v].R-tree[v].L==1 )
		tree[v].lcover=tree[v].rcover=false,tree[v].linenum=0;
	else 	
	{
		tree[v].lcover=tree[v<<1].lcover;
		tree[v].rcover=tree[(v<<1)+1].rcover;
		tree[v].linenum=tree[v<<1].linenum+tree[(v<<1)+1].linenum-tree[v<<1].rcover*tree[(v<<1)+1].lcover;
	}
}

void update( int v, int l, int r, int flag )
{
	int mid;
	if( tree[v].L==l && tree[v].R==r )
	{
		tree[v].cover+=flag;
		getline( v );
		getlinenum( v );
		return ;
	}
	mid=(tree[v].L+tree[v].R)>>1;
	if( r<=mid )update( v<<1, l, r, flag );
	else if( l>=mid )update( (v<<1)+1, l, r, flag );
	else 
	{
		update( v<<1, l, mid, flag );
		update( (v<<1)+1, mid, r, flag );
	}
	getline( v );
	getlinenum( v );
}

int main( )
{
	int n,i,t1,t2;
	int x1,x2,y1,y2;
	while( scanf("%d",&n) != EOF )
	{
		for( i=0; i<n; i++ )
		{
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			t1=i<<1;t2=(i<<1)+1;
			Xpoint[t1].y=x1;Xpoint[t2].y=x2;
			Xpoint[t1].num=-(i+1);
			Xpoint[t2].num=i+1;
			Ypoint[t1].y=y1;Ypoint[t2].y=y2;
			Ypoint[t1].num=-(i+1);  //��������ĵ�
			Ypoint[t2].num=i+1;     //��������ĵ�
			yline[t1].x=x1;yline[t2].x=x2;
			yline[t1].flag=1;//���ž������
			yline[t2].flag=-1;//���ž����ұ�
		}
		sort( yline, yline+(n<<1) );
		sort( Xpoint, Xpoint+(n<<1) );
		sort( Ypoint, Ypoint+(n<<1) );
		for( i=0; i<(n<<1); i++ )
		{
			if( Xpoint[i].num<0 )Xpost[-Xpoint[i].num-1][0]=i;
			else Xpost[Xpoint[i].num-1][1]=i;
		}
		for( i=0; i<(n<<1); i++ )
		{
			if( Ypoint[i].num<0 )
				Ypost[Xpost[-Ypoint[i].num-1][0]][0]=Ypost[Xpost[-Ypoint[i].num-1][1]][0]=i;
			else Ypost[Xpost[Ypoint[i].num-1][0]][1]=Ypost[Xpost[Ypoint[i].num-1][1]][1]=i;
		}
		make_tree( 1, 0, (n<<1)-1 );
		int ans=0,Len=0;
		update( 1, Ypost[0][0], Ypost[0][1], yline[0].flag );
		for( i=1; i<2*n; i++ )
		{
			ans+=2*tree[1].linenum*(yline[i].x-yline[i-1].x);
			ans+=abs(tree[1].len-Len);
			Len=tree[1].len;
			update( 1, Ypost[i][0], Ypost[i][1], yline[i].flag );
		}
		ans+=abs(tree[1].len-Len);
		printf("%d\n",ans);
	}
	return 0;
}


//#include<iostream>
//#include<algorithm>
//#define Inf 10000
//
//
//using namespace std;
//
//struct Node { //�߶����Ľڵ�
//	int L,R; // ��ǰ�ڵ��ʾ�����䷶Χ
//	Node *Ls,*Rs; // ���Ҷ���
//	int len,linenum,cover,sum; // ��ǰ����ı�ʾ�ĳ��ȣ��Ե�ǰ����Ϊ�����������ǵ�������Ŀ��   ��ǰ���䱻���ǵĴ������Ե�ǰ����Ϊ�����������ǵ�������ܳ���
//	bool lcover,rcover;   //������Ҷ˵��Ƿ񱻸��� 
//	Node() {Ls = Rs = 0;L = R = 0;len = linenum = cover = sum = 0; lcover = rcover = false;}
//};
//struct  Line { // �洢���ε�����
//	int start,end;// ���ߵ�����yֵ
//	int x;        // ���ߵ�x ֵ
//	bool InOut;  // ����Ǿ��ε���߻����ұ�
//	bool operator < (const Line & a) const{
//		return x < a.x;
//	}
//};
//Line YLine[Inf];  // �洢���о��εĵ�����
//int Index[Inf];  //�洢��ɢ���yֵ 
//Node *root;     // �߶���������
//int C_nt = 0;   // ȥ�غ��yֵ����
//int Rnum;  // ���εĸ���
//void Maketree(Node *&root, int L,int R){  //�����߶���
//	if(L < R){
//		root = new Node;
//		root->L = L;
//		root->R = R;
//		root->cover = 0;
//		root->len = Index[R]- Index[L];
//		if(R - L > 1) {
//			int middle = (L + R)/2;
//			Maketree(root->Ls,L,middle);
//			Maketree(root->Rs,middle,R);
//		}
//	}
//}
//void GetLen(Node *&root){      // ����Ե�ǰ�ӵ�Ϊ�����������ǵ������ܳ���
//	if(root->cover > 0)
//		root->sum = root->len;
//	else if(root->R - root->L > 1)
//		root->sum = root->Ls->sum + root->Rs->sum;
//	else root->sum = 0;
//
//}
//void GetLinenum(Node*&root){ //����Ե�ǰ�ڵ�Ϊ�������������������������
//	if(root->cover > 0){
//		root->lcover = root->rcover = true;
//		root->linenum = 1;
//	}
//	else if(root->R - root->L > 1){
//		root->lcover = root->Ls->lcover;
//		root->rcover = root->Rs->rcover;
//		root->linenum = root->Ls->linenum + root->Rs->linenum
//			- root->Ls->rcover * root->Rs->lcover;
//	}
//	else {
//		root->lcover = root->rcover = false;
//		root->linenum = 0;
//	}
//}
//void Insert(Node *&root,int L,int R){  // ����������
//	if(L <= root->L && R >= root->R){
//		root->cover++;
//	}
//	else {
//		int middle = (root->L + root->R)/2;
//		if(L < middle) Insert(root->Ls,L,R);
//		if(R > middle) Insert(root->Rs,L,R);
//	}
//	GetLen(root);  // �������串�ǳ����Լ����ǵ�������Ŀ
//	GetLinenum(root);
//}
//
//void Delete(Node *&root,int L,int R){ //ɾ�����ε��ұ�
//	if(L <= root->L && R >= root->R){
//		root->cover--;
//	}
//	else{
//		int middle = (root->L + root->R)/2;
//		if(L < middle) Delete(root->Ls,L,R);
//		if(R > middle) Delete(root->Rs,L,R);
//	}
//	GetLen(root);// �������串�ǳ����Լ����ǵ�������Ŀ
//	GetLinenum(root);
//}
//
//int Gindex(int key){ // ����key ���±�
//	return lower_bound(Index,Index + C_nt,key) - Index;
//}
//int main(){
//	freopen("out1.txt","w",stdout);
//	scanf("%d",&Rnum);
//	int x1,x2,y1,y2;
//	for(int i = 0; i < Rnum; i++) // ������Σ��洢���ε�����Լ�yֵ����
//	{
//		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
//		YLine[2*i].x = x1; YLine[2*i+1].x = x2;
//		YLine[2*i].start = YLine[2*i+1].start = y1;
//		YLine[2*i].end = YLine[2*i+1].end = y2;
//		YLine[2*i].InOut = 1; YLine[2*i+1].InOut = 0;
//		Index[2*i] = y1; Index[2*i+1] = y2;
//	}
//	sort(Index,Index + Rnum*2);
//	sort(YLine,YLine + Rnum*2);
//	for(int i = 1; i < 2*Rnum; i++) { //ȥ���ظ��ĵ�
//		if(Index[i] != Index[i-1])
//			Index[C_nt++] = Index[i-1];
//	}
//	Index[C_nt++] = Index[2*Rnum-1];
//	Maketree(root,0,C_nt-1); // ����
//	int ans = 0,Lsum = 0;
//	for(int i = 0; i < 2*Rnum - 1; i++){ // �����ҽ���ɨ�� 
//		if(YLine[i].InOut) Insert(root,Gindex(YLine[i].start),Gindex(YLine[i].end));
//		else Delete(root,Gindex(YLine[i].start),Gindex(YLine[i].end));
//
//		//�������к���Ҫ����������ÿ�������߲������ɾ����ģ�����γ�ͼ���ں��ź����ŵķ����������ӵ��ܳ����Լ����һ�¡������е�����^_^��          
//		ans += root->linenum*(YLine[i+1].x - YLine[i].x)*2; // ������
//		printf("%d\n",ans);
//		ans += abs(root->sum - Lsum);// �����ӵ�
//		printf("%d\n",ans);
//		Lsum = root->sum;
//	}
//	Delete(root,Gindex(YLine[2*Rnum-1].start),Gindex(YLine[2*Rnum-1].end));
//	ans += abs(root->sum - Lsum);
//	printf("%d\n",ans);
//	return 0;
//}