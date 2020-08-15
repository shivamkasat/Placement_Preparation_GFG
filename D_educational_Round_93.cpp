#include <bits/stdc++.h>
#define ll long long
#define pi pair < int, int >
#define fr first
#define sc second
using namespace std;

int findMaxArea(vector < int > &redVec, vector < int > &greenVec, vector < int > &blueVec, int r, int g, int b, vector < vector < vector < int > > > &dp) {
	if ((r == 0 && g == 0) || (r == 0 && b == 0) || (b == 0 && g == 0)) {
		return 0;
	}

	int max1 = 0;
	int max2 = 0;
	int max3 = 0;

	if (dp[r][g][b] != -1) {
		return dp[r][g][b];
	}

	if (g != 0 && b != 0) {
		max1 = (greenVec[g - 1] * blueVec[b - 1]) + findMaxArea(redVec, greenVec, blueVec, r, g - 1, b - 1, dp);
	} 
	if (r != 0 && b != 0) {
		max2 = (redVec[r - 1] * blueVec[b - 1]) + findMaxArea(redVec, greenVec, blueVec, r - 1, g, b - 1, dp);
	} 
	if (r != 0 && g != 0) {
		max3 = (redVec[r - 1] * greenVec[g - 1]) + findMaxArea(redVec, greenVec, blueVec, r - 1, g - 1, b, dp);
	}

	dp[r][g][b] = max(max1, max(max2, max3));
	return dp[r][g][b];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int R, G, B;
	cin>>R>>G>>B;
	vector < int > redVec;
	vector < int > greenVec;
	vector < int > blueVec;
	int red;
	int green;
	int blue;
	for (int i = 0; i < R; i++) {
		cin>>red;
		redVec.push_back(red);
	}
	for (int i = 0; i < G; i++) {
		cin>>green;
		greenVec.push_back(green);
	}
	for (int i = 0; i < B; i++) {
		cin>>blue;
		blueVec.push_back(blue);
	}
	sort(redVec.begin(), redVec.end());
	sort(greenVec.begin(), greenVec.end());
	sort(blueVec.begin(), blueVec.end());
	vector < vector < vector < int > > > dp(R + 1, vector < vector < int > >(G + 1, vector < int >(B + 1, -1)));
	cout<<findMaxArea(redVec, greenVec, blueVec, R, G, B, dp);
	return 0;
}