#include<iostream>
#include<vector>
#include<random>
#include<map>

int main(){
    
    std::random_device rd;

    std::mt19937 gen(rd());

    std::uniform_int_distribution<> dist(1,10);

    int num, s;
    int sum = 0;
    int ans = 0;
    std::cout << "Enter the length of the vector: ";
    std::cin >> num;
    std::vector<int> nums(num);
    
    std::cout << "Enter the sum subarrays should add up to: ";
    std::cin >> s;

    for(int i = 0; i < num; i++){
        nums[i] = dist(gen);
        std::cout << nums[i] << " ";
    }

    std::cout << '\n';
    
    for(int i = 0, k = 0; k < num;){
        
        std::cout << "sum " << sum << '\n';
        
        if(sum < s){
            sum += nums[k];
            k++;
        }else if(sum == s){
            ans++;
            sum -= nums[i];
            i++;
        }else if(sum > s){
            sum -= nums[i];
            i++;
        }

        if(i > k){
            k = i;
        }
        

        std::cout << "k " << k << '\n';

    }
    
    std::cout << ans << '\n';

}
