def maxSumIncSubSeq(oriArr):
    maxArr=[None]*len(oriArr)
    indArr=[None]*len(oriArr)
    for i in range(len(oriArr)):
        maxArr[i]=oriArr[i]
        indArr[i]=i
    print(maxArr)
    print(indArr)
    j=0
    for i in range(1,len(oriArr)):
        for j in range(i):
            if(oriArr[j]<oriArr[i]):
                #maximum of the number in max array or the sum of the value in originalArr[i] + maxArr[j]
                prev=maxArr[i]
                maxArr[i]=max(maxArr[i],maxArr[j]+oriArr[i])
                if(prev<maxArr[i]):
                    indArr[i]=j
                    print("-------------")
                    print(maxArr[i])
                    print(indArr[i])
                    print("-------------")
    print(maxArr)
    print(indArr)
    maximum=0
    for i in range(len(maxArr)):
        if(maxArr[i]>maximum):
            maximum=maxArr[i]
            index=i
    while(index>0):
        print(oriArr[index])
        index=indArr[index]
    print(oriArr[index])
        
                
arr=[4,6,1,3,8,4,6]
maxSumIncSubSeq(arr)