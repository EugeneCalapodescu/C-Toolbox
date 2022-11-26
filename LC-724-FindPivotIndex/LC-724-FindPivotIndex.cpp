#include <vector>
#include <iostream>

using namespace std;

void print(const vector<int>& nums)
{
	for (auto i : nums)
		cout << i << " ";
	cout << "\n";
}


int pivotIndex(vector<int>& nums)
{
	int N = nums.size();

	vector<int> left_sums(N, 0);

	left_sums[0] = nums[0];
	for (int i = 1; i < N; i++)
		left_sums[i] = left_sums[i - 1] + nums[i];

	print(left_sums);

	vector<int> right_sums(N, 0);

	right_sums[N-1] = nums[N-1];
	for (int i = N-2; i >= 0; i--)
		right_sums[i] = right_sums[i + 1] + nums[i];

	print(right_sums);

	for (int i = 0; i < N; i++)
	{
		int left = (i == 0) ? 0 : left_sums[i - 1];
		int right = (i == N-1) ? 0 : right_sums[i + 1];
		if (left == right)
			return i;
	}

	return -1;
}


int main()
{
	vector<int> nums = { 1, 7, 3, 6, 5, 6 };

	cout << pivotIndex(nums);
}