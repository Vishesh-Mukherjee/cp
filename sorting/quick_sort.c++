#include<bits/stdc++.h>

using namespace std;

void printArr(vector<int> arr) {
	cout << "Arr: ";
	for (int i:arr) cout << i << " ";
	cout << endl;
}

int partition(vector<int> &arr, int left, int right) {
	int pivot = arr[right];
	int j = left;
	for (int i = left; i <= right; i ++) {
		if (arr[i] <= pivot) {
			swap(arr[i], arr[j]);
			j ++;
		}
	}
	return j-1;
}

void quick_sort(vector<int> &arr, int left, int right) {
	if (left >= right) return;
	int pivot = partition(arr, left, right);
	quick_sort(arr, left, pivot-1);
	quick_sort(arr, pivot+1, right);
}

vector<int> sortArr(vector<int> arr) {
	int n = arr.size();
	quick_sort(arr, 0, arr.size()-1);
	return arr;
}

bool test(vector<int> arr) {
	vector<int> sortByUser = sortArr(arr);
	sort(arr.begin(), arr.end());	
	for (int i = 0; i < arr.size(); i ++) if (sortByUser[i] != arr[i]) return false;
	return true;
}

void testCases(vector<vector<int>> matrix) {
	for (vector<int> arr: matrix) {
		if (test(arr)) cout << "True" << endl;
		else cout << "False" << endl;
	}
}	

int main() {
	testCases({{1, 5, 2, 4, 3}, {1, 2, 3, 4, 5}, {5, 4, 3, 2, 1}});
}
