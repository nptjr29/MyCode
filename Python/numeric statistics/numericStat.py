from math import sqrt
num = raw_input( "Enter as many positive numbers as you want. Enter a negative number when you are done: ")
list1 = []
sum = 0.0
sumVar = 0.0
var = 0.0

while int(num) > 0:
	list1.append( num )
	sum = int( num ) + int ( sum )
	num = raw_input("Enter as many positive numbers as you want. Enter a negative number when you are done: ")

count = len( list1 )

average = float( sum ) / float ( count )

print "Average is %.2f" %(average)

for item in list1:
	sumVar = sumVar + ( ( float(item) - float(average) ) ** 2 )

var = float(sumVar) / (float(count) - 1) 

print "Variance is %.2f" %(var)

sd = sqrt(var)

print "Standard deviation is %.2f" %(sd)

