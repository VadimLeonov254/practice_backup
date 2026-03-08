#include<iostream>
#include<vector>
#include<random>


int main(){
    
    std::vector<std::vector<int>> log_base;
    std::vector<int> logs (1000000);
    std::string ans = "yes";

    while(ans != "no"){
        std::cout <<  "Do you want to collect logs?" << '\n';
        std::cin >> ans;
        if(ans == "no"){
            break;
        }else{
            for(int i = 0; i < 1000000; i++){
                logs[i] = rand() % 101;
            }
            log_base.push_back(logs);
        }
    }
   
   std::cout << log_base.size() << '\n'; 

}
