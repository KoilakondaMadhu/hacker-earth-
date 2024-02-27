#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;  // Read the number of elements in the sequence
    vector<int> v(n);  // Create a vector to store the elements of the sequence
    for(int i=0;i<n;i++){
        cin >> v[i];  // Read each element of the sequence
    }
    vector<int> pref(n, -1);  // Create a vector to store the indices of the nearest smaller elements on the left side
    vector<int> suf(n, -1);   // Create a vector to store the indices of the nearest smaller elements on the right side
    stack<int> st;  // Create a stack to store indices of elements

    // Loop to find the nearest smaller element on the right side for each element
    for(int i=0;i<n;i++){
        if(st.empty()){
            st.push(i);
        }
        else{
            while(!st.empty() && v[st.top()] > v[i]){
                suf[st.top()] = i;  // Set the index of the nearest smaller element on the right side
                st.pop();
            }
            st.push(i);
        }
    }

    // Clear the stack for reuse
    while(!st.empty()) st.pop();

    // Loop to find the nearest smaller element on the left side for each element
    for(int i=n-1;i>=0;i--){
        if(st.empty()){
            st.push(i);
        }
        else{
            while(!st.empty() && v[st.top()] > v[i]){
                pref[st.top()] = i;  // Set the index of the nearest smaller element on the left side
                st.pop();
            }
            st.push(i);
        }
    }

    // Loop to print the differences between the indices of the nearest smaller elements
    for(int i=0;i<n;i++){
        if(pref[i] == -1 || suf[i] == -1) cout << "-1";  // If no smaller element found on one side, print -1
        else {
            cout << (suf[i] - pref[i] - 2);  // Print the difference between indices of nearest smaller elements
        }
        if(i < n-1) cout << " ";  // Print space between elements
    }
    cout << endl;  // Print newline after each test case
}

int main(){
    int t;
    cin >> t;  // Read the number of test cases
    while(t--){
        solve();  // Call the solve function for each test case
    }
}
