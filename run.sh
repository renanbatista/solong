#!/bin/bash

clear
make
valgrind --leak-check=full --show-leak-kinds=all -s -q ./so_long "test.ber" "1024" "768"
# ./so_long "test.ber" "1024" "768"
make fclean