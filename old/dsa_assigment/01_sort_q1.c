#include <stdio.h>

void swap(int * a, int * b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void bubbleSort(int a[], int n) {
    int i,j, swapped;
    for(i=0; i<n-1; i++) {
        swapped = 0;
        for(j=0; j<n-i-1; j++) {
            if(a[j] > a[j+1]){
                swap(&a[j], &a[j+1]);
                swapped = 1;
            }
        }
        if(swapped==0) break;
    }
}

void merge(int a[], int n, int b[], int m) {
    for(int i=0; i<m && i<n; i++){
        if(a[n-i-1] > b[i]) {
            swap(&a[n-i-1], &b[i]);
        }
        else break;
    }
    bubbleSort(a, n);
    bubbleSort(b, m);
}    

int main() {
    int n,m;
    scanf("%d%d", &n, &m);
    int a[n], b[m];
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    for(int i=0; i<m; i++) scanf("%d", &b[i]);
    merge(a, n, b, m);
    for(int i=0; i<n; i++) printf("%d ", a[i]);
    printf("\n");
    for(int i=0; i<m; i++) printf("%d ", b[i]);
    return 0;
}