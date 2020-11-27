make && gcc -g -fsanitize=address -fsanitize=leak test.c -L. -lft && ./a.out
