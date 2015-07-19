#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

const int MAX = 2000000;

void countingSort(vector<int> array, int n, vector<int> sorted, int k) {
    int c[100000];

    for(int i = 0; i < k; i++) {
        c[k] = 0;
    }

    for(int i = 0; i < n; i++) {
        c[array[i]]++;
    }

    for(int i = 1; i <= k; i++) {
        c[i] += c[i-1];
    }

    for(int i = 0; i < n; i++) {
        sorted[c[array[i]]-1] = array[i];
        c[array[i]]--;
    }

    for(int i = 0; i < n; i++) {
        if( i ) {
            printf(" ");
        }
        printf("%d", sorted[i]);
    }
    printf("\n");
}

int main() {
    int n;
    vector<int> array;
    vector<int> sorted;
    scanf("%d", &n);

    int k = 0;
    int val;
    for(int i = 0; i < n; i++) {
        scanf("%d", &val);
        array.push_back(val);
        sorted.push_back(0);
        if( i ) {
            if(k < val) {
                k = val;
            }
        } else {
            k = array[i];
        }
    }

    countingSort(array, n, sorted, k);
        
    
    return 0;
}
