#include<iostream>
#include<vector>
#include<random>

int atMost(std::vector<int>& nums, int j){
    
    int sum = 0;

    int ans = 0;

    for(int i = 0, k = 0; k < nums.size(); k++){
        sum += nums[k];

        while(sum > j){
            sum -= nums[i];
            i++;
        }
        
        ans += (k-i+1);

    }

    return ans;

}

int main(){
    
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> dist(0,1);



    int num, bin;

    std::cout << "Enter the size of the vector: ";
    std::cin >> num;
    std::vector<int> nums(num);
    
    std::cout << "Enter the sum of the subvector: ";
    std::cin >> bin;

    for(int i = 0; i < num; i++){
        nums[i] = dist(gen);
        std::cout << nums[i] << " ";
    }
    std::cout << '\n';

   std::cout << atMost(nums, bin) - atMost(nums, bin - 1) << '\n';; 

}
