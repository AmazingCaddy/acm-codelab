#include<stdio.h>
#include<string.h>
int main(){
int n,i,len;char c[19];
	scanf("%d",&n);
	getchar();
	for(i=1;i<=n;i++){
		gets(c);
		len=strlen(c);
		printf("He/She is from ");
		if(c[0]=='3'&&c[1]=='3') {
			printf("Zhejiang,");
		}
		else if(c[0]=='1'&&c[1]=='1'){
			printf("Beijing,");
		}
		else if(c[0]=='7'&&c[1]=='1'){
			printf("Taiwan,");
		}
		else if(c[0]=='8'&&c[1]=='1'){
			printf("Hong Kong,");
		}
		else if(c[0]=='8'&&c[1]=='2'){
			printf("Macao,");
		}
		else if(c[0]=='5'&&c[1]=='4'){
			printf("Tibet,");
		}
		else if(c[0]=='2'&&c[1]=='1'){
			printf("Liaoning,");
		}
		else if(c[0]=='3'&&c[1]=='1'){
			printf("Shanghai,");
		}
		printf("and his/her birthday is on %c%c,%c%c,%c%c%c%c based on the table.\n",c[10],c[11],c[12],c[13],c[6],c[7],c[8],c[9]);
	}
	return 0;
}