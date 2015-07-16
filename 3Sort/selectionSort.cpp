#include <iostream>

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
        int minj = i;
        for(int j = i; j < n; j++) {
            if(a[j] < a[minj]) {
                flag = 1;
                minj = j;
            }
        }
        if(minj != i) {
            numOfSwaps++;
        }
        swap(a[i], a[minj]);
    }

    for(int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }

    cout << endl;
    cout << numOfSwaps << endl;


    return 0;
}
