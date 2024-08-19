#include<iostream>
using namespace std;
void demxu(int a[], int n, int m) {
	int x=0, i=0, dem;
	int s=m;
	for(int j=0;j<n;j++){
		dem=s/a[j];
		s=s%a[j];
		cout << "\nSo dong xu thu "<<(j+1)<<": "<<dem;
	}
	cout <<"\n";
	do
	{
		if (m>=a[i])
		{
			m -= a[i];
			x++;
			cout <<m<<" ";
		}else{
			i++;
			}
	} while (m>=0 && i<n);
	cout << "\nSo tien con lai la: " << m;
	 cout << "\nTong so dong xu la: "<< x;
}
int main(){
	int n, m;
	cout << "Nhap so loai tien: ";
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i){
		cout << "Nhap vao menh gia thu " << (i+1) << ": ";
		cin >> a[i];
	}
	cout << "Nhap tong so tien: ";
	cin >> m;
	demxu(a,n,m);
	return 0;
}