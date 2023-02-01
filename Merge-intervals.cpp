#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> res;
    int n = intervals.size();
    
    stack<pair<int,int>> st;
    sort(intervals.begin(),intervals.end());
    st.push({intervals[0][0], intervals[0][1]});
    for(int i=1;i<n;i++){

        if(st.top().second>=intervals[i][0]){
            st.top().second = max(st.top().second, intervals[i][1]);
        }
        else{
            st.push({intervals[i][0],intervals[i][1]});
        }
    }
    while(!st.empty()){
        pair<int,int> temp = st.top();
        st.pop();
        vector<int> ans;
        ans.push_back(temp.first);
        ans.push_back(temp.second);
        res.push_back(ans);
    }
    return res;
}

int main(){
    return 0;
}