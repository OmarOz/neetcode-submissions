class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> m;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        m[key].emplace_back(timestamp,value);
    }
    
    string get(string key, int timestamp) {
        vector<pair<int,string>>& val = m[key];
        int l=0, r=val.size()-1;
        string ans="";
        while(l<=r){
            int mid=(l+r)/2;
            if(val[mid].first <= timestamp){
                ans=val[mid].second;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return ans;
    }
};
