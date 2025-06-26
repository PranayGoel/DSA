class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words;

        for(auto word: wordList) words.insert(word);
        queue<pair<string,int>> q;

        q.push({beginWord,1});

        while(!q.empty()){
            string word = q.front().first;
            int len = q.front().second;
            q.pop();

            for(int i = 0; i< word.size(); i++){
                string temp = word;
                for(char c = 'a'; c <= 'z'; c++){
                    temp[i] = c;
                    if(words.find(temp) != words.end()){
                        if(temp == endWord) return len+1;
                        q.push({temp, len+1});
                        words.erase(temp);
                    }
                }
            }
        }
        return 0;
    }
};