'''def minimum(a,b,c):
    if(a>b and a>c):return a:if(b>a and b>c):return b:return c'''
def minSubSqMatrix(mat):
    res=[[999 for j in range(len(mat[0]))]for i in range(len(mat))]
    for i in range(len(mat)):
        res[i][0]=mat[i][0]
    for i in range(len(mat[0])):
        res[0][i]=mat[0][i]
    for i in range(1,len(mat)):
        for j in range(1,len(mat[0])):
            if(mat[i][j]==0):
                res[i][j]=0
            else:
                value=min([res[i][j-1],res[i-1][j],res[i-1][j-1]])
                res[i][j]=1+value
    print(res)
    






mat=[[0,0,1,1,1],[1,0,1,1,1],[0,1,1,1,1],[1,0,1,1,1]]
minSubSqMatrix(mat)