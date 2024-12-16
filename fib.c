#include <stdint.h>
#include <stdio.h>

unsigned long long int fibCache[] = {};

unsigned long long int fibRecursive(int fibValue);
unsigned long long int fibIterative(int fibValue);

unsigned long long int fibRecursiveProvider(int fibValue)
{
    if (fibValue == 0 || fibValue == 1) {
        return fibValue;
    }
    return fibRecursive(fibValue - 1) + fibRecursive(fibValue - 2);
}

unsigned long long int fibIterativeProvider(int fibValue)
{
    unsigned long long int fibSum = 0;
    unsigned long long int prevNum = 0;
    unsigned long long int currentNum = 1;
    for (size_t ix = 1; ix < fibValue; ++ix) {
        fibSum = prevNum + currentNum;
        prevNum = currentNum;
        currentNum = fibSum;
    }
    return fibSum;
}

unsigned long long int fibRecursive(int fibValue)
{
    if (fibCache[fibValue] == 0) {
        fibCache[fibValue] = fibRecursiveProvider(fibValue);
    }
    return fibCache[fibValue];
}

unsigned long long int fibIterative(int fibValue)
{
    if (fibCache[fibValue] == 0) {
        fibCache[fibValue] = fibIterativeProvider(fibValue);
    }
    return fibCache[fibValue];
}

int main(int argc, char* argv[])
{
    int firstNum;
    int input = sscanf(argv[1], "%u", &firstNum);
    char fibType = *argv[2];

    int nthNum = firstNum - 1;

    if (fibType == 'r') {
        unsigned long long int result = fibRecursive(nthNum);
        printf("%llu", result);
    } else if (fibType == 'i') {
        unsigned long long int result = fibIterative(nthNum);
        printf("%llu", result);
    }

    return 0;
}
