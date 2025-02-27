#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
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
#define NOT_SURE    0                   // Chưa chắc chắn
#define SURE        1                   // Chắc chắn
#define oo          999999999           // Xem như vô cùng

int mark[MAX_N];                        // Trạng thái đánh dấu của các đỉnh
int d[MAX_N];                           // Chiều dài đường đi ngắn nhất

//Bước 3: Cài đặt Dijkstra tìm đường đi ngắn nhất từ đỉnh s
void Moore_Dijkstra(Graph *pG, int s) {
    // Đánh dấu tất cả các đỉnh đều NOT_SURE
    for (int v = 1; v <= pG->n; v++)                  
    mark[v]=NOT_SURE;                                 

    // Gán d[v] = oo với mọi v trong V
    for (int v = 1; v <= pG->n; v++)                  
    d[v] = oo;                                        

    // Gán d[s] = 0
     d[s] = 0;                                        
    
    set<Cell> T; //cây đỏ đen T dùng để lưu các cặp (d[u], u) với u NOT_SURE

    // Đưa cặp (d[s], s) vào T
    T.insert(make_pair(d[s], s));
    
    // Lặp n lần (mỗi lần chọn một đỉnh và đánh dấu nó là SURE)
    for (int it = 1; it <= pG->n; it++) {
        if (T.empty()) // Nếu T rỗng
            break;
    
        // Tìm đỉnh u NOT_SURE có d[u] nhỏ nhất
        int u;
        // Gán u = trường thứ hai (second) của phần tử đầu tiên trong S
                   u=(*T.begin()).second;                                       
        
        // Xoá phần tử đầu tiên (có d[u] bé nhất) của S
        T.erase(T.begin());                                  

        // Xét các đỉnh kề v của u và cập nhật d[v]
        for (int i = 0; i < pG->adj[u].size(); i++) {
            int v, w;
            // Gán v = đỉnh kề (second) thứ i của danh sách pG->adj[u]
            v=pG->adj[u][i].second;                                                              
            // Gán w = trọng số của cung (u, v) tương ứng (second)
            w=pG->adj[u][i].first;                                          
            
            // Nếu v NOT_SURE
            if (mark[v] == NOT_SURE                )
                // Nếu d[v] lớn hơn d[u] + edgeWeight(u, v)
                if (d[v] > d[u] + w            ) {
                    // Xoá giá trị cũ (d[v], v) trong T
                    T.erase(make_pair(d[v], v));                                   
                    
                    // Cập nhật giá trị mới d[v] = d[u] + edgeWeight(u, v)
                    d[v] = d[u] + w;                      
                    
                    // Thêm cặp giá trị mới (d[v], v) vào T
                    T.insert(make_pair(d[v], v));
                                                                      
                }
        }
        
        // Đánh dấu u là SURE
                                                          
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
        
        // Gán trọng số cung (u, v) là w <=> thêm cặp (w, v) vào adj[u]
        G.adj[u].push_back(make_pair(w, v));       

        // Gán weight(v, u) = w      (Giả sử G là đồ thị vô hướng)
        G.adj[v].push_back(make_pair(w, u));       
    }
    
    Moore_Dijkstra(&G, 1);
    
    for (int u = 1; u <= G.n; u++)
        cout << "d[" << u << "] = " << d[u] << endl;

    return 0;
}
