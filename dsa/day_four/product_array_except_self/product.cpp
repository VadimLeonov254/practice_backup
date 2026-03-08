#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>



int main(){
    
    int num = 1;
    int numm;
    int left_prod = 1;
    int right_prod = 1;
    std::vector<int> left_prods;
    std::cout << "Enter the length of the vector: ";
    std::cin >> numm;
    std::vector<int> nums(numm);
    std::vector<int> answer(numm);

    std::vector<int> right_prods(numm);

    std::unordered_map<int, int> let;

    for(int i = 0; i < numm; i++){
        std::cin >> num;
        nums[i] = num;
    }
   
    for(int i = 0; i < nums.size(); i++){
        left_prods.push_back(left_prod);
        left_prod *= nums[i];
        right_prods[numm-i-1] = right_prod;
        right_prod *= nums[numm-i-1];
    }
    
    for(int i = 0; i < numm; i++){
        answer[i] = left_prods[i] * right_prods[i];
    }

    for(int i = 0; i < numm; i++){
        std::cout << answer[i] << " ";
    } 
    std::cout << '\n';

}
