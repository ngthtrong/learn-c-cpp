#include <stdio.h>
#include <iostream>
using namespace std;

//Bước 1: Biểu diễn bằng phương pháp ma trận trọng số (adjacency matrix)
#define NO_EDGE -1        // Không có cung giữa hai đỉnh
#define MAX_N 101         // Tối đa 100 đỉnh, đánh số đỉnh từ 1
struct Graph {            // Khai báo struct kiểu C++, không cần dùng typedef
    int n, m;             // n: số đỉnh, m: số cung
    int W[MAX_N][MAX_N];  // Ma trận trọng số: W[u][v] == edge weight (u, v)
};

//Bước 2: Khai báo các hằng và biến hỗ trợ (biến toàn cục):
#define UNREACHED    0                  // Chưa đến
#define REACHED      1                  // Đã đến
#define oo          999999999           // Xem như vô cùng

int mark[MAX_N];                        // Trạng thái đánh dấu của các đỉnh
int k[MAX_N];                           // Khoảng cách đến cây MST hiện tại
int p[MAX_N];                           // p[u]: đỉnh cha của u (đỉnh trong cây MST gần với u nhất)

//Bước 3: Cài đặt thuật toán Prim tìm cây khung nhỏ nhất từ đỉnh s
void Prim(Graph *pG, int s, Graph *pMST) {
    // Đánh dấu tất cả các đỉnh đều UNREACHED
    for(int i =0; i< MAX_N; i++)                      
    mark[i]=0;                                        

    // Gán k[v] = oo với mọi v trong V
    for(int i =0; i< MAX_N; i++)                      
    k[i] = oo;                                        

    // Gán k[s] = 0
    k[s] = 0;                                         
    
    
    pMST->n = pG->n;     // Đỉnh của cây là đỉnh của đồ thị G
    pMST->m = pG->n - 1; // Cây có số cung bằng số dỉnh - 1
    
    // Khởi tạo cây pMST rỗng bằng cách cho ma trận trọng số chứa toàn giá trị NO_EDGE;
    for(int i = 0; i <MAX_N; i++)                     
        for(int j =0;  j<MAX_N; j++)                  
           pMST->W[i][j] = NO_EDGE;                   
                                                      
    

    // Lặp n lần (mỗi lần chọn một đỉnh và đánh dấu nó là REACHED)
    for (int it = 1; it <= pG->n; it++) {
        // Tìm đỉnh u UNREACHED có k[u] nhỏ nhất
        int u = -1;
        int min_k = oo;
        for (int v = 1; v <= pG->n; v++)
            // Nếu v UNREACHED
            if ( mark[v]==UNREACHED             )
                if (k[v] < min_k) {
                    //Gán min_k = k[v]
                    min_k = k[v];                                     
                    
                    u = v; // Cho u = v
                }
        
        if (u == -1) //Không tìm được u
            break;
            
        // Xét các đỉnh kề v của u và cập nhật k[v]
        for (int v = 1; v <= pG->n; v++)
            // Nếu u kề với v và v UNREACHED
            if ( mark[v]==UNREACHED && pG->W[u][v]!=NO_EDGE         )
                // Nếu k[v] lớn hơn edgeWeight(u, v)
                if ( k[v]>pG->W[u][v]               ) {
                    //Cập nhật k[v] = edgeWeight(u, v)
                    k[v]=pG->W[u][v];                                 

                    //Cập nhật p[v]
                    p[v] = u;                                         
                }

        // Đánh dấu u là REACHED
        mark[u]=REACHED;                                  
        
        // Nếu u khác s, thêm cung (p[u], u, k[u]) vào pMST
        if ( u!=s                 ) {
            pMST->W[p[u]][u]=k[u];                            
            pMST->W[u][p[u]]=k[u];                            
        }
    }
}


//Bước 4: Kiểm thử
int main() {
    Graph G;
    
    cin >> G.n >> G.m;
    for (int u = 1; u <= G.n; u++)
        for (int v = 1; v <= G.n; v++)
            // Gán weight(u, v) = NO_EDGE
            G.W[u][v] = NO_EDGE;                              
    
    
    //Đọc các cung và thêm vào đồ thị
    for (int e = 1; e <= G.m; e++) {
        int u, v, w;
        cin >> u >> v >> w;
        
        // Gán trọng số cung (u, v) là w
         G.W[u][v] = w;                                   

        // Gán weight(v, u) = w      (Giả sử G là đồ thị vô hướng)
         G.W[v][u] = w;                                   
    }
    
    Graph MST;
    Prim(&G, 1, &MST);
    
    int total_weight = 0;
    for (int u = 1; u <= G.n; u++) {
        cout << "k[" << u << "] = " << k[u] << endl;
        total_weight += k[u];
    }
    
    cout << "Total weight = " << total_weight << endl;

    cout << "Weight matrix of MST:" << endl;
    for (int u = 1; u <= MST.n; u++) {
        for (int v = 1; v <= MST.n; v++)
            cout << MST.W[u][v] << ' ';
        cout << endl;
    }

    return 0;
}
