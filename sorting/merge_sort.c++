#include<bits/stdc++.h>

using namespace std;

void printArr(vector<int> arr) {
	cout << "Arr: ";
	for (int i:arr) cout << i << " ";
	cout << endl;
}

void merge(vector<int> &left, vector<int> &right, vector<int> &arr) {
	int i = 0, j = 0, k = 0;
	while (i < left.size() and j < right.size()) {
		if (left[i] < right[j]) {
			arr[k] = left[i];
			i ++;
		} else {
			arr[k] = right[j];
			j ++;
		}
		k ++;
	}
	while (i < left.size()) {
		arr[k] = left[i];
		i ++;
		k ++;
	}
	while (j < right.size()) {
		arr[k] = right[j];
		j ++;
		k ++;
	}
}

void mergeSort(vector<int> &arr) {
	int n = arr.size();
	if (n <= 1) {
		return;
	}
	int mid = n/2;
	vector<int> left(mid);
	vector<int> right(n-mid);
	int j = 0;
	for (int i = 0; i < n; i ++) {
		if (i < mid) left[i] = arr[i];
		else {
			right[j] = arr[i];
			j ++;
		}
	}
	mergeSort(left);
	mergeSort(right);
	merge(left, right, arr);
}

vector<int> sortArr(vector<int> arr) {
	mergeSort(arr);
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
