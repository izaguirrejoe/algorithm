#include <iostream>
#include <vector>

using namespace std;

template <typename T> 
void insertion_sort_nondecreasing(vector<T>& vi)
{
    for(int i = 1; i < vi.size(); ++i)
    {
        T key = vi[i];
        int j = i-1;
        while(j >= 0 && vi[j] > key)
        {
            vi[j+1] = vi[j];
            --j;
        }
        vi[j+1] = key;
    }
}

template <typename T>
void insertion_sort_nonincreasing(vector<T>& vi)
{
    for(int i = 1; i < vi.size(); ++i)
    {
        T key = vi[i];
        int j = i-1;
        while(j >= 0 && vi[j] < key)
        {
            vi[j+1] = vi[j];
            --j;
        }
        vi[j+1] = key;
    }
}
