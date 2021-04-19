'''一个整数，加上100后是一个完全平方数，再加上268又是一个完全平方数，请问这个数是多少？'''

for i in range(200000):
    if (i+100)**0.5==int((i+100)**0.5):
        if (i+100+268)**0.5==int((i+100+268)**0.5):
            print(i)
            break
        else :
            continue
    else :
        continue


