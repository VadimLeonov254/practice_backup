#include<iostream>
#include<vector>
#include<algorithm>


int main(){
 
    int num, el, numb;
    std::string ans = "yes";
    std::cout << "Enter the length of the array: ";
    std::cin >> num;
    std::vector<int> nums(num);

    for(int i = 0; i < num; i++){
        std::cin >> el;
        nums[i] = el;
    }
    
    std::cout << "Length of the array is " << nums.size() << '\n';
    for(int i = 0; i < num; i++){
        std::cout << nums[i] << " "; 
    }
    std::cout << '\n';
    
    std::sort(nums.begin(), nums.end());

    while(ans == "yes"){
        std::cout << "Do you wanna add more numbers?" << '\n';
        std::cin >> ans;
        if(ans == "no"){
            break;
        }
        std::cout << "Enter number: ";
        std::cin >> numb;
        if(numb > *std::min_element(nums.begin(), nums.end())){
            for(int i = 0; i < num-1; i++){
                if(numb > nums[i] && numb > nums[i+1]){
                    nums[i] = nums[i+1];
                    if(i == num-2){
                        nums[i+1] = numb;
                    }
                }else if(numb > nums[i] && numb < nums[i+1]){
                    nums[i] = numb;
                    break;
                }
            }
        }
        for(int i = 0; i < num; i++){
            std::cout << nums[i] << " "; 
        }
        std::cout << '\n';   
    }


}
