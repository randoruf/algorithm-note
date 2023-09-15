#include <algorithm>
#include <vector>

using namespace std;


class Solution {
public:
    int giveGem(vector<int>& old_gem, vector<vector<int>>& operations) {
        vector<int> gem = old_gem; 
        for (auto op : operations){
            int x = op[0], y = op[1]; 
            int gift = gem[x] / 2; 
            gem[x] = gem[x] - gift; 
            gem[y] = gem[y] + gift; 
        }
        return *std::max_element(gem.begin(), gem.end()) - *std::min_element(gem.begin(), gem.end()) ; 
    }
};

