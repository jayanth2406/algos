#include <stdio.h>

void sort(int a[], int n){
    int ect=0, oct=0;
    int e[n], o[n];
    for(int i=0; i<n; i++) if(a[i]%2==0) e[ect++] = a[i];
    for(int i=n-1; i>0; i--) if(a[i]%2!=0) o[oct++] = a[i];
    for(int i=0; i<ect; i++) a[i] = e[i];
    for(int i=0; i<oct; i++) a[i+ect] = o[i];
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    sort(a, n);
    for(int i=0; i<n; i++) printf("%d ", a[i]);
    return 0;
}