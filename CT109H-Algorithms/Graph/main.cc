#include <stdio.h>
#include <iostream>
#include <vector>
#include <list>
using namespace std;

//Bước 1: Biểu diễn bằng phương pháp ma trận kề (adjacency matrix)
#define MAX_N 101           // Tối đa 100 đỉnh, đánh số đỉnh từ 1
struct Graph {              // Khai báo struct kiểu C++, không cần dùng typedef
    int n, m;               // n: số đỉnh, m: số cung
    vector<int> adj[MAX_N];  // adj[u]: danh sách các đỉnh kề của u
};

//Bước 2: Khai báo các hằng và biến hỗ trợ (biến toàn cục):
#define UNVISITED   0    // Chưa duyệt
#define IN_PROGRESS 1    // Đang duyệt
#define ALL_DONE    2    // Duyệt xong

int mark[MAX_N];         // Trạng thái của các đỉnh trong quá trình duyệt
int start_time[MAX_N];   // Thời điểm bắt đầu duyệt của các đỉnh
int finish_time[MAX_N];  // Thời điểm duyệt xong của các đỉnh

list<int> L;             // Lưu thứ tự topo của các đỉnh 


//Bước 3: Cài đặt DFS cho lần duyệt 1
int DFS1(Graph *pG, int w, int currentTime) {
    // Gán start time của w = current time
    start_time[w]=currentTime;                      
    currentTime++;                         // Tăng curent time
    // Đánh dấu w đang duyệt (Mark w as IN PROGRESS)
    mark[w]=1;
    
    // Lần lượt xét qua các đỉnh kề v của w
    for (int i = 0; i < pG->adj[w].size(); i++) {
        int v;
        // Gán v = phần tử thứ i của danh sách pG->adj[w]
        v = pG->adj[w][i];                 
        
        if ( mark[v]==0                     ) {                             // Nếu v chưa duyệt
            currentTime = DFS1(pG, v, currentTime);  // Gọi đệ quy duyệt v, trả về finish time của v
            currentTime++;
        }
    }
       
    // Gán finish time của w = current time
    finish_time[w]=currentTime;                
    
    // Đánh dâu w đã duyệt xong (Mark w as ALL DONE)
    mark[w]=2;                                     
    
    // Thêm w vào đầu danh sách L
    L.push_front(w);                             
    
    return currentTime;
}


//Bước 4: Cài đặt DFS cho lần duyệt 2, in các đỉnh trong quá trình duyệt
// Không cần lưu trữ thông tin về start and finish time
void DFS2(Graph *pG, int w) {
    // Đánh dấu w đang duyệt (Mark w as IN PROGRESS)
    mark[w]=1;                                      
    
    // In w ra màn hình, theo sau là một khoảng trắng.
    cout << w << " ";                                
    
    // Lần lượt xét qua các đỉnh kề v của w
    for (int i = 0; i < pG->adj[w].size(); i++) {
        int v;
        // Gán v = phần tử thứ i của danh sách pG->adj[w]
        v = pG->adj[w][i];                      

        if ( mark[v]==0                     ) {                             // Nếu v chưa duyệt
            DFS2(pG, v);                            // Gọi đệ quy duyệt v
        }
    }
       
    // Đánh dâu w đã duyệt xong (Mark w as ALL DONE)
    mark[w]=2;                                      
}


// Bước 4. Cài đặt SCC
void SCC(Graph* pG1) {

    //1. Duyệt lần 1 trên đồ thị pG1
    for (int u = 1; u <= pG1->n; u++)
        mark[u] = UNVISITED;

    L.clear();             // Làm rỗng danh sách L
    int currentTime = 0;
    for (int u = 1; u <= pG1->n; u++)
        if (mark[u] == UNVISITED) {
            currentTime = DFS1(pG1, u, currentTime);
            currentTime ++;
        }
        
    
    //2. Đảo ngược các cung của G1 => G2
    Graph G2;
    G2.n = pG1->n;
    G2.m = pG1->m;
    for (int u = 1; u <= pG1->n; u++)
        for (int i = 0; i < pG1->adj[u].size(); i++) {
            int v = pG1->adj[u][i];
            // Thêm cung (v, u) vào G2
            G2.adj[v].push_back(u);                      
        }
    
    
    //3. Duyệt lần 2 trên đồ thị G2
    for (int u = 1; u <= G2.n; u++)
        mark[u] = UNVISITED;

    int cnt = 0;
    list<int>::iterator it;
    //Duyệt lần 2 dựa trên thứ tự trong danh sách L
    for (it = L.begin(); it != L.end(); it++) {
        int u;
        // Gán u = phần tử tại vị trí it
        u = *it;

        if (mark[u] == UNVISITED) {
            cnt++;
            cout << "SCC[" << cnt << "] = ";
            DFS2(&G2, u); //Duyệt để in BPLT mạnh thứ cnt
            cout << endl;
        }
    }
    
    cout << "We found " << cnt << " SCC(s)." << endl;    
}


//Bước 4: Kiểm thử
int main() {
    Graph G1;
    
    cin >> G1.n >> G1.m;

    for (int e = 1; e <= G1.m; e++) {
        int u, v;
        cin >> u >> v;
        G1.adj[u].push_back(v);      // G là đồ thị có hướng
    }
    
    //Gọi SCC
    SCC(&G1);
    
    return 0;
}

