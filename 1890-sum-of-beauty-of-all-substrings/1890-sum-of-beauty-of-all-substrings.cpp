class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int sum = 0;

        for(int i = 0; i< n; i++){
            unordered_map<char, int> freq;
            for(int j = i; j < n; j++){
                freq[s[j]]++;

                int minFreq = INT_MAX;
                int maxFreq = INT_MIN;

                for(auto it: freq){
                    minFreq = min(it.second, minFreq);
                    maxFreq = max(it.second, maxFreq);
                }

                sum += maxFreq - minFreq;
            }
        }

        return sum;
    }
};