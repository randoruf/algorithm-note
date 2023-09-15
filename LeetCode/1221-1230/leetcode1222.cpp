#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> ans; 
        int N = 8; 
        int ox = king[0], oy = king[1]; 
        vector<vector<int>> dir = {{-1, -1}, {-1, 0}, {-1, 1}, 
                                   {0, -1},           {0, 1}, 
                                   {1, -1}, {1, 0}, {1, 1}}; 

        for (int i = 0; i < 4; i++){
            int x = ox; 
            int y = oy; 
            while (0 <= x && x < N && 0 <= y && y < N){
                x = x + dir[i][0]; 
                y = y + dir[i][1]; 
                vector<int> cur = {x, y}; 
                if (std::find(queens.begin(), queens.end(), cur) != queens.end()){
                    ans.push_back({x, y});
                    break; 
                }
            }
        }

        return ans;        
    }
};


// int main(){
//     vector<vector<int>> v = {{0,1},{1,0},{4,0},{0,4},{3,3},{2,4}};
//     vector<int> t= {4, 0}; 
//     if (std::find(v.begin(), v.end(), t) != v.end()){
//         std::cout << "Hello World !\n"; 
//     } 
// }


