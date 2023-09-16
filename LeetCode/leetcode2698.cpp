#include <cstdio>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canPartitioned(int target, string currPattern){
        if (currPattern.empty()) return false; 
        if (target == stoi(currPattern)) return true;
        for (int i = 1; i <= currPattern.size() - 1; i++){
            // std::cout << currPattern.substr(0, i) << ", " << currPattern.substr(i) << "\n"; 
            int x = stoi(currPattern.substr(0, i));
            if (x > target) return false;
            if (canPartitioned(target - x, currPattern.substr(i))){
                return true;
            }
        }
        return false;
    }

    int punishmentNumber(int n) {
        int ans = 0; 
        for (int i = 1; i <= n; i++){
            if (canPartitioned(i, to_string(i * i))){
                ans += (i * i); // local cache, no need to optimize? 
            }
        }
        return ans; 
    }
};






int main(){
    auto s = Solution(); 
    s.punishmentNumber(45); 

}
