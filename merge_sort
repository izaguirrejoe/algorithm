#include <iostream>
#include <vector>

using namespace std;
const int SENTINEL = 9999999;

void merge(vector<int>& vi, long p, long q, long r) //the two sorted portions to be merged are as follows: the first is from p to q, inclusive. The second is from q+1 to r
{
    //create the "left" and "right" arrays
    long size_l = q-p+1;
    long size_r = r-q;
    vector<int> left(size_l), right(size_r);
    for(int i = 0; i < size_l; ++i)
        left[i] = vi[p + i];
    for(int i = 0; i < size_r; ++i)
        right[i] = vi[q+1+i];
    left.push_back(SENTINEL);
    right.push_back(SENTINEL);
    
    //merge the two arrays, placing the result back in the original array
    int i = 0;
    int j = 0;
    for(long k = p; k <= r; ++k)
    {
        if(left[i] <= right[j])
        {
            vi[k] = left[i];
            ++i;
        }
        else
        {
            vi[k] = right[j];
            ++j;
        }
    }
}

void merge_sort(vector<int>& vi, long p, long r)
{
    if(p < r)
    {
        long q = (p+r)/2;
        merge_sort(vi,p,q);
        merge_sort(vi,q+1,r);
        merge(vi,p,q,r);
    }
}
