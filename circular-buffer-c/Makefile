SRC_DIR := source
OBJ_DIR := objects
BIN_DIR := bin

EXE := $(BIN_DIR)/circbuffer.c.exe
SRC := $(wildcard $(SRC_DIR)/*.c)
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
# or
# OBJ := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

CPPFLAGS := -Iinclude -MMD -MP
CFLAGS := -Wall
LDFLAGS := -Llib
LDLIBS := -lm

all: $(EXE)

.PHONY: all

$(EXE): $(OBJ) | $(BIN_DIR)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

# $< = first argument
# $! = targets
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

clean:
	@$(RM) -rv $(BIN_DIR) $(OBJ_DIR)
# @ removes echo

# '-' silences errors
-include $(OBJ:.o=.d)