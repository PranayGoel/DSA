class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;

        for(auto ch: tasks){
            mp[ch]++;
        }

        priority_queue<pair<int,char>> maxh;

        for(auto it: mp){
            maxh.push({it.second, it.first});
        }
        int count = 0;
        while(maxh.size() > 0){
            int slots = n+1;
            vector<pair<int, char>> temp;

            while(maxh.size() > 0 && slots > 0){
                pair<int,char> top = maxh.top();
                maxh.pop();
                top.first--;
                if(top.first > 0) temp.push_back(top);
                count++;
                slots--;
            }

            for(auto& task : temp){
                maxh.push(task);
            }

            if(maxh.size() > 0){
                count += slots;
            }

        }
        return count;;
    }
};