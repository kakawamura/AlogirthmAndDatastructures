//逆ボーランド記法 Reverse Polish Notation RPN
#include <iostream>
#include <stack>

using namespace std;

stack<int> s;

int calculate(char c) {
    int a, b;
    switch(c) {
        case '+':
            a = s.top();
            s.pop();
            b = s.top();
            s.pop();
            return a + b;
            break;
        case '-':
            a = s.top();
            s.pop();
            b = s.top();
            s.pop();
            return b - a;
            break;
        case '/':
            a = s.top();
            s.pop();
            b = s.top();
            s.pop();
            return b / a;
            break;
        case '*':
            a = s.top();
            s.pop();
            b = s.top();
            s.pop();
            return a * b;
            break;
        default:
            return (int)c - '0';
            break;
    }
}

int main() {
    char tmp;
    while((tmp = cin.get()) != '\n') {
        s.push(calculate(tmp));
        tmp = cin.get();
        if(tmp == '\n') {
            break;
        }
    }

    cout << s.top() << endl;

    return 0;
}
