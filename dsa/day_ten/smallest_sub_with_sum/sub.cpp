#include<iostream>
#include<vector>
#include<random>

int main(){
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1,10);

    int num, sum;
    int s = 0;
    int len = 0;
    int min_len = 0;
    std::cout << "Enter the length of the vector: ";
    std::cin >> num;
    std::cout << "Enter minimum sum of the subarray: ";
    std::cin >> sum;

    std::vector<int> nums(num);

    for(int i = 0 ; i < nums.size(); i++){
        nums[i] = dist(gen);
        std::cout << nums[i] << " ";
    }

    std::cout << '\n';
    
    for(int i = 0, k = 0; k < nums.size();){
        while(s < sum){
            if(nums[k] == sum){
                min_len = 1;
            }
            s += nums[k];
            k++;
        }
        
        if(i == 0){
            min_len = k;
        }else{
            len = k - i;
        }
        
        if(len <= min_len && len > 0){
            min_len = len;
        }
        
        while(s >= sum){
            s -= nums[i];
            i++; 
        }

        

    } 
    
    std::cout << min_len << '\n';
}
