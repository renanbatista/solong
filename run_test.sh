#!/bin/bash

clear
make fclean
make test
./so_long "test.ber" "1024" "768"