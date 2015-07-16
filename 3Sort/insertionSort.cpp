#include <iostream>

using namespace std;

const int MAX = 100000;

int main() {
    int n;
    int a[MAX];

    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < n; i++) {
        int tmp = a[i];
        int j = i - 1;

        while(j >= 0 && a[j] > tmp) {
            a[j+1] = a[j];
            j--;
        }

        a[j+1] = tmp;
        for(int i = 0; i < n; i++) {
            cout << a[i] << ' ';
        }
        cout << endl;
    }

    for(int i = 0; i < n; i++) {
        cout << a[i] << endl;
    }

    return 0;
}
