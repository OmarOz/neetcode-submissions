class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>>st;
        int ans=0;
        for(int i=0;i<heights.size();i++){
            int start=i;
            while(!st.empty() && st.top().second > heights[i]){
                int h=st.top().second;
                int idx=st.top().first;
                ans=max(ans,h*(i-idx));
                start=idx;
                st.pop();
            }
            st.push({start,heights[i]});
        }
        while(!st.empty()){
            int h=st.top().second;
            int idx=st.top().first;
            ans=max(ans,h*((int)heights.size()-idx));
            st.pop();
        }
        return ans;
    }
};
