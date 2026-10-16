class Solution {
public:
    int BS(vector<int>& nums, int target,int l,int r){
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid] == target){return mid;}
            if(nums[mid] > target){r=mid-1;}
            else{l=mid+1;}
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        while(l<r){
            int mid=(l+r)/2;
            cout<<l<<" "<<mid<<" "<<r<<"\n";
            if(nums[mid] > nums[r]){l=mid+1;}
            else{
                r=mid;
            }
        }
        int p=l;
        int ans=BS(nums,target,0,p-1);
        if(ans != -1){return ans;}
        return BS(nums,target,p,nums.size()-1);
    }
};
