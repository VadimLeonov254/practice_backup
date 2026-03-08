![C++](https://img.shields.io/badge/C++-17-blue)

# Array of Structures vs Structure of Arrays

## The goal of this lab is to measure the difference between: ##

- Access to the element through the arrays of structure
- Access to the element through the structures of an array

Both tests perform the same operation (++ on every element of the arrays), but differ in how memory is accessed.

Hypothesis: Array of structures will be faster because it represents the logical sequence of operations, making it easier for the compiler to access it.

---

## Experimental setup:
Hardware
- CPU: AMD Ryzen 5 2600 Six-Core Processor
- L1 Cache: 96 KB (per core)
- L2 Cache: 512 KB (per core)
- L3 Cache: 16 MB (shared)
- RAM: 16 GB<br>

Compiler
G++ 13.3.0

---

## Declaration of AoS and SoA

**SoA:**

    struct Position_arr{
        std::vector<float> x,y,z;
        std::vector<float> vx,vy,vz;
    };

**AoS:**

    struct Position{
        float x,y,z;
        float vx,vy,vz;
    };

And then, we create a vector of 10^8 elements for both structures in int main()

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

        }

 
**What does it mean?**

We started by creating a variable named n with the value 10^8 to ensure we use the same numbers throughout the program. After that, we create a vector pos
with the length of n - this is our *Array of Structures*<br><br>
Then, we create an instance of the structure **Position_arr, p**. Once we create it, we can access every array from the structure to make their lengths
equal to n. This is our *Structure of arrays*.

# Theory background
## Cache lines

Modern CPUs fetch memory in cache lines, which are typically 64 bytes "long". Each float weighs 4 bytes.

Thus, each cache line contains **64/4 = 16** floats

The CPU does not load individual variables — it loads entire cache lines.

## Memory layout — AoS

Given:

    struct Position{
        float x,y,z;
        float vx,vy,vz;
    };
    
Each **Position** element consists of 6 floats:
6 * 4 = 24 bytes

So, one cache line holds 64 / 24 = 2 whole elements

If x,y,z are the only ones updated, then per **Position** element:
- 3 floats are used
- 3 floats are unused

Meaning 50% of the loaded data is irrelevant to the operation.

Bandwidth is partially wasted.

## Memory layout — SoA

Given:

    struct Position_arr{
        std::vector<float> x,y,z;
        std::vector<float> vx,vy,vz;
    };

Each array is contiguous in memory.

For example, an array with 16 floats *x*:

    x x x x x x x x x x x x x x x x

Here, 16 * 4 bytes = 64 bytes -> onr cache line contains 16 useful floats

With this in mind, we get that each vector gets its own part of the memory and never interacts with vx/vy/vz, because, unlike the AoS case, there is no way for them to get in the way, as they are not on the same 
cache line with the vector

## Consequence

When updating only position data (x, y, z):
- Cache lines loaded from memory contain only position values.
- Velocity arrays (vx, vy, vz) reside in entirely separate memory regions.
- No cache line that services position updates contains velocity data.

When we iterate through SoA, we iterate through a continuous vector of floats; everything is pretty and predictable.

When we iterate through AoS, however, we are going over something like this:

    [x y z vx vy vz][x y z vx vy vz][x y z vx vy vz]...

We deal with a bunch of 24-byte objects.

# Benchmarks(using chrono timer)

*SoA:* 9.9 ns per loop
*AoS:* 15.7 ns per loop

SoA is 1.6 times faster than AoS.

Doesn't sound like a lot, does it? 

Now think further - the difference is 1.6 times **per loop** and we have 10^8 of these loops.

# Conclusion

The experiment demonstrates that memory layout significantly affects performance when operating on large datasets.

When only a subset of fields is accessed, the Structure of Arrays (SoA) layout achieves higher cache efficiency because each cache line contains exclusively relevant data. This reduces unnecessary memory traffic and improves effective bandwidth utilization.

In contrast, the Array of Structures (AoS) layout interleaves used and unused fields within the same cache lines. As a result, velocity data is loaded into cache even when it is not accessed, leading to wasted bandwidth.

Therefore, for workloads that operate on specific fields independently, SoA provides better performance due to improved cache line utilization and reduced memory overhead.
