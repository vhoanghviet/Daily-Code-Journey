#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) {
        val = x;
        left = right = NULL;
    }
};

void spiralOrder(Node* root) {
    if(!root) return;
    queue<Node*> q;
    q.push(root);
    int level = 0;
    int do_reverse = 0;
    while(!q.empty()) {
        int size = q.size();
        vector<int> cur_level;
        while(size--) {
            Node* v = q.front(); q.pop();
            cur_level.push_back(v->val);
            if(v->left) q.push(v->left);
            if(v->right) q.push(v->right);
        }
        
        if(level == 0 || level == 1) {
            do_reverse = 0;
        } else if( level % 2 == 0 ) {
            do_reverse = 1;
        } else {
            do_reverse = 0;
        }
        level++;
        if(do_reverse == 1) reverse(cur_level.begin(), cur_level.end());
        for(int x : cur_level) cout << x << " ";
    }
}
    



int main() {
    // Tối ưu tốc độ nhập xuất
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; 
    if (!(cin >> n)) return 0;
    
    Node* root = NULL;
    map<int, Node*> mp; // Dùng map để quản lý các node theo giá trị của chúng

    while (n--) {
        int u, v; char c;
        cin >> u >> v >> c;

        // Nếu node cha u chưa tồn tại, tạo mới
        if (mp.find(u) == mp.end()) {
            mp[u] = new Node(u);
        }
        
        // Nếu node con v chưa tồn tại, tạo mới
        if (mp.find(v) == mp.end()) {
            mp[v] = new Node(v);
        }

        // Đặt root là node cha của cạnh đầu tiên xuất hiện
        if (root == NULL) {
            root = mp[u];
        }

        // Tiến hành nối cạnh dựa trên map trong O(1)
        if (c == 'L') {
            mp[u]->left = mp[v];
        } else {
            mp[u]->right = mp[v];
        }
    }

    //
    spiralOrder(root);


    return 0;
}