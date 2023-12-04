#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// Function to calculate the maximum beautifulness
int calculateMaximumBeautifulness(int n, vector<int>& permutation) {
    int beautifulness = 0;

    // Calculate the initial beautifulness
    for (int i = 0; i < n; i++) {
        beautifulness += abs(permutation[i] - (i + 1));
    }

    // Check if swapping two elements can increase the beautifulness
    for (int i = 0; i < n - 1; i++) {
        if (abs(permutation[i] - permutation[i + 1]) == 1) {
            // Calculate beautifulness after swapping two elements
            int beautifulnessAfterSwap = beautifulness;
            beautifulnessAfterSwap -= abs(permutation[i] - (i + 1));
            beautifulnessAfterSwap -= abs(permutation[i + 1] - (i + 2));
            beautifulnessAfterSwap += abs(permutation[i] - (i + 2));
            beautifulnessAfterSwap += abs(permutation[i + 1] - (i + 1));

            // Update the maximum beautifulness
            beautifulness = max(beautifulness, beautifulnessAfterSwap);
        }
    }

    return beautifulness;
}

int main() {
    int n;
    cin >> n;

    vector<int> permutation(n);
    for (int i = 0; i < n; i++) {
        cin >> permutation[i];
    }

    // Calculate the maximum beautifulness
    int maximumBeautifulness = calculateMaximumBeautifulness(n, permutation);

    cout << maximumBeautifulness << endl;

    return 0;
}