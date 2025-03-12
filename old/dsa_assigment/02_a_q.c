#include <stdio.h>

int main() {
// q.1 ---------------------------------------------------------

    int n, s;
    scanf("%d", &n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    scanf("%d", &s);
    for(int i=0;i<n;i++) {
        if(a[i]%s==0) printf("%d ", a[i]);
    }

//q.2 ---------------------------------------------------------
    int m,n;
    scanf("%d%d", &m, &n);
    int a[m][n];
    for(int i=0;i<m;i++) for(int j=0;j<n;j++) scanf("%d", &a[i][j]);
    for(int i=m-1;i>=0;i--) for(int j=n-1;j>=0;j--) printf("%d ", a[i][j]);

//q.3 ---------------------------------------------------------
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    for(int i=0; i<n; i++) if(a[i]==0) printf("0 ");
    for(int i=0; i<n; i++) if(a[i]!=0) printf("%d ", a[i]);

// ---------------------------------------------------------------
    return 0;
}