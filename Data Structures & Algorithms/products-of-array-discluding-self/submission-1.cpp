class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output(nums.size());
        // for(int i = 0; i < nums.size(); i++) {
        //     int prod = 1;
        //     for(int j = 0; j < nums.size(); j++) {
        //         if(j == i) continue;
        //         prod *= nums[j];
        //     }
        //     output.push_back(prod);
        // }

        int prefixProd = 1;
        int suffixProd = 1;
        for(int i = 0; i < nums.size(); i++) {
            output[i] = prefixProd;
            prefixProd *= nums[i];
        }
        for(int i = nums.size() - 1; i >= 0; i--) {
            output[i] *= suffixProd;
            suffixProd *= nums[i];
        }

        return output;
    }
};
