texttocpp: main.cpp
	g++ -o texttocpp main.cpp -I.

install:
	install ./texttocpp /usr/local/bin/texttocpp
