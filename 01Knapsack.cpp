#include <iostream>
using namespace std;
int knapsack(int*,int*,int,int);
int max(int,int);
int main()
{
	/*int wt[]={1,3,4,5};
	int val[]={1,4,5,7};
	int total=7;*/
	int wt[]={10,20,30};
	int val[]={60,100,120};
	int total=50;
	int len=sizeof(val)/sizeof(val[0]);
	cout<<len<<endl;
	int resultFinal=knapsack(wt,val,total,len);
	cout<<resultFinal<<endl;;
	return 0;
}
int knapsack(int *wt,int* val,int total,int len)
{
	cout<<"Inside knapsack"<<endl;
	int i,j;
	//int result[4][8];
	int result[3][51];
	/*int** result;
    result=new int*[len];
	for(k=0;k<len;k++)
	{
		result[k]=new int[total];
	}*/
	for(i=0;i<len;i++)
	{
		for(j=0;j<=total;j++)
		{
			if(i==0||j==0)
			{
				result[i][j]=0; // When the sum of weigth has to be zero we need 0 items.. so all items and weights are 0.
			}
			else if(j<wt[i])
			{
				result[i][j]=result[i-1][j]; // when the current total weight (2) is lesse than the weight of the item (3) being iterated on , we simply take the previous value of this item
			}
			else{
				result[i][j]=max(val[i]+result[i-1][j-wt[i]],result[i-1][j]); // when the current total weight is equal (3/4) to or greater than the weight of the item being iterated on (3), we have  choices. Either take the item or leave it depending on which ever instance gives the maximum value. If the item is taken we add its value along with the previously computed value of the remaining weight , or take only the previously computed weight by letting this item go. 
			}
			//cout<<result[i][j]<<endl;
		}
	}
	int value=result[len-1][total];
	/*for(int i = 0; i < len; ++i) {
		delete [] result[i];
	}
	delete [] result;*/
	return value;
}
int max(int a,int b)
{
	return (a>b)?a:b;
}
