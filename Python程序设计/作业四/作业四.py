

import random 
testlist=list(range(1,1000))
LIST=random.sample(testlist,50)
#print(LIST)

def oddremove(onelist):
    for i in onelist[::-1]:
        if i%2!=0:
             onelist.remove(i)

oddremove(LIST)
print(LIST)
    