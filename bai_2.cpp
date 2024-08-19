#include <iostream>
#include <algorithm>
using namespace std;

struct item
{
    int kl;
    int giatri;
    double ti_le;
};

bool cmp(item a, item b){
    return a.ti_le > b.ti_le;
}
double tui_phan_so(int n, int m, item a[]){
    sort(a, a+n, cmp);
    for(int i=0;i<n;i++){
        cout << a[i].kl <<" "<<a[i].giatri<<endl;
    }
    int tong_kl = 0;
    double gt_bd = 0.0;
    for(int i = 0; i < n && tong_kl < m; i++){
        while(a[i].kl + tong_kl <= m){
            tong_kl += a[i].kl;
            gt_bd += a[i].giatri;
            cout << gt_bd << " ";
        } 
        if(a[i].kl + tong_kl > m) {
            int con_lai = m - tong_kl;
            gt_bd += a[i].ti_le * con_lai;
            tong_kl += con_lai;   
        }
    }
    return gt_bd;
}
int main() {
    int m, n;
    cout << "khoi luong cua tui la: ";
    cin >> m;
    cout << "Nhap so do vat: ";
    cin >> n;
    item a[n];
    for(int i = 0;i<n;i++){
        cout << "Nhap khoi luong cua vat " <<(i+1)<<": ";
        cin >> a[i].kl;
        cout << "Nhap gia tri cua vat " <<(i+1)<<": ";
        cin >> a[i].giatri;
        a[i].ti_le = (double)a[i].giatri / a[i].kl;
    }
    int max_value = tui_phan_so(n, m, a);
    cout << "\nGia tri lon nhat cua tui: " << max_value << endl;
    return 0;
}