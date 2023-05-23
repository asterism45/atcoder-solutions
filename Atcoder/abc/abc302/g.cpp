#include <iostream>
#include <vector>

using namespace std;

int min_operations_to_sort(int n, vector<int>& a) {
    vector<int> counts(5, 0);
    for(int i = 0; i < n; i++) {
        counts[a[i]]++;
    }
    
    vector<int> boundaries(5, 0);
    for(int i = 1; i <= 4; i++) {
        boundaries[i] = boundaries[i-1] + counts[i];
    }
    
    int operations = 0;
    vector<int> position_counts(5, 0);
    for(int i = 0; i < n; i++) {
        int number = a[i];
        if(i < boundaries[number-1] || i >= boundaries[number]) {
            operations++;
        }
        position_counts[number]++;
        boundaries[number-1] += position_counts[number-1];
    }
    
    return operations;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << min_operations_to_sort(n, a) << endl;
    return 0;
}
