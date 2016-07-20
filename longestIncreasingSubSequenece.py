def longestIncreasingSubSequence(arr):
    res=[None]*len(arr)
    ind=[None]*len(arr)
    for i in range(len(arr)):
        res[i]=1
        ind[i]=i
    maximum=0
    for i in range(1,len(arr)):
        for j in range(i):
            if(arr[j]<arr[i]):
                prev=res[i]
                current=res[j]+1
                if(prev<current):
                    res[i]=current
                    ind[i]=j
                    if(current>maximum):
                        current=maximum
                        maxInd=i

    print(res)
    print(ind)
    print("Num that forms the longest increasing subsequence")
    while(maxInd>0):
        if(prev==maxInd):
            break;
        print(arr[maxInd])
        prev=maxInd
        maxInd=ind[maxInd]








arr=[3,4,-1,0,6,2,3]
longestIncreasingSubSequence(arr)