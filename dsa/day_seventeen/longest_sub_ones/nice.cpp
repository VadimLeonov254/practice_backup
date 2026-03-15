#include<iostream>
#include<vector>
#include<random>

int main(){
    
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> dist(0,1);

    int num;
    
    int curr = 0;
    int ans = 0;
    int zeros = 0;
    int ones = 0;

    std::cout << "Enter the length of the vector: ";
    std::cin >> num;

    std::vector<int> nums(num);
    
    for(int i = 0; i < num; i++){
        nums[i] = dist(gen);
        std::cout << nums[i] << " ";
    }
    
    std::cout << '\n';

    for(int i = 0, k = 0; k < num; k++){
       
        if(nums[k] == 0){
            zeros++;
        }else{
            ones++;
        }
        
        if(zeros == 1 && ones > 0){
            if(ones > ans){
                ans = k-i;
            }
        }else if(zeros > 1){
            if(nums[i] == 0){
                zeros--;
            }else{
                ones--;
            }
            i++;
        }

    }

    std::cout << ans << '\n';

}
