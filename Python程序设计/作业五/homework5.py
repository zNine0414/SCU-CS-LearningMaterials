f = open("scan.txt","r")
data = f.read()

a = data.split("\n")
list1 = []
list2 = []
list3 = []
list4 = []
list5 = []
list6 = []
list7 = []
list8 = []
for i in a:
    if "Address" in i:
        list1.append(i)
    if "ESSID" in i:
        list2.append(i)
    if "Mode" in i:
        list3.append(i)
    if "Channel" in i:
        list4.append(i)
    if "Signal" in i:
        list5.append(i)
    if "Quality" in i:
        list6.append(i)
    if "Encryption" in i:
        list7.append(i)
for i in range(0,len(list1)):
    list1[i] = list1[i][19:]
for i in range(0,len(list2)):
    list2[i] = list2[i][17:]
for i in range(0,len(list3)):
    list3[i] = list3[i][16:24]
for i in range(0,len(list4)):
    list4[i] = list4[i][33:]
for i in range(0,len(list5)):
    list5[i] = list5[i][18:26]
for i in range(0,len(list6)):
    list6[i] = list6[i][36:]
for i in range(0,len(list7)):
    list7[i] = list7[i][22:]
print("Address".ljust(25),end='')
print("ESSID".ljust(20),end='')
print("Mode".ljust(20),end='')
print("Channel".ljust(20),end='')
print("Signal".ljust(20),end='')
print("Quality".ljust(20),end='')
print("Encryption".ljust(20),end='\n')

for i in range(8):
    print(list1[i].ljust(25),end='')
    print(list2[i].ljust(20),end='')
    print(list3[i].ljust(20),end='')
    print(list4[i].ljust(20),end='')
    print(list5[i].ljust(20),end='')
    print(list6[i].ljust(20),end='')
    print(list7[i].ljust(20),end='\n')
 