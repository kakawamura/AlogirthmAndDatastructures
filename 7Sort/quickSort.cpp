#include <iostream>
#include <stdio.h>

using namespace std;

int n;

struct Card {
    char suit;
    int value;
};

int partition(Card array[], int p, int r) {
    int partitionPoint = array[r].value;
    
    int partitionIndex = p;
    for(int i = p; i < r; i++) {
        if(array[i].value <= partitionPoint) {
            swap(array[i], array[partitionIndex]);
            partitionIndex++;
        }
    }
    swap(array[partitionIndex], array[r]);

    return partitionIndex;
}

void quickSort(Card array[], int p, int r) {
    if(p < r) {
        int q = partition(array, p, r);

        quickSort(array, p, q-1);
        quickSort(array, q+1, r);
    }
}

void print(Card array[]) {
    for(int i = 0; i < n; i++) {
        printf("%c %d\n",array[i].suit, array[i].value);
    }
}

void merge(struct Card array[], int left, int mid, int right) {
    int leftMaxIndex = mid - left;
    int rightMaxIndex = right - mid;

    struct Card leftArray[50002];
    struct Card rightArray[50002];

    //create left Array
    for(int i = 0; i < leftMaxIndex; i++) {
        leftArray[i] = array[left + i];
    }
    leftArray[leftMaxIndex].value = 1000000000; //sentinel

    //create right Array
    for(int i = 0; i < rightMaxIndex; i++) {
        rightArray[i] = array[mid + i];
    }
    rightArray[rightMaxIndex].value = 1000000000; //sentinel

    //merge the two array
    int leftPointer = 0, rightPointer = 0;
    for(int i = left; i < right; i++) {
        if(leftArray[leftPointer].value <= rightArray[rightPointer].value) {
            array[i] = leftArray[leftPointer++];
        } else {
            array[i] = rightArray[rightPointer++];
        }
    } 
}

void mergeSort(struct Card array[], int left, int right) {
    if(left + 1 < right) {
        int mid = (right + left) / 2;

        mergeSort(array, left, mid);
        mergeSort(array, mid, right);
        merge(array, left, mid, right);
    }
}

int main() {
    Card mergeArray[100000], quickArray[100000];
    int v;
    char s[10];
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%s", s);
        scanf("%d", &v);
        mergeArray[i].suit = quickArray[i].suit = s[0];
        mergeArray[i].value = quickArray[i].value = v;
    }


    mergeSort(mergeArray, 0, n);
    quickSort(quickArray, 0, n-1);

    bool isStable = 1;
    for(int i = 0; i < n; i++) {
        if(mergeArray[i].suit != quickArray[i].suit) {
            isStable = 0;
            break;
        }
    }

    if(isStable) {
        printf("Stable\n");
    } else {
        printf("Not stable\n");
    }

    print(quickArray);

    return 0;
}
