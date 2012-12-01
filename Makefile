CC = gcc
all_execs = reverselist arraymanipulation copy declarearray nofrees wc simpleexample global
FLAGS = -g -Wall -Werror

all : $(all_execs)

% : %.c
	$(CC) $< $(FLAGS) -o $@

clean:
	rm $(all_execs)
