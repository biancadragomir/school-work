import time
import socket
from threading import Thread


def f(cs, i):
    print("This is client number ", i)
    time.sleep(10)
    sth = cs.recv(1024).decode()
    print("the server received: ", sth)
    cs.send('hello from server!'.encode())
    cs.close()

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind(("127.0.0.1", 9999))
s.listen(5)
i = 0
while True:
    print("Execution started")
    i += 1
    cs, addr = s.accept()
    t = Thread(target=f, args=(cs,i,))
    t.start()
