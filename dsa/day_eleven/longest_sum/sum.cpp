#include<iostream>
#include<vector>
#include<random>

int main(){
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0,10);

    int num, sub;
    int sum = 0;
    int len = 0;
    std::cout << "Enter the length of the vector: ";
    std::cin >> num;
    
    std::vector<int> nums(num);
    
    std::cout << "Enter the maximum sum of the subarray: ";
    std::cin >> sub;    

    for(int i = 0; i < nums.size(); i++){
        nums[i] = dist(gen);
        std::cout << nums[i] << " ";
    }
    std::cout << '\n';

    for(int i = 0, k = 0; k < nums.size();){
        while(sum <= sub){
            sum += nums[k];
            k++;
        }
        
        if(i == 0){
            len = k-1;
        }else{
            if(k-1-i > len){
                len = k-1-i;
            }
        }

        while(sum > sub){
            sum -= nums[i];
            i++;
        }

        if(k >= nums.size()){
            break;
        } 

    }
    
    std::cout << len << '\n';

}
