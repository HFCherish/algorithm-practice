#include <set>
#include <map>
#include <queue>
#include <stack>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <limits.h>
#include <string.h>
#include <string>
#include <algorithm>
#define MID(x,y) ( ( x + y ) >> 1 )
#define L(x) ( x << 1 )
#define R(x) ( x << 1 | 1 )
#define FOR(i,s,t) for(int i=(s); i<(t); i++)
#define BUG puts("here!!!")
#define STOP system("pause")
#define file_r(x) freopen(x, "r", stdin)
#define file_w(x) freopen(x, "w", stdout)

using namespace std;

char s[2000];
char o[2000];

int main()
{
	int num = 1;
	int cha = 9;
	int type = 3;
	file_w("sql.txt");
	while( gets(s) )
	{
		int cnt = 0;
		int len = strlen(s);
		bool out = false;
		if( len == 0 ) continue;
		FOR(i, 1, len)
		{
			if( out && s[i] != ' ' && s[i] != '\t')
				o[cnt++] = s[i];
				
			//if( s[i] == -94 && s[i-1] ==-95)
			if(s[i] == '.') 
				out = true;
		}
		
		cout << "update problem set answer = '";
		FOR(i, 0, cnt)
			putchar(o[i]);
		cout << "' where chapter = " << cha << " and type = " << type << " and number = " << num++ << ";" << endl;
	}
return 0;
}
