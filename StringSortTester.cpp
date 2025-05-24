#include "StringSortTester.h"
#include "StringQuickSort.h"
#include "StringMergeSort.h"
#include "MSDRadixSort.h"
#include <algorithm>
#include <chrono>

size_t StringSortTester::comparisonCount = 0;

SortResult StringSortTester::testStandardQuickSort(std::vector<std::string>& arr) {
    comparisonCount = 0;
    auto start = std::chrono::high_resolution_clock::now();
    
    std::sort(arr.begin(), arr.end(), [](const std::string& a, const std::string& b) {
        comparisonCount++;
        return a < b;
    });
    
    auto end = std::chrono::high_resolution_clock::now();
    double timeMs = std::chrono::duration<double, std::milli>(end - start).count();
    
    return {timeMs, comparisonCount};
}

SortResult StringSortTester::testStandardMergeSort(std::vector<std::string>& arr) {
    comparisonCount = 0;
    auto start = std::chrono::high_resolution_clock::now();
    
    std::stable_sort(arr.begin(), arr.end(), [](const std::string& a, const std::string& b) {
        comparisonCount++;
        return a < b;
    });
    
    auto end = std::chrono::high_resolution_clock::now();
    double timeMs = std::chrono::duration<double, std::milli>(end - start).count();
    
    return {timeMs, comparisonCount};
}

SortResult StringSortTester::testStringQuickSort(std::vector<std::string>& arr) {
    comparisonCount = 0;
    auto start = std::chrono::high_resolution_clock::now();
    
    StringQuickSort::sort(arr, comparisonCount);
    
    auto end = std::chrono::high_resolution_clock::now();
    double timeMs = std::chrono::duration<double, std::milli>(end - start).count();
    
    return {timeMs, comparisonCount};
}

SortResult StringSortTester::testStringMergeSort(std::vector<std::string>& arr) {
    comparisonCount = 0;
    auto start = std::chrono::high_resolution_clock::now();
    
    StringMergeSort::sort(arr, comparisonCount);
    
    auto end = std::chrono::high_resolution_clock::now();
    double timeMs = std::chrono::duration<double, std::milli>(end - start).count();
    
    return {timeMs, comparisonCount};
}

SortResult StringSortTester::testMSDRadixSort(std::vector<std::string>& arr) {
    comparisonCount = 0;
    auto start = std::chrono::high_resolution_clock::now();
    
    MSDRadixSort::sort(arr, comparisonCount, false);
    
    auto end = std::chrono::high_resolution_clock::now();
    double timeMs = std::chrono::duration<double, std::milli>(end - start).count();
    
    return {timeMs, comparisonCount};
}

SortResult StringSortTester::testMSDRadixSortWithQuickSort(std::vector<std::string>& arr) {
    comparisonCount = 0;
    auto start = std::chrono::high_resolution_clock::now();
    
    MSDRadixSort::sort(arr, comparisonCount, true);
    
    auto end = std::chrono::high_resolution_clock::now();
    double timeMs = std::chrono::duration<double, std::milli>(end - start).count();
    
    return {timeMs, comparisonCount};
}

std::map<std::string, SortResult> StringSortTester::runAllTests(std::vector<std::string> arr) {
    std::map<std::string, SortResult> results;
    
    // Тестируем стандартные алгоритмы
    std::vector<std::string> arrCopy = arr;
    results["Standard QuickSort"] = testStandardQuickSort(arrCopy);
    
    arrCopy = arr;
    results["Standard MergeSort"] = testStandardMergeSort(arrCopy);
    
    // Тестируем специализированные алгоритмы
    arrCopy = arr;
    results["String QuickSort"] = testStringQuickSort(arrCopy);
    
    arrCopy = arr;
    results["String MergeSort"] = testStringMergeSort(arrCopy);
    
    arrCopy = arr;
    results["MSD RadixSort"] = testMSDRadixSort(arrCopy);
    
    arrCopy = arr;
    results["MSD RadixSort with QuickSort"] = testMSDRadixSortWithQuickSort(arrCopy);
    
    return results;
}

template<typename Func>
double StringSortTester::measureTime(Func func) {
    auto start = std::chrono::high_resolution_clock::now();
    func();
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration<double, std::milli>(end - start).count();
} 