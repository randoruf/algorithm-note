#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        const int n = arr.size(); 
        int j = n-1;
        while (j > 0 && arr[j-1] <= arr[j]){ // 非递减
            j--; 
        }
        if (j == 0){
            return 0 ;
        }
        
        int ans = j; 
        // 枚举 i (i能演进的条件是使得 arr[0..i] 也是非递增)
        for (int i = 0; i + 1 < n ; i++){
            while (j < n && arr[i] > arr[j]){
                j++; 
            }
            ans = min(ans, j - i - 1);
            if (arr[i] > arr[i + 1]) break;
        }
        return ans; 
    }   
};

