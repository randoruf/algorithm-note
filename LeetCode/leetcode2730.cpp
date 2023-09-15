#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        if (s.size() < 2) return s.size();

        int ans = 0; 
        int cnt = 0; 
        int i = 0; 

        for (int j = 1; j < s.size(); j++){    
            if (s[j-1] == s[j]) ++cnt; 
            while (i < j && cnt > 1){ 
                i++;
                if (s[i-1] == s[i]) cnt--; 
            }    
            ans = max(ans, j - i + 1); 
        }

        return ans; 
    }
};


int main(){
    string s = "hello world!"; 
    std::cout << s.substr(0, 4) << "\n"; 
}


