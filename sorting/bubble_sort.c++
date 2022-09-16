#include<bits/stdc++.h>

using namespace std;

void printArr(vector<int> arr) {
	cout << "Arr: ";
	for (int i:arr) cout << i << " ";
	cout << endl;
}

vector<int> sortArr(vector<int> arr) {
	int n = arr.size();
	for (int i = n-1; i > 0; i --) {
		for (int j = 0; j < i; j ++) {
			if (arr[j] > arr[j+1]) {
				swap(arr[j], arr[j+1]);
			}
		}
	}
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
