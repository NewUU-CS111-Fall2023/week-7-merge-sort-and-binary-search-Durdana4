
#include <iostream>
#include <vector>

int findKthMissingPositive(std::vector<int>& arr, int k) {
    int n = arr.size();
    int missingCount = 0;
    int currNum = 1;
    int i = 0;

    while (missingCount < k) {
        if (i < n && arr[i] == currNum) {
            i++;
        } else {
            missingCount++;
        }

        if (missingCount == k) {
            return currNum;
        }

        currNum++;
    }

    return -1; // -1 indicates an error if k is larger than the missing count
}

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    int kthMissing = findKthMissingPositive(arr, k);
    std::cout << kthMissing << std::endl;

    return 0;
}
