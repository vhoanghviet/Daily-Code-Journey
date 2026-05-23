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
int getHeight(Node* root) {
    if(!root) return 0;
    return max(getHeight(root->left), getHeight(root->right)) + 1;
}

bool leavesAreSameLevel(Node* root) {
    if(!root) return true;
    queue<Node*> q;
    q.push(root);
    int h = 0;
    int leaf_level = -1;
    while(!q.empty()) {
        int size = q.size();
        h++;
        while(size--) {
            Node* v = q.front(); q.pop();
            if(!v->left && !v->right) {
                if(leaf_level == -1) {
                    leaf_level = h;
                } else if(leaf_level != h) return false;
            }
            if(v->left) q.push(v->left);
            if(v->right) q.push(v->right);
        }
        
    }
    return true;
        
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
    if(leavesAreSameLevel(root)) cout << "YES\n"; 
    else cout << "NO\n";


    return 0;
}