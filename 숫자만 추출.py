list = []
data = []
for i in range(0,312):
    data.append((input()))
    pos1 = str(data[i]).find('=')
    pos2 = str(data[i]).find(';')
    list.append(str(data[i][pos1+1:pos2]))

for i in range(0, 312):
    print(list[i], end = ',')