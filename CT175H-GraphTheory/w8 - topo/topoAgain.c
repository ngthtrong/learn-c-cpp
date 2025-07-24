#include <stdio.h>
#define MAX_N 50
//Khai báo cấu trúc đồ thị
typedef struct{
    int A[100][100]; //ma trận kề đỉnh - đỉnh
    int n;  //số lượng đỉnh
} Graph;

//Khai báo cấu trúc dữ liệu danh sách List
typedef struct {
    int size;
    int elements[MAX_N];
} List;

void make_null_list(List *pL) {
    pL->size = 0;
}

void push_back(List *pL, int x) {
    pL->elements[pL->size++] = x;
}

int element_at(List *pL, int i) {
    if(pL->size > 0)
        return pL->elements[i-1];
    return -1;
}

void copy_list(List *L1, List *L2) {
    make_null_list(L1);
    L1->size = L2->size;

    for (int i = 0; i < L1->size; ++i)
        L1->elements[i] = L2->elements[i];
}

typedef struct {
    int data[100];
    int front, rear;
} Queue;

/* Khởi tạo hàng đợi rỗng */
void make_null_queue(Queue *pQ) {
    pQ->front = 0;
    pQ->rear = -1;
}

/* Đưa phần tử u vào cuối hàng đợi */
void enqueue(Queue *pQ, int u) {
    pQ->rear++;
    pQ->data[pQ->rear] = u;
}

/* Xem phần tử đầu hàng đợi */
int front(Queue *pQ) {
    return pQ->data[pQ->front];
}
/* Xoá bỏ phần bỏ đầu hàng đợi */
void dequeue(Queue *pQ) {
    pQ->front++;
}
/* Kiểm tra hàng đợi rỗng */
int empty_queue(Queue *pQ) {
    return pQ->front > pQ->rear;
}

//Cài đặt hàm void SapXepToPo(Graph *G, List *pL)
void SapXepToPo(Graph *G, List *pL) {
    // Tính bậc vào cho mỗi đỉnh
    int in_degree[MAX_N + 1];
    for (int i = 1; i <= G->n; i++) {
        in_degree[i] = 0;
    }
    
    for (int u = 1; u <= G->n; u++) {
        for (int v = 1; v <= G->n; v++) {
            if (G->A[u][v] == 1) {
                in_degree[v]++;
            }
        }
    }
    
    // Khởi tạo hàng đợi với các đỉnh có bậc vào = 0
    Queue Q;
    make_null_queue(&Q);
    
    for (int u = 1; u <= G->n; u++) {
        if (in_degree[u] == 0) {
            enqueue(&Q, u);
        }
    }
    
    // Khởi tạo danh sách kết quả
    make_null_list(pL);
    
    // Sắp xếp topo sử dụng BFS
    while (!empty_queue(&Q)) {
        int u = front(&Q);
        dequeue(&Q);
        push_back(pL, u);
        
        for (int v = 1; v <= G->n; v++) {
            if (G->A[u][v] == 1) {
                in_degree[v]--;
                if (in_degree[v] == 0) {
                    enqueue(&Q, v);
                }
            }
        }
    }
}

//Hàm nhập đồ thị vào từ bàn phím
int NhapDuLieu(Graph* G ){ //
    int c, d, m, x, y;
    scanf("%d%d", &G->n, &m);
    for (d=1; d<=G->n; d++)
        for (c=1; c<=G->n; c++)
            G->A[d][c] = 0;
    
    for (c = 0; c < m; c++){
        scanf("%d%d", &x, &y);   
        G->A[x][y] = 1;
    }
    return 1;   
} //hết hàm NhapDuLieu()

//Hàm in kết quả ra màn hình void InKetQua( Graph* G, List *pL)
//pL danh sách các đỉnh được sắp xếp.
void InKetQua(Graph* G, List *pL) {
    int answer = 9; // Đáp án đầu tiên là 9
    
    for (int i = 0; i < pL->size; i++) {
        int puzzle = pL->elements[i];
        
        // In ra số câu đố và đáp án của nó
        printf("%d %d\n", puzzle, answer);
        
        // Cập nhật đáp án cho câu đố tiếp theo
        answer += 45;
    }
}
//hết hàm InKetQua()
    
int main(){
    Graph G;
    List L;
    NhapDuLieu(&G);
    SapXepToPo(&G, &L);
    InKetQua(&G, &L);
    return 0;
}