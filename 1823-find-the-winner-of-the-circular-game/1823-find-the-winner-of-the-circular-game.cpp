class Solution {
public:
   int win(int n, int k, int sum, int j, vector<int>&arr) {
    if (n == 1) {
        return sum;
    }
    j = (j + k-1) % n;
    int removed = arr[j];            
    arr.erase(arr.begin() + j);
    if (j == arr.size()) {
        j = 0;
    }      
    return win(n - 1, k, sum - removed, j, arr); 

}

int findTheWinner(int n, int k) {
    vector<int> arr(n);
    int sum, j = 0;
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
    sum = n * (n + 1) / 2;
    return win(n, k, sum, j, arr);
}

};