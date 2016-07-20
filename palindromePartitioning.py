def isPalindrome(strInput,i,j):
    print("Inside is palindrome")
    print(strInput,i,j)
    while(i<j):
        if(strInput[i]!=strInput[j]):
            return False
        i+=1
        j=-1
    return True

def palindromePartitioning(strInput):
    res=[[999 for j in range(len(strInput))] for i in range(len(strInput))]
    for l in range(1,len(strInput)+1):
        print("Inside l")
        print(l)
        if(l==1):
            for i in range(len(strInput)):
                res[i][i]=0
        else:
            for i in range(len(strInput)-l+1):
                print("Inside i")
                j=i+l-1
                if(isPalindrome(strInput,i,j)):
                    res[i][j]=0
                else:
                    print("inside else")
                    for k in range(i,j):
                        print("Inside k")
                        print(res[i][k])
                        print(res[k+1][l-1])
                        res[i][j]=min(res[i][j],1+res[i][k]+res[k+1][j])
                        print(res[i][j])
            
        
        print(res)
        
palindromePartitioning("abcbm")