function func()
    local value = math.abs(1)
    return value
end

function func1()
    local value = func()
    return value
end

func1()
