// Knapsack Problem Implementation
#include<iostream>
#include<iomanip>
using namespace std;

int knapsackRec(int wt[], int price[], int N, int W) {
	if (N == 0 || W == 0) {
		// If no items left or weight limit filled
		return 0;
	}
	if (wt[N - 1] > W) {
		//If amount is greater than weight Discard it
		return knapsackRec(wt, price, N - 1, W);
	}
	int include = 0, exclude = 0;
	// include the item
	include = price[N - 1] + knapsackRec(wt, price, N - 1, W - wt[N - 1]);
	// Dont Include the item;
	exclude = knapsackRec(wt, price, N - 1, W);

	return max(include, exclude);
}

int knapsackBottomUp(int wt[], int price[], int N, int W) {

	int dp[N + 1][W + 1];
	for (int n = 0; n <= N; n++) {
		for (int w = 0; w <= W; w++) {

			if (n == 0 || w == 0) {
				dp[n][w] = 0;
			}
		}
	}
	for (int n = 1; n <= N; n++)
	{
		for (int w = 1; w <= W; w++)
		{
			if (wt[n - 1] <= w) {
				// Take the profit after including the item
				int remainingProfit = dp[n - 1][w - wt[n - 1]];
				// add the price to that profit
				int newProfit = price[n - 1] + remainingProfit;
				// Take the max of new profit and profit previously computed by not including the item
				dp[n][w] = max(newProfit, dp[n - 1][w]);
			}
			else {
				dp[n][w] = dp[n - 1][w];
			}
		}
	}
	// for (int i = 0; i <= N; i++) {
	// 	for (int j = 0; j <= W; j++) {
	// 		cout << setw(3) << dp[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }
	return dp[N][W];

}

int main() {

	int wt[] = {2, 7, 3, 4, 5};
	int price[] = {5, 20, 20, 10, 15};
	int N = 4;
	int W = 14;
	int maxProfit = knapsackRec(wt, price, N, W);
	int maxProfitDP = knapsackBottomUp(wt, price, N, W);
	cout << maxProfit << " " << maxProfitDP;
	return 0;
	
}