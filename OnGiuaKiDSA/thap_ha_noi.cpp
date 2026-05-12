#include <bits/stdc++.h>
#include <string>
using namespace std;

void thap_ha_noi(int n, char a, char b, char c, int disk_num) {
    if(n == 1) {
        cout << "Move disk " << disk_num << 
        " from " << a << " to " << c << endl;
    }
    else {
        thap_ha_noi(n-1,a,c,b, n-1);
        thap_ha_noi(1,a,b,c, n);
        thap_ha_noi(n-1,b,a,c, n-1);
    }  
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    thap_ha_noi(n, 'A', 'B', 'C', n);

    return 0;
}