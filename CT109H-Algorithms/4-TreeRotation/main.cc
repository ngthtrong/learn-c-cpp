#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Select(vector<int> A, int k) {
    // Nếu len(A) <= 10 thì sắp xếp A và trả về A[k-1]
    if ( A.size()<=10                   ) {
        sort(A.begin(), A.end());        //Sắp xếp vector A tăng dần
        return A[k-1]                        ;
    }

    // Chọn pivot, hãy viết mã để chọn pivot theo phương pháp "fancy pivot"
    int n = A.size();
    vector<int> B;
    for (int i = 0; i < n; i += 5) {
        int group_size = i + 5 <= n ? 5 : n - i;
        //Tìm phần tử trung vị của A[i], A[i+1], ..., A[i + group_size - 1] và đưa vào B
        //Sử dụng vector temp chứa các phần tử A[i], A[i+1], ..., A[i + group_size - 1]
        //Gọi hàm sort() để sắp xếp các phần tử của temp
        //Lấy phần tử chính giữa của temp, tức temp[len(temp)/2], đưa vào B
        int cnt = 0;
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < i*2; j++)
            {
                cnt++;
            }
            
        }
        
                                                          
                                                          
                                                          
                                                          
                                                          
                                                          
                                                          
    }
    // Gọi Select(B, len(B)/2) để tìm pivotVal
    int pivotVal =  Select(B, B.size()/2)        ;

    // Kiểm tra pivotVal
    cout << "pivot value = " << pivotVal << endl;

    // Phân hoạch A thành L, pivotVal và R
    vector<int> L, R;
    for (int i = 0; i < A.size(); i++) {
        if(A[i]<pivotVal)                                 
         L.push_back(A[i]);                               
        else if (A[i]>pivotVal)                           
        R.push_back(A[i]);                                
                                                          
    }

    if (k == L.size() + 1)      // k = len(L) + 1
        return pivotVal                      ;
        
    if (k < L.size() + 1)       // k < len(L) + 1
        return Select(L,k)                   ;

    return Select(R,k-L.size()-1)        ;              // k > len(L) + 1

}

//Bước 4: Kiểm thử
int main() {
    int n, k;
    vector<int> A;
    cin >> n >> k;
    A.resize(n);   //Thay đổi kích thước của A về n phần tử
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int ret = Select(A, k);
    cout << "Select(A, " << k << ") = " << ret << endl;
    
    return 0;
}
