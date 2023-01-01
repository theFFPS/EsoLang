CXX       ?= g++
CXX_OPTS  ?= -Wall -Werror -Wextra -g
PREFIX    ?= /usr
OUT        = target/esolang
all:
	$(CXX) $(CXX_OPTS) -o $(OUT) src/Main.cc
clean:
	rm -rf $(OUT)
install: all
	cp $(OUT) $(PREFIX)/bin