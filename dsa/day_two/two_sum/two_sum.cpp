#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>

int main(){
    std::map<int, int> check;
    std::vector<int> nums;
    std::deque<int> ans;
    int t, mi, ma;
    int n = 1;
    
    bool done = false;

    while(n != 0){
        std::cout << "Enter the number to continue/0 to finish typing" << '\n';
        std::cin >> n;
        if(n != 0){
            nums.push_back(n);
        }
    }
    
    std::cout << "Enter the target number: ";
    std::cin >> t;
    

    for(int i = 0; i < nums.size(); i++){
        if(check.find(nums[i]) != check.end() && nums[i]*2 == t){
            std::cout << check[nums[i]] << " " << i << '\n';
            done = true;
            break;
        }else{
            check.emplace(nums[i], i);
        }
    }
    
    if(done == false){
        for(int i = 0; i < nums.size(); i++){
            if(check.find(t-nums[i]) != check.end()){
                ans.push_back(std::min(nums[i], t-nums[i]));
                ans.push_back(std::max(nums[i], t-nums[i]));
                if(ans[0] != ans[1]){
                    if(check[ans[0]] < check[ans[1]]){
                        std::cout << check[ans[0]] << " " << check[ans[1]] << '\n';
                    }else{
                        std::cout << check[ans[1]] << " " << check[ans[0]] << '\n';
                    }
                }else{
                    std::cout << "Not found!" << '\n';
                }
                std::cout << "Not found!" << '\n';
            }
        }
    }

    std::cout << "Not found!" << '\n';

}
