a = coroutine.create(function()
    while(true)do
        print('a')
        coroutine.yield()
    end
end)

b = coroutine.create(function()
    while(true)do
        print('b')
        coroutine.yield()
    end
end)


while(true) do
    coroutine.resume(a)
    coroutine.resume(b)
end
