#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;
int TimMax(int x,int y,int z);
int main()
{
	string a,b,c;
	int F[30][30][30],E[30][30][30];
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
					 E[i][j][k]=1;
				}
				else 
					if(F[i-1][j][k]>=F[i][j-1][k] && F[i-1][j][k]>=F[i][j][k-1])
						{
							F[i][j][k]=F[i-1][j][k];
							E[i][j][k]=2;
						}
					else
						if(F[i][j-1][k]>=F[i-1][j][k] && F[i][j-1][k] >= F[i][j][k-1])
							{
								F[i][j][k]=F[i][j-1][k];
								E[i][j][k]=3;
							}
							else
							{
								F[i][j][k]=F[i][j][k-1];
								E[i][j][k]=4;
							}
			}
	tg=F[n][m][l];
	int i=n,j=m,k=l;
	string s="";
	while(i!=0 && j!=0 && k!=0)
	{
		if(E[i][j][k]==1)
		{
			s=a[i-1]+s;
			i-=1;j-=1;k-=1;
		}
		else
			if(E[i][j][k]==2) i=i-1;
			else if(E[i][j][k]==3)j=j-1;
				else if(E[i][j][k]==4) k=k-1;
	}
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
