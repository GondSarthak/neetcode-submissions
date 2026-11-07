class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        // for(int i = 0; i < nums.size(); i++) {
        //     for(int j = i + 1; j < nums.size(); j++) {
        //         if(nums[i] == nums[j]) return true;
        //     }
        // }

        // vector<int> hash(100000, 0);
        // for(int i = 0; i < nums.size(); i++) {
        //     hash[nums[i]]++;
        // }
        // for(int i = 0; i < hash.size(); i++) {
        //     if(hash[i] > 1) return true;
        // }

        unordered_set<int> st;
        for(int i = 0; i < nums.size(); i++) {
            if(st.contains(nums[i])) return true;
            st.insert(nums[i]);
        }
        return false;
    }
};