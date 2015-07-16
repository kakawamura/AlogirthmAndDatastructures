#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    stack<int> s;
    stack< pair<int, int> > areas;
    string inputs;
    cin >> inputs;

    int xAxis = 0;
    double totalArea = 0; 
    for(string::iterator it = inputs.begin(); it != inputs.end(); ++it) {
        xAxis++;
        if((*it) == '\\') {
            s.push(xAxis);
        } else if((*it) == '/') {
            if(!s.empty()) {
                int length = xAxis - s.top() + 1;
                int tmp = (length + (length - 2)) * 0.5;
                totalArea += tmp;
                int puddle = tmp;
                while(!areas.empty() && areas.top().first > s.top()) {
                    puddle += areas.top().second;
                    areas.pop();
                }

                areas.push(make_pair(s.top(), puddle));
                s.pop();
                }
        }
    }
    
    printf("%d\n", (int)totalArea);
    printf("%d", (int)areas.size());

    vector<int> ans;

    while(!areas.empty()) {
        ans.push_back(areas.top().second);
        areas.pop();
    }
    reverse(ans.begin(), ans.end());

    for(int i = 0; i < ans.size(); i++) {
        printf(" %d", ans[i]);
    }
    printf("\n");

    return 0;
}
