#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// Function to compare the frequencies of elements
struct FrequencyComparator {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    }
};

// Function to return the k most frequent elements in nums
vector<int> topKFrequent(vector<int>& nums, int k) {
    int n = nums.size();

    // Create a frequency map to count the occurrences of elements
    unordered_map<int, int> frequencyMap;
    for (int i = 0; i < n; i++) {
        frequencyMap[nums[i]]++;
    }

    // Create a max-heap to store the k most frequent elements
    priority_queue<pair<int, int>, vector<pair<int, int>>, FrequencyComparator> maxHeap;

    // Push the elements and their frequencies into the max-heap
    for (auto& entry : frequencyMap) {
        maxHeap.push(entry);
        if (maxHeap.size() > k) {
            maxHeap.pop();
        }
    }

    // Extract the k most frequent elements from the max-heap
    vector<int> result;
    while (!maxHeap.empty()) {
        result.push_back(maxHeap.top().first);
        maxHeap.pop();
    }

    // Reverse the result to get the elements in the desired order
    reverse(result.begin(), result.end());

    return result;
}

int main() {
    int size;
    cin >> size;

    vector<int> nums(size);
    for (int i = 0; i < size; i++) {
        cin >> nums[i];
    }

    int k;
    cin >> k;

    // Find the k most frequent elements in nums
    vector<int> kMostFrequent = topKFrequent(nums, k);

    // Print the k most frequent elements
    for (int i = 0; i < kMostFrequent.size(); i++) {
        cout << kMostFrequent[i] << " ";
    }
    cout << endl;

    return 0;
}