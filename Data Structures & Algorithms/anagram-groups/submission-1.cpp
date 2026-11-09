class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
            vector<vector<string>> ans;
        //     vector<bool> visited(strs.size(), false);
        //     for (int i = 0; i < strs.size(); i++) {
        //         if (visited[i]) continue;

        //         vector<string> group;
        //         group.push_back(strs[i]);
        //         visited[i] = true;

        //         for (int j = i + 1; j < strs.size(); j++) {
        //             if (visited[j]) continue;

        //             if (isAnagram(strs[i], strs[j])) {
        //                 group.push_back(strs[j]);
        //                 visited[j] = true;
        //             }
        //         }

        //         ans.push_back(group);
        //     }
        //     return ans;
        // }

        // bool isAnagram(string s, string t) {
        //     if (s.size() != t.size()) return false;
        //     vector<int> hash(26, 0);
        //     for (int i = 0; i < s.size(); i++) {
        //         hash[s[i] - 'a']++;
        //         hash[t[i] - 'a']--;
        //     }

        //     for (int i = 0; i < hash.size(); i++) {
        //         if (hash[i] != 0) return false;
        //     }
        //     return true;
        // }
        unordered_map<string, vector<string>> mp;

        // for (string s : strs) {
        //     vector<int> hash(26, 0);

        //     for (char c : s) {
        //         hash[c - 'a']++;
        //     }

        //     string key;

        //     for (int count : hash) {
        //         key += to_string(count) + "#";
        //     }

        //     mp[key].push_back(s);
        // }

        for (string s : strs) {
            string key = s;
            sort(key.begin(), key.end());

            mp[key].push_back(s);
        }

        for (auto& entry : mp) {
            ans.push_back(entry.second);
        }

        return ans;
    }
};
