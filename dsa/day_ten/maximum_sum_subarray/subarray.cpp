#include<iostream>
#include<vector>
#include<random>

int main(){
    
    std::random_device rd;

    std::mt19937 gen(rd());

    std::uniform_int_distribution<> dist(1,10);

    int num, s;
    int sum = 0;
    int ans = 0;
    std::cout << "Enter the length of the vector: ";
    std::cin >> num;

    std::cout << "Enter the size of subarray: ";
    std::cin >> s;

    std::vector<int> nums(num);

    for(int i = 0; i < num; i++){
        nums[i] = dist(gen);
        std::cout << nums[i] << " ";
    }

    std::cout << '\n';

    for(int i = 0, k = 0; k < nums.size(); k++){
        if(k <= s-1){
            sum += nums[k];
            ans = sum;
        }else{
            sum = sum - nums[i] + nums[k];
            if(sum > ans){
                ans = sum;
            }
            i++;
        }

        std::cout << "k " << k << " i " << i << '\n';

    }

    std::cout << ans << '\n';

}
