#include<iostream>
#include<vector>
#include<chrono>
#include<random>


int main(){
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::bernoulli_distribution d(0.5);


    int len, num;
    std::cout << "Enter the size of the vector: ";
    std::cin >> len;
    std::vector<int> nums(len);

    std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
    for(int i = 0; i < len; i++){
        num += nums[i];
    }
    std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
    std::chrono::nanoseconds duration_time = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time-start_time);

    std::cout << "Sequential duration per loop: " << duration_time.count()/len << '\n';
    num = 0;
    std::chrono::steady_clock::time_point start_rand = std::chrono::steady_clock::now();
    for(int i = 0; i < len; i++){
        bool b = d(gen);
        if(b){
            num++;
        }
    }
    std::chrono::steady_clock::time_point end_rand = std::chrono::steady_clock::now();
    std::chrono::nanoseconds duration_rand = std::chrono::duration_cast<std::chrono::nanoseconds>(end_rand-start_rand);

    std::cout << "Random duration per loop: " << duration_rand.count()/len << '\n';

}
