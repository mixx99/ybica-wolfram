# make OUT_O_DIR=debug CC=clang CFLAGS="-g -O0"
# make OUT_O_DIR=debug
# make OUT_O_DIR=debug clean
# make clean

ifeq ($(origin CC),default)
	CC = gcc
endif

CFLAGS ?= -O2
OUT_O_DIR ?= build
# COMMONINC = -I./include
TESTS = ./Tests
SRC = ./src
ROOT_DIR:=$(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))
LDFLAGS ?= -lm

# override CFLAGS += $(COMMONINC)

CSRC = src/main.c src/vector.c

# reproducing source tree in object tree
COBJ := $(addprefix $(OUT_O_DIR)/,$(CSRC:.c=.o))
DEPS = $(COBJ:.o=.d)

.PHONY: all
all: $(OUT_O_DIR)/main.x

$(OUT_O_DIR)/main.x: $(COBJ)
	$(CC) $^ -o $@ $(LDFLAGS)

# static pattern rule to not redefine generic one
$(COBJ) : $(OUT_O_DIR)/%.o : %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(DEPS) : $(OUT_O_DIR)/%.d : %.c
	@mkdir -p $(@D)
	$(CC) -E $(CFLAGS) $< -MM -MT $(@:.d=.o) > $@

.PHONY: clean
clean:
	rm -rf $(COBJ) $(DEPS) $(OUT_O_DIR)/*.x $(OUT_O_DIR)/*.log

# targets which we have no need to recollect deps
NODEPS = clean

ifeq (0, $(words $(findstring $(MAKECMDGOALS), $(NODEPS))))
include $(DEPS)
endif
