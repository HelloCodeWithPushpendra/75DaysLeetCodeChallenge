class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int>ans;

        int n = words.size();
        int wordLen = words[0].size();

        unordered_map<string, int> mp;
        for(string word : words) {
            mp[word]++;
        }

        for(int i = 0; i < wordLen; i++) {
            int left = i;
            int count = 0;

            unordered_map<string, int> seen;

            for(int right = i; right + wordLen <= s.size(); right += wordLen) {

                string word = s.substr(right, wordLen);

                if(mp.find(word) != mp.end()) {
                    seen[word]++;
                    count++;

                    while(seen[word] > mp[word]) {
                        string leftWord = s.substr(left, wordLen);

                        seen[leftWord]--;
                        left += wordLen;
                        count--;
                    }

                    if(count == n) {
                        ans.push_back(left);
                        string leftWord = s.substr(left, wordLen);

                        seen[leftWord]--;
                        left += wordLen;
                        count--;
                    }

                }
                else {
                    seen.clear();
                    count = 0;
                    left = right + wordLen;
                }
            }
        }

        return ans;
    }
};