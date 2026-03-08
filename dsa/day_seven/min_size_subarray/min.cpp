#include<iostream>
#include<vector>
#include<random>


int main(){

    std::random_device rd;

    std::mt19937 gen(rd());

    std::uniform_int_distribution<> dis(1,100);

    int num, sum, target;
    std::cout << "Enter the length of the vector: ";
    std::cin num;
    
    std::cout << "Enter the target value: ";
    std::cin >> target;

    std::vector<int> nums(num);

    for(int i = 0; i < num; i++){
        nums[i] = dis(gen);
        std::cout << nums[i] << " ";
    }
    std::cout << '\n';

    for(int i = 0, k = 1; k < num; k++){
        sum += nums[k];
        
        while(sum >= target){
            i++;
        }
    }
    




}
