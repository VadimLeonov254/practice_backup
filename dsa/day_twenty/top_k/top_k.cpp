#include<iostream>
#include<random>
#include<vector>
#include<map>
#include<algorithm>

int main(){
    
    std::map<int, int> n;

    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> dist(1,10);
    
    int num, k;

    std::cout << "Enter the length of the array: ";
    std::cin >> num;
    std::vector<int> nums(num);
    
    std::cout << "Enter top k elements: ";
    std::cin >> k;

    for(int i = 0; i < num; i++){
        nums[i] = dist(gen);
        std::cout << nums[i] << " ";
    }
    
    std::cout << '\n';
    
    for(int i = 0; i < num; i++){
        if(n.find(nums[i]) == n.end()){
            n.emplace(nums[i], 1);
        }else{
            n[nums[i]]++;
        }
    }
    


    for(int i = 0; i < k; i++){
    auto maxEl = std::max_element(n.begin(), n.end(),
    [](const auto& i1, const auto& i2) {
        return i1.second <= i2.second;
    });
    std::cout << maxEl -> first << " ";
        n.erase(maxEl->first);
    }
    
    std::cout << '\n';
}
