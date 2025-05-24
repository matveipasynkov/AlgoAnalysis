#pragma once

#include <string>
#include <vector>
#include <map>
#include <chrono>
#include <functional>

struct SortResult {
    double timeMs;
    size_t comparisons;
};

class StringSortTester {
public:
    // Тестирование стандартных алгоритмов
    static SortResult testStandardQuickSort(std::vector<std::string>& arr);
    static SortResult testStandardMergeSort(std::vector<std::string>& arr);
    
    // Тестирование специализированных алгоритмов
    static SortResult testStringQuickSort(std::vector<std::string>& arr);
    static SortResult testStringMergeSort(std::vector<std::string>& arr);
    static SortResult testMSDRadixSort(std::vector<std::string>& arr);
    static SortResult testMSDRadixSortWithQuickSort(std::vector<std::string>& arr);
    
    // Запуск всех тестов на одном массиве
    static std::map<std::string, SortResult> runAllTests(std::vector<std::string> arr);
    
private:
    static size_t comparisonCount;
    
    // Шаблонный метод для измерения времени выполнения
    template<typename Func>
    static double measureTime(Func func);
}; 