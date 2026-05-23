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

// Hàm đếm số node lá (Giữ nguyên của bạn vì đã chuẩn)
int countLeaves(Node* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    return countLeaves(root->left) + countLeaves(root->right);
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

    // Duyệt và in kết quả số lượng node lá
    cout << countLeaves(root) << "\n";

    return 0;
}