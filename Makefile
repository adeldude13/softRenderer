CC := clang++
cfiles := main.cpp window.cpp color.cpp draw.cpp vec.cpp obj.cpp
hfiles := color.hpp window.hpp vec.hpp draw.hpp obj.hpp
files := $(cfiles) $(hfiles) Makefile
out := main
libs := `pkg-config --cflags --libs sdl2`
args := $(libs) -O0 -ggdb3 -Wall -Wextra -o $(out)

main: $(files)
	$(CC) $(args) $(cfiles)

clean:
	rm $(out)
