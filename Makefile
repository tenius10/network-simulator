CC = g++
CFLAGS = -g -Wall -Werror -std=c++11
SOURCES = bulk_send_service_installer.cpp bulk_send_service.cpp echo_service_installer.cpp echo_service.cpp host.cpp link_installer.cpp link.cpp manual_router.cpp message_service_installer.cpp message_service.cpp node.cpp object.cpp packet_sink_service_installer.cpp packet_sink_service.cpp service_installer.cpp service.cpp simulator.cpp object.h


all: first second third forth

# 목적 파일 만들어서 효율적으로 컴파일하고 싶은데... 시험 전 날에 2시간째 에러가 나서 그냥 이렇게 작성했습니다.
first: ./scenarios/first.cpp $(SOURCES)
	$(CC) $(CFLAGS) -o first ./scenarios/first.cpp $(SOURCES)

second: ./scenarios/second.cpp $(SOURCES)
	$(CC) $(CFLAGS) -o second ./scenarios/second.cpp $(SOURCES)

third: ./scenarios/third.cpp $(SOURCES)
	$(CC) $(CFLAGS) -o third ./scenarios/third.cpp $(SOURCES)

forth: ./scenarios/forth.cpp $(SOURCES)
	$(CC) $(CFLAGS) -o forth ./scenarios/forth.cpp $(SOURCES)

clean:
	rm -f *.o *.exe first second third forth