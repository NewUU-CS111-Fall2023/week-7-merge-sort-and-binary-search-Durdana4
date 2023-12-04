#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to merge two sorted arrays into one sorted array
vector<int> mergeSortedArrays(vector<int>& arr1, vector<int>& arr2) {
    vector<int> merged;

    int n = arr1.size();
    int m = arr2.size();
    int i = 0, j = 0;

    // Merge the arrays in non-increasing order
    while (i < n && j < m) {
        if (arr1[i] >= arr2[j]) {
            merged.push_back(arr1[i]);
            i++;
        } else {
            merged.push_back(arr2[j]);
            j++;
        }
    }

    // Add the remaining elements from arr1, if any
    while (i < n) {
        merged.push_back(arr1[i]);
        i++;
    }

    // Add the remaining elements from arr2, if any
    while (j < m) {
        merged.push_back(arr2[j]);
        j++;
    }

    return merged;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;

        vector<int> arr1(N);
        vector<int> arr2(M);

        for (int i = 0; i < N; i++) {
            cin >> arr1[i];
        }

        for (int i = 0; i < M; i++) {
            cin >> arr2[i];
        }

        // Merge the arrays into one sorted array
        vector<int> merged = mergeSortedArrays(arr1, arr2);

        // Print the merged array
        for (int i = 0; i < merged.size(); i++) {
            cout << merged[i] << " ";
        }
        cout << endl;
    }

    return 0;
}