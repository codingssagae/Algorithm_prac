#include <iostream>
#include <algorithm>
#define MAX 10001
#define INF 123456789
using namespace std;

int coins[MAX];
int dp[MAX];

int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> coins[i];
	}
	for (int i = 1; i <= k; i++) {
		dp[i] = INF;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = coins[i]; j <= k; j++) {
			dp[j] = min(dp[j], dp[j - coins[i]] + 1);
		}
	}
	if (dp[k] == INF) cout << -1;
	else cout << dp[k];
}