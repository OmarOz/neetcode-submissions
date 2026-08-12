class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int l=0,r=0, mx=0;
        vector<int>freq(200);
        int ans=0;
        while(r<n){
            freq[s[r] - 'A']++;
            mx=max(mx,freq[s[r] - 'A']);
            // cout<<s[r]<<"\n";
            if(mx + k >= r-l+1){ ans=max(ans,r-l+1);}
            else{
                while(l<r && *max_element(freq.begin(),freq.end()) + k < r-l+1){
                    // for(int i=0;i<30;i++){cout<<freq[i]<<" ";}
                    freq[s[l] - 'A']--;
                    l++;
                    // cout<<"\n";
                    // cout<<"L: "<<l<<"\n";
                }
            }
            r++;
        }
        return ans;
    }
};
