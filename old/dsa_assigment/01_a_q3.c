#include <stdio.h>

int search(int a[], int n, int s) {
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(a[i]+a[j]==s) return 1;
        }
    }
    return 0;
}

int main() {
    int n, s;
    scanf("%d%d", &s, &n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    int x = search(a, n, s);
    printf("%d", x);
    return 0;
}