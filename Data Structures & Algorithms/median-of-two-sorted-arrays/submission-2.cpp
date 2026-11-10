class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>a,b;
        if(nums1.size() <= nums2.size()){
            a=nums1;
            b=nums2;
        }
        else{a=nums2; b=nums1;}
        int totalSz = a.size() + b.size();
        int half = (totalSz+1)/2;
        int l = 0,r=a.size();
        while(l<=r){
            int midA = (l+r) / 2;
            int midB = half - midA;
            int Aleft = midA > 0 ? a[midA - 1] : INT_MIN;
            int Aright = midA < a.size()? a[midA] : INT_MAX;
            int Bleft = midB > 0 ? b[midB - 1] : INT_MIN;
            int Bright = midB < b.size() ? b[midB] : INT_MAX;


            if(Aleft <= Bright && Bleft <= Aright){
                if(totalSz & 1){
                    return max(Aleft, Bleft);
                }
                else{
                    return (max(Aleft,Bleft) + min(Aright,Bright)) / 2.0;
                }
            }
            if(Aleft > Bright){
                r=midA-1;
            }
            else{l=midA+1;}
        }
        return 0;
    }
};
