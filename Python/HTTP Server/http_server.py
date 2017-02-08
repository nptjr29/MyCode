import socket
import sys
import io

HOST, PORT = 'nptjr29', 8000
count = 0

listen_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
listen_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
listen_socket.bind((HOST, PORT))
listen_socket.listen(1)
listen_socket.accept()

while True:
	client_connection, client_address = listen_socket.accept()
	request = client_connection.recv(1024)
	
	if request[:4] != "GET ":
		http_response = "400 Bad Request"
		print "Bad Request"
	elif request[:11] == "GET /STATUS":
		http_response = """\
STATUS PAGE
Server is running.
There have been %s documents served so far
""" %count
		print("Sent STATUS")
	else:			
		filename = request[5:15]
		try:
			f=open( filename, "r" )
			http_response = f.read()
			print("Sent %s" %filename)
			count = count + 1
		except IOError:
			http_response = "404 File Not Found"
			print ("Could not find %s" %filename)

	client_connection.sendall(http_response)
	client_connection.close()
