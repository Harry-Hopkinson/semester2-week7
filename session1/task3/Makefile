# Task 3 Makefile

CFLAGS = -Wall -Wextra -Werror

task3: task3.c logging.h
	gcc $(CFLAGS) -o task3 task3.c

verbose: task3.c logging.h
	gcc $(CFLAGS) -DVERBOSE -o task3 task3.c

clean:
	@rm -f task3

.PHONY: clean
