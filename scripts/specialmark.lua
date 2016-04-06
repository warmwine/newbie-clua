--单引号字符串
a = 'alo\n123"'
print(a)

--双引号字符串
a = "alo\n123\""
print(a)

--用\+整数转码的字符串
a = '\97lo\10\04923"'
print(a)

--用level0的[[]]表示的字符串
a = [[alo
123"]]
print(a)

--用level2的[[]]表示的字符串
a = [==[
alo
123"]==]
print(a)
