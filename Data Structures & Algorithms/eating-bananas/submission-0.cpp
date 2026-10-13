class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1,r=1e9;
        int ans=0;
        while(l<=r){
            long long mid=(l+r)/2;
            long long curr=0;
            for(int i=0;i<piles.size();i++){
                curr+=(piles[i] + mid-1)/mid;
            }
            // cout<<mid<<" "<<curr<<"\n";
            if(curr <= h){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};
