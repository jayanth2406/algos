#include <stdio.h>

int sort(int a[], int n, int x, int y){
    int s=0;
    for(int i=0; i<n; i++) {
        if(a[i] < x) s+=a[i];
        if(a[i] > y) s+=a[i];
    }
    return s;
}

int main() {
    int n,t;
    scanf("%d", &n);
    int a[n];
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    scanf("%d", &t);
    int c[t], z=t;
    while(z>0) {
        int x,y;
        scanf("%d%d", &x, &y);
        c[z]=sort(a, n, x, y);
        z--;
    }
    for(int i=t; i>0; i--) printf("%d\n", c[i]);
    return 0;
}