#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

int n, k;
int w[100000];

int solve(int p) {
    int weight = 0;
    int numOfLoads = 0;
    for(int i = 0; i < k; i++){
        weight = 0;
        while(weight + w[numOfLoads] <= p) {
            weight += w[numOfLoads];
            if(numOfLoads == n) {
                return n;
            }
            numOfLoads++;
        }
    }

    return numOfLoads;
}

void binarySearch() {
    long long left = 0;
    long long right = 1000000 * 10000;
    while(right - left > 1) {
        long long mid =(right + left) / 2;
        int v = solve(mid);
        if(v >= n) {
            right = mid;
        } else {
            left = mid;
        }
    }

    cout << right << endl;
}

int main() {

    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
    }
    
    binarySearch();

    return 0;
}
