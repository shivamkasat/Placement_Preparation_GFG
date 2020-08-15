#include <bits/stdc++.h>
using namespace std;

int findMaxMatSum(vector < int > &rowSum, int m) {
	vector < int > cumSum(rowSum.size() + 1);
	cumSum.push_back(0);
	for (int i = 0; i < rowSum.size(); i++) {
		cumSum.push_back(cumSum[i] + rowSum[i]);
	}
	int maxSum = INT_MIN;
	cout<<"cumSum "<<endl;
	for (auto x : cumSum) {
		cout<<"x = "<<x<<" ";
	}
	cout<<endl;
	for (int i = m; i < cumSum.size(); i++) {
		maxSum = max(maxSum, cumSum[i] - cumSum[i - m]);
	}

	return maxSum;
}

int maxSumSquareSubMat(vector < vector < int > > &mat) {
	int rows = mat.size();
	int cols = mat[0].size();
	int result = INT_MIN;

	vector < int > rowSum(rows, 0);
	for (int j = 0; j < cols; j++) {
		for (auto &x : rowSum) {
			x = 0;
		}

		for (int k = j; k < cols; k++) {
			for (int i = 0; i < rows; i++) {
				rowSum[i] += mat[i][k];
				//findMaxMatSum(rowSum, k - j + 1);
			}
			int retVal = findMaxMatSum(rowSum, k - j + 1);
			result = max(result, retVal);	
			cout<<"j = "<<j<<" k = "<<k<<" ret val = "<< retVal<<endl;
		}
	}

	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int test;
	cin>>test;
	while (test--) {
		int rows;
		int cols;
		cin>>rows;
		cin>>cols;
		vector < vector < int > >mat(rows, vector < int >(cols, 0));
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				cin>>mat[i][j];
			}
		}

		cout<<maxSumSquareSubMat(mat)<<endl;
	}
	return 0;
}