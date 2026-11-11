
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // int longest = 0;

        // for(int i = 0; i < nums.size(); i++) {
        //     int currEle = nums[i];
        //     int count = 1;

        //     while(true) {
        //         bool found = false;

        //         for(int j = 0; j < nums.size(); j++) {
        //             if(nums[j] == currEle + 1) {
        //                 currEle = nums[j];
        //                 count++;
        //                 found = true;
        //                 break;
        //             }
        //         }

        //         if(!found) break;
        //     }

        //     longest = max(longest, count);
        // }

        // return longest;

        // if(nums.empty()) return 0;

        // sort(nums.begin(), nums.end());

        // int longest = 1;
        // int count = 1;

        // for(int i = 1; i < nums.size(); i++) {
        //     if(nums[i] == nums[i-1]) {
        //         continue;
        //     }
        //     if(nums[i] == nums[i-1] + 1) {
        //         count++;
        //     }
        //     else {
        //         count = 1;
        //     }

        //     longest = max(longest, count);
        // }

        // return longest;

        unordered_set<int> st(nums.begin(), nums.end());
        int longest = 0;
        for(int num : st) {
            if(st.find(num - 1) == st.end()) {

                int currEle = num;
                int count = 1;

                while(st.find(currEle + 1) != st.end()) {
                    currEle++;
                    count++;
                }

                longest = max(longest, count);
            }
        }
        return longest;
    }
};
