#include<iostream>
#include<string>
#include<cstring>
using namespace std;
void lps(char*,int);
int main()
{
  char stringInput[]="agbdba";
  int lenOfArray= strlen(stringInput);
  lps(stringInput,lenOfArray);
  return 0;
}
void lps(char* stringInput, int lenOfArray)
{
  int result[6][6]={-1};
  int index2=0;
  cout<<"lenofArray:"<<lenOfArray<<endl;
  for(int i=0;i<lenOfArray;i++)
  {
    result[i][i]=1;
  }
  for(int len=2;len<=lenOfArray;len++)
  {
    for(int index1=0;index1<lenOfArray-len+1;index1++)
    {
      index2=index1+len-1;
      if(stringInput[index1] == stringInput[index2] && len == 2)
      {
        result[index1][index2]=2;
      }
      else if(stringInput[index1] == stringInput[index2])
      {
        result[index1][index2]=2 + result[index1+1][index2-1];
      }
      else
      {
        result[index1][index2]=max(result[index1+1][index2],result[index1][index2-1]);
      }
    }
  }
  for(int i=0;i<lenOfArray;i++)
  {
    for(int j=0;j<lenOfArray;j++)
    {
      cout<<result[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<endl;
  cout<<"LPS:"<<result[0][lenOfArray-1];
  int len=lenOfArray;
  while(len!=0)
  {
	  cout<<stringInput[result[0][lenOfArray-1]]<<"";
	  len=lenOfArray-result[0][lenOfArray-1];
  }
}
int max(int a,int b)
{
  return (a>b)?a:b;
}