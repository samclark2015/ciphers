.PHONY: all build_dir clean

TARGETS := vigenere shift affine otp recursive
COMMON := main.c common.c b64.c include/b64.h include/common.h 

CC := gcc

SRC_DIR := src
OUT_DIR := bin

all: $(addprefix $(OUT_DIR)/,$(TARGETS))

dirs: 
	mkdir -p $(OUT_DIR)/

clean: 
	rm -rf $(OUT_DIR)/*

$(OUT_DIR)/%: $(SRC_DIR)/ciphers/%.c $(addprefix $(SRC_DIR)/,$(COMMON))
	$(CC) $(filter-out %.h,$^) -I $(SRC_DIR)/include -o $@