#include<iostream>
using namespace std;

long long giai_thua(int n) {
    if (n == 0) return 1;
    else return n * giai_thua(n - 1);
}

int main() {
    int n;
    cout << "Nhap so nguyen duong n: ";
    cin >> n;
    cout << "Giai thua cua " << n << " la: " << giai_thua(n) << endl;
    return 0;
}
// Max 25