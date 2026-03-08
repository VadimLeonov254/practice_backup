#include<iostream>
#include<vector>
#include<random>
#include<algorithm>

int main(){
    int num, count;
    std::cout << "Enter the number of elements of the array: ";
    std::cin >> num;
    std::vector<int> nums(num);

    for(int i = 0; i < num; i++){
        nums[i] = rand() % 10;
    }

    count = std::count(nums.begin(), nums.end(), 0); 

    for(int i = 0; i < num; i++){
        if(nums[i] == 0){
            nums.erase(nums.begin()+i);
            nums[num-1] = 0;
            count--;
        }
        if(count == 0){
            break;
        }
    }
    
    
    for(int i = 0; i < num; i++){
        std::cout << nums[i] << " ";
    }
    std::cout << '\n';

}
