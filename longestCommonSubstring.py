def longestCommonSubstring(str1,str2):
    res=[[0 for j in range(len(str1)+1)]for i in range(len(str2)+1)]
    max=0
    maxI=0
    maxJ=0
    for i in range(1,len(str2)+1):
        for j in range(1,len(str1)+1):
            if(str2[i-1]==str1[j-1]):
                res[i][j]=res[i-1][j-1]+1 
                if(max<res[i][j]):
                    max=res[i][j]
                    maxI=i;
                    maxJ=j;
                               
    print(res)
    while(maxI and maxJ):
        if(res[maxI][maxJ]):
            print(str2[maxI-1])
            maxI-=1
            maxJ-=1
        else:
            break
        
        
longestCommonSubstring("abcdaf","zbcdf")