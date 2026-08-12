class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int l=0,r=n-1,ans=0;
        int mxL=height[l], mxR=height[r];
        while(l<r){
            if(mxL<=mxR){
                l++;
                mxL=max(mxL,height[l]);
                ans+=mxL-height[l];
            }
            else{
                r--;
                mxR=max(mxR,height[r]);
                ans+=mxR-height[r];
            }
        }
        return ans;
    }
};
