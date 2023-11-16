#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 1e3 + 14;
int n, m, a[N][N], mx[N];

int main() {
    // Input the number of rows (n) and columns (m)
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;

    // Input the elements of the 2D array 'a' and compute the maximum value in each column
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            mx[j] = max(mx[j], a[i][j]);
        }

    // Create a vector of tuples to store information about each row
    vector<tuple<int, ll, int>> v;

    // Process each row to calculate the number of elements equal to the maximum value in their columns,
    // the sum of elements in the row, and the row index
    for (int i = 0; i < n; ++i) {
        int s = 0;
        for (int j = 0; j < m; ++j)
            s += a[i][j] == mx[j];
        v.emplace_back(s, accumulate(a[i], a[i] + m, 0ll), i);
    }

    // Find the tuple with the maximum value of the first element ('s') and print the corresponding row index
    cout << std::get<2>(*max_element(v.begin(), v.end())) + 1 << '\n';
}



// Problem
// James visits a restaurant, looks at the menu, and realizes that there is no price on it. Since he wanted to know the prices before he orders, he looked up the restaurant online and found 
//  different versions of the menu. He knew from experience that usually the menu which has the maximum number of items that have the maximum price on that item between the menus is the most updated one and if there are multiple menus with that condition the one with the maximum average price is the most updated one. Help him find the most updated menu.

// In other words, a price on an item is good if it is the maximum price on that item among all menus, and a menu is the most updated one if it has the maximum number of good prices on it.
// If there are multiple menus with the maximum number of good prices, the menu with the higher price average is the most updated one.

// Input format

// The first line contains integers 
//  and 
//  that denote the number of menus and the number of items on each menu respectively.
// The next 
//  line each contains 
//  integers represented as 
// , the 
//  price on the 
//  menu.
// Output format

// Print a single number denoting the number of the most updated menu.

// It is guaranteed that the answer is unique.

// Constraints

// Sample Input
// 3 4
// 1 2 1 10
// 3 2 3 4
// 1 3 3 2
// Sample Output
// 2
// Time Limit: 1
// Memory Limit: 256
// Source Limit:
// Explanation
// There are 4 items in this example. The maximum price for the first three items is 3 and for the last item is 10.

// First menu has only one good price which is the last one, Second menu has 2 good prices on it, which are first and third items and the last menu, has 2 good prices too.

// Se between second and third menus, we have to compare averages. Average of second menu is 
//  and average of third menu is 
// , so the second menu would be the answer.
