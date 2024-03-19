.PHONY: install uninstall dist clean
CC=g++
CFLAGS=-Wall -Wextra -Werror -std=c++17

install: uninstall
	make clean
	mkdir build
	cd src && qmake && make && make clean && rm Makefile && cd ../ && mv src/TimeTracker.app build

uninstall:
	rm -rf build*

dvi:
	open README.md

dist: install
	rm -rf Dist_TimeTracker/
	mkdir Dist_TimeTracker/
	mkdir Dist_TimeTracker/src
	mv ./build/TimeTracker.app Dist_TimeTracker/src/
	tar cvzf Dist_TimeTracker.tgz Dist_TimeTracker/
	rm -rf Dist_TimeTracker/
	rmdir build

clean:
	cd src && rm -rf *.a && rm -rf *.o  && rm -rf *.dSYM && rm -rf *.out && rm -rf $(EXECUTABLE) && rm -rf CPPLINT.cfg 
	cd src && rm -rf *.info && rm -rf Dist_TimeTracker && rm -rf *tgz && rm -rf build && rm -rf .qmake.stash