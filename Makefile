CC = gcc
all_execs = reverselist reverselist-clang
FLAGS = -g -Wall -Werror

all : $(all_execs)

% : %.c
	$(CC) $< $(FLAGS) -o $@

%-clang : %.c
	~ece190/bin/clang $< $(FLAGS) -o $@

clean:
	rm $(all_execs)
