#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    for(int i=0; i<n;i++) {
        int t=a[i];
        for(int j=i+1; j<n; j++){
            if(t==a[j]) {
                printf("%d repeated at %d index",t, j);
                return 0;
            }
        }
    }
    printf("There is no repeated element");
    return 0;
}