sum = eval(input())
money=0
if sum > 100:
    money+=(sum-100)*0.01
    sum=100
if sum > 60:
    money+=(sum-60)*0.015
    sum=60
if sum > 40:
    money+=(sum-40)*0.03
    sum=40
if sum > 20:
    money+=(sum-20)*0.05
    sum=20
if sum > 10:
    money+=(sum-10)*0.075
    sum=10
if sum <=10:
    money+=sum*0.1
print(money)
