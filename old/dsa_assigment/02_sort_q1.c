#include <stdio.h>

void segregate(int a[], int n, int x, int y) {
    for(int i=0; i<n; i++) if(a[i]<x) printf("%d ", a[i]);
    printf("%d ", x);
    for(int i=0; i<n; i++) if(a[i]>x && a[i]<y) printf("%d ", a[i]);
    printf("%d ", y);
    for(int i=0; i<n; i++) if(a[i]>y) printf("%d ", a[i]);
}

int main() {
    int n, x, y;
    scanf("%d", &n);
    int a[n];
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    scanf("%d%d", &x, &y);
    segregate(a,n,x,y);
    return 0;
}