#include <iostream>
#include <vector>

using namespace std;

// Recursive function to calculate x raised to the power n
int recursivePow(int x, int n) {
    // Base case: x^0 = 1
    if (n == 0) {
        return 1;
    }

    // Recursive case: x^n = x * x^(n-1)
    return x * recursivePow(x, n - 1);
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Calculate x raised to the power n for each element in nums
    for (int i = 0; i < n; i++) {
        int result = recursivePow(nums[i], nums[i]);
        cout << result << " ";
    }
    cout << endl;

    return 0;
}