class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>>s;
        int n=temperatures.size();
        vector<int>ans(n);
        for(int i = 0;i<n;i++){
            int t=temperatures[i];
            while(!s.empty() && t>s.top().first){
                int idx = s.top().second;
                s.pop();
                ans[idx] = i - idx; 
            }
            s.push({t,i});
        }
        return ans;
    }
};
