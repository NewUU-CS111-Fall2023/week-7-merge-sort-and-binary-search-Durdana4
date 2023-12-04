/*
 * Author:
 * Date:
 * Name:
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to find the sum of remaining numbers in the array
long long findRemainingSum(vector<int>& arr) {
    int n = arr.size();
    long long sum = 0;

    // Iterate N-2 times
    for (int i = 0; i < n - 2; i++) {
        vector<int> medians;

        // Find medians of all odd-sized subarrays
        for (int j = 0; j <= n - i - 3; j += 2) {
            vector<int> subarray = { arr[j], arr[j + 1], arr[j + 2] };
            sort(subarray.begin(), subarray.end());
            medians.push_back(subarray[1]);
        }

        // Find the minimum median
        int minMedian = *min_element(medians.begin(), medians.end());

        // Add minMedian to the sum
        sum += minMedian;

        // Remove the first occurrence of minMedian from the array
        auto it = find(arr.begin(), arr.end(), minMedian);
        arr.erase(it);
    }

    // Add the remaining numbers to the sum
    for (int num : arr) {
        sum += num;
    }

    return sum;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        // Find the sum of the remaining numbers
        long long remainingSum = findRemainingSum(arr);

        cout << remainingSum << endl;
    }

    return 0;
}
