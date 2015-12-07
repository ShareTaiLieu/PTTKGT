#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;
int TimMax(int x,int y,int z);
int main()
{
	string a,b,c;
	int F[20][20][20];
	cout << "Nhap 3 day:";
	getline(cin,a);
	getline(cin,b);
	getline(cin,c);
	int n,m,l,tg=0,tg1=0;
	n=a.length();
	m=b.length();
	l=c.length();
	for(int i=0;i<=n;i++) 
		for(int j=0;j<=m;j++) 
			for(int k=0;k<=l;k++) F[i][j][k]=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			for(int k=1;k<=l;k++)
			{
				if(a[i-1]==b[j-1] && a[i-1]==c[k-1] && b[j-1]==c[k-1])
				{
					 tg1=F[i-1][j-1][k-1]+1;
					 F[i][j][k]=tg1;
				}
				else 
				{
					tg=TimMax(F[i-1][j][k],F[i][j-1][k],F[i][j][k-1]);
					F[i][j][k]=tg;
				}
			}
	tg=F[n][m][l];
	int i=n,j=m,k=l;
	string s="";
	cout << "Ket qua la: " << F[n][m][l] << endl << s;
}
int TimMax(int x,int y,int z)
{
	int max=x;
	if(x<=y)
	{
		if(y<=z) max=z;
		else max=y;
	}
	return max;
}
