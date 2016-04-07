print("USE_LUA_AS_MOD_LOGIC")

bar = Bar.new(5)
-- bar now refers to a new instance of Bar with its member x set to 5

x = bar:add_this(2)
-- x is now 7

bar = nil

print('=========================================================')
print('user stock: ', x)
print('=========================================================')
