def stockBuyAndSellWithKTransactions(price,trans):
    
    res=[[None for j in range(len(price))]for i in range(trans+1)]
    for i in range(len(price)):
        res[0][i]=0
    for i in range(trans+1):
        res[i][0]=0
    for i  in range(1,trans+1):
        for j in range(1,len(price)):
            maximum=0
            for m in range(j):
                #either do not make any transaction today and take the profit from yesterday's 
                #transaction or make a profit by selling today against the prices that was 
                #spent on buying the stock until (on all days before) todays + reduce a 
                #transaction and take the profit that would have been made by closing on the 
                #day that you have bought the stock.
                maximum=max(maximum,price[j]-price[m]+res[i-1][m])
            res[i][j]=max(maximum,res[i][j-1])
    print(res)



price=[2,5,7,1,4,3,1,3]
stockBuyAndSellWithKTransactions(price, 3)