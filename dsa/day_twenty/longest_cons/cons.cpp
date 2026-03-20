#include<iostream>
#include<vector>
#include<set>
#include<random>

int main(){

    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> dist(1,10);
    
    int num;
    
    int ans = 0;
    int curr = 0;

    std::cout << "Enter the length of the vector: ";
    std::cin >> num;

    std::vector<int> nums(num);
    std::set<int> n;

    for(int i = 0; i < num; i++){
        nums[i] = dist(gen);
        std::cout << nums[i] << " ";
        n.insert(nums[i]);
    }
    
    std::cout << '\n';
    
    for(int i = 0; i < n.size()-1; i++){
        if(n[i+1] - n[i] == 1){
            curr++;
        }

        if(curr > ans){
            ans = curr;
            curr = 0;
        }

    }
    
    std::cout << ans << '\n';

}
