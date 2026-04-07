// 1092B: Team Forming

#include <iostream>
#include <vector>
using namespace std;

int getMax(vector<int> &a) {
    int m = a[0];
    for(int i = 1; i < a.size(); i++) {
        if(a[i] > m) m = a[i];
    }
    return m;
}

void countingSort(vector<int> &a, int exp) {
    int n = a.size();
    vector<int> output(n), count(10,0);

    for(int i = 0; i < n; i++) {
        int digit = (a[i]/exp) % 10;
        count[digit]++;
    }
    for(int i = 1; i < 10; i++) {
        count[i] += count[i-1];
    }
    for(int i = n-1; i >= 0; i--) {
        int digit = (a[i]/exp) % 10;
        output[count[digit] - 1] = a[i];
        count[digit]--;
    }
    a = output;
}

void radixSort(vector<int> &a) {
    int n = a.size();
    int m = getMax(a);
    for(int exp = 1; (m/exp) > 0; exp *= 10) {
        countingSort(a, exp);
    }
}

using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    radixSort(a);
    int sum = 0;
    for(int i = 0; i < n; i+=2) {
        int dif = a[i] - a[i+1];
        if(dif < 0) dif *= -1;
        sum += dif;
    }
    cout << sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}