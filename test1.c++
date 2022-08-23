// Generate all subset of an array and print it.

#include <bits/stdc++.h>

using namespace std;

void printArray(int *arr, int a, int b) {
	for (int i = a; i <= b; i ++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {
	int arr[] = {1, 5, 2, 4, 3};
	int n = sizeof(arr)/sizeof(int);
	for (int i = 0; i < n; i ++) {
		for (int j = i; j < n; j ++) {
			printArray(arr, i, j);
		}
	}
}

