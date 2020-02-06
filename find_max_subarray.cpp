#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

const int NEG_INF = -10000000;

tuple<int,long,long> find_max_cross_subarray(const vector<int>& v, long low, long mid, long high)
{
    int sum = 0;
    long left_low = mid;
    int left_sum = NEG_INF;
    for(long i = mid; i >=0; --i)
    {
        sum += v[i];
        if(sum > left_sum)
        {
            left_sum = sum;
            left_low = i;
        }
    }
    sum = 0;
    long right_high = mid + 1;
    int right_sum = NEG_INF;
    for(long i = mid + 1; i < v.size(); ++i)
    {
        sum += v[i];
        if(sum > right_sum)
        {
            right_sum = sum;
            right_high = i;
        }
    }
    return make_tuple(left_sum+right_sum, left_low, right_high);
}

tuple<int,long,long> find_max_subarray(const vector<int>& v, long low, long high)
{
    if (low == high)
        return make_tuple(v[low], low, high);
    long mid = (low+high)/2;
    tuple<int,long,long> left = find_max_subarray(v, low, mid);
    int left_sum = get<0>(left);
    tuple<int,long,long> right = find_max_subarray(v, mid + 1, high);
    int right_sum = get<0>(right);
    tuple<int,long,long> cross = find_max_cross_subarray(v, low, mid, high);
    int cross_sum = get<0>(cross);
    if(left_sum >= right_sum && left_sum >= cross_sum)
        return left;
    else if(right_sum >= left_sum && right_sum >= cross_sum)
        return right;
    else return cross;
}


int main()
{
    vector<int> v {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
    tuple<int,long,long> t = find_max_subarray(v, 0, v.size());
    cout << "The max subarray has a sum of " << get<0>(t)
    << " with indices " << get<1>(t)
    << " and " << get<2>(t)
    << ".\n";
    return 0;
}
