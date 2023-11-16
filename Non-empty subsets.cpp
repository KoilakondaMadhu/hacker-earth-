#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 2e5 + 14;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int mn = INT_MAX;
		for (int i = 0; i < n; ++i) {
			int x;
			cin >> x;
			mn = min(mn, x);
		}
		cout << mn << '\n';
	}
}



// You are given an array 
//  consisting of 
//  non-negative integers. Find out the minimum number 
//  such that there exists a non-empty subset of 
//  for which the bitwise OR of all its elements is equal to 
// .

// Input format

// The first line contains an integer 
//  (
// ) denoting the number of test cases.
// The first line of each test case contains an integer 
//  denoting the number of elements in array 
// .
// The second line of each test case contains 
//  space-separated integers of array 
// .
// Note: It is guaranteed that sum of 
//  over all test cases is less than or equal to 
// .

// Output format

// For each test case, print a line containing the minimum possible value of 
// .

// Constraints




