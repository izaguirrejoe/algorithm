#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long binary_search(const vector<int>& A, long p, long q, int key)
{
    if(p <= q)
    {
        long n = (p+q)/2;
        if(A[n] == key)
            return n;
        if(A[n] > key)
            return binary_search(A, p, n-1, key);
        return binary_search(A, n+1, q, key);
    }
    return -1;
}
