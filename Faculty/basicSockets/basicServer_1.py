import socket
host = socket.gethostname()
port = 9999
s = socket.socket()
print('created socket\n')
s.bind(('127.0.0.1', port))
s.listen(5)
conn, addr = s.accept()
print('accepted connection')
print('Got connection from ', addr[0], '(', addr[1], ')')
print('Thank you for connecting')
# data='hello from server'
if True:
    data = conn.recv(1024).decode()
    print('the server received: ')
    print(data)
    conn.send(b'hello from server')
    print('now closing the socket')
    conn.close()