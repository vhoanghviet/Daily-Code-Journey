#include <bits/stdc++.h>
using namespace std;


double divide(double x, double y) {
    if(abs(y) < 1e-9) return -1.0;
    if(abs(x) < 1e-9) return 0;
    double low = 0, high = (double)ULLONG_MAX;

    double precision = 0.0001;
    while(high - low > precision) {
        double mid = low + (high - low)/2;
        if(mid * y <= x) { // Mid <= x/y
            low = mid; // Nhích trỏ low lên
        } else { // Mid > x/y
            high = mid; // Lùi trỏ high xuống
        }
    }
    return low;
}







int main() {
    return 0;
}