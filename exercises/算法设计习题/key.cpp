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

const int MAX = 20;
string R, tmp, LA;
int n;
pair<string, string> F[MAX];

bool ch_in_s(char ch, string b)
{
	FOR(i, 0, b.length())
		if( ch == b[i] )
			return true;
	return false;
}
bool s_in_s(string a, string b)
{
	FOR(i, 0, a.length())
		if( !ch_in_s(a[i], b) )
			return false;
	return true;
}
string solve()
{
	string ans = LA;
	bool used[MAX];
	memset(used, false, sizeof(used));
	do
	{
		tmp = ans;	
		FOR(i, 0, n)
			if( !used[i] && s_in_s(F[i].first, ans) )
			{
				used[i] = true;
				ans += F[i].second;
			}	
	}while( tmp != ans );
	sort(ans.begin(), ans.end());
	unique(ans.begin(), ans.end());
	FOR(i, 1, ans.length())
		if( ans[i] == ans[i-1] )
		{
			ans.resize(i);
			break;
		}
	return ans;
}

int main()
{
	cout << "�������е����Լ�(��ABCD�ȴ�д��ĸ��ʾ����ͬ����" << endl;
	
	cin >> R;
	
	cout << "�����ϵ��N��" << endl;
	cin >> n;
	
	cout << "����N����ϵ����A->B��ʾ��ÿ��һ����ϵ:" << endl; 
	FOR(i, 0, n)
	{
		cin >> tmp;
		bool f = false;
		FOR(k, 0, tmp.length())
		{
			if( tmp[k] == '-' )
				k += 2, f = true;
			if( !f )
				F[i].first += tmp[k];
			else
				F[i].second += tmp[k];
		}
	}
	
	cout << "����Ҫ��õ����Լ��հ������ԣ�" << endl; 
	cin >> LA;
	
	string ans = solve();
	cout << "������������������������������������" << endl << "���Լ�" << LA << "�ıհ�(AB+)Ϊ:" << endl << ans << endl; 
	cout << "������������������������������������" << endl;
		
system("pause");
return 0;
}
