#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> factors;
    for(int i = 1; i <= n; i++) {
        if(n % i == 0) {
            factors.push_back(i);
        }
    }

    if(k > factors.size()) {
        cout << "-1";
    } else {
        cout << factors[k-1] << "\n";
    }

    return 0;
}