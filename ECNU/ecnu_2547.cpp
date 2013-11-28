#include <iostream>

using namespace std;

void dfs(int a,int b)

{

      int c=(b-a),d=(-a-b);

      if(c!=0||d!=0)

           if(abs(c)%2)dfs((c+1)/2,(d+1)/2);

           else dfs(c/2,d/2);

      else return;

      if(abs(c)%2)printf("1");

      else printf("0");

}

 

int main()

{
      int cas,k,a,b;

      scanf("%d",&cas);

      for(k=1;k<=cas;k++)

      {
           scanf("%d%d",&a,&b);

           printf("Case #%d: ",k);

           if(a||b)dfs(a,b);

           else printf("0");

           printf("\n");
      }
	  return 0;
}
