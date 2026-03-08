#include<iostream>
#include<vector>
#include<cmath>
#include<chrono>
#include<random>
#include<cstdlib>

int main(){
    std::vector<int> nums(256 * std::pow(2, 20));

    for(int i = 0; i < nums.size(); i++){
        nums[i] = i;
    }

    std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
    
    for(int i = 0; i < nums.size(); i++){
        nums[i]++;
    }

    std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();

    std::chrono::nanoseconds duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);

    std::cout << "Average sequential time: " << duration.count()/(256 * std::pow(2,20)) << '\n';
    

    for(int i = 0; i < nums.size(); i++){
        nums[i] = rand() % 2560000;
    }
    
    std::chrono::steady_clock::time_point start_time_rand = std::chrono::steady_clock::now();
    for(int i = 0 ; i < nums.size(); i++){
        nums[rand()%(256*(1<<20))]++;
    }

    std::chrono::steady_clock::time_point end_time_rand = std::chrono::steady_clock::now();

    std::chrono::nanoseconds duration_rand = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time_rand - start_time_rand);
    std::cout << "Average random time: " << duration_rand.count()/(256 * std::pow(2,20)) << '\n';


}
