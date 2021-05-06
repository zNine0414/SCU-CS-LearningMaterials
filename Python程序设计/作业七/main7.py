class Bug:
   initialPostion=0
   fx=1
   #0代表向左，1代表向右
   def  __init__(self,initialPostion):
       self.initialPostion=initialPostion
   def  turn(self):
       self.fx+=1
       self.fx=self.fx%2
   def  move(self):
       if self.fx==1:
           self.initialPostion+=1
       elif self.fx==0:
           self.initialPostion-=1
   def  getPostion(self):
        print(self.initialPostion)


bug1=Bug(0)
bug1.getPostion()
bug1.move()
bug1.getPostion()
bug1.move()

bug1.getPostion()
bug1.turn()
bug1.getPostion()
bug1.move()
bug1.getPostion()
bug1.move()
bug1.getPostion()
bug1.move()
bug1.getPostion()
bug1.move()
bug1.getPostion()
