//最大子段和
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int maxSubArray(vector<int> &nums)
{
	//类似寻找最大最小值的题目，初始值一定要定义成理论上的最小最大值
	int result = INT_MIN;
	int numsSize = int(nums.size());
	int sum = 0;
	for (int i = 0; i < numsSize; i++)
	{
		sum += nums[i];
		result = max(result, sum);
		//如果sum < 0，重新开始找子序串
		if (sum < 0)
		{
			sum = 0;
		}
	}

	return result;
}

int main()
{
	int num,X;
	vector<int> v;
	char s;
	while (cin >> num)
	{
		v.clear();
		for (int i = 0; i < num; i++)
		{
			cin >> X;
			v.push_back(X);
		}
		cout<<"结果为：" << maxSubArray(v) <<endl;
	}
}