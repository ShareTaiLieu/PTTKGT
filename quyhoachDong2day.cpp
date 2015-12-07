#include <stdio.h>
#include <string.h>
 
int m, n;
char a[12309];
char b[12309];
int F[2309][2309];
 
int max(int a, int b){ return a>b?a:b; }
 
main(){
   int i, j;
   scanf("%s%s", a+1, b+1);
   m = strlen(a+1);
   n = strlen(b+1);
   for (i=1; i<=m; i++)
   for (j=1; j<=n; j++)
   if (a[i]==b[j]) F[i][j] = F[i-1][j-1] + 1;
   else F[i][j] = max(F[i-1][j], F[i][j-1]);
 
   printf("%dn", F[m][n]);
}
