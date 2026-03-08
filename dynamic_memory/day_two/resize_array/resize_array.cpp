#include<iostream>

int main(){
    
    int size, a, n, num;
    std::string ques;
    
    std::cout << "Enter the number of the array: ";
    std::cin >> size;
    
    int* data = new int[size];
    
    std::cout << "Enter " << size << " numbers" << std::endl;

    for(int i = 0; i < size; i++){
        std::cin >> a;
        data[i] = a;
    }

    while(ques != "no"){

        std::cout << "Your array:" << std::endl;

        for(int i = 0; i < size; i++){
            std::cout << data[i] << " ";
        }

        std::cout << std::endl;
    
        std::cout << "Do you want to add more numbers to the array? (yes/no)" << std::endl;
        std::cin >> ques;
        if(ques == "Yes" || ques == "yes"){
            std::cout << "Enter how many numbers you want to add: ";
            std::cin >> n;
            
            std::cout << "Enter " << n << " numbers" << std::endl;

            int* newData = new int[size + n];
            for(int i = 0; i < size; i++){
                newData[i] = data[i];
            }
            delete[] data;

            data = newData;
            size += n;
               
            for(int i = size-n; i < size; i++){
                std::cin >> a;
                data[i] = a;
            }
            
        }
            
    }
    std::cout << "Have a nice day!" << std::endl;

}
