#include<iostream>
#include<random>
#include<vector>
#include<map>
int atMost(std::vector<int>& nums, int j){
    std::map<int, int> ch;
    int ans = 0;
    int dist = 0;
    for(int i = 0, k = 0; k < nums.size(); k++){
        if(ch.find(nums[k]) == ch.end()){
            ch.emplace(nums[k], 1);
            dist++;
            }else{
                ch[nums[k]]++;
            }while(dist > j){
                if(ch[nums[i]] == 1){
                    dist--;
                } 
                ch[nums[i]]--;
                i++;
            }
            if(dist <= j){
                ans += (k-i+1);
            }
    }
    return ans;
}
int main(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1,10);
    int num, sub;
    int ans_a = 0;
    int ans_b = 0;
    int dista = 0;
    std::map<int, int> n;
    std::cout << "Enter the length of the array: ";
    std::cin >> num;
    std::vector<int> nums(num);
    std::cout << "Enter the number of the distinct integers in a subarray: ";
    std::cin >> sub;
    for(int i = 0; i < num; i++){
        nums[i] = dist(gen);
        std::cout << nums[i] << " ";
    }
    std::cout << '\n';
    int a = atMost(nums, sub);
    int b = atMost(nums, sub-1);
    std::cout << a-b << '\n';
}
