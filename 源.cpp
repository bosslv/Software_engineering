//����Ӷκ�
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int maxSubArray(vector<int> &nums)
{
	//����Ѱ�������Сֵ����Ŀ����ʼֵһ��Ҫ����������ϵ���С���ֵ
	int result = INT_MIN;
	int numsSize = int(nums.size());
	int sum = 0;
	for (int i = 0; i < numsSize; i++)
	{
		sum += nums[i];
		result = max(result, sum);
		//���sum < 0�����¿�ʼ������
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
		cout<<"���Ϊ��" << maxSubArray(v) <<endl;
	}
}