//Time complexity O(n2) and space complexity O(n)
#include<iostream>
using namespace std;
void lis(int*,int);
int max(int,int);
int main()
{
  int a[]={ 3,4,-1,0,6,2,3};
  int len=sizeof(a)/sizeof(int);
  lis(a,len);
  return 0;
}
void lis(int* a,int len)
{
  int* temp=new int [len];
  int* actualSol=new int[len];// store the solution (not implemented)
  for(int i=0;i<len;i++)
  {
    temp[i]=1;// create a temporary array and assign all the value to 1
	//actualSol[i]=i;
  }
  for(int i=1;i<len;i++) // index i starts from 1
  {
    for(int j=0;j<i;j++) // index j starts from 0 so always j<i
    {
      if(a[j]<a[i]) // if the preceeding value is lower than the next it can form a subsequence. So increase the length by comparing what is present previously. Use max
      {
        temp[i]=max(temp[i],1+temp[j]);
		//actualSol[i]=j;
        cout<<temp[i]<<" ";
      }
    }
  }
  cout<<endl<<temp[0]<<" ";
  int maximum=temp[0];
 // int maxIndex;
  for(int i=1;i<len;i++)
  {
    cout<<temp[i]<<" ";
    if(maximum<temp[i]) // print the maximum value by iterating thru the loop
    {
      maximum =temp[i];
	  //maxIndex=i;
    }
  }
  cout<<endl;
  cout<<"Longest Increasing subsequence of length "<<maximum<<endl;
  /*for(int i=0;i<len;i++)
  {
	  cout<<actualSol[i]<<" ";
  }*/
      //lets print the actual solution
       /* int t = maxIndex;
        int newT = maxIndex;
        do{
            t = newT;
            cout<<a[t]<<" ";
            newT = actualSol[t];
        }while(t != newT);
       cout<<endl;	*/
}
int max(int a,int b)
{
  return (a>b)?a:b;
}