//����Ӷκ�
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class solution {
public:
	int maxSubArray(int *nums,int s)
	{
		//����Ѱ�������Сֵ����Ŀ����ʼֵһ��Ҫ����������ϵ���С���ֵ
		int result = INT_MIN;
		int numsSize = s;
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
		cout<<"���Ϊ��" << s.maxSubArray(v,num) <<endl;
	}
}