SERVER_PATH := src
UNIT_TESTS_PATH := tests/UnitTests

all: server tests report

server: 
	make -C $(SERVER_PATH)

tests: unit_tests system_tests

unit_tests: 
	make -C $(UNIT_TESTS_PATH)

system_tests: 
	echo 'run system tests'


clean:
	make -C $(SERVER_PATH) clean
	make -C $(UNIT_TESTS_PATH) clean
	
.PHONY: all server tests unit_tests system_tests
