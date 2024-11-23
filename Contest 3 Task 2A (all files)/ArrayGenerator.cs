#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

class ArrayGenerator
{
    private:
    std::vector<int> baseArray;
    std::mt19937 rng; // Генератор случайных чисел

    public:
    ArrayGenerator() : rng(std::chrono::steady_clock::now().time_since_epoch().count())
    {
        // Создание базового массива длины 10000 со случайными числами
        baseArray.resize(10000);
        std::uniform_int_distribution<int> dist(0, 6000);
        for (auto & elem : baseArray)
        {
            elem = dist(rng);
        }
    }

    // Генерация массива случайных значений заданного размера
    std::vector<int> getRandomArray(size_t size)
    {
        return std::vector<int>(baseArray.begin(), baseArray.begin() + size);
    }

    // Генерация массива, отсортированного в обратном порядке
    std::vector<int> getReverseSortedArray(size_t size)
    {
        std::vector<int> arr = getRandomArray(size);
        std::sort(arr.rbegin(), arr.rend());
        return arr;
    }

    // Генерация "почти отсортированного" массива
    std::vector<int> getNearlySortedArray(size_t size, int swaps = 10)
    {
        std::vector<int> arr = getRandomArray(size);
        std::sort(arr.begin(), arr.end());
        for (int i = 0; i < swaps; ++i)
        {
            size_t idx1 = rng() % size;
            size_t idx2 = rng() % size;
            std::swap(arr[idx1], arr[idx2]);
        }
        return arr;
    }
};
