function test(x)
    q = 3
    p = function (value)
        return value * x + q
    end
    q = 4
    return p
end

retFunc = test(10)
q = retFunc(5)
print(q)
