import  sys
import datetime
import socket
from datetime import timedelta

f1 = open( sys.argv[1], "r" )
f2 = open( sys.argv[2], "a" )

now=datetime.datetime.now()
name=socket.gethostname()

f=open('/proc/uptime', 'r')
uptimeSeconds = float(f.readline().split()[0])
uptimeString = str(timedelta(seconds = uptimeSeconds))
f.close()

i = 0

while uptimeString[i] != ".":
	i = i + 1

uptime = uptimeString[0 : i]

lines=f1.readlines()
for line in lines:
	if "%HOSTNAME%" in line:
		f2.write(line.replace("%HOSTNAME%", name))
	elif "%DATE%" in line:
		f2.write(line.replace("%DATE%", now.strftime("%m/%d/%Y")))
	elif "%UPTIME%" in line:
		f2.write(line.replace("%UPTIME%", uptime))
	else:
		f2.write(line)
	
f1.close()
f2.close()   
