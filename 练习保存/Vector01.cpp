#include <iostream>
#include "Test.h"

void show(int n) { cout << n << ' '; }

int main(int argc, char *argv[])
{
    vector<int> nums;
    nums.reserve(10);
    for (int i = 0; i < 10; ++i)
        nums.push_back(i);

    cout << "Iter for: " << endl;
    for (auto p = nums.begin(); p != nums.end(); ++p)
        cout << *p << ' ';
    cout << "\nAt for: " << endl;
    for (unsigned j = 0; j < nums.size(); ++j)
        cout << nums.at(j) << ' ';
    cout << "\nFor_each: " << endl;
    for_each(nums.begin(), nums.end(), show);

    cout << "\nFront = " << nums.front() << endl;
    cout << "Back = " << nums.back() << endl;
    cout << "nums[3] = " << nums.at(3) << endl;
    auto local_index = find(nums.begin(), nums.end(), 2);
    cout << "2 index: " << local_index-nums.begin() << endl;
    local_index = find_if(nums.begin(), nums.end(), bind2nd(greater<int>(), 5));
    cout << "The index of number that first greater than 5 is " << local_index-nums.begin() << endl;

    cout << "Insert number:\n";
    nums.insert(nums.begin(), 100);
    for (auto x: nums)
        cout << x << ' ';
    cout << endl;
    int tmp[3] = {19, 45, 30};
    nums.insert(nums.end(), tmp, tmp + 3);
    for (auto x: nums)
        cout << x << ' ';
    cout << endl;
    nums.insert(nums.begin(), 5, 99);
    for (auto x: nums)
        cout << x << ' ';
    cout << endl;

    cout << "Delete number:\n";
    nums.pop_back();
    for (auto x: nums)
        cout << x << ' ';
    cout << endl;
    nums.erase(nums.begin() + 5);
    for (auto x: nums)
        cout << x << ' ';
    cout << endl;
    nums.erase(nums.begin() + 5, nums.begin() + 8);
    for (auto x: nums)
        cout << x << ' ';
    cout << endl;
    //nums.clear();
    cout << "nums size: " << nums.size() << endl;

    vector<int> nums2;
    for (int i = 20; i < 30; i++)
        nums2.push_back(i);
    for (auto x: nums2)
        cout << x << ' ';
    cout << endl;
    nums.swap(nums2);
    cout << "-----swap------\n";
    cout << "nums:\n";
    for (auto x: nums)
        cout << x << ' ';
    cout << endl;
    cout << "nums2:\n";
    for (auto x: nums2)
        cout << x << ' ';
    cout << endl;
    return 0;
}
