#include <bits/stdc++.h>

using namespace std;

int binary_search(vector<int> array, int target){
	int left = 0;
	int right = array.size() - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (array[mid] == target)
		{
			return mid;
		}
		else if (array[mid] > target)
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	return -1;
}

int main(){
    int n, x, k;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++){
        cin >> x;
        v.push_back(x);
    }
    cin >> k;
    if(binary_search(v, k) != -1) cout << "Yes";
    else cout << "No";
}