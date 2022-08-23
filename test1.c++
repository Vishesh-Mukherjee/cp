// Generate all subset of an array and print it.
//
// Consider an array:
// {1, 2, 3, 4}
// Subarray: Contiguous sequence in an array i.e.
// {1, 2}, {1, 2, 3}
// Subsequence: Need not to be contiguous, but maintains order i.e.
// {1, 2, 4}
// Subset: Same as subsequence except it has empty set i.e.
// {1, 3}, {}
//
// Given an array/sequence of size n, possible:
// Subarray = n*(n+1)/2
// Subsequence = (2^n)-1 (non-empty subsequeces)
// Subset = 2^n

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
	int count = 0;
	for (int i = 0; i < n; i ++) {
		for (int j = i; j < n; j ++) {
			printArray(arr, i, j);
			count ++;
		}
	}
	cout << "Subarray count: " << count << endl;
}

