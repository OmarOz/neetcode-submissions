class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums3;
        int n=nums1.size(), m=nums2.size();
        int k=n+m;
        for(auto &it:nums1){nums3.push_back(it);}
        for(auto &it:nums2){nums3.push_back(it);}
        sort(nums3.begin(),nums3.end());
        if(k & 1){return (double)nums3[k/2]; }
        return ((double)nums3[k/2] + (double)nums3[(k/2) - 1])/2;
    }
};
