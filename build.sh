#!/bin/sh

set -xe
cc clock.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o clock
