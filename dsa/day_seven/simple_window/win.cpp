#include<iostream>
#include<vector>
#include<random>
#include<algorithm>

int main(){
    
    std::random_device rd;

    std::mt19937 gen(rd());

    std::uniform_int_distribution<> dis(1, 100);

    int num, win, sum, size;
    std::cout << "Enter the length of the vector: ";
    std::cin >> num;
    std::vector<int> nums(num);
    std::vector<int> sums;


    std::cout << "Enter the length of the window: ";
    std::cin >> win;
    
    for(int i = 0; i < num; i++) nums[i] = dis(gen);

    for(int i = 0; i < num; i++) std::cout << nums[i] << " ";


    std::cout << '\n';
   
    for(int i = 0; i < win; i++){
        sum += nums[i];
    }

    sums.push_back(sum/win);

    for(int i = 1, k = win; k < num; k++){
        sum += nums[k];
        sum -= nums[i-1];
        sums.push_back(sum/win);
        i++;
    }

    for(int i = 0; i < sums.size(); i++) std::cout << sums[i] << " ";

    std::cout << '\n';

   std::cout << "Largest average: " << *max_element(sums.begin(), sums.end()) << '\n';

}
