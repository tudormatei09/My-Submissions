#include "iostream"
#include <algorithm>
#include <utility>
const int SIZE = 21;
std::pair<int, int> dp[1 << SIZE]; // .first - numărul de drumuri, .second - greutatea ultimului drum
int v[SIZE];
int n, k;
void Solve() {
    std::cin >> n >> k;
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }
    dp[0] = {1, 0};
    for (int mask = 1; mask < (1 << n); mask++) {
        dp[mask] = {n + 1, 0};
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                int prev_mask = mask ^ (1 << i);
                auto [rides, weight] = dp[prev_mask];

                if (weight + v[i] <= k) {
                    dp[mask] = std::min(dp[mask], {rides, weight + v[i]});
                } else {
                    dp[mask] = std::min(dp[mask], {rides + 1, v[i]});
                }
            }
        }
    }
    std :: cout << dp[(1 << n) - 1].first;
}
int main() {
    std :: ios_base :: sync_with_stdio(false);
    std :: cin.tie(0);
    Solve();
    return 0;
}
