#include "StringGenerator.h"
#include <algorithm>
#include <chrono>

StringGenerator::StringGenerator() {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    rng.seed(seed);
}

std::vector<std::string> StringGenerator::generateRandomArray(int size) {
    std::vector<std::string> arr(size);
    for (int i = 0; i < size; i++) {
        arr[i] = generateRandomString(10, 200);
    }
    return arr;
}

std::vector<std::string> StringGenerator::generateReverseSortedArray(int size) {
    std::vector<std::string> arr = generateRandomArray(size);
    std::sort(arr.begin(), arr.end(), std::greater<std::string>());
    return arr;
}

std::vector<std::string> StringGenerator::generateAlmostSortedArray(int size) {
    std::vector<std::string> arr = generateRandomArray(size);
    std::sort(arr.begin(), arr.end());
    makeAlmostSorted(arr, size / 10); // 10% перестановок
    return arr;
}

std::vector<std::string> StringGenerator::generateCommonPrefixArray(int size) {
    std::vector<std::string> arr(size);
    std::string prefix = generateRandomString(5, 10);
    
    for (int i = 0; i < size; i++) {
        arr[i] = generateStringWithPrefix(prefix, 10, 200);
    }
    return arr;
}

std::string StringGenerator::generateRandomString(int minLength, int maxLength) {
    std::uniform_int_distribution<int> lengthDist(minLength, maxLength);
    std::uniform_int_distribution<int> charDist(0, alphabet.length() - 1);
    
    int length = lengthDist(rng);
    std::string result;
    result.reserve(length);
    
    for (int i = 0; i < length; i++) {
        result += alphabet[charDist(rng)];
    }
    
    return result;
}

std::string StringGenerator::generateStringWithPrefix(const std::string& prefix, int minLength, int maxLength) {
    std::uniform_int_distribution<int> lengthDist(minLength, maxLength);
    std::uniform_int_distribution<int> charDist(0, alphabet.length() - 1);
    
    int length = lengthDist(rng);
    std::string result = prefix;
    result.reserve(length);
    
    for (int i = prefix.length(); i < length; i++) {
        result += alphabet[charDist(rng)];
    }
    
    return result;
}

void StringGenerator::makeAlmostSorted(std::vector<std::string>& arr, int numSwaps) {
    std::uniform_int_distribution<int> indexDist(0, arr.size() - 1);
    
    for (int i = 0; i < numSwaps; i++) {
        int idx1 = indexDist(rng);
        int idx2 = indexDist(rng);
        std::swap(arr[idx1], arr[idx2]);
    }
} 