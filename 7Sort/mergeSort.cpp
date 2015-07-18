#include <iostream>
#include <stdio.h>

using namespace std;
int array[500000];
int n;
int counter = 0;

void merge(int left, int mid, int right) {
    int leftMaxIndex = mid - left;
    int rightMaxIndex = right - mid;

    int leftArray[500000];
    int rightArray[500000];

    //create left Array
    for(int i = 0; i < leftMaxIndex; i++) {
        leftArray[i] = array[left + i];
    }
    leftArray[leftMaxIndex] = 1000000000; //sentinel

    //create right Array
    for(int i = 0; i < rightMaxIndex; i++) {
        rightArray[i] = array[mid + i];
    }
    rightArray[rightMaxIndex] = 1000000000; //sentinel

    //merge the two array
    int leftPointer = 0, rightPointer = 0;
    for(int i = left; i < right; i++) {
        counter++;
        if(leftArray[leftPointer] >= rightArray[rightPointer]) {
            array[i] = rightArray[rightPointer];
            rightPointer++;
        } else {
            array[i] = leftArray[leftPointer];
            leftPointer++;
        }
    } 
}

void mergeSort(int left, int right) {
    if(left + 1 < right) {
        int mid = (right + left) / 2;

        mergeSort(left, mid);
        mergeSort(mid, right);
        merge(left, mid, right);

    }
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    mergeSort(0, n);
        
    printf("%d", array[0]);
    for(int i = 1; i < n; i++) {
        printf(" %d", array[i]);
    }
    printf("\n%d\n", counter);
    
    return 0;
}
