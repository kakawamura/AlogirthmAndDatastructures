//ラウンドロビンスケジューリング Round Robin Scheduling
#include <cstdio>
#include <iostream>
#include <string>
#include <queue>

using namespace std;

queue<string> name;
queue<int> processTime;

int main() {
    int n, qms;
    cin >> n >> qms;
    
    string na;
    int t;
    for(int i = 0; i < n; i++) {
        cin >> na >> t;
        :name.push(na);
        processTime.push(t);
    }

    int totalTime = 0;
    while(name.size() != 0) {
        string tmpName = name.front();
        int tmpTime = processTime.front() - qms;
        name.pop();
        processTime.pop();

        if(tmpTime > 0) {
            totalTime += qms;
            name.push(tmpName);
            processTime.push(tmpTime);
        } else { // if process has finished
            totalTime += qms + tmpTime;
            cout << tmpName << ' ' << totalTime << endl;
        }
    }
}
