class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>freq(26),freq2(26);
        int m=s1.size();
        for(auto it:s1){freq[it - 'a']++;}
        int n=s2.size();
        int l=0,r=0;
        while(r<n){
            freq2[s2[r] - 'a']++;
            r++;
            if(r-l == m){
                bool flag=true;
                for(int i=0;i<m;i++){
                    if(freq[s1[i] - 'a'] != freq2[s1[i] - 'a']){flag=false; break;}
                }
                if(flag){return true;}
            }
            if(r-l >= m){
                freq2[s2[l] - 'a']--;
                l++;
            }
        }
        return false;
    }
};
