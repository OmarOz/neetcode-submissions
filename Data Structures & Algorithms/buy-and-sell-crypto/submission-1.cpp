class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l=0,r=0;
        int n=prices.size();
        int ans=0;
        while(r<n){
            if(prices[l] < prices[r]){
                ans=max(ans,prices[r] - prices[l]);
            }
            else{l=r;}
            r++;
        }
        return ans;
    }
};
