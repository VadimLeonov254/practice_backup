#include<iostream>
#include<vector>
#include<random>

int main(){
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1,10);
    
    int num, odd;
    
    int count_odd = 0;
    int ans = 0;
    int prefix = 0;

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
    for(int i = 0, k = 0; k < nums.size();){

        if(nums[k] % 2 == 1){
            count_odd++;
        }
        
        while(count_odd > odd){
            if(nums[i] % 2 == 1){
                count_odd--;
            }
            i++;
        }

        if(count_odd == odd){
            int temp = i;
            while(temp <= k && nums[temp] % 2 == 0){
                ans++;
                temp++;
            }
            ans++;
        }

        k++;
    }
    std::cout << ans << '\n';
}
