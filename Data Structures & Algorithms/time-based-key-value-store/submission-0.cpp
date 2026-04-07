class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].emplace_back(timestamp,value);
    }
    
    string get(string key, int timestamp) {
        auto& valArr = mp[key];
        int right = valArr.size()-1;
        int left =0;
        string result = ""; 
        while(left<=right){
            int mid = left + (right-left)/2;
            if(valArr[mid].first<=timestamp){
                result = valArr[mid].second;
                left= mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return result;
    }

};
