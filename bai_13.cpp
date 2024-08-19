#include<bits/stdc++.h>
using namespace std;

void tim_day_con(int arr[], int n, int sum, vector<int> &vec, int i) {
    if (sum == 0) {
        for (auto x : vec)
            cout << x << " ";
        cout << endl;
        return;
    }
    if (i == n)
        return;
    if (arr[i] <= sum) {
        vec.push_back(arr[i]); //them p/tu arr[i] vao cuoi vecto vec
        tim_day_con(arr, n, sum - arr[i], vec, i + 1);
        vec.pop_back(); // loai bo p/tu cuoi cung cua vecto vec
    }
    tim_day_con(arr, n, sum, vec, i + 1);
}

int main() {
    int n, sum;
    vector<int> vec;
    cout << "Nhap so phan tu cua day: ";
    cin >> n;
    int arr[n];
    for( int i; i < n; i++){
        cout << "Phan tu thu "<<(i+1)<< ": ";
        cin >> arr[i];
    }
    cout << "Nhap tong cho truoc: ";
    cin >> sum;
    tim_day_con(arr, n, sum, vec, 0);
    return 0;
}