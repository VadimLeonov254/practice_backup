#include <iostream>
#include <vector>

int main() {
    std::vector<int> v;

    for (int i = 0; i < 1000000; i++) {
        v.push_back(i);
    }


    std::cout << "Size: " << v.size() << '\n' << "Capacity: " << v.capacity() << '\n';

    std::vector<int> v_res;
    v_res.reserve(1000000);

    for(int i = 0; i < 1000000; i++){
        v_res.push_back(i);
    }

    std::cout << "Size: " << v_res.size() << '\n' << "Capacity: " << v_res.capacity() << '\n';
}
