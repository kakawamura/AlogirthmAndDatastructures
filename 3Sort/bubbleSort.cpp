#include <iostream>
#include <algorithm>


using namespace std;

const int MAX = 100000;

int main() {
    int n;
    int a[MAX];
    int numOfSwaps = 0;

    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    bool flag = 1;
    for(int i = 0; flag; i++) {
        flag = 0;
        for(int j = 0; j < n-1-i; j++) {
            if(a[j] > a[j+1]) { // when all the elements are sorted the flag won't go up
                swap(a[j], a[j+1]);
                flag = 1; 
                numOfSwaps++;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
    cout << endl;
    cout << numOfSwaps << endl;

    return 0;
}
