import subprocess

#below line executes top command for one iteration 
result = subprocess.check_output("top -b -n 1 -c", shell=True).split("\n")

head = result[:5]
body = [x for x in result[7:] if x] #removes empty strings

for line in head:
    print line

data1 = { }
data2 = { }
for line in body:
	print line
	y = line.split()
	if len(y) == 12 and y[0].isdigit() :
		y[0] = int(y[0])
		if y[0] in data1.keys() :
			data1[y[0]][0] = data1[y[0]][0] + float(y[8])
		else :
			data1[y[0]] = [float(y[8]),y[11]]

		if y[0] in data2.keys() :
			data2[y[0]][0] = data2[y[0]][0] + float(y[9])
		else :
			data2[y[0]] = [float(y[9]),y[11]]

#print data1, '\n'
#print data2, '\n'

items1 = [(v, k) for k, v in data1.items()]
items1.sort()
items1.reverse()
items1 = [(k, v) for v, k in items1]

items2 = [(v, k) for k, v in data2.items()]
items2.sort()
items2.reverse()
items2 = [(k, v) for v, k in items2]

#print items1, '\n'
#print items2, '\n'

print '\n'
print "Highest CPU consuming process with PID=", items1[0][0], items1[0][1][1]

print "lowest CPU time consuming process with PID= ", items1[len(items1) - 1][0], items1[len(items1) - 1][1][1]

print '\n'

print "Highest memory consuming process with PID=", items2[0][0], items2[0][1][1]

print "lowest memory consuming process with PId= ", items2[len(items2) - 1][0], items2[len(items2) - 1][1][1]
