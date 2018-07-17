#include<iostream>
// Ladder problem Cracking the coding Interview
using namespace std;
int waysRec(int n, int k) {
	if (n < 0) {
		return 0; // this way is not possible
	}
	if (n == 0) {
		return 1; // reached the top of stairs so take this as one way
	}
	int ans = 0;
	for (int i = 1; i <= k; i++) {
		ans += waysRec(n - i, k);
	}
	return ans;

}

//BOTTOM UP
// *********
int waysBottomUp(int n, int k) {
	int dp[100];
	dp[0] = 1;
	for (int step = 1; step <= n; step++) {
		dp[step] = 0;
		for (int j = 1; j <= k; j++) {
			if (step - j >= 0) {
				dp[step] += dp[step - j];
			}
		}
	}
	return dp[n];
}
int main() {
	int n = 4, k = 3;
	cout << waysRec(n, k) << endl;
	cout << waysRec(5, 3) << endl;
	cout << waysBottomUp(6, 3) << endl;
}