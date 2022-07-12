#include <iostream>
#include <chrono>
#include <string_view>
#include <vector>
#include <random>
#include <algorithm>

class Timer
{
    std::chrono::steady_clock::time_point m_start;
    public:
        Timer():m_start{std::chrono::steady_clock::now()} {

        }
        void ShowResult(std::string_view message = "") {
            auto end = std::chrono::steady_clock::now();
            auto difference = end - m_start;
            std::cout << std::chrono::duration_cast<std::chrono::microseconds>(difference).count() << std::endl;
        }
};

constexpr unsigned VEC_SIZE{1000000000};
std::vector<long> CreateVector() {
    std::vector<long> vec;
    vec.reserve(VEC_SIZE);
    std::default_random_engine engine{std::random_device{}()};
    std::uniform_int_distribution<long> dist{0, VEC_SIZE};
    for(unsigned i = 0; i < VEC_SIZE; ++i) {
        vec.push_back(dist(engine));
    }
    return vec;
}

#include <execution>

int main()
{
    // execution policies -> separate classes: seq - sequence (not parallelized), par - parallel, par_unseq (maybe vectorized)
    auto dataset = CreateVector();
    Timer t;
    //std::sort(dataset.begin(), dataset.end()); // seriel - is quicker??? :D 
    std::sort(std::execution::par, dataset.begin(), dataset.end());
    // auto result = std::accumulate(dataset.begin(), dataset.end(), 0L);
    // auto result = std::reduce(dataset.begin(), dataset.end(), 0L);
    
    t.ShowResult("sorting time:");
    return 0;
}