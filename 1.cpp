//最大子段和
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class solution {
public:
	int maxSubArray(int *nums,int s)
	{
		//类似寻找最大最小值的题目，初始值一定要定义成理论上的最小最大值
		int result = INT_MIN;
		int numsSize = s;
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
};

int main()
{
	int num,X;
	int v[1000] = {0};
	char s;
	while (cin >> num)
	{
		memset(v, 0, sizeof(v));
		for (int i = 0; i < num; i++)
		{
			cin >> X;
			v[i] = X;
		}
		solution s;
		cout<<"结果为：" << s.maxSubArray(v,num) <<endl;
	}
}