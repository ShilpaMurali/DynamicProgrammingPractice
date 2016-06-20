#include<iostream>
#include<string>
using namespace std;
void med(string,string);
int min(int,int,int);
int main()
{
	 string one="abcdef";
	 string two="azced";
	 med(one,two);
	 return 0;
}
void med(string one,string two)
{
	int lenOne=one.size();
	int lenTwo=two.size();
	int result[7][6];
	for(int i=0;i<=lenOne;i++)
	{
		result[i][0]=i;
	}
	for(int i=0;i<=lenTwo;i++)
	{
		result[0][i]=i;
	}
	for(int i=1;i<=lenOne;i++)
	{
		for(int j=1;j<=lenTwo;j++)
		{
            if(one[j-1]==two[i-1])
			{
				result[i][j]=result[i-1][j-1];
			}
			else
			{
				result[i][j]=min(result[i-1][j-1],result[i][j-1],result[i-1][j])+1;
				cout<<result[i][j]<<" ";
			}
		}
	}
	cout<<endl;
    for(int i=0;i<=lenOne;i++)
	{
		for(int j=0;j<=lenTwo;j++)
		{
		    cout<<result[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<result[lenOne][lenTwo];
}
int min(int a,int b,int c)
{
	 return a < b ? (a < c ? a : c) : (b < c ? b : c);
    /*if(a<=b && a<=c)
        return a;
    else if(b<=c && b<=a)
        return b;
    else
        return c;*/
}