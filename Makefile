CC = g++
CFLAGS = -g -Wall -Werror -std=c++11

all: first second

first: scenarios/first.cpp echo_service_installer.cpp echo_service.cpp host.cpp link_installer.cpp link.cpp manual_router.cpp message_service_installer.cpp message_service.cpp router.cpp service_installer.cpp node.cpp service.cpp address.h packet.h 
	$(CC) $(CFLAGS) -o first scenarios/first.cpp echo_service_installer.cpp echo_service.cpp host.cpp link_installer.cpp link.cpp manual_router.cpp message_service_installer.cpp message_service.cpp router.cpp service_installer.cpp node.cpp service.cpp address.h packet.h

second: scenarios/second.cpp echo_service_installer.cpp echo_service.cpp host.cpp link_installer.cpp link.cpp manual_router.cpp message_service_installer.cpp message_service.cpp router.cpp service_installer.cpp node.cpp service.cpp address.h packet.h 
	$(CC) $(CFLAGS) -o second scenarios/second.cpp echo_service_installer.cpp echo_service.cpp host.cpp link_installer.cpp link.cpp manual_router.cpp message_service_installer.cpp message_service.cpp router.cpp service_installer.cpp node.cpp service.cpp address.h packet.h 

clean:
	rm -f *.o first