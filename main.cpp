#include <vector>
#include <iostream>
#include <deque>
#include <chrono>

int main() {
   
    std::vector v1 = {
        10, 20, 30, 5, 15, 10, 20, 30, 5, 15, 10, 20, 30, 5, 15, 10, 20, 30, 5, 15, 10, 20, 30, 5, 15, 10, 20, 30, 5,
        15, 10, 20, 30, 5, 15, 10, 20, 30, 5, 15, 10, 20, 30, 5, 15, 10, 20, 30, 5, 15
    };
    std::vector v2 = {
        10, 20, 30, 5, 15, 10, 20, 30, 5, 15, 10, 20, 30, 5, 15, 10, 20, 30, 5, 15, 10, 20, 30, 5, 15, 10, 20, 30, 5,
        15, 10, 20, 30, 5, 15, 10, 20, 30, 5, 15, 10, 20, 30, 5, 15, 10, 20, 30, 5, 15
    };

    std::deque d1 = {
        10, 20, 30, 5, 15, 10, 20, 30, 5, 15, 10, 20, 30, 5, 15, 10, 20, 30, 5, 15, 10, 20, 30, 5, 15, 10, 20, 30, 5,
        15, 10, 20, 30, 5, 15, 10, 20, 30, 5, 15, 10, 20, 30, 5, 15, 10, 20, 30, 5, 15
    };
    std::deque d2 = {
        10, 20, 30, 5, 15, 10, 20, 30, 5, 15, 10, 20, 30, 5, 15, 10, 20, 30, 5, 15, 10, 20, 30, 5, 15, 10, 20, 30, 5,
        15, 10, 20, 30, 5, 15, 10, 20, 30, 5, 15, 10, 20, 30, 5, 15, 10, 20, 30, 5, 15
    };

    // swap
    auto start_swap_1 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 10000; i++) {
        swap(v1, v2);
    }
    auto end_swap_1 = std::chrono::high_resolution_clock::now();

    auto start_swap_2 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 10000; i++) {
        swap(d1, d2);
    }
    auto end_swap_2 = std::chrono::high_resolution_clock::now();

    // insert front
    auto start_front_1 = std::chrono::high_resolution_clock::now();
    for (std::size_t i = 0; i < v2.size(); i++) {
        v1.insert(v1.begin(), *(v2.begin() + i));
    }
    auto end_front_1 = std::chrono::high_resolution_clock::now();

    auto start_front_2 = std::chrono::high_resolution_clock::now();
    for (std::size_t i = 0; i < d2.size(); i++) {
        d1.push_front(*(d2.begin() + i));
    }
    auto end_front_2 = std::chrono::high_resolution_clock::now();


    auto duration_swap_vec = std::chrono::duration_cast<std::chrono::nanoseconds>(end_swap_1 - start_swap_1);
    auto duration_swap_deq = std::chrono::duration_cast<std::chrono::nanoseconds>(end_swap_2 - start_swap_2);
    auto duration_front_vec = std::chrono::duration_cast<std::chrono::nanoseconds>(end_front_1 - start_front_1);
    auto duration_front_deq = std::chrono::duration_cast<std::chrono::nanoseconds>(end_front_2 - start_front_2);


    std::cout << "Execution time(vector) for swapping: " << duration_swap_vec.count() << " nanoseconds" << '\n';
    std::cout << "Execution time(deque) for swapping: " << duration_swap_deq.count() << " nanoseconds" << "\n";
    std::cout << "Execution time(vector) for inserting front: " << duration_front_vec.count() << " nanoseconds" << '\n';
    std::cout << "Execution time(deque) for inserting front: " << duration_front_deq.count() << " nanoseconds" << "\n";
}
