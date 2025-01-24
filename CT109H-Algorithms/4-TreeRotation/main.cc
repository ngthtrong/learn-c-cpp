
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//Bước 1: Biểu diễn bằng phương pháp danh sách các đỉnh kề (adjacency list)
#define MAX_N 101               // Tối đa 100 đỉnh, đánh số đỉnh từ 1
struct Graph {                  // Khai báo struct kiểu C++, không cần dùng typedef
    int n, m;                   // n: số đỉnh, m: số cung
    vector<int> adj[MAX_N];     // adj[u]: danh sách các đỉnh kề của đỉnh u
};

//Bước 2: Khai báo các hằng và biến hỗ trợ (biến toàn cục):
#define UNVISITED   0    // Chưa duyệt
#define VISITED     1    // Đã duyệt

int mark[MAX_N];         // Trạng thái của các đỉnh trong quá trình duyệt


//Bước 3: Cài đạt DFS
void BFS(Graph *pG, int w) {
    queue<int> Q;          // Khai báo hàng đợi
    mark[w] = VISITED;     // Đánh dấu w đã duyệt

    // Thêm w vào Q
    Q.push(w);                                        
    while ( !Q.empty()                     ) { //Trong khi Q chưa rỗng
        int u;
        //Gán u = phần tử đầu hàng đợi
        u = Q.front();                                    
        
        //Xoá bỏ phần tử đầu hàng đợi
        Q.pop();                                          

        for (int i = 0; i < pG->adj[u].size(); i++) {
            int v;
            // Gán v = phần tử thứ i của danh sách pG->adj[u]
            v = pG->adj[u][i];                                
            
            if ( mark[v]==UNVISITED             ) {         // Nếu v chưa duyệt
                // Đánh dấu v đã duyệt
                mark[v]=UNVISITED;                                
                            
                // Thêm v vào hàng đợi Q
                Q.push(v);                                        
            }
        }
    }
}

//Bước 4: Kiểm thử
int main() {
    Graph G;
    
    cin >> G.n >> G.m;
    
    //Đọc các cung và thêm vào đồ thị
    for (int e = 1; e <= G.m; e++) {
        int u, v;
        cin >> u >> v;
        G.adj[u].push_back(v);
        G.adj[v].push_back(u);    // Giả sử G là đồ thị vô hướng
    }
    
        
    // Gán tất cả các đỉnh đều chưa duyêt
    for (int u = 1; u <= G.n; u++)
        mark[u] = UNVISITED;
    
    //Gọi BFS nhiều lần để duyệt toàn bộ đồ thị
    int cnt = 0;
    for (int u = 1; u <= G.n; u++)
        if (mark[u] == UNVISITED) {
            BFS(&G, u);
            cnt++;      // Đếm số bộ phần liên thông
        }

    cout << "G has " << cnt << " connected component(s)" << endl;

    return 0;
}
