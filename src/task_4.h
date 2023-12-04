#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Function to find the kth smallest element in the matrix
int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n;
    n = matrix.size();

    // Create a min-heap to store the elements of the matrix
    priority_queue<int, vector<int>, greater<>> minHeap;

    // Push the first element of each row into the min-heap
    for (int i = 0; i < n; i++) {
        minHeap.push(matrix[i][0]);
    }

    // Extract the kth smallest element from the min-heap
    while (k > 1) {
        int smallest = minHeap.top();
        minHeap.pop();

        // Push the next element from the same row into the min-heap
        int row = smallest / n;
        int col = smallest % n;
        if (col < n - 1) {
            minHeap.push(matrix[row][col + 1]);
        }

        k--;
    }

    return minHeap.top();
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> matrix(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    // Find the kth smallest element in the matrix
    int kthSmallestElement = kthSmallest(matrix, k);

    cout << kthSmallestElement << endl;

    return 0;
}