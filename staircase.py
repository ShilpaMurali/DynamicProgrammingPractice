#modification of fibonacci series
def staircaseWays(n):
    if(n==1):
        return 1
    elif(n==2):
        return 2
    else:
        return (n-1)+(n-2)
    
def staircaseWaysUsingFibUtil(n,m):
    res=[0]*n
    res[0]=1
    res[1]=1
    for i in range(2,n):
        for j in range(1,m+1):
            if(j>i):
                break
            res[i]+=res[i-j]
    print(res)
    return res[n-1]
    
def staircaseWaysUsingFib(n,m):
    return staircaseWaysUsingFibUtil(n+1,m)

print(staircaseWays(5))
#(4,2)= Reach the 4th stair using 1 step or 2 steps
print(staircaseWaysUsingFib(5,2))