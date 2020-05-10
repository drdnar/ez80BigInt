# ----------------------------
# Set NAME to the program name
# Set ICON to the png icon file name
# Set DESCRIPTION to display within a compatible shell
# Set COMPRESSED to "YES" to create a compressed program
# ----------------------------

NAME        ?= BIGINT
COMPRESSED  ?= NO
ICON        ?= iconc.png
DESCRIPTION ?= "BigInt test"

# ----------------------------

include $(CEDEV)/include/.makefile
