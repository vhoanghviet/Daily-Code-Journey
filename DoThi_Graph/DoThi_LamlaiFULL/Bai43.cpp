#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Cấu trúc lưu trạng thái trong hàng đợi BFS
struct State {
    int r, c; // Tọa độ dòng (row) và cột (column)
};

int n, m;
char grid[505][505];
int min_turns[505][505]; // Lưu số lần đổi hướng nhỏ nhất để đến ô (r, c)

// 4 hướng di chuyển tương ứng: Lên, Phải, Xuống, Trái
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void solve() {
    cin >> n >> m;
    int start_r = -1, start_c = -1;
    int target_r = -1, target_c = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'S') {
                start_r = i;
                start_c = j;
            } else if (grid[i][j] == 'T') {
                target_r = i;
                target_c = j;
            }
            min_turns[i][j] = 1e9; // Khởi tạo số lần bẻ lái ban đầu là vô cùng
        }
    }

    queue<State> q;
    
    // Xuất phát tại S, số lần đổi hướng ban đầu là -1.
    // Tại sao là -1? Vì khi từ S phóng tia đi hướng đầu tiên, ta tăng turns lên thành 0.
    // (Như tụi mình đã bàn, hướng đầu tiên xuất phát hoàn toàn miễn phí, tính là 0 lần bẻ lái).
    min_turns[start_r][start_c] = -1; 
    q.push({start_r, start_c});

    while (!q.empty()) {
        State curr = q.front();
        q.pop();

        int curr_turn = min_turns[curr.r][curr.c];

        // Nếu số lần đổi hướng hiện tại đã bằng 2 rồi, thì tia phóng tiếp theo sẽ tốn 3 lần bẻ lái -> Phạm luật, bỏ qua không phóng nữa
        if (curr_turn >= 2) continue;

        // Phóng tia theo 4 hướng vuông góc
        for (int i = 0; i < 4; i++) {
            int nr = curr.r + dr[i];
            int nc = curr.c + dc[i];

            // Dùng vòng lặp while để tia đi thẳng liên tục theo hướng i
            while (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] != '*') {
                
                // Đi thẳng thì số lần bẻ lái của các ô trên tia này = (số lần bẻ lái của ô gốc + 1)
                int next_turn = curr_turn + 1;

                // Nếu tìm được cách đến ô (nr, nc) với số lần bẻ lái ít hơn trước đó
                if (next_turn < min_turns[nr][nc]) {
                    min_turns[nr][nc] = next_turn;
                    
                    // Nếu đã chạm tới đích T và hợp lệ thì kết thúc luôn cho nhanh
                    if (nr == target_r && nc == target_c) {
                        cout << "YES\n";
                        return;
                    }

                    // Đẩy vào queue để từ ô này lại tiếp tục phóng các tia vuông góc khác
                    q.push({nr, nc});
                }
                
                // Tiếp tục đi thẳng theo hướng cũ
                nr += dr[i];
                nc += dc[i];
            }
        }
    }

    // Nếu chạy hết BFS mà không cập nhật được đích T <= 2 lần bẻ lái
    if (min_turns[target_r][target_c] <= 2) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    // Tối ưu tốc độ nhập xuất để không bị sấp mặt vì Time Limit Exceeded (TLE)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    
    return 0;
}