#include <iostream>
using namespace std;

int knapsack(int w, int n, int weights[], int values[]) {
    int dp[n+1][w+1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= w; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (weights[i-1] <= j)
                    dp[i][j] = max(values[i-1] + dp[i-1][j-weights[i-1]], dp[i-1][j]);
                else
                    dp[i][j] = dp[i-1][j];
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= w; j++) {
            cout << dp[i][j] <<" ";
        }
        cout << endl;
    }
    return dp[n][w];
}
int main() {
    int w, n;
    cout << "khoi luong cua tui la: ";
    cin >> w;
    cout << "Nhap so do vat: ";
    cin >> n;
    int weights[n], values[n];
    for(int i = 0;i<n;i++){
        cout << "Nhap khoi luong cua vat " <<(i+1)<<": ";
        cin >> weights[i];
        cout << "Nhap gia tri cua vat " <<(i+1)<<": ";
        cin >> values[i];
    }
    int max_value = knapsack(w, n, weights, values);
    cout << "Gia tri lon nhat tui co the chua: " << max_value << endl;
    return 0;
}
