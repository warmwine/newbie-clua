lastPrice = 0
flag=0
stock=0
lastbuy=0

function newPriceComing(p)
    print(p)
    if lastPrice>0 then
        if p < lastPrice - 10 then
            flag = 1
        end
        if p > lastPrice + 10 then
            flag = -1
        end
        if p > lastPrice - 1 and flag==1 then
            print("Buy 1000 stock on ", p)
            stock = stock + 1000
            lastbuy = p
            flag = 0
        end

        if p < lastPrice + 1 and flag==-1 and stock>0 then
            print("Sell ", stock, " stock on ", p, "  Earn ", (p - lastbuy)*1000)
            stock = 0
            flag = 0
        end
    end
    lastPrice = p
end

print("USE_LUA_AS_MOD_LOADED")
