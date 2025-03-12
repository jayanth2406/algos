/// q.1 /////////////////////////////////////////////////
#include <stdio.h>

int isPrime(int n) {
    for(int i=2; i<n; i++) if(n%i==0) return 0;
    return 1;
}

int main() {
    int a[10];
    for(int i=0; i<10; i++) scanf("%d", &a[i]);
    printf("Prime Numbers: ");
    for(int i=0; i<10; i++) if(isPrime(a[i])==1) printf("%d ", a[i]);
    printf("\nComposite Numbers: ");
    for(int i=0; i<10; i++) if(isPrime(a[i])==0) printf("%d ", a[i]);
    return 0;
}
////////////////////////////////////////////////////////
/// q.2 /////////////////////////////////////////////////
#include <stdio.h>

void shiftArray(int a[], int n, int s) {
    for(int i=0; i<s; i++){
        int t=a[0];
        for(int j=0; j<n-1; j++) a[j] = a[j+1];
        a[n-1] = t;
    }
}

int main() {
    int n, s;
    scanf("%d", &n);
    int a[n];
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    scanf("%d", &s);
    if(s>=n) {
        printf("Invalid postion");
        return 0;
    }
    shiftArray(a, n, s);
    for(int i=0; i<n; i++) printf("%d ", a[i]);
    return 0;
}
////////////////////////////////////////////////////////
/// q.3 /////////////////////////////////////////////////
#include <stdio.h>

void printIndex(int a[], int n){
    for(int i=0; i<n; i++) 
    for(int j=1; j<=a[i]; j++) 
    if(j*j==a[i]) printf("%d ", i);
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter %d integers for the array: ", n);
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    printf("Indexes of perfect squares in the array: ");
    printIndex(a, n);
    return 0;
}
////////////////////////////////////////////////////////