class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int l=0,r=0, mx=0;
        vector<int>freq(26);
        int ans=0;
        while(r<n){
            freq[s[r] - 'A']++;
            mx=max(mx,freq[s[r] - 'A']);
            if(mx + k >= r-l+1){ ans=max(ans,r-l+1);}
            else{
                while(l<r && *max_element(freq.begin(),freq.end()) + k < r-l+1){
                    freq[s[l] - 'A']--;
                    l++;
                }
            }
            r++;
        }
        return ans;
    }
};
