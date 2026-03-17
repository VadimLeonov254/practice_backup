#include<iostream>
#include<map>
#include<vector>
#include<random>
#include<algorithm>

int main(){
    
    std::map<int, int> ns;
    std::map<int, int> ns_q;


    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> dist(1,10);
    
    int num, sum;

    std::cout << "Enter the length of the array: ";
    std::cin >> num;
    
    std::cout << "Enter the sum: ";
    std::cin >> sum;
    
    std::vector<int> nums(num);

    for(int i = 0; i < num; i++){
        nums[i] = dist(gen);
        std::cout << nums[i] << " ";
    }
    
    std::cout << '\n';

    for(int i = 0; i < num; i++){
        if(ns.find(nums[i]) == ns.end()){
            ns.emplace(nums[i], i);
        }
    }
    
    for(int i = 0; i < num; i++){
        if(ns.find(sum - nums[i]) != ns.end()){
            std::cout << std::min(i, ns[sum-nums[i]]) << " " << std::max(i, ns[sum-nums[i]]) << '\n';
            break;
        }
    }

}
