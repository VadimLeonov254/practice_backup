#include<iostream>
#include<algorithm>

int* compressRow(const int* row, int M, int& outSize){
    int* data;

    data = new int[outSize];

    for(int i = 0, k = 0; i < M; i++){
        if(row[i] != 0){
            data[k] = row[i];
            k++;
        }
    }
    return data;
}


int* decompressRow(const int* compressed, int compressed size, int M){
    
}


int main(){
    
    int outSize;
    
    int arr[3][4] = {{0,5,0,2},
                     {1,0,0,0},
                     {3,0,4,0}
                    };
    
    for(int i = 0; i < std::size(arr); i++){
        outSize = 4 - std::count(std::begin(arr[i]), std::end(arr[i]), 0);
        
        std::cout << *compressRow(arr[i], 4, outSize);

    }


}
