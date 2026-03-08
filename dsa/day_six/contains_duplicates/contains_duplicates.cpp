#include<iostream>
#include<vector>
#include<map>
#include<random>

int main(){
    
    std::random_device rd;
    std::mt19937 gen(rd());
    
    std::uniform_int_distribution<> distrib(1,100);

    int num;
    bool flag = false;
    std::map<int,int> freq;
    std::cout << "Enter the size of the vector: ";
    std::cin >> num;
    std::vector<int> nums(num);
    for(int i = 0; i < num; i++){
        nums[i] = distrib(gen);
        if(freq.find(nums[i]) != freq.end()){
            flag = true;
            freq[nums[i]]++;
        }else{
            freq.emplace(nums[i],1);
        }
        std::cout << nums[i] << " ";
    }
    
    std::cout << " " << '\n';
    if(flag == true){
        std::cout << "There are duplicates" << '\n';
    }else{
        std::cout << "There are no duplicates" << '\n';
    }
    

}
