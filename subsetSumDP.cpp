#include<iostream>
using namespace std;
bool subsetSum(int*,int,int);
int main()
{
  int num[]={2,3,7,8,10};
  int len=sizeof(num)/sizeof(int);
  int sum=11;
  if(subsetSum(num,len,sum))
  {
    cout<<"The subsetsum is found"<<endl;
  }
  else
  {
    cout<<"The subset sum was not found"<<endl;
  }
  return 0;
}
bool subsetSum(int* num, int len,int sum)
{
  //int result[len][sum];
  bool result[6][12]={0}; // Add extra row and column to make the space for row 0 and column 0 so that you have access to previous values
  int i,j;
  for(j=0;j<=sum;j++)
  {
    result[0][j]=false;// Make row 1 = false since using element 0, no sum can be formed
  }
    for (i = 0; i <=len; i++) {
            result[i][0] = true;// we can make a sum of zero without any elements ie empty set. So true denoted by 1 for column 0;
  }
  for(int i=1;i<=len;i++)
  {
    for(int j=1;j<=sum;j++)
    {
      result[i][j]=result[i-1][j]; // copy the previous value first
      if(num[i-1]>j )  // since loop starts from 1 we use i-1
      {
        result[i][j]=result[i-1][j]; // if sum is lesser than the element being itereated over-> Choose the previous value that was used.
        //cout<<result[i][j]<<endl;
      }
      else
      {
        result[i][j]=result[i-1][j] || result[i-1][j-num[i-1]]; // eg: sum is 5 and we are having num[i-1]=3, in this case we visit the value of previous num say 2, if it was true, it means that we can make 5 from 2 and 3
        //cout<<result[i][j]<<endl;
      }
    }
  }
  for(int i=0;i<=len;i++)
  {
    for(int j=0;j<=sum;j++)
    {
      cout<<result[i][j]<<" ";
    }
    cout<<endl;
  }
  return result[len][sum];
}