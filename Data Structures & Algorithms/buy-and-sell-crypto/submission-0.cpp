class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn=1e9, ans=-1e9;
        int n=prices.size();
        for(int i=0;i<n;i++){
            mn=min(mn,prices[i]);
            ans=max(ans,prices[i] - mn);
        }
        return ans;
    }
};
