#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100
#define OO 999999

// Cấu trúc để lưu trữ đồ thị
typedef struct {
    int n, m;
    int A[MAX_N][MAX_N];
} Graph;

// Khởi tạo đồ thị
void init_graph(Graph* G, int n) {
    G->n = n;
    G->m = 0;
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            G->A[i][j] = OO;
        }
    }
}

// Thêm cung vào đồ thị
void add_edge(Graph* G, int u, int v, int w) {
    G->A[u][v] = w;
    G->A[v][u] = w;
}

// Cấu trúc để lưu một cạnh của cây khung
typedef struct {
    int u, v, w;
} Edge;

// Hàm so sánh cho qsort để sắp xếp các cạnh
int compare_edges(const void* a, const void* b) {
    Edge* e1 = (Edge*)a;
    Edge* e2 = (Edge*)b;
    if (e1->u != e2->u) {
        return e1->u - e2->u;
    }
    return e1->v - e2->v;
}

// Thuật toán Prim
void prim(Graph* G) {
    int pi[MAX_N];    // pi[v] = đỉnh cha của v trong cây khung
    int d[MAX_N];     // d[v] = trọng số nhỏ nhất để kết nối v vào cây
    int mark[MAX_N];  // mark[v] = 1 nếu v đã thuộc cây, 0 nếu chưa
    int n = G->n;
    int i, j;

    // Khởi tạo
    for (i = 1; i <= n; i++) {
        pi[i] = -1;
        d[i] = OO;
        mark[i] = 0;
    }

    d[1] = 0; // Bắt đầu từ đỉnh 1

    // Vòng lặp chính của Prim
    for (i = 1; i <= n; i++) {
        int u = -1, min_d = OO;
        // Tìm đỉnh u chưa thuộc cây có d[u] nhỏ nhất
        for (j = 1; j <= n; j++) {
            if (!mark[j] && d[j] < min_d) {
                min_d = d[j];
                u = j;
            }
        }

        if (u == -1) break; // Đồ thị không liên thông

        mark[u] = 1; // Đánh dấu u đã thuộc cây

        // Cập nhật d và pi cho các đỉnh kề với u
        for (int v = 1; v <= n; v++) {
            if (!mark[v] && G->A[u][v] < d[v]) {
                d[v] = G->A[u][v];
                pi[v] = u;
            }
        }
    }

    // Tính tổng trọng số và xây dựng danh sách cạnh của cây khung
    long long sum_w = 0;
    Edge mst[MAX_N];
    int mst_count = 0;

    for (i = 1; i <= n; i++) {
        if (pi[i] != -1) {
            sum_w += d[i];
            int u = pi[i];
            int v = i;
            // Đảm bảo u < v để sắp xếp
            if (u > v) {
                int temp = u;
                u = v;
                v = temp;
            }
            mst[mst_count].u = u;
            mst[mst_count].v = v;
            mst[mst_count].w = G->A[pi[i]][i];
            mst_count++;
        }
    }

    // Sắp xếp các cạnh của cây khung
    qsort(mst, mst_count, sizeof(Edge), compare_edges);

    // In kết quả
    printf("%lld\n", sum_w);
    for (i = 0; i < mst_count; i++) {
        printf("%d %d %d\n", mst[i].u, mst[i].v, mst[i].w);
    }
}

int main() {
    Graph G;
    int n, m, i;
    scanf("%d%d", &n, &m);
    init_graph(&G, n);

    for (i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        add_edge(&G, u, v, w);
    }

    prim(&G);

    return 0;
}
