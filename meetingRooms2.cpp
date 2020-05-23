// submitted on interview bit

int Solution::solve(vector<vector<int> > &intervals) {
    sort(intervals.begin(), intervals.end());
    priority_queue < int, vector < int >, greater < int > > minHeap;
    minHeap.push(intervals[0][1]);
    //minHeap will only store the end time.
    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] < minHeap.top()) {
            minHeap.push(intervals[i][1]);
        } else {
            minHeap.pop();
            minHeap.push(intervals[i][1]);
        }
    }

    return minHeap.size();
}
