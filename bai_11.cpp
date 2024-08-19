#include <iostream>
#include <algorithm>
using namespace std;
struct Item {
  int kl;
  int giatri;
};
bool sosanh(Item a, Item b) {
  return (a.giatri / a.kl) > (b.giatri / b.kl);
}
int knapsack(int w, Item items[], int n) {
// sắp xếp giá trị giảm dần
  sort(items, items + n, sosanh);
  int gt_bd = 0;
  int tong_kl = 0;
  for(int i=0;i<n;i++){
    cout << items[i].kl <<" "<<items[i].giatri<<endl;
  }
  for (int i = 0; i < n; i++) {
    while (tong_kl + items[i].kl <= w) {
    tong_kl += items[i].kl;
	  gt_bd += items[i].giatri;
    cout << gt_bd <<" ";
    }
 }
 return gt_bd;
}
int main() {
  int w, n;
  cout << "khoi luong cua tui la: ";
  cin >> w;
  cout << "Nhap so do vat: ";
  cin >> n;
  Item items[n];
  for(int i = 0; i < n; i++){
    cout << "Nhap khoi luong cua vat " <<(i+1)<<": ";
    cin >> items[i].kl;
    cout << "Nhap gia tri cua vat " <<(i+1)<<": ";
    cin >> items[i].giatri;
  }
  int max_value = knapsack(w, items, n);
  cout << "\nGia tri lon nhat cua tui: " << max_value << endl;
  return 0;
}