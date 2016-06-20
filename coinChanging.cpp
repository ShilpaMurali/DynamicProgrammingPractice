#include<iostream>
using namespace std;
void coinChanging(int*,int,int);
int main()
{
	int coins[]={7,2,3,6};
	coinChanging(coins,4,13);
	return 0;
}
void coinChanging(int* coins,int len,int sum)
{
	int* sumArray;
	sumArray=new int[sum+1];
	int* coinArray;
	coinArray=new int[sum+1];
	for(int i=0;i<=sum;i++)
	{
		sumArray[i]=9999;
		coinArray[i]=-1;
	}
	for(int i=0;i<len;i++)
	{
		for(int j=0;j<=sum;j++)
		{
			if(j==0)
			{
				sumArray[j]=0;
			}
			else if(j>=coins[i])//coin array is updated only if the sum is greater than or equal to the coin denomination that is being iterated upon. If the denomination is lesser we do not make any updates to the array.
			{
				if(sumArray[j]>1+sumArray[j-coins[i]])
				{
					sumArray[j]=1+sumArray[j-coins[i]];
					coinArray[j]=i;// store the index of the coin in the coins array which was used to obtain the minimum result
				}
				//sumArray[j]=min(sumArray[j],1+sumArray[j-coins[i]]);
				//coinArray[j]=i;// store the index of the coin in the coins array which was used to obtain the minimum result
			}
		}
	}
		for(int j=0;j<=sum;j++)
		{
			cout<<sumArray[j]<<" ";
		}
		cout<<endl;
		for(int j=0;j<=sum;j++)
		{
			cout<<coinArray[j]<<" ";
		}
		cout<<endl;
		int i=sum;
		while(i!=0)
		{
			int index=coinArray[i];// Last index: 13 has value 3, use this as the index and get coins[3]==6
			cout<<coins[index]<<" ";
			i=i-coins[index];// reduce the index by 13-6==7;
		}
}
int min(int a,int b)
{
	return (a<b)?a:b;
}