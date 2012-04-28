CC = gcc
all_execs = reverselist reverselist-clang arraymanipulation arraymanipulation-clang copy copy-clang declarearray declarearray-clang nofrees nofrees-clang
FLAGS = -g -Wall -Werror

all : $(all_execs)

% : %.c
	$(CC) $< $(FLAGS) -o $@

%-clang : %.c
	~ece190/bin/clang $< $(FLAGS) -o $@

clean:
	rm $(all_execs)
