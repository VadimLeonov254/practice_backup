#include<iostream>
#include<vector>
#include<random>

int main(){

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1,100);
    
    int day;
    std::cout << "Enter the number of the number of days: ";
    std::cin >> day;
    std::vector<int> days(day);

    int mini_pos = 0;
    int maxi_pos = 1;
    
    int profit = 0;

    for(int i = 0; i < day; i++){
        days[i] = dist(gen); 
    }
   
    int mini = days[0];
    int maxi = days[1];
    
    for(int i = 0; i < day; i++) std::cout << days[i] << " ";

    std::cout << '\n';

    for(int i = 0; i < day; i++){
        if(days[i] < mini && i != day-1){
            mini = days[i];
            mini_pos = i;
            if(mini_pos > maxi_pos){
                maxi_pos = mini_pos;
                maxi = mini;
            }
        }else if(days[i] > maxi && i > mini_pos && days[i] - mini > profit){
            maxi = days[i];
        }
    }
    
    std::cout << "Buy at " << mini << '\n';
    std::cout << "Sell at " << maxi << '\n';

}
