// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Position this line where user code will be pasted.

// } Driver Code Ends
/*you are required to complete this method*/

/*  Function to find number of islands in the given graph
*   A[]: input array
*   N, M: Row and column of given matrix
*/

bool isValid(pair < int, int > pos, int n, int m)
{
    int i = pos.first;
    int j =  pos.second;
    
    if (i < 0 || i >= n || j < 0 || j >= m) 
        return false;
    
    return true;
}


void sink(pair < int, int > pos, vector < vector < int > > &island)
{
    for (int i = pos.first - 1; i <= pos.first + 1; i++) {
        for (int j = pos.second - 1; j <= pos.second + 1; j++) {
            if (isValid(make_pair(i, j), island.size(), island[0].size()) && island[i][j] == 1) {
		island[i][j] = 0;
                sink(make_pair(i, j), island);
            }
        }
    }
}

int findIslands(vector<int> A[], int N, int M) {
    vector < vector < int > > island(N, vector < int >(M, 0));
    for (int i = 0; i < N; i++) {
        for (int j  = 0; j < M; j++) {
            island[i][j] = A[i][j];
        }
    }
    
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (island[i][j] == 1) {
                count++;
                sink(make_pair(i, j), island);
            }
        }
    }
    return count;
}

int main() {

    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<int> A[N];
        for (int i = 0; i < N; i++) {
            vector<int> temp(M);
            A[i] = temp;
            for (int j = 0; j < M; j++) {
                cin >> A[i][j];
            }
        }
        cout << findIslands(A, N, M) << endl;
    }
    return 0;
}
