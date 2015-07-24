#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX = 10000;
const int VMAX = 100000;

int main() {
    int n, a[MAX], b[MAX];
    int t[VMAX+1];
    bool isChecked[MAX];
    scanf("%d", &n);

    int aMin = VMAX;
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        b[i] = a[i];
        aMin = min(aMin, a[i]);
    }
    sort(b, b + n);

    for(int i = 0; i < n; i++) {
        isChecked[i] = false;
        t[b[i]] = i; // indexはiに行け
    }

    
    int ans = 0;
    //look cycles
    for(int i = 0; i < n; i++) {
        if(isChecked[i]) {
            continue;
        }
        int cur = i;
        int nInCycle = 0;
        int minInCycle = VMAX;
        int sum = 0;
        while(!isChecked[cur]) {
            isChecked[cur] = true;
            nInCycle++;
            int v = a[cur];
            minInCycle = min(v, minInCycle);
            sum += v;
            cur = t[v];
            if(isChecked[cur]) {
                break;
            }
        }
        ans += min(sum + (nInCycle - 2) * minInCycle, minInCycle + sum + (nInCycle + 1) * aMin);
    }

    printf("%d\n", ans);

    return 0;
}
