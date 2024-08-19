#include<iostream>
using namespace std;

long long giai_thua[100];

void dynamicFactorial(int n) {
    giai_thua[0] = 1;
    for(int i = 1; i <= n; i++) {
        giai_thua[i] = i * giai_thua[i - 1];
    }
}

int main() {
    int n;
    cout << "Nhap so nguyen duong n: ";
    cin >> n;
    dynamicFactorial(n);
    cout << "Giai thua cua " << n << " la: " << giai_thua[n] << endl;
    return 0;
}