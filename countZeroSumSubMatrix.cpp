#include <bits/stdc++.h>
using namespace std;

int countZeroSubArrays(vector < int > &temp) {
	vector < int > nums(temp + 1, 0);
	for (int i = 1; i < nums.size(); i++) {
		nums[i] = temp[i - 1] + nums[i - 1];
	}

	unordered_map < int, int > hmap;
	int count = 0;
	for (auto x : nums) {
		if (hmap.find(x) != hmap.end()) {
			count += hmap[x];
			hmap[x]++;
		} else {
			hmap[x] = 1;
		}
	}

	return count;
}

int countZeroSubMat(vector < vector < int > > &mat) {
	int rows = mat.size();
	int cols = mat[0].size();
	int totalCount = 0;
	vector < int > temp(rows, 0);
	for (int l = 0; l < cols; l++) {
		for (auto &x : temp) {
			x = 0;
		}
		for (int r = l; r < cols; r++) {
			//maintaing running row sum
			for (int i = 0; i < rows; i++) {
				temp[i] += mat[i][r];
			}

			//count the zero sum submatrix;
			totalCount += countZeroSubArrays(temp);


		}
	}

	return totalCount;
}

int main() {
	int test;
	cin>>test;
	while (test--) {
		int rows;
		int cols;
		cin>>rows;
		cin>>cols;
		vector < vector < int > > mat(rows, vector < int >(cols, 0));
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				cin>>mat[i][j];
			}
		}
		cout<<countZeroSubMat(mat)<<endl;
	}
	return 0;
}