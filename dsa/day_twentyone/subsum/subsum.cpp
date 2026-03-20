#include<iostream>
#include<map>
#include<vector>
#include<random>

int main(){
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 10);


    int s;
    
    int curr = 0;
    int ans = 0;

    std::vector<int> nums{1,2,3};
    
    int num = nums.size();

    std::map<int, int> n = {{0, 1}};
    
    std::cout << "Enter the number subs should add up to: ";
    std::cin >> s;


    for(int k = 0; k < num; k++){
        curr += nums[k];
        if(n.find(curr-s) != n.end()){
            ans += n[curr-s];
        }
        
        n[curr]++;

    }
    
    std::cout << ans << '\n';

}
