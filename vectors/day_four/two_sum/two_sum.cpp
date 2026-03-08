#include<iostream>
#include<vector>
#include<random>
#include<algorithm>
#include<unordered_map>

int main(){
    
    int num, n;


    std::cout << "Enter the length of the array: ";
    std::cin >> num;
    std::vector<int> nums(num);

    for(int i = 0; i < num; i++){
        nums[i] = rand()%11;
    }
    
    std::cout << "Enter the number: ";
    std::cin >> n;
    
    std::cout << "Your array:" << '\n';
    for(int numb : nums){
        std::cout << numb << " ";
    }
    std::cout << '\n';

    std::unordered_map<int, int> seen;

    for(int i = 0; i < num; i++){
        int need = n - nums[i];

        if(seen.count(need)){
            std::cout << seen[need] << " " << i << '\n'; 
        }

        seen[nums[i]] = i;

    }    
    
    std::cout << "Nothing was found:(" << '\n';

}
