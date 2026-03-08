#include<iostream>
#include<vector>
#include<random>

int main(){

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(-10, 10);
    
    int num, sub;
    int sum = 0;
    int ans = 0;
    std::cout << "Enter the length of the vector: ";
    std::cin >> num;

    std::vector<int> nums(num);
   
    std::cout << "Enter the length of the subarray: ";
    std::cin >> sub;

    for(int i = 0; i < nums.size(); i++){
        nums[i] = dist(gen);
        std::cout << nums[i] << " ";
    }
    std::cout << '\n';

    
    for(int i = 0, k = 0; k < nums.size();){
        while(k < sub){
            ans += nums[k];
            if(k == nums.size()){
                break;
            }
            k++;
        }
        if(k == nums.size()){
            break;
        }
        sum = ans;
        sum -= nums[i];
        sum += nums[k];
        i++;
        k++; 
        if(sum > ans){
            ans = sum;
        }

    }
    
    std::cout << "Maximum average sub of size " << sub << " is " << ans/static_cast<double>(sub) << '\n';

}
