<?php
$s=socket_create(AF_INET,SOCK_DGRAM,0);            //create a UDP socket
socket_sendto($s,"hey",3,0,"127.0.0.1",9999);      //send 3 bytes to the server
socket_recvfrom($s,$b,10,0,$serv_ip,$serv_port);   //read max 10 bytes from socket $s into buffer $b
echo "Received: ".$b." from IP=".$serv_ip.":".$serv_port;
?>