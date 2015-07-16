#include <iostream>
#include <stdio.h>

using namespace std;

bool binarySearch(int S[], int n, int search) {
    
    int left = 0;
    int right = n;

    while(left < right) {
        int mid = (left + right) / 2;
        if(S[mid] == search) {
            return true;
        } else if(S[mid] > search) {
            right = mid;
        } else if(S[mid] < search) {
            left = mid + 1;
        }
    }
    
     return false;
}

int main() {
    int n, S[100000];
    int q;
    int ans = 0;

    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &S[i]);
    }

    scanf("%d", &q);
    int search;
    for(int i = 0; i < q; i++) {
        scanf("%d", &search);
        if(binarySearch(S, n, search)) {
            ans++;
        }
    }

    printf("%d\n", ans);
    
    return 0;
}
