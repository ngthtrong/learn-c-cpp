#include <iostream>
#include <vector>
using namespace std;

/* Khai báo CTDL Graph*/
#define MAX_N 100
typedef struct {
    int n, m;
    vector<int> adj[MAX_N];
} Graph;


//Biến hỗ trợ dùng để lưu trạng thái của đỉnh: đã duyệt/chưa duyệt
int mark[MAX_N];

void DFS(Graph &G, int u) {
	//1. Đánh dấu u đã duyệt
	printf(" %d", u);  //Làm gì đó trên u
	mark[u] = 1; 	    //Đánh dấu nó đã duyệt

	//2. Xét các đỉnh kề của u
	for (int i = 0; i < G.adj[u].size(); i++) {
	    int v = G.adj[u][i];
	    
		if (mark[v] == 0) {	//Nếu v chưa duyệt
		    
			DFS(G, v);      //gọi đệ quy duyệt nó
		}
		
	}
}

int main() {
	//1. Khai báo đồ thị G
	Graph G;
	//2. Đọc dữ liệu và dựng đồ thị
	int n, m, u, v;
	cin >> n >> m;
    G.n = n;
    G.m = m;
	for (int e = 0; e < m; e++) {
	    cin >> u >> v;
	    G.adj[u].push_back(v);
	    G.adj[v].push_back(u);
	}

	//3. Khởi tạo mảng mark[u] = 0, với mọi u = 1, 2, ..., n
	for (int u = 1; u <= G.n; u++) {
		mark[u] = 0;
	}

	//4. Duyệt toàn bộ đồ thị
	int index =1;
	for (int u = 1; u <= G.n; u++)
    if (mark[u] == 0) {
            cout<<"#"<<index++<<":";
			DFS(G, u);
			cout<<"\n";
		}
	
    return 0;
}

