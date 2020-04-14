#include<iostream>
#include<string>
#include<malloc.h>
using namespace std;
int m, n;
class Link
{
public:
	Link(string s, char c[], int nu[] , double dl[]) 
	{
		num = (int *)malloc(sizeof(int)*(n+m+1));
		ch = (char *)malloc(sizeof(char)*(n+m+1));
		d = (double *)malloc(sizeof(double)*(n+m+1));
		type = s; 
		num = nu;
		ch = c;
		d = dl;
	};
	~Link();
	void show() 
	{
		if (type == "int")
			for (int i = 0; i < m + n; i++)
				cout << num[i] << " ";
		if (type == "char")
			for (int i = 0; i < m + n; i++)
				cout << ch[i] << " ";
		if (type == "double")
			for (int i = 0; i < m + n; i++)
				cout << d[i] << " ";
	}
	Link operator +(Link &l);
private:
	string type;
	int *num;
	char *ch;
	double *d;
};
Link Link::operator +(Link &l)
{
	for (int i = n,j=0; i < m + n; i++,j++)
	{
		if (this->type == "int")
			this->num[i] = l.num[j];
		if (this->type == "double")
			this->d[i] = l.d[j];
		if (this->type == "char")
			this->ch[i] = l.ch[j];
	}
	return Link(this->type,this->ch,this->num,this->d);
}
 
Link::~Link()
{
 
}
int main()
{
	string s;
	int *num1 = {};
	int *num2 = {};
	char *ch1 = {};
	char *ch2 = {};
	char ch;
	double *d1 = {};
	double *d2 = {};
	cin >> s;
	cin >> m >> n;
	if (s == "int")
	{
		num1 = (int *)malloc(sizeof(int)*n);
		num2 = (int *)malloc(sizeof(int)*m);
		for (int i = 0; i < n; i++)
			cin >> num1[i];
		for (int i = 0; i < m; i++)
			cin >> num2[i];
		Link l1(s,ch1,num1,d1);
 
		Link l2(s,ch2,num2,d2);
		Link l3 = l1 + l2;
		l3.show();
	}
	if (s == "char")
	{
		ch1 = (char *)malloc(sizeof(char)*(n+1));
		ch2 = (char *)malloc(sizeof(char)*(m+1));
 
		for (int i = 0; i < n; i++)
		{
			cin >> ch1[i];
			ch = getchar();
		}
		for (int i = 0; i < m; i++)
		{
			cin >> ch2[i];
			ch = getchar();
		}Link l1(s, ch1, num1, d1);
		Link l2(s, ch2, num2, d2);
		Link l3 = l1 + l2;
		l3.show();
	}
	if (s == "double")
	{
		d1 = (double *)malloc(sizeof(double)*n);
		d2 = (double *)malloc(sizeof(double)*m);
 
		for (int i = 0; i < n; i++)
			cin >> d1[i];
		for (int i = 0; i < m; i++)
			cin >> d2[i];
		Link l1(s, ch1, num1, d1);
		Link l2(s, ch2, num2, d2);
		Link l3 = l1 + l2;
		l3.show();
	}
	return 0;
 
}