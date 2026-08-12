class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int l=0,r=0,sub=0,ans=0;
        while(r<n){
            if(height[r] >= height[l] ){
                if(r-l>1){
                    ans+=(min(height[r], height[l]) * (r-l-1)) - sub;
                }
                l=r;
                r++;
                sub=0;
            }
            else{
                sub+=height[r];
                r++;
            }
        }
        r = n - 1; l = n - 1; sub = 0;
        while(l >= 0){
            if(height[l] > height[r]){
                if(r-l>1){
                    ans+=(min(height[r], height[l]) * (r-l-1)) - sub;
                }
                r=l;
                l--;
                sub=0;
            }
            else{
                if(l != r){
                    sub+=height[l];
                }
                l--;
            }
        }
        return ans;
    }
};
