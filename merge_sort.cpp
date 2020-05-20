#include <bits/stdc++.h>

using namespace std; 

void merge(vector < int > &arr, int low, int high)
{
	
	int mid = low + (high - low) / 2;
	int i = low;
	int j = mid + 1;

	vector < int > vec;

	while (i <= mid && j <= high) {
		if (arr[i] <= arr[j]) {
			vec.push_back(arr[i]);
			i++;
		} else {
			vec.push_back(arr[j]);
			j++;
		}
	}

	while (i <= mid) {
		vec.push_back(arr[i]);
		i++;
	}

	while (j <= high) {
		vec.push_back(arr[j]);
		j++;
	}
	
	for (int i = 0,j = low; i < vec.size(); i++, j++) {
		arr[j] = vec[i];
	}
	
}

void merge_sort(vector < int > &arr, int low, int high)
{
	if (low >= high) {
		return;
	}

	int mid = low + (high - low) / 2;

	merge_sort(arr, low, mid);
	merge_sort(arr, mid + 1, high);
	merge(arr, low, high);
}

int main()
{
	int n;
	cin>>n;
	vector < int > arr(n);
	for (int i = 0; i < n; i++) {
		cin>>arr[i];
	}
	
	merge_sort(arr, 0, arr.size() - 1);

	cout<<"output after sorting"<<endl;

	for (int i = 0; i < arr.size(); i++) {
		cout<<arr[i]<<" ";
	}
	
	return 0;
}
