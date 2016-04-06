a = function()
    x = 1
    b = function()
        x = x + 1
    end
    x = 3
    b()
    print(x)
end

a()
