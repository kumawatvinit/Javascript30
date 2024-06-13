#include <bits/stdc++.h>
using namespace std;

int Solution(int N, int K, vector<int> candle)
{
    unordered_map<int, int> freqMap; // Frequency map to track the counts of candles
    int start = 0, end = 0;          // Sliding window pointers
    int minLength = N + 1;           // Initialize with a large value (larger than any possible subarray length)
    int distinctCount = 0;           // Number of distinct candles from 1 to K in the current window

    while (end < N)
    {
        // Expand the window by including the candle at the 'end' position
        int currentCandle = candle[end];
        if (currentCandle >= 1 && currentCandle <= K)
        {
            freqMap[currentCandle]++;
            if (freqMap[currentCandle] == 1)
            {
                distinctCount++;
            }
        }
        end++;

        // Now, check if the window contains all candles from 1 to K
        while (distinctCount == K)
        {
            // Update the minimum length if the current window is smaller
            minLength = min(minLength, end - start);

            // Try to shrink the window from the 'start' pointer
            int startCandle = candle[start];
            if (startCandle >= 1 && startCandle <= K)
            {
                if (freqMap[startCandle] == 1)
                {
                    distinctCount--;
                }
                freqMap[startCandle]--;
            }
            start++;
        }
    }

    // If minLength is still larger than N, it means no valid window was found
    return (minLength <= N) ? minLength : -1;
}

int main()
{
    // Test case: should return 4 (the subarray [5, 3, 1, 7])
    cout << Solution(7, 3, {4, 5, 3, 1, 7, 2, 6}) << endl;

    return 0;
}
