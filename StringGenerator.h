#pragma once
#include <string>
#include <vector>
#include <random>

class StringGenerator {
public:
    StringGenerator();
    
    // Генерация случайного массива строк
    std::vector<std::string> generateRandomArray(int size);
    
    // Генерация обратно отсортированного массива
    std::vector<std::string> generateReverseSortedArray(int size);
    
    // Генерация почти отсортированного массива
    std::vector<std::string> generateAlmostSortedArray(int size);
    
    // Генерация массива с общими префиксами
    std::vector<std::string> generateCommonPrefixArray(int size);

private:
    std::mt19937 rng;
    const std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#%:;^&*()-.";
    
    // Генерация случайной строки заданной длины
    std::string generateRandomString(int minLength, int maxLength);
    
    // Генерация строки с заданным префиксом
    std::string generateStringWithPrefix(const std::string& prefix, int minLength, int maxLength);
    
    // Создание почти отсортированного массива из отсортированного
    void makeAlmostSorted(std::vector<std::string>& arr, int numSwaps);
}; 