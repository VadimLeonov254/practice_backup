#include<iostream>
#include<vector>
#include<random>

int atMost(std::vector<int>& nums, int j){
    int count_odd = 0;
    int ans = 0;

    for(int i = 0, k = 0; k < nums.size(); k++){
        if(nums[k] % 2 == 1){
            count_odd++;
        }

        while(count_odd > k){
            if(nums[i] & 2 == 1){
                count_odd-;
            }
            i++;
        }

        ans += (k-i+1);

    }

    return ans;

}

int main(){
    
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> dist(1,10);
    
    int num, odd;
    
    std::cout << "Enter the length of the vector: ";
    std::cin >> num;
    std::vector<int> nums(num);
    
    std::cout << "Enter the number of the odd numbers in subarray: ";
    std::cin >> odd;

    for(int i = 0; i < num; i++){
        nums[i] = dist(gen);
        std::cout << nums[i] << " ";
    }
    
    std::cout << '\n';
    
    int ans = atMost(nums, odd) - atMost(nums, odd - 1);

    std::cout << ans << '\n';

}
