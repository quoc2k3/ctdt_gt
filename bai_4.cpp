#include <iostream>
#include <algorithm>

using namespace std;

int day_chung(int n, int m, int a[], int b[]){
    int F[n+1][m+1];
    for(int i = 0; i <= n; i++){
        for(int j = 0 ; j <= m; j++){
            if(i == 0 || j == 0){
                F[i][j] = 0;
            } else if(a[i - 1] == b[j - 1]){
                F[i][j] = F[i - 1][j - 1] + 1;
            }
            else {
                F[i][j] = max(F[i][j - 1], F[i - 1][j]);
            }
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            cout << F[i][j] <<" ";
        }
        cout << endl;
    }
    int i = n, j = m;
    string c = "";
    while(F[i][j] != 0){
        if(a[i - 1] == b[j - 1]){
            c += to_string(a[i - 1]);
            c += " ";
            i--;
            j--;
        }
        else if(F[i - 1][j] > F[i][j - 1]){
            i--;
        } else{
            j--;
        }
    }
    reverse(c.begin(), c.end());
    cout << "\nChuoi con: ";
    cout << c;
    return F[n][m];
}

int main() {
    int n, m;
    cout << "Nhap do dai day thu 1: ";
    cin >> n;
    cout << "Nhap do dai day thu 2: ";
    cin >> m;
    int a[n], b[m];
    for(int i = 0; i < n; i++){ 
        cout << "Nhap chuoi thu 1: ";
        cin >> a[i];
    }
    for(int j = 0; j < m; j++){
        cout << "Nhap chuoi thu 2: ";
        cin >> b[j];
    }
    cout << "Day thu 1 la: ";
        for(int i = 0; i < n; i++){ 
        cout << a[i] << " ";
    }
    cout << endl;
    cout << "Day thu 2 la: ";
        for(int j = 0; j < m; j++){
        cout << b[j] << " ";
    }
    cout << endl;
    int d = day_chung(n, m, a, b);
    cout << "\nDay con chung dai nhat la: " << d << endl;
    return 0;
}
