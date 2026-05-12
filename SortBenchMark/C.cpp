#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<string> strs(n);
    for(int i = 0; i < n; i++) cin >> strs[i];
    
    const int MAXLEN = 100;
    vector<vector<int>> byLen(MAXLEN + 1);
    for(int i = 0; i < n; i++) byLen[strs[i].size()].push_back(i);
    
    vector<string> result;
    result.reserve(n);
    
    for(int len = 10; len <= MAXLEN; len++){
        vector<int>& bucket = byLen[len];
        if(bucket.empty()) continue;
        int m = bucket.size();
        
        vector<int> temp(m);
        int cnt[27];
        
        for(int pos = len - 1; pos >= 0; pos--){
            memset(cnt, 0, sizeof(cnt));
            for(int i = 0; i < m; i++) cnt[(unsigned char)strs[bucket[i]][pos] - 'a' + 1]++;
            for(int c = 1; c <= 26; c++) cnt[c] += cnt[c-1];
            for(int i = 0; i < m; i++) temp[cnt[(unsigned char)strs[bucket[i]][pos] - 'a']++] = bucket[i];
            for(int i = 0; i < m; i++) bucket[i] = temp[i];
        }
        
        for(int i = 0; i < m; i++) result.push_back(strs[bucket[i]]);
    }
    
    cout << n << '\n';
    for(auto& s : result) cout << s << '\n';
    return 0;
}