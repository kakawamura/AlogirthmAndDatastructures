#include <iostream>
#include <stdio.h>

using namespace std;

const int MAX = 200000;

long long ans = 0;

long long n, array[MAX];

void merge(int left, int mid, int right) {
    int leftMaxIndex = mid - left;
    int rightMaxIndex = right - mid;

    long long leftArray[500000];
    long long rightArray[500000];

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
        if(leftArray[leftPointer] <= rightArray[rightPointer]) {
            array[i] = leftArray[leftPointer++];
        } else {
            array[i] = rightArray[rightPointer++];
            ans += leftMaxIndex - leftPointer;
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
    scanf("%lld", &n);
    for(int i = 0; i < n; i++) {
        scanf("%lld", &array[i]);
    }

    mergeSort(0, n);
    printf("%lld\n", ans);

    return 0;
}

