#include <iostream>
#include <algorithm>
using namespace std;
struct hoat_dong 
{
    int id;
    int start;
    int finish;
};
bool cmp(hoat_dong a, hoat_dong b){
    return a.finish < b.finish;
}
void xep_lich(int n, hoat_dong a[]){
    sort(a, a + n, cmp);
    int b = 0;
    for(int i = 0; i < n; i++){
       if( b < a[i].start){
            b = a[i].finish;
            cout << a[i].id << " ";
       }
       
    }
}
int main() {
    int n;
    cout << "Nhap so hoat dong: ";
    cin >> n;
    hoat_dong a[n];
    for(int i = 0; i < n; i++){
        cout << "Nhap id hoat dong thu " <<(i+1)<<": ";
        cin >> a[i].id;
        cout << "Nhap thoi gian bat dau hoat dong thu " <<(i+1)<<": ";
        cin >> a[i].start;
         cout << "Nhap thoi gian ket thuc hoat dong thu " <<(i+1)<<": ";
        cin >> a[i].finish;
    }
    xep_lich(n, a);
    
    return 0;
}
        