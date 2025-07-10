class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        map<int, int> mp;

        // Step 1: Build a sweep line map
        // +1 at flower start, -1 at flower end + 1
        for (int i = 0; i < flowers.size(); i++) {
            mp[flowers[i][0]]++;         // Flower starts blooming
            mp[flowers[i][1] + 1]--;     // Flower stops blooming after end day
        }

        // Step 2: Build a timeline of bloom counts using prefix sum
        vector<pair<int, int>> f; // {day, total number of flowers blooming}
        int count = 0;
        for (auto i : mp) {
            count += i.second;           // Update current bloom count
            f.push_back({i.first, count});
        }

        vector<int> result;

        // Step 3: For each person, find how many flowers are blooming at their arrival time
        for (int i = 0; i < people.size(); i++) {
            // Binary search: find the first day > people[i]
            auto it = upper_bound(f.begin(), f.end(), make_pair(people[i], INT_MAX));

            if (it == f.begin()) {
                // No day ≤ people[i] → no flowers are blooming yet
                result.push_back(0);
            } else {
                --it; // Move to last day ≤ people[i]
                result.push_back(it->second); // Get bloom count on that day
            }
        }

        return result;
    }
};
