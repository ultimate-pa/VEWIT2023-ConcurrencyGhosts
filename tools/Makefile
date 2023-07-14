#------------------------------------------------------------------------------
# Makefile - Build targets to lint and validate YAML-based witness files and
#            concurrent example programs
#------------------------------------------------------------------------------
# Author: Manuel Bentele
#   Date: 2023-07-12
#------------------------------------------------------------------------------

CC = gcc
PL = clang-tidy
WL = yamllint
WV = yajsv
WD = generate-schema-doc
VT = Ultimate

#------------------------------------------------------------------------------
# Define input files (witnesses, programs, paths, ...)
#------------------------------------------------------------------------------
PROGRAM_FILES = $(wildcard ../examples/*.c)
WITNESS_FILES = $(wildcard ../examples/*.yaml)

WITNESS_SCHEMA_FILE = ../witness.schema.json
WITNESS_DOCCFG_FILE = jsfh/jsfh.yml
WITNESS_DOCOUT_DIR  = output/schema/doc
WITNESS_DOCPUB_DIR  = ../schema-doc

ULTIMATE_TLC_FILE = ultimate/toolchain_automizer-c-inline.xml
ULTIMATE_CFG_FILE = ultimate/settings_concurrent-analysis.epf
ULTIMATE_LOG_DIR  = output/ultimate/log

#------------------------------------------------------------------------------
# Build target definitions
#------------------------------------------------------------------------------
.PHONY: all
all: build validate verify

# define 'build' targets
.PHONY: build
build: build-witness-schema-doc

.PHONY: build-witness-schema-doc
build-witness-schema-doc: $(WITNESS_DOCOUT_DIR)/index.html

$(WITNESS_DOCOUT_DIR)/index.html:
	mkdir -p $(WITNESS_DOCOUT_DIR)
	$(WD) --config-file $(WITNESS_DOCCFG_FILE) $(WITNESS_SCHEMA_FILE) $@

# define 'validate' targets
.PHONY: validate
validate: validate-programs validate-witnesses

# define 'validate' targets for all programs
.PHONY: validate-programs
validate-programs: lint-program-syntax validate-program-syntax

.PHONY: lint-program-syntax
lint-program-syntax: $(PROGRAM_FILES)
	$(PL) $? --

.PHONY: validate-program-syntax
validate-program-syntax: $(PROGRAM_FILES)
	$(CC) -Wall -Wextra -fsyntax-only $?

# define 'validate' targets for all witnesses
.PHONY: validate-witnesses
validate-witnesses: lint-witness-syntax validate-witness-syntax

.PHONY: lint-witness-syntax
lint-witness-syntax: $(WITNESS_FILES)
	$(WL) -s -d "{extends: default, rules: {line-length: disable}}" $?

.PHONY: validate-witness-syntax
validate-witness-syntax: $(WITNESS_FILES)
	$(WV) -s $(WITNESS_SCHEMA_FILE) $?

# define 'verify' targets for all programs
.PHONY: verify
verify: ultimate-program-verify

.PHONY: ultimate-program-verify
ultimate-program-verify: $(patsubst %.c, $(ULTIMATE_LOG_DIR)/%.log, $(notdir $(PROGRAM_FILES)))

$(ULTIMATE_LOG_DIR)/%.log: $(PROGRAM_FILES)
	mkdir -p $(ULTIMATE_LOG_DIR)
	$(VT) -tc $(ULTIMATE_TLC_FILE) -s $(ULTIMATE_CFG_FILE) -i $< > $@

# define 'publish' target to publish schema documentation
.PHONY: publish
publish: $(WITNESS_DOCPUB_DIR)/index.html

$(WITNESS_DOCPUB_DIR)/index.html: $(WITNESS_DOCOUT_DIR)/index.html
	mkdir -p $(WITNESS_DOCPUB_DIR)
	cp -rf $(WITNESS_DOCOUT_DIR)/* $(WITNESS_DOCPUB_DIR)

# define 'clean' target to remove all generated artifacts
.PHONY: clean
clean:
	rm -rf $(WITNESS_DOCOUT_DIR)
	rm -rf $(ULTIMATE_LOG_DIR)
