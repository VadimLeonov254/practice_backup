#include<iostream>
#include<vector>
#include<chrono>

struct Position{
    float x, y, z;
    float vx, vy, vz;
};

struct Position_arr{
    std::vector<float> x,y,z;
    std::vector<float> vx,vy,vz;
};

int main(){
    
    long n = 100000000;

    std::vector<Position> pos(n);
    
    Position_arr p;

    p.x.resize(n);
    p.y.resize(n);
    p.z.resize(n);
    p.vx.resize(n);
    p.vy.resize(n);
    p.vz.resize(n);
    
    auto start_soa = std::chrono::steady_clock::now();
    for(long i = 0; i < n; i++){
        p.x[i]++;
        p.y[i]++;
        p.z[i]++;
    }
    auto end_soa = std::chrono::steady_clock::now();
    auto duration_soa = std::chrono::duration_cast<std::chrono::nanoseconds>(end_soa - start_soa);

    std::cout << "Duration SOA: " << duration_soa.count() / static_cast<double>(n) << '\n';

    auto start_aos = std::chrono::steady_clock::now();
    for(long i = 0; i < n; i++){
        pos[i].x++;
        pos[i].y++;
        pos[i].z++;
    }
    auto end_aos = std::chrono::steady_clock::now();
    auto duration_aos = std::chrono::duration_cast<std::chrono::nanoseconds>(end_aos - start_aos);

    std::cout << "Duration AOS: " << duration_aos.count() / static_cast<double>(n) << '\n';
}
