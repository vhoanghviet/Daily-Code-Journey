#include <bits/stdc++.h>
#include <string>
using namespace std;
void merge(vector<string> &Merge, vector<int> &B, vector<int> &C, int n, int m) {
    int k = 0;
    int i = 0;
    int j = 0;
    while(i < n && j < m) {
        if(B[i] < C[j]) {
            i++;
            Merge[k++] += "b" + to_string(i);
        } else {
            j++;
            Merge[k++] += "c" + to_string(j);
        }
    }
    while(i < n) {
        i++;
        Merge[k++] += "b" + to_string(i);
    }
    while(j < m) {
        j++;
        Merge[k++] += "c" + to_string(j);
    }
}

void init(vector<string> &Merge, int size) {
    for(int i = 0 ; i < size; i++) {
        Merge[i] = "";
    }
}
void printstr(vector<string> &Merge, int size) {
    for(int i = 0 ; i < size; i++) {
        cout << Merge[i] << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,m;
    cin >> n >> m;
    vector<int> B(n);
    vector<int> C(m);
    for(int i = 0; i < n ; i++) cin >> B[i];
    for(int i = 0; i < m ; i++) cin >> C[i];
    
    vector<string> Merge(n+m, "");
    merge(Merge, B, C, n, m);
    printstr(Merge, n+m);
    return 0;
}