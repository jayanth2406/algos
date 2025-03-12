#include <stdio.h>

void segregate(int a[], int n) {
    int zct=0;
    for(int i=0; i<n; i++) if(a[i]==0) zct++;
    for(int i=0; i<n; i++){
        if(i<zct) a[i]=0;
        else a[i]=1;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    segregate(a, n);
    for(int i=0;i<n;i++) printf("%d ", a[i]);    
    return 0;
}