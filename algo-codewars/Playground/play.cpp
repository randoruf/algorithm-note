#include <vector>
#include <algorithm>
#include <iostream>

std::vector<int> countPositivesSumNegatives(std::vector<int> input)
{
    auto is_postive = [](int e){ return e >= 0; }; 
    auto is_negative = [&is_postive](int e){return !is_postive(e); }; 
    int neg_total = 0; 

    for (int e : input){
      if (is_negative(e)){
        neg_total += e; 
      }
    }
    return {static_cast<int>(std::count_if(input.begin(), input.end(), is_postive)), 
            neg_total}; 
}

int main(){
  
  std::vector<int> v = countPositivesSumNegatives({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, -11, -12, -13, -14, -15}); 
  std::cout << v[0] << ", " << v[1] << "\n"; 
}