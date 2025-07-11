class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        using t = pair<long long, int>;
        priority_queue<t, vector<t>, greater<t>> busyRooms;
        //endTime, room

        priority_queue<int, vector<int>, greater<int>> freeRooms;
        for(int i = 0; i< n; i++) freeRooms.push(i); // initally all rooms are free
        vector<int> freq(n, 0);

        for(int i = 0; i< meetings.size(); i++){
            long start = meetings[i][0];
            long end = meetings[i][1];

            while(!busyRooms.empty() && start >= busyRooms.top().first){ // remove all the meetings that are over
                int room = busyRooms.top().second;
                freeRooms.push(room);
                busyRooms.pop();
            }

            if(!freeRooms.empty()){
                int room = freeRooms.top();
                freeRooms.pop();
                freq[room]++;
                busyRooms.push({end, room});
            }
            else{
                auto [endTime, room] = busyRooms.top();
                busyRooms.pop();
                long long newEndTime = endTime - start + end;
                freq[room]++;
                busyRooms.push({newEndTime, room});
            }
        }

        int max_meetings = INT_MIN;
        int max_meet_room;

        for(int i = 0; i < freq.size(); i++){
            if(max_meetings < freq[i]){
                max_meet_room = i;
                max_meetings = freq[i];
            }
        }

        return max_meet_room;
    }
};