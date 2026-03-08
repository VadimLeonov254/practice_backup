#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>

int main(){


    int num, k, min, max, el;
    int sum = 0;
    float avg;
    std::cout << "Enter the size of the array: ";
    std::cin >> num;
    std::vector<int> nums(num);
    
    std::cout << "Enter " << num << " numbers" << '\n';

    for(int i = 0; i < num; i++){
        std::cin >> el;
        nums[i] = el;
    }
    
    for(int i = 0; i < num; i++){
        std::cout << nums[i] << " ";
    }  
    std::cout << '\n';

    std::cout << "Enter the size of the window: ";
    std::cin >> k;

    for(int i = 0; i < k; i++){
        sum += nums[i];
    }
    avg = static_cast<double>(sum)/k;
    max = *max_element(nums.begin(), nums.begin()+k);
    min = *min_element(nums.begin(), nums.begin()+k);
    std::cout << "Average for the window: " << avg << '\n';
    std::cout << "Maximum for the window: " << max << '\n';
    std::cout<< "Minimum for the window: " << min << '\n';
    std::cout << '\n';
    for(int i = 0; i < num-k; i++){
        sum = sum - nums[i] + nums[i+k];
        avg = static_cast<double>(sum) / k;

        std::cout << i << '\n';

        if(nums[i] == min){
            min = *min_element(nums.begin()+i+1, nums.begin()+i+k+1);
        }else if(nums[i+k] < min){
            min = nums[i+k];
        }
        
        if(nums[i] == max){
            max = *max_element(nums.begin()+i+1, nums.begin()+i+k+1);
        }else if(nums[i+k] > max){
            max = nums[i+k];
        }
        
        std::cout << "Average for the window: " << avg << '\n';
        std::cout << "Maximum for the window: " << max << '\n';
        std::cout<< "Minimum for the window: " << min << '\n';
        std::cout << '\n';       
    }

}
