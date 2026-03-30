#include<iostream>
#include<vector>
#include<random>
#include<map>

int main(){
    
    std::map<int, int> n;
    n[0] = 1;

    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> dist(-5,5);

    int num, sum;
    int ans = 0; 
    int presum = 0;

    std::cout << "Enter the length of the array: ";
    std::cin >> num;
    
    std::cout << "Enter the sum k subarray should add up to: ";
    std::cin >> sum;

    std::vector<int> nums(num);

    for(int i = 0; i < num; i++){
        nums[i] = dist(gen);
        std::cout << nums[i] << " ";
    }
    std::cout << '\n';

    for(int i = 0, k = 0; k < nums.size(); k++){
        presum += nums[k];
        if(n.find(presum-sum) != n.end()){
            ans += n[presum-sum];
        }
        
        n[presum]++;

    }
    
    std::cout << ans << '\n';

}
