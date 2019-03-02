DEBUG=yes
CC=g++

SRC_DIR=source
HEADER_DIR=header
BIN_DIR=bin

SRC_EXT=cpp
HEADER_EXT=hpp

EXEC=prog

LDFLAGS= -I$(HEADER_DIR)
CFLAGS= -MMD -ansi --std=gnu++11 -pedantic -Wall -Wextra #-Wold-style-cast -Woverloaded-virtual -Wfloat-equal -Wwrite-strings -Wpointer-arith -Wcast-qual -Wcast-align -Wconversion -Wshadow -Wredundant-decls -Wdouble-promotion -Winit-self -Wswitch-default -Wswitch-enum -Wundef -Wlogical-op -Winline
ifeq ($(DEBUG),yes)
CFLAGS+= -ggdb
endif

DEPENDENCIES=$(subst $(SRC_DIR),$(BIN_DIR),$(patsubst %.$(SRC_EXT),%.d,$(wildcard $(SRC_DIR)/*.$(SRC_EXT))))


all:$(EXEC)
ifeq ($(DEBUG),yes)
	@echo "Génération en mode debug"
else
	@echo "Génération en mode release"
endif

$(EXEC): $(subst $(SRC_DIR),$(BIN_DIR),$(patsubst %.$(SRC_EXT),%.o,$(wildcard $(SRC_DIR)/*.$(SRC_EXT))))
	@$(CC) -o $(EXEC) $^ $(CFLAGS) $(LDFLAGS)

$(BIN_DIR)/%.o: $(SRC_DIR)/%.$(SRC_EXT)
	@$(CC) -c $< -o $@ $(CFLAGS) $(LDFLAGS)

-include $(DEPENDENCIES)

clean:
		@rm -rf $(BIN_DIR)/*.o
clean_exec:
		@rm -rf $(EXEC)
proper:clean clean_exec
