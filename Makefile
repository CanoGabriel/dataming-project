#SOURCES := $(shell find . -name "*.cpp")
DEBUG=yes

#---------------------------------------
#Editable part
SOURCE_DIR=source

TARGET_NAME=program
TARGET_DIR=bin

BUILD_DIR=build
RESSOURCE_DIR=resources

LIB_FLAG= -pthread
STATIC_LIB=


CFLAGS= -MMD -ansi --std=gnu++11 -pedantic -Wall -Wextra
SYSTEM_CFLAGS= $(GTEST_DIR)/include


ifeq ($(DEBUG),yes)
CFLAGS+= -ggdb
endif

CC=g++
SOURCE_EXT=cpp
HEADER_EXT=hpp
TARGET=$(TARGET_DIR)/$(TARGET_NAME)

sources := $(shell find $(SOURCE_DIR) -name "*.$(SOURCE_EXT)")
objects := $(sources:$(SOURCE_DIR)/%.$(SOURCE_EXT)=$(BUILD_DIR)/obj/%.o)
headers := $(shell find $(SOURCE_DIR) -name "*.$(HEADER_EXT)")
LDFLAGS := $(sort $(addprefix -I,$(dir $(headers))))

all: library $(TARGET) resources
#---------------------------------------
#Add of google test compile variable
GTEST_DIR=./lib/GoogleTestFramework/googletest
SYSTEM_CFLAGS = $(GTEST_DIR)/include
STATIC_LIB += $(BUILD_DIR)/lib/libgtest.a


#Add the compile rules for the Google Test Framework
googletest:directories $(BUILD_DIR)/lib/libgtest.a

$(BUILD_DIR)/lib/libgtest.a:$(BUILD_DIR)/lib/gtest-all.o
	@ar -rv $(BUILD_DIR)/lib/libgtest.a $(BUILD_DIR)/lib/gtest-all.o
	@echo "Google test library compiled"

$(BUILD_DIR)/lib/gtest-all.o : $(GTEST_DIR)/src/gtest-all.cc
	@g++ -std=c++11 -isystem $(GTEST_DIR)/include -I${GTEST_DIR} -pthread -c $(GTEST_DIR)/src/gtest-all.cc -o $(BUILD_DIR)/lib/gtest-all.o


#---------------------------------------
library: googletest

resources: directories
	@cp $(RESSOURCE_DIR)/* $(TARGET_DIR)/

-include $(OBJECTS:.$(OBJEXT)=.d)

directories:
	@mkdir -p $(RESSOURCE_DIR)
	@mkdir -p $(TARGET_DIR)
	@mkdir -p $(BUILD_DIR)/obj $(BUILD_DIR)/lib

$(TARGET):$(objects)
	@$(CC) -o $(TARGET) $^ $(CFLAGS) -isystem $(SYSTEM_CFLAGS) $(LIB_FLAG) $(STATIC_LIB) $(LDFLAGS) $(LIB)

$(BUILD_DIR)/obj/%.o:$(SOURCE_DIR)/%.$(SOURCE_EXT)
	@mkdir -p $(@D)
	@$(CC) -isystem $(SYSTEM_CFLAGS) $(LDFLAGS) $(CFLAGS) $(LIB_FLAG) -c -o $@ $<

clean:
	@rm -rf $(BUILD_DIR)/obj

#Full Clean, Objects and Binaries
cleaner: clean
	@rm -rf $(TARGET_DIR)

exec:
	./$(TARGET)

.PHONY: all clean cleaner resources
