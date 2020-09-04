.PHONY = clean all debug nlocal run

CC = clang++-10
EXE = main
COMPILE_FLAGS = -std=c++17 -DNOOPTIMISE -Wall -O2 -Wshadow
DEFINE_LOCAL = -DLOCAL
DEBUG_FLAGS = -g
RELEASE_FLAGS =

ifeq ($(BUILD), debug)
COMPILE_FLAGS += $(DEBUG_FLAGS)
else
COMPILE_FLAGS += $(RELEASE_FLAGS)
endif

ifneq ($(RUN), nlocal)
COMPILE_FLAGS += $(DEFINE_LOCAL)
endif


all:
	@rm -rf $(EXE)
	@$(CC) -o $(EXE) $(COMPILE_FLAGS) main.cpp
	@echo "======= BEGIN =======\n"
	@./main
	@echo "=======  END  =======\n"
	
just: $(EXE)

debug:
	make "BUILD=debug"

nlocal:
	make "RUN=nlocal"

$(EXE): main.cpp
	@$(CC) -o $(EXE) $(COMPILE_FLAGS) main.cpp    

clean:
	rm -rf $(EXE)
