#include <iostream>
#include <vector>
using namespace std;

void generatePermutations(vector<int>& nums, int index) 
{
    int n = nums.size();

    if (index == n) 
    {
        for (int i = 0; i < n; ++i)
            cout << nums[i] << " ";
        cout << endl;
        return;
    }

    for (int i = index; i < n; ++i) 
    {
        swap(nums[index], nums[i]);
        generatePermutations(nums, index + 1);
        swap(nums[index], nums[i]);
    }
}

int main() 
{
    setlocale(LC_ALL, "Russian");
    vector<int> nums(5);
    cout << "Введите 5 различных натуральных чисел: ";
    for (int i = 0; i < 5; ++i) 
    {
        cin >> nums[i];
    }

    cout << "Все перестановки этих чисел:\n";
    generatePermutations(nums, 0);

    return 0;
}