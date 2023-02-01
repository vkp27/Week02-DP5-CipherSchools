#include<bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    vector<int> leftMin(n, -1);
    stack<int> st1;

    for(int i = 0; i < n; i++) {
        while (!st1.empty() && heights[i] <= heights[st1.top()]) {
            st1.pop();
        }

        if (!st1.empty()) {
            leftMin[i] = st1.top();
        }

        st1.push(i);
    }

    vector<int> rightMin(n, n);
    stack<int> st2;

    for(int i = n-1; i >= 0; i--) {
        while (!st2.empty() && heights[i] <= heights[st2.top()]) {
            st2.pop();
        }

        if (!st2.empty()) {
            rightMin[i] = st2.top();
        }

        st2.push(i);
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans = max(ans, heights[i] * (rightMin[i] - leftMin[i] - 1));
    }

    return ans;
}

int main(){
    return 0;
}