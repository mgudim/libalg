TARGET = libalg.a
BUILD_DIR = ../build/src


SRC_DIR = ./
SRC_FILES := $(subst $(SRC_DIR), , $(shell find $(SRC_DIR) -name "*.c"))
OBJ_FILES = $(addprefix $(BUILD_DIR)/, $(SRC_FILES:.c=.o))
CC = clang
CC_FLAGS = -O2 -g
INC_DIR = ../include /home/libds/include
INC_FLAGS = $(addprefix -I, $(INC_DIR))
LIBDS_PATH = /home/libds/libds.a
LINK_FLAGS =  $(LIBDS_PATH)
link: compile extract_libds
	mkdir -p $(BUILD_DIR)
	mkdir -p $(BUILD_DIR)/libds
	ar rcs $(BUILD_DIR)/$(TARGET) $(LINK_FLAGS) $(OBJ_FILES) $(shell find $(BUILD_DIR)/libds_objs -name "*.o")


compile: $(OBJ_FILES)


$(BUILD_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CC_FLAGS) $(INC_FLAGS) -c $< -o $@


extract_libds:
	mkdir -p $(BUILD_DIR)/libds_objs
	cd $(BUILD_DIR)/libds_objs; ar -x /home/libds/libds.a
