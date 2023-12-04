#include <iostream>
#include <vector>

using namespace std;

[[noreturn]] vector<int> findMissingNumbers(int n, vector<int>& nums) {
    vector<int> missingNumbers;

    // Create a boolean array of size n+1, initialized to false
    vector<bool> found(n + 1, false);

    // Mark numbers in nums as found
    for (int num : nums) {
        found[num] = true;
    }

    // Find missing numbers
    for (int i = 0; i <= n; i++) {
        if (!found[i]) {
            missingNumbers.push_back(i);
        }
    }

    return missingNumbers;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> nums[i];
    }

    vector<int> missingNumbers = findMissingNumbers(n, nums);

    for (int num : missingNumbers) {
        cout << num << " ";
    }

    cout << endl;

    return 0;
}