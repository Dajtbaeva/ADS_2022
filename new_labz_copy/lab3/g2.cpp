// minimum number of items to be delivered
// https://kbtuedu.sharepoint.com/sites/CodemodeADSFall2022/_layouts/15/stream.aspx?id=%2Fsites%2FCodemodeADSFall2022%2FShared%20Documents%2FG1%2FRecordings%2FG1%2D20220926%5F200001%2DMeeting%20Recordi     nmjnnnnnnnnnnnnnnnnnnnnnnnnnnnnjhjng%2Emp4

// Подход: Необходимо найти минимальное количество товаров для одной доставки. Итак, идея состоит в том, чтобы выполнить итерацию от 
// 1 до максимального значения элементов в корзине и вычислить количество туров, необходимых для каждой корзины, и найти общее количество 
// туров для полной доставки. Первое такое значение с турами, меньшими или равными K, дает требуемое число.

#include <iostream>
using namespace std;

int binary_search(int ar[], int size, int f) {
	int maxi = 0;
	for (int i = 0; i < size; i++) {
		maxi = max(maxi, ar[i]);
	}
	int left = 1, right = maxi + 1, mid;
	int ans = -1;
	while (left + 1 < right) {
		mid = left + (right - left) / 2;
		int req_f = 0;
		for (int i = 0; i < size; i++) {
			req_f += (ar[i] + mid - 1) / mid;
		}
		if (req_f <= f) {
			right = mid;
			ans = right;
		} else if (req_f > f) left = mid;
	}
	return ans;
}

int main() {
	int n, k;
	cin >> n >> k;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << binary_search(a, n, k);
}
