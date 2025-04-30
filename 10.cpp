#include <iostream>
#include <vector>
using namespace std;

int knapsack(int W, const vector<int>& weight, const vector<int>& value, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (weight[i - 1] <= w) {
                dp[i][w] = max(value[i - 1] + dp[i - 1][w - weight[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {
    vector<int> value = {12, 10, 20, 15};
    vector<int> weight = {2, 1, 3, 2};
    int W = 5;
    int n = value.size();

    int maxVal = knapsack(W, weight, value, n);
    cout << "Maximum value in knapsack: " << maxVal << endl;

    return 0;
}
