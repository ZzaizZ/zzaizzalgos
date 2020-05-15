#include <bits/stdc++.h>

using namespace std;
/**
 * Алгоритм Кадана для циклического массива.
 * Поиск подмассива с максимальной суммой в циклическом массиве
 * Идея:
 */

int maxSubarraySumCircular(vector<int>& A) {
    int localMax = -3000;
    int globalMax = -3000;

    int localMin = 3000;
    int globalMin = 3000;

    int sum = 0;
    for (int i : A)
    {
        localMax = max(i, localMax + i);
        globalMax = max(localMax, globalMax);
        localMin = min(i, localMin + i);
        globalMin = min(localMin, globalMin);
        sum += i;
    }
    return globalMax > 0 ? max(globalMax, sum - globalMin) : globalMax;
}

int main()
{
    vector<int> a = {5, -3, 5};
    printf("Result: %i\n", maxSubarraySumCircular(a));
    a = {1,-2,3,-2};
    printf("Result: %i\n", maxSubarraySumCircular(a));
    a = {3,-1,2,-1};
    printf("Result: %i\n", maxSubarraySumCircular(a));
    a = {-2,-3,-1};
    printf("Result: %i\n", maxSubarraySumCircular(a));

    return 0;
}
