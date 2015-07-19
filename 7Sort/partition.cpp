#include <iostream>
#include <stdio.h>

using namespace std;

int partition(int array[], int p, int r) {
    int partitionPoint = array[r];
    
    int partitionIndex = p;
    for(int i = p; i < r; i++) {
        if(array[i] <= partitionPoint) {
            swap(array[i], array[partitionIndex]);
            partitionIndex++;
        }
    }
    swap(array[partitionIndex], array[r]);

    return partitionIndex;
}

int main() {
    int n;
    int array[100000];
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    int partitionIndex = partition(array, 0, n-1);
    

    for(int i = 0; i < n; i++) {
        if( i ) {
            printf(" ");
        }
        if(partitionIndex == i) {
            printf("[");
            printf("%d", array[i]);
            printf("]");
        } else {
            printf("%d", array[i]);
        }
    }
    printf("\n");

    return 0;
}
