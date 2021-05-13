#一个名为id的int类型私有数据域。
#一个名为balance的float类型私有数据域。
#一个名为annualInterestRate的float类型私有数据域。假设所有账户都有相同的年利率。
#一个名为dateCreated的date类型私有数据域，存储账户的开户日期。
#一个用于创建指定id、 annualInterestRate和初始余额的账户的初始化方法，开户日期取当前时间。
#balance的访问器和修改器。
#Id、 annualInterestRate和dateCreated的访问器。
#一个名为getMonthlyInterestRate()的方法，返回月利率。
#一个名为withdraw()的方法，从账户提取特定数额。
#一个名为deposit()的方法，向账户存储特定数额。
import datetime
class Account:
    __id=0
    __balance=0.0
    __annualInterestRate=0.0
    __dateCreated的date=0
    def  __init__(self,id,balance):
       self.id=id
       self.balance=balance
       self.annualInterestRate=0.04
       self.dateCreated=datetime.datetime(2021,5,13)
    def testbalance(self,balance):
        self.balance=balance
    def getbalance(self):
        print(self.balance)
    def getid(self):
        print(id)
    def getannualInterestRate(self):
        print(self.annualInterestRate)
    def getdateCreated(self):
        print(self.dateCreated)
    def getgetMonthlyInterestRate(self):
        print((self.annualInterestRate)/12)
    def withdraw(self,money):
        self.balance-=money
    def deposit(self,money):
        self.balance+=money
a0 = Account(100, 100)
a1 = Account(101, 100)
a2 = Account(102, 100)
a3 = Account(103, 100)
a4 = Account(104, 100)
a5 = Account(105, 100)
a6 = Account(106, 100)
a7 = Account(107, 100)
a8 = Account(108, 100)
a9 = Account(109, 100)
list = [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9]
while True:
    print("Enter and id:",end = '')
    id = int(input())
    if id < 110 and id > 99:
        i = id % 100
        print("Main menu:")
        print("1: check balance")
        print("2: withdraw")
        print("3: deposit")
        print("4: exit")
        print("Enter  a choice:",end = '')
        choice = int(input())
        while choice != 4:
            if choice == 1:
               print("The balance is:",end = '')
               list[i].getbalance()
            if choice == 2:
                print("Please input the amount:",end = '')
                amount = int(input())
                list[i].withdaw(amount)
                print("The balance is:",end = '')
                list[i].getbalance()
            if choice == 3:
                print("Please input the amount:",end = '')
                amount = int(input())
                if amount>=0:
                    list[i].doposit(amount)
                    print("The balance is:",end = '')
                    list[i].getbalance()
                else:
                    print("Please input a positive number")
            choice = int(input())
    else:
        print("Please enter a right id")