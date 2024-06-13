#include <iostream>
#include <vector>
#include <algorithm> // For sort function

using namespace std;

int calculateMaximumProfit(int N, int K, const std::vector<int>& cost, const std::vector<int>& sell) {
    vector<int> profit(N);
    
    for (int i = 0; i < N; ++i) {
        profit[i] = sell[i] - cost[i];
    }
    
    // std::sort(profit.rbegin(), profit.rend());
    
    int currentMoney = K;
    int totalProfit = 0;
    
    for (int i = 0; i < N; ++i) {
        if (currentMoney >= cost[i] && profit[i] > 0) {
            currentMoney += profit[i]; 
            totalProfit += profit[i];  
        }
    }
    
    return totalProfit;
}

int main() {
    
    int N; // Number of items
    int K; // Initial amount of money
    std::cin >> N >> K;
    
    std::vector<int> cost(N);
    std::vector<int> sell(N);
    
    
    for (int i = 0; i < N; ++i) {
        std::cin >> cost[i] >> sell[i];
    }
    
    int maxProfit = calculateMaximumProfit(N, K, cost, sell);
    std::cout << "The maximum profit John can achieve is: " << maxProfit << std::endl;
    
    return 0;
}

/*
2 50
25 25
30 37
*/