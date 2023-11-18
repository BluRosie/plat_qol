# Makefile
.PHONY: clean all


ifeq ($(OS),Windows_NT)
EXE := .exe
else
EXE := .exe
endif

default: all

ROMNAME = rom.nds
BUILDROM = plat_qol.nds
####################### Tools #########################
NDSTOOL = tools/ndstool
ARMIPS = tools/armips

####################### Setting ########################
ifeq ($(strip $(DEVKITPRO)),)
PREFIX = arm-none-eabi-
AS = $(PREFIX)as
CC = $(PREFIX)gcc
LD = $(PREFIX)ld
OBJCOPY = $(PREFIX)objcopy
else
PREFIX = bin/arm-none-eabi-
AS = $(DEVKITARM)/$(PREFIX)as
CC = $(DEVKITARM)/$(PREFIX)gcc
LD = $(DEVKITARM)/$(PREFIX)ld
OBJCOPY = $(DEVKITARM)/$(PREFIX)objcopy
endif

LDFLAGS = rom.ld -T linker.ld
ASFLAGS = -mthumb -I ./data
CFLAGS = -mthumb -mno-thumb-interwork -mcpu=arm7tdmi -mtune=arm7tdmi -mno-long-calls -march=armv4t -Wall -Wextra -Os -fira-loop-pressure -fipa-pta

PYTHON = python3
NARCHIVE = $(PYTHON) tools/narcpy.py
LINK = build/linked.o
OUTPUT = build/output.bin
####################### Build #########################
C_SUBDIR = src
ASM_SUBDIR = asm
INCLUDE_SUBDIR = include
BUILD = build
BUILD_NARC = $(BUILD)/narc
BASE = base
FILESYS = $(BASE)/root

INCLUDE_SRCS := $(wildcard $(INCLUDE_SUBDIR)/*.h)

C_SRCS := $(wildcard $(C_SUBDIR)/*.c)
C_OBJS := $(patsubst $(C_SUBDIR)/%.c,$(BUILD)/%.o,$(C_SRCS))

ASM_SRCS := $(wildcard $(ASM_SUBDIR)/*.s)
ASM_OBJS := $(patsubst $(ASM_SUBDIR)/%.s,$(BUILD)/%.d,$(ASM_SRCS))
OBJS     := $(C_OBJS) $(ASM_OBJS)

############## Code #####################
##Change the files names so it points to your custom .c file.
build/%.d:asm/%.s
	mkdir -p build
	$(AS) $(ASFLAGS) -c $< -o $@

build/%.o:src/%.c
	mkdir -p build
	@echo -e "\e[32;1mCompiling $<\e[37;1m"
	$(CC) $(CFLAGS) -c $< -o $@

$(LINK):$(OBJS)
	$(LD) $(LDFLAGS) -o $@ $(C_OBJS) $(ASM_OBJS)

$(OUTPUT):$(LINK)
	$(OBJCOPY) -O binary $< $@


########## All ###############
##Make sure to also change the necessary fields in here too !
all:$(OUTPUT)
	@mkdir -p base $(BUILD) $(BUILD)/data $(BUILD_NARC)
	@rm -rf build/data/*
	@$(NDSTOOL) -x $(ROMNAME) -9 base/arm9.bin -7 base/arm7.bin -y9 base/overarm9.bin -y7 base/overarm7.bin -d base/root -y base/overlay -t base/banner.bin -h base/header.bin
	@echo -e "\e[32;1mCreated Successfully!!\e[37;1m"
	@echo -e "\e[32;1mUnpack weather_sys.narc\e[37;1m"
	@$(NARCHIVE) extract base/root/data/weather_sys.narc -o build/data/ -nf
	@echo -e "\e[32;1mInsert code\e[37;1m"
	@$(PYTHON) scripts/insert.py
	@echo -e "\e[32;1mSkip synth overlay verification\e[37;1m"
	@$(ARMIPS) armips/new_things.s
	$(MAKE) move_narc
	@$(NARCHIVE) create base/root/data/weather_sys.narc build/data/ -nf
	@echo -e "\e[32;1mBuild Rom\e[37;1m"
	@$(NDSTOOL) -c $(BUILDROM) -9 base/arm9.bin -7 base/arm7.bin -y9 base/overarm9.bin -y7 base/overarm7.bin -d base/root -y base/overlay -t base/banner.bin -h base/header.bin
	@echo -e "\e[32;1mDone!\e[37;1m"


build_tools:
	mkdir -p tools/source
	rm -r -f tools/source/ndstool
	cd tools/source ; git clone https://github.com/devkitPro/ndstool.git
	cd tools/source/ndstool ; git checkout fa6b6d01881363eb2cd6e31d794f51440791f336
	cd tools/source/ndstool ; find . -name '*.sh' -execdir chmod +x {} \;
	cd tools/source/ndstool ; ./autogen.sh
	cd tools/source/ndstool ; ./configure && $(MAKE)
	mv tools/source/ndstool/ndstool tools/ndstool
	rm -r -f tools/source/ndstool

	rm -r -f tools/source/armips
	cd tools/source ; git clone --recursive https://github.com/Kingcom/armips.git
	cd tools/source/armips ; mkdir build
	cd tools/source/armips/build ; cmake -DCMAKE_BUILD_TYPE=Release ..
	cd tools/source/armips/build ; cmake --build .
	mv tools/source/armips/build/armips tools/armips
	rm -r -f tools/source/armips


SCR_SEQ_TARGET = $(FILESYS)/fielddata/script/scr_seq.narc
SCR_SEQ_DIR = $(BUILD)/scr_seq
SCR_SEQ_NARC = $(BUILD_NARC)/scr_seq.narc
SCR_SEQ_DEPENDENCIES_DIR := rawdata/scripts
SCR_SEQ_DEPENDENCIES := $(SCR_SEQ_DEPENDENCIES_DIR)/*

$(SCR_SEQ_NARC): $(SCR_SEQ_DEPENDENCIES)
	@mkdir -p $(SCR_SEQ_DIR)
	@$(NARCHIVE) extract $(SCR_SEQ_TARGET) -o $(SCR_SEQ_DIR) -nf
	@cp -r $(SCR_SEQ_DEPENDENCIES_DIR)/. $(SCR_SEQ_DIR)
	@$(NARCHIVE) create $@ $(SCR_SEQ_DIR) -nf

NARC_FILES += $(SCR_SEQ_NARC)


move_narc: $(NARC_FILES)
	@cp $(SCR_SEQ_NARC) $(SCR_SEQ_TARGET)


clean:
	rm -rf build/

