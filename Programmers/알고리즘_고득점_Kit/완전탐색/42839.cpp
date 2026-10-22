/**
 * 소수 찾기
 * https://school.programmers.co.kr/learn/courses/30/lessons/42839
 */

#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

void createPrimeList(vector<int>& primeList) {
    int maxNum = primeList.size() - 1;
    
    primeList[0] = 0;
    primeList[1] = 0;
    
    for (int i = 2; i * i <= maxNum; i++) {
        int j = i + i;
        
        while (j <= maxNum) {
            primeList[j] = 0;
            j += i;
        }
    }
}

void dfs(set<int>& candidates, string num, const string& numbers, vector<int> visited) {
    for (int i = 0; i < numbers.size(); i++) {
        if (visited[i]) {
            continue;
        }
        
        num.push_back(numbers[i]);
        candidates.insert(stoi(num));
        visited[i] = 1;
        
        dfs(candidates, num, numbers, visited);
        
        // back tracking
        num.pop_back();
        visited[i] = 0;
    }
}

int solution(string numbers) {    
    sort(numbers.rbegin(), numbers.rend());
    
    vector<int> primeList(stoi(numbers) + 1, 1);
    
    createPrimeList(primeList);
    
    int count = 0;
    set<int> candidates;
    vector<int> visited(numbers.size(), 0);
    
    dfs(candidates, "", numbers, visited);
    
    for (auto elem : candidates) {
        if (primeList[elem]) {
            count++;
        }
    }
    
    return count;
}


// optimized code

void buildPrimeTable(std::vector<bool>& isPrime) {
    const int maximum = static_cast<int>(isPrime.size()) - 1;

    isPrime[0] = false;
    isPrime[1] = false;

    for (int divisor = 2; divisor <= maximum / divisor; ++divisor) {
        if (!isPrime[divisor]) {
            continue;
        }

        for (int multiple = divisor * divisor; multiple <= maximum; multiple += divisor) {
            isPrime[multiple] = false;
        }
    }
}

void countPrimes(
    const std::string& digits,
    std::vector<bool>& used,
    int currentNumber,
    const std::vector<bool>& isPrime,
    int& primeCount
) {
    for (std::size_t index = 0; index < digits.size(); ++index) {
        if (used[index]) {
            continue;
        }

        if (index > 0 && digits[index] == digits[index - 1] && !used[index - 1]) {
            continue;
        }

        if (currentNumber == 0 && digits[index] == '0') {
            continue;
        }

        const int nextNumber = currentNumber * 10 + (digits[index] - '0');

        if (isPrime[nextNumber]) {
            ++primeCount;
        }

        used[index] = true;
        countPrimes(digits, used, nextNumber, isPrime, primeCount);
        used[index] = false;
    }
}

int solution(std::string numbers) {
    std::string largestNumber = numbers;
    std::sort(largestNumber.rbegin(), largestNumber.rend());

    const int maximum = std::stoi(largestNumber);
    if (maximum < 2) {
        return 0;
    }

    std::vector<bool> isPrime(maximum + 1, true);
    buildPrimeTable(isPrime);

    std::sort(numbers.begin(), numbers.end());

    std::vector<bool> used(numbers.size(), false);
    int primeCount = 0;

    countPrimes(numbers, used, 0, isPrime, primeCount);

    return primeCount;
}