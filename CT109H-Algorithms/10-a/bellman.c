#include <stdio.h>
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

//Bước 1: Biểu diễn bằng phương pháp dánh sách các đỉnh kề (adjacency list)
//Sử dụng n danh sách adj[]
//Với mỗi cung u --w--> v, ta lưu (v, w) vào danh sách adj[u]
typedef pair<int, int> Cell; // phần tử đầu tiên (first) lưu trọng số w
                             // phần tử thứ hai (second) lưu đỉnh kề  v

#define MAX_N 101               // Tối đa 100 đỉnh, đánh số đỉnh từ 1
struct Graph {                  // Khai báo struct kiểu C++, không cần dùng typedef
    int n, m;                   // n: số đỉnh, m: số cung
    vector<Cell> adj[MAX_N];    // danh sách adj[u] lưu các cặp (w1, v1), (w2, v2), ...
};                              // u --w1--> v1
                                //  \--w2--> v2

//Bước 2: Khai báo các hằng và biến hỗ trợ (biến toàn cục):
#define oo          999999999           // Xem như vô cùng

int mark[MAX_N];                        // Trạng thái đánh dấu của các đỉnh
int d[MAX_N];                           // Chiều dài đường đi ngắn nhất

//Bước 3: Cài đặt thuật toán Bellman-Ford tìm đường đi ngắn nhất từ đỉnh s
void Bellman_Ford(Graph *pG, int s) {
    // Gán d[v] = oo với mọi v trong V
    for(int i = 0; i<MAX_N; i++)                      
    d[i]=oo;                                          

    // Gán d[s] = 0
    d[s] = 0;                                         

    // Lặp n-1 lần từ 0 đến n - 2
    for (int it = 0; it <= pG->n - 2; it++) {
        // Duyệt qua tất cả các đỉnh u
        for (int u = 1; u <= pG->n; u++) {
            
            // Xét các đỉnh kề v của u và cập nhật d[v]
            for (int i = 0; i < pG->adj[u].size(); i++) {
                int v, w;
                // Gán (w, v) = phần tử thứ i của danh sách pG->adj[u]
                w=pG->adj[u][i].first();                          
                v=pG->adj[u][i].second();                         

                // Nếu d[v] lớn hơn d[u] + edgeWeight(u, v), chú ý d[u] phải khác vô cùng
                if ( d[v]>d[u]+pG->adj[u][i].first()&&d[u]!=oo          )
                    //Cập nhật d[v] = d[u] + edgeWeight(u, v)
                    d[v]=d[u]+pG->adj[u][i].first()                   
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
        int u, v, w;
        cin >> u >> v >> w;
        
        // Gán trọng số cung (u, v) là w
        G.adj[u][v]={w,v};                                

    }
    
    Bellman_Ford(&G, 1);
    
    for (int u = 1; u <= G.n; u++)
        cout << "d[" << u << "] = " << d[u] << endl;

    return 0;
}
