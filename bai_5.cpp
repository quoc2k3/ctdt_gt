#include <iostream>
using namespace std;

int countPartitions(int n) {
    int dp[100] = {0};
    dp[0] = 1;
    //vòng lặp i duyệt từ 1 -> n đại diện cho các số nguyên dương cần phân tích
    for (int i = 1; i <= n; i++) {
    //vòng lặp bên trong (vòng lặp j) duyệt qua các giá trị từ i đến n, đại diện cho các tổng có thể tạo thành bằng cách thêm số i vào các tổng đã có trước đó.
        for (int j = i; j <= n; j++) {
            dp[j] += dp[j - i];// số cách phân tích tổng j sẽ bằng tổng số cách phân tích tổng j - i (đã tính toán trước đó) và số cách phân tích số i.
        }
    }
    return dp[n];//số cách phân tích số n thành tổng các số nguyên dương.
}
int main() {
    int n;
    cout << "Nhap so n: ";
    cin >> n;
    int result = countPartitions(n);
    cout << "So cach phan tich cua so " << n << " la: " << result << endl;
    return 0;
}