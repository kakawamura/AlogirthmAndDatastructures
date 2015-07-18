#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

struct Point {
    double x, y;
};

void koch(int n, Point a,Point b){
    if(n == 0) {
        return;
    }

    Point s, t, u;
    double th = M_PI * 60.0 / 180.0;
    s.x = a.x + ((b.x - a.x) / 3.0);
    s.y = a.y + ((b.y - a.y) / 3.0);

    t.x = a.x + (((b.x - a.x) / 3.0) * 2.0);
    t.y = a.y + (((b.y - a.y) / 3.0) * 2.0);

    //回転行列
    u.x = (t.x - s.x) * cos(th) - (t.y - s.y) * sin(th) + s.x;
    u.y = (t.x - s.x) * sin(th) + (t.y - s.y) * cos(th) + s.y;
    
    koch(n-1, a, s);
    printf("%.8f %.8f\n", s.x, s.y);

    koch(n-1, s, u);
    printf("%.8f %.8f\n", u.x, u.y);

    koch(n-1, u, t);
    printf("%.8f %.8f\n", t.x, t.y);

    koch(n-1, t, b);
}

int main() { 
    int n;
    scanf("%d", &n);

    Point a, b;
    a.x = 0;
    a.y = 0;
    b.x = 100;
    b.y = 0;

    printf("%.8f %.8f\n", a.x, a.y);
    koch(n, a, b);
    printf("%.8f %.8f\n", b.x, b.y);
    
    return 0;
}
