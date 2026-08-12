class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,vector<int>>ind;
        for(int i=0;i<nums.size();i++){
            ind[nums[i]].push_back(i);
        }
        vector<int>ans(2);
        for(int i=0;i<nums.size();i++){
            cout<<nums[i]<<" "<<target - nums[i]<<"\n";
            if(ind.count(target-nums[i])>0 && i != ind[target - nums[i]][ind[target - nums[i]].size()-1]){
                ans[0]=ind[nums[i]][ind[nums[i]].size()-1];
                ind[nums[i]].pop_back();
                ans[1]=ind[target - nums[i]][ind[target - nums[i]].size()-1];
                break;
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};
