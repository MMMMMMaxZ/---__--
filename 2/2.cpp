class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> cop;
        vector<int> ans;
        for(auto i=nums.begin();i!=nums.end();i++){
            auto k = cop.find(target-*i);
            if( k != cop.end() ){
                ans.push_back(i-nums.begin());
                ans.push_back(k->second);
                return ans;
            }else{
                cop[*i]=i-nums.begin();
            }
        }
        ans.push_back(-1);
		ans.push_back(-1); 
        return ans;
    }
};
