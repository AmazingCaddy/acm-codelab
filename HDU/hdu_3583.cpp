//  2010年08月31日 星期二 21时26分09秒 

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

char ch[30];
int n;
void init( ) { for( int i = 0; i < 8; i++ ) ch[i] = i + 'a'; }

void print( int dep , int t )
{
    if( dep == n )
    {
        for( int i = 0; i < t; i++ )
            printf("\t");
        printf("printf(\"%c",ch[0]);
        for( int i = 1; i < n; i++ )
            printf("<%c",ch[i]);
        printf("\\n\");\n");
    }
    else
    {
        ch[dep] = 'a' + dep; int p = t;
        for( int i = dep - 1; i >= 0; i-- )
        {
            for( int j = 0; j < p; j++ )
                printf("\t");
            printf("if (%c<%c)\n",ch[i],ch[i+1]);
            print( dep + 1, p + 1 );
            for( int j = 0; j < p; j++ )
                printf("\t");
            printf("else\n");
            p++;
            swap( ch[i], ch[i+1] );
        }
        print( dep + 1, p );
        for( int i = 0; i < dep; i++ )
            ch[i] = ch[i+1];
    }
}

int main( )
{
    //freopen("out.txt","w",stdout);
    while( scanf("%d",&n) && n )
    {
        init( );
        printf("#include <stdio.h>\n\nint ");
        for( int i = 0; i < n; i++ )
        {   
            if( i ) printf(",");
            printf("%c",ch[i]);
        }
        printf(";\nbool ok;\n\nint main()\n{\n");
        printf("\tprintf(\"Please enter %d different integers:\\n\");\n", n);
        printf("\tdo\n\t{\n\t\tscanf(\"");
        for( int i = 0; i < n; i++ )
            printf("%%d");
        printf("\"");
        for( int i = 0; i < n; i++ )
            printf(",&%c",ch[i]);
        printf(");\n\t\tok=1;\n\t\tif (");
        for( int i = 0; i < n; i++ )
        {
            for( int j = i + 1; j < n; j++ )
            {
                if( !( i == 0 && j == 1 ) )printf(" || ");
                printf("%c==%c",ch[i], ch[j]);
            }
        }
        printf(")\n\t\t\tok=0;\n\t}while (ok);\n");
        
        ch[0] = 'a';
        print( 1, 1 );
        
        
        printf("\treturn 0;\n}\n\n"); 
    }
    return 0;
}

/*
#include <stdio.h>

int a,b,c,d;
bool ok;

int main()
{
	printf("Please enter 4 different integers:\n");
	do
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);
		ok=1;
		if (a==b || a==c || a==d || b==c || b==d || c==d)
			ok=0;
	}while (ok);
	if (a<b)
		if (b<c)
			if (c<d)
				printf("a<b<c<d\n");
			else
				if (b<d)
					printf("a<b<d<c\n");
				else
					if (a<d)
						printf("a<d<b<c\n");
					else
						printf("d<a<b<c\n");
		else
			if (a<c)
				if (b<d)
					printf("a<c<b<d\n");
				else
					if (c<d)
						printf("a<c<d<b\n");
					else
						if (a<d)
							printf("a<d<c<b\n");
						else
							printf("d<a<c<b\n");
			else
				if (b<d)
					printf("c<a<b<d\n");
				else
					if (a<d)
						printf("c<a<d<b\n");
					else
						if (c<d)
							printf("c<d<a<b\n");
						else
							printf("d<c<a<b\n");
	else
		if (a<c)
			if (c<d)
				printf("b<a<c<d\n");
			else
				if (a<d)
					printf("b<a<d<c\n");
				else
					if (b<d)
						printf("b<d<a<c\n");
					else
						printf("d<b<a<c\n");
		else
			if (b<c)
				if (a<d)
					printf("b<c<a<d\n");
				else
					if (c<d)
						printf("b<c<d<a\n");
					else
						if (b<d)
							printf("b<d<c<a\n");
						else
							printf("d<b<c<a\n");
			else
				if (a<d)
					printf("c<b<a<d\n");
				else
					if (b<d)
						printf("c<b<d<a\n");
					else
						if (c<d)
							printf("c<d<b<a\n");
						else
							printf("d<c<b<a\n");
	return 0;
}

*/
