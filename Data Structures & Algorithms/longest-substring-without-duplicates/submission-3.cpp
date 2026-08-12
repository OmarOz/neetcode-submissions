class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        if(n == 0){return 0;}
        int l=0,r=0, ans=1;
        map<char,int>freq;
        while(r<n){
            freq[s[r]]++;
            if(freq[s[r]] > 1){
                while(l<=r && freq[s[r]]>1){
                    freq[s[l]]--;
                    l++;
                }
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};
