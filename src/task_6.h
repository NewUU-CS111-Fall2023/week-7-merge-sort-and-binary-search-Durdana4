#include <iostream>
#include <vector>

using namespace std;

// Function to search for the target value in the sorted array
pair<int, int> searchInsert(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return {1, mid}; // Target found
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return {-1, left}; // Target not found, return the index where it would be inserted
}

int main() {
    int size;
    cin >> size;

    vector<int> nums(size);
    for (int i = 0; i < size; i++) {
        cin >> nums[i];
    }

    int target;
    cin >> target;

    // Search for the target value in the sorted array
    pair<int, int> result = searchInsert(nums, target);

    // Print the result
    cout << result.first << " " << result.second << endl;

    return 0;
}