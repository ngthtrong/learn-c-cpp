# Learn C/C++

Đây là nơi lưu trữ mã nguồn C/C++ cho các môn học tại Đại học Cần Thơ.

## 📚 Các môn học

### ✅ Hoàn thành
- **CT177H** - Data Structure (Cấu trúc dữ liệu) 
- **CT109H** - Algorithms (Phân tích, thiết kế thuật toán)
- **CT175H** - Graph Theory (Lý thuyết đồ thị)

### 🔄 Đang học
- **CT287H** - Model Checking (Kiểm chứng mô hình)

## 📁 Cấu trúc dự án

```
learn-c-cpp/
├── CT177H-DataStructure/          # Cấu trúc dữ liệu
│   ├── 0-RelearnC/               # Ôn tập C cơ bản
│   ├── 1-ListArray/              # Danh sách mảng
│   ├── 2-LinkedList/             # Danh sách liên kết
│   ├── 3-Stack/                  # Ngăn xếp
│   ├── 4-Queue/                  # Hàng đợi
│   ├── 5-Practice/               # Bài tập thực hành
│   ├── 6-BST/                    # Cây tìm kiếm nhị phân
│   ├── 7-TreeAVL/                # Cây AVL
│   ├── 8-Sort&Search/            # Sắp xếp và tìm kiếm
│   └── 9-Hash/                   # Bảng băm
├── CT109H-Algorithms/             # Thuật toán
│   ├── 0-final/                  # Đề thi cuối kỳ
│   ├── 1-Lecture1/               # Bài giảng 1 (Chia để trị)
│   ├── 2-Lecture2/               # Bài giảng 2 (Sắp xếp)
│   ├── 3-Sort/                   # Thuật toán sắp xếp
│   ├── 4-TreeRotation/           # Xoay cây
│   ├── 10-a/                     # Bellman-Ford
│   └── Graph/                    # Thuật toán đồ thị
├── CT175H-GraphTheory/            # Lý thuyết đồ thị
│   ├── DFS/                      # Duyệt theo chiều sâu
│   ├── lib/                      # Thư viện
│   ├── w3/                       # Tuần 3 - Đồ thị có hướng
│   ├── w5 - traversal/           # Tuần 5 - Duyệt đồ thị
│   ├── w6 & 7 - shortest path/   # Tuần 6-7 - Đường đi ngắn nhất
│   ├── w8 - topo/                # Tuần 8 - Sắp xếp topo
│   ├── w9 - tree/                # Tuần 9 - Cây khung tối thiểu
│   └── w11 - flow/               # Tuần 11 - Luồng cực đại
└── CT287H-ModelChecking/          # Kiểm chứng mô hình
    ├── 

```

## 🚀 Cách chạy code

### Windows (PowerShell/CMD)

**Biên dịch và chạy file C:**
```bash
gcc temp.c -o temp.exe
.\temp.exe
```

**Biên dịch và chạy file C++:**
```bash
g++ file.cpp -o file.exe
.\file.exe
```

**Sử dụng task có sẵn trong VS Code:**
- Nhấn `Ctrl+Shift+P`
- Chọn `Tasks: Run Task`
- Chọn `C/C++: gcc.exe build active file`

### Linux/macOS

```bash
gcc file.c -o file
./file
```

## 🛠️ Môi trường phát triển

- **IDE:** Visual Studio Code
- **Compiler:** GCC (MSYS2)
- **OS:** Windows
- **Extensions:** C/C++ Extension Pack

## 📝 Ghi chú

- Mỗi thư mục chứa các file bài tập và ví dụ của từng chủ đề
- File `temp.c` dùng để test code nhanh
- Các file build được lưu trong thư mục `build/` tương ứng
