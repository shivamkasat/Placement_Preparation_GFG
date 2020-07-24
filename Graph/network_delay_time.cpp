class Solution {
    public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        //created adjList of the form node->[{neigh, edgeWeight}]
        vector < vector < pair < int, int > > > adjList(N + 1);
        for (auto edge : times) {
            adjList[edge[0]].push_back({edge[1], edge[2]});
        }


        vector < int > dist(N + 1, INT_MAX);
        dist[K] = 0;

        //set will contain pair in the form of {distance, Node}
        set < pair < int, int > > distAndNode;
        distAndNode.insert({0, K});

        int currentNode;
        int currentDist;
        vector < bool > visited(N + 1, false);

        while (distAndNode.empty() != true) {
            currentNode = distAndNode.begin()->second;
            currentDist = distAndNode.begin()->first;
            distAndNode.erase({currentDist, currentNode});
            visited[currentNode] = true;
            for (auto neigh : adjList[currentNode]) {
                if (visited[neigh.first] == false && dist[neigh.first] > currentDist + neigh.second) {
                    if (distAndNode.find({dist[neigh.first], neigh.first}) != distAndNode.end()) {
                        distAndNode.erase({dist[neigh.first], neigh.first});
                    }
                    dist[neigh.first] = currentDist + neigh.second;
                    distAndNode.insert({dist[neigh.first], neigh.first});
                }
            }
        }


        int minTime = INT_MIN;
        for (int i = 1; i < N + 1; i++) {
            minTime = max(dist[i], minTime);
        }

        if (minTime == INT_MAX) {
            return -1;
        }
        return minTime;
    }
};
