#include<iostream>
#include<vector>
#include<random>

int main(){
    int len;

    std::vector<int> arra{1,8,9};
    std::vector<int> arrb{2,3,4};
    
    std::vector<int> gen(6);

   int k = 0;
   int j = 0; 

    for(int i = 0; i < 6; i++){
        if(k == 3){
            gen[i] = arrb[j++];
        }else if(j == 3){
            gen[i] = arra[k++];
        }else if (arra[k] <= arrb[j]){
            gen[i] = arra[k++];
        }else{
            gen[i] = arrb[j++];
        }
    }
    
    std::cout << gen[3] << '\n';

    for(int num : gen) std::cout << num << " ";
    std::cout << '\n';

}
