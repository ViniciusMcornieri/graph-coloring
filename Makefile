ALL:
	clang src/*.c -Wall -Werror -o src/main
test:
	gcc tests/*.c src/*.c tests/seatest/src/seatest.c -o all_tests -Wall
	./all_tests

clear:
	rm all_tests
	rm src/main
