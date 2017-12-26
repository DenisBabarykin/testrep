SERVER_PATH := src

all: server tests report

server: 
	make -C $(SERVER_PATH)

tests: unit_tests system_tests

unit_tests: 
	echo 'run unit tests'

system_tests: 
	echo 'run system tests'


clean:
	make -C $(SERVER_PATH) clean
	
.PHONY: all server tests unit_tests system_tests