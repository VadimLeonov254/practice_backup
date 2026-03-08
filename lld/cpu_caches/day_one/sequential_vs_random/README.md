[![C++](https://img.shields.io/badge/C++-17-blue)](https://isocpp.org/)  

# Sequential vs Random Memory Access



## The goal of this lab is to measure the performance difference between:<br> 
- Sequential memory access
- Random memory access

Both tests perform the same operation (++ on an int), but differ in how memory is accessed.

Hypothesis: sequential access will be significantly faster due to better CPU cache utilization and spatial locality than random access.

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
## Data size calculation

    std::vector<int> nums(256 * 1 << 20);
    
But what does it mean?<br>

We have 256 * 2^20 elements in the vector, which is equal to 268435456. Given that each integer takes up 4 bytes, we get that the total size of our vector is 1073741824 bytes, which is exactly 1 GB, 
which is way larger than the L3 cache in the processor used in the experiment.<br>

Vector nums guarantees that most accesses will go to RAM immediately.

---

## Theory background
Cache lines:

Modern CPUs fetch memory in cache lines, which are typically 64 bytes "long". Each integer weighs 4 bytes.

Thus, each cache line contains **64/4 = 16** integers

---

## Sequential access

When accessing nums, 

nums[0], nums[1], nums[2], nums[3], ..., nums[n]

What happens is, when i in nums[i] is increased by 1 every single time, all the way to 256 * 1<<20, the compiler, using a cache line provided by a processor, can see the next 15 integers on this cache line. 
However, it does not provide the exact values until they have been called.

---

## Random access

When accessing nums[i], where i in rand() % (256 * 1<<20),

It goes all over the place, causing nums[i] to go all over the place as well.

What happens is, when i in nums[i] is randomly generated, it's not guaranteed that it will land on the next prefetched 15 integers from the previous call of the nums[i], where i follows the conditions provided above.

With this, we expect a drastic spike in latency, because now, the compiler has no choice but to get out of the cache line and probably even beyond the L3 cache, just to catch the i.

---

## Code structure

**Sequential phase:**

    for(int i = 0; i < nums.size(); i++){
        nums[i]++;
    }
---
**Random phase:**

    for(int i = 0 ; i < nums.size(); i++){
        nums[rand()%(256*(1<<20))]++;
    }

## Benchmarks(using chrono timer)

*Sequential:* 8.55 ns
*Random:* 107.275 ns

**Random access is 12.5 times slower(using chorono timer).**
---

##Conclusion

Sequential access is faster because:

- Processor prefetches 15 next integers, sort of "trying to guess what's coming next".

Random access is slower because:

- Almost every access misses cache
- Cache lines are mostly wasted, so we never use prefetched, or "guessed" numbers

**With this, changing only the access pattern (not the operation) caused a 100× difference in performance.**
