#include <bits/stdc++.h>
using namespace std;


double divide(double x, double y) {
    if(abs(y) < 1e-9) return -1.0;
    if(abs(x) < 1e-9) return 0.00000;
    double left = 0.0, right = (double)ULLONG_MAX;
    double mid ;
    while(abs(right-left) >= 0.0001) {
        mid = left + (right - left)/2;
        if(mid * y <= x) {
            left = mid;
        } else {
            right = mid;
        }
    }
    return mid;
}