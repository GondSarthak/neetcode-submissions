class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        // vector<int> hashS(26, 0);
        // vector<int> hashT(26, 0);

        // for(int i = 0; i < s.size(); i++) {
        //     hashS[s[i] - 'a']++;
        //     hashT[t[i] - 'a']++;
        // }

        // for(int i = 0; i < hashS.size(); i++) {
        //     if(hashS[i] != hashT[i]) return false;
        // }

        // vector<bool> visited(t.size(), false);

        // for(int i = 0; i < s.size(); i++) {
        //     int found = false;
        //     for(int j = 0; j < t.size(); j++) {
        //         if(s[i] == t[j] && !visited[j]) {
        //             visited[j] = true;
        //             found= true;
        //             break;
        //         }
        //     }
        //     if(!found) return false;
        // }

        vector<int> hash(26, 0);
        for(int i = 0; i < s.size(); i++) {
            hash[s[i] - 'a']++;
            hash[t[i] - 'a']--;
        }

        for(int i = 0; i < hash.size(); i++) {
            if(hash[i] != 0) return false;
        }
 
       return true;  
    }
};
