#include<iostream>
#include<string>
using namespace std;
void lcs(string,string,int,int);
int main()
{
	string one="aggtab";
	string two="gxtxayb";
	int len1=one.size();
	int len2=two.size();
	lcs(one,two,len1,len2);
	return 0;
}
void lcs(string one,string two,int len1,int len2)
{
	int result[7][8];
	for(int i=0;i<=len1;i++)
	{
		for(int j=0;j<=len2;j++)
		{
			if(i==0||j==0)
			{
				result[i][j]=0;
			}
			else if(one[i]==two[j])
			{
				result[i][j]=1+result[i-1][j-1];
			}
			else
			{
				result[i][j]=max(result[i][j-1],result[i-1][j]);
			}
		}
	}
	int value=result[len1][len2]; // last element in the table gives us the length of the lcs of the two strings.
	cout<<"Value of lcs is "<<value<<endl;
	char* resultString;
	resultString= new char[value+1];//value+1;
	resultString[value]='\0';
	int i=len1,j=len2;
	while(i>0 && j>0)
	{
		if(one[i-1]==two[j-1])
		{
			resultString[value-1]=one[i-1];// when caharacters in both strings are the same take that character and move the pointer to the diagonal element
			i--;
			j--;
			value--;
		}
		else if(result[i-1][j]>result[i][j-1])// choose between a max of top element and the left side element	
		{
			i--;
		}
		else
			j--;
	}
	cout<<"LCS string is "<<resultString<<endl;
}
int max(int a,int b)
{
	return (a>b)?a:b;
}