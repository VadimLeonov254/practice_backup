#include<iostream>
#include<random>
#include<vector>
#include<set>


bool dup(std::vector<int>& nums){
    std::set<int> numu;

    for(int i = 0; i < nums.size(); i++){
        if(numu.find(nums[i]) != numu.end()){
            return true;
        }else{
            numu.insert(nums[i]);
        }
    }
    
    return false;

}

int main(){
        
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> dist(1,10);
    
    int num;

    std::cout << "Enter the length of the vector: ";
    std::cin >> num;    
    std::vector<int> nums(num);
    
    for(int i = 0; i < num; i++){
        nums[i] = dist(gen);
        std::cout << nums[i] << " ";
    }
    
    std::cout << '\n';
    
    if(dup(nums) == 1){
        std::cout << "True" << '\n';
    }else{
        std::cout << "False" << '\n';
    }

}
