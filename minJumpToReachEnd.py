def minJumpToReachEnd(arr):
    minJump=[999]*len(arr)
    indJump=[999]*len(arr)
    minJump[0]=0
    indJump[0]=-1
    for i in range(1,len(arr)):
        for j in range(i):
            if(arr[j]+j>=i):
                prev=minJump[i]
                minJump[i]=min(minJump[i],minJump[j]+1)
                if(prev>minJump[i]):
                    indJump[i]=j
    print(minJump)
    print(indJump)
    index=indJump[len(arr)-1]
    while(index>0):
        print(arr[index])
        index=indJump[index]
    print(arr[index])



arr=[2,3,1,1,2,4,2,0,1,1]
minJumpToReachEnd(arr)