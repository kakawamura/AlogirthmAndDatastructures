#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

const int MAX = 1000001;
char H[MAX][14];

int getCharNumber(char c) {
    switch(c) {
        case 'A':
            return 1;
        case 'C':
            return 2;
        case 'G':
            return 3;
        case 'T':
            return 4;
        default:
            return 0;
    }
}

int getKey(char c[]) {
    int key = 0, p = 1;
    for(int i = 0; i < strlen(c); i++) {
        key += p*getCharNumber(c[i]);
        p *= 5; //位を一つ上げる
    }

    return key;
}

int doubleHash(int key, int type) {
    switch(type) {
        case 0:
            return key % MAX;
        case 1:
            return 1 + (key % (MAX-1));
        default:
            return 0;
    }
}


void insert(char c[]) {
    int key;
    for(long long i = 1; ; i++) {
        key = (doubleHash(getKey(c), 0) + i * doubleHash(getKey(c), 1)) % MAX;
        if(strlen(H[key]) == 0) {
            strcpy(H[key], c);
            break;
        } else if(strcmp(H[key], c) == 0) { // same?
            break;
        }
    }
}

bool find(char c[]) {
    int key;
    for(long long i = 1; ; i++) {
        key = (doubleHash(getKey(c), 0) + i * doubleHash(getKey(c), 1)) % MAX;
        if(strlen(H[key]) == 0) {// the hash hasn't been past -> couldn't be found
            return false;
        } else if(strcmp(H[key], c) == 0) { // same?
            return true;
        }
    }

    return false;
}

int main() {
    int n;
    scanf("%d", &n);

    char command[7], data[13];
    for(int i = 0; i < n; i++) {
        scanf("%s %s", command, data);
        if(strcmp(command, "insert") == 0) {
            insert(data);
        } else if(strcmp(command, "find") == 0) {
            if(find(data)) {
                printf("yes\n");
            } else {
                printf("no\n");
            }
        }
    }
    return 0;
}
