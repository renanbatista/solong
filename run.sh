#!/bin/bash

clear
make fclean
make
./so_long "test.ber" "1024" "768"
# valgrind -s --leak-check=full ./so_long "test.ber" "1024" "768"