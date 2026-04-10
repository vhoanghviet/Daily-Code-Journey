#include <iostream>
#include <vector>
using ll = long long;
using namespace std;

const int HASH_SIZE = 19997; 
// CHọn một số nguyên tố lớn để tránh xung đột

struct Node {
    ll key;
    Node* pNext;
};

Node* hashTable[HASH_SIZE];
// Mảng này chứa các Head danh sách liên kết.

// Viết hàm băm
int get_hash(ll gia_tri_dau_vao) {
    return gia_tri_dau_vao % HASH_SIZE;
}
// Lưu vào mảng băm giá trị cho các Node từ 0 đến 19996.

void insert(ll gia_tri_dau_vao) {
    // Dựa vào quy tắc chaining
    int hash = get_hash(gia_tri_dau_vao);
    Node* newNode = new Node();
    newNode->key = gia_tri_dau_vao;
    newNode->pNext = hashTable[hash];
    // Khởi tạo newNode với key là Giá trị đầu vào, vào head vị trí hash 
    // Của mảng băm
    hashTable[hash] = newNode; 
    // Thêm newNode vào head của mảng băm
}
// Hàm tìm kiếm -> Duyệt từ head tại vị trí hash của mảng hash table
bool exists(ll gia_tri_dau_vao) {
    
    int hash = get_hash(gia_tri_dau_vao);
    Node* curr = hashTable[hash];
    while(curr != NULL) {
        if(curr->key == gia_tri_dau_vao) return true;
        curr = curr->pNext;
    }
    return false;
}

void solve() {
    
    ll x;
    cin >> x;
    for(ll a = 1; a*a*a < x; a++) {
        ll b_to_the_power_of_3 = x - a*a*a;
        // Kiểm tra nếu tồn tại b mũ 3 sao cho a mũ 3 + b mũ 3 bằng x
        if(exists(b_to_the_power_of_3)) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i = 0 ; i < HASH_SIZE; i++) hashTable[i] = nullptr;
    // reset mảng băm
    for(ll i = 0; i <= 10000; i++) {
        insert(i*i*i);
    // Thêm vào 10000 node có giá trị x_3 sẵn
    }
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}