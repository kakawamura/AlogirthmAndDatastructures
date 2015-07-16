#include <iostream>

using namespace std;

int main() {
    int n;
    int input[10000];

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }

    int maxv = input[1] - input[0];
    int minv = input[0];

    for(int i = 1; i < n; i++) {
        maxv = max(maxv, input[i] - minv);
        minv = min(minv, input[i]);
    }

    cout << maxv << endl;
        
    return 0;
}
