#include<iostream>
#include<memory>
#include<chrono>


struct Test{
    int num = 10;
};


int main(){
    
    size_t n = 1000000;
    
    std::chrono::steady_clock::time_point start_stack = std::chrono::steady_clock::now();
    for(size_t i = 0; i < n; i++){
        Test stack_test;
    }
    std::chrono::steady_clock::time_point end_stack = std::chrono::steady_clock::now();
    std::chrono::nanoseconds duration_stack = std::chrono::duration_cast<std::chrono::nanoseconds>(end_stack - start_stack);
    
    std::cout << "Stack duration: " << duration_stack.count() / static_cast<double>(n) << '\n';


    std::chrono::steady_clock::time_point start_heap = std::chrono::steady_clock::now();
    for(size_t i = 0; i < n; i++){
        Test* heap_test = new Test;
        delete heap_test;
    }
    std::chrono::steady_clock::time_point end_heap = std::chrono::steady_clock::now();
    std::chrono::nanoseconds duration_heap = std::chrono::duration_cast<std::chrono::nanoseconds>(end_heap - start_heap);

    std::cout << "Heap duration: " << duration_heap.count() / static_cast<double>(n) << '\n';

}
