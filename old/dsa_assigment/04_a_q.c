/// q.1 /////////////////////////////////////////////////
#include <stdio.h>

int main() {
    int m, n;
    scanf("%d%d", &m, &n);
    if(m!=n) {
        printf("Not a Sq. Matrix, so, fuck off!");
        return 0;
    }
    int a[m][n];
    for(int i=0; i<m; i++) for(int j=0; j<n; j++) scanf("%d", &a[i][j]);
    int d=0;
    for(int i=0; i<m; i++) d+=a[i][i];
    printf("%d", d);
    return 0;
}
////////////////////////////////////////////////////////
/// q.2 /////////////////////////////////////////////////
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    for(int i=0; i<n; i++) if(a[i]>=32) {
        printf("%d", a[i]);
        if(i!=n-1) printf(",");
    }
    return 0;
}
////////////////////////////////////////////////////////
/// q.3 /////////////////////////////////////////////////
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    
    for(int i=0; i<n; i++){
        for(int j=i-1; j>0; j--) {
            if(a[i]==a[j]) goto x;
        }
        printf("%d ", a[i]);
        x:
    }
    return 0;
}
////////////////////////////////////////////////////////