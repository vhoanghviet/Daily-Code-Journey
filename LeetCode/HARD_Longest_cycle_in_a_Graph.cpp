#include <bits/stdc++.h>
using namespace std;
// 2360(Hard) Longest Cycle in a Graph
        vector<int> ke[(int)1e5 + 1];
        vector<int> t_ke[(int)1e5 + 1];
        bool visited[(int)1e5 + 1];
        stack<int> st;
        int dem = 0, longest = -1;
    void DFS(int u) {
        visited[u] = true;
        for(int v : ke[u]) {
            if(!visited[v]) {
                DFS(v);
            }
        }
        st.push(u);
    }
    void DFS2(int u) {
        // -------------------------------------------------------------------------------
        dem++;
        // -------------------------------------------------------------------------------
        visited[u] = true;
        for(int v : t_ke[u]) {
            if(!visited[v]) {
                DFS2(v);
            }
        }
    }
    int longestCycle(vector<int>& edges) {
        longest = -1;
        while(!st.empty()) st.pop();
        for(int i = 0; i < (int)edges.size(); i++) {
            ke[i].clear();
            t_ke[i].clear();
            visited[i] = false;
        }
        for(int i = 0; i < (int)edges.size(); i++) {
            int x = i;
            int y = edges[i];
            // cout << x << " "<< y << endl;
            if(y != -1) ke[x].push_back(y);
            if(y != -1) t_ke[y].push_back(x);
        }
        memset(visited, false, sizeof(visited));
        for(int i = 0; i < (int)edges.size(); i++) {
            if(!visited[i]) {
                DFS(i);
            }
        }
        memset(visited, false, sizeof(visited));
        while(!st.empty()) {
            int top = st.top(); st.pop();
            if(!visited[top]) {
                // -------------------------------------------------------------------------------
                dem = 0; // Cập nhật biến đếm = 0
                DFS2(top); // Mỗi lần đệ quy DFS2(y) dem++
                if(longest < dem && dem > 1) longest = dem; // Lưu độ dài tplt mạnh dài nhất, tplt mạnh >1 
                // -------------------------------------------------------------------------------
            }
        }
        return longest;
    }

    int main() {
        ios_base::sync_with_stdio(false); cin.tie(NULL);
        int n;
        cin >> n;
        vector<int> edges;
        for(int i = 0 ; i < n ; i++) {
            int x ; cin >> x;
            edges.push_back(x);
        }
        cout << longestCycle(edges);
    }