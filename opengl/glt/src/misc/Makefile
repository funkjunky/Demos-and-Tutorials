SUBDIRS = internal
CPP_SRC = string.cpp text2src.cpp timer.cpp compress.cpp image.cpp observer.cpp \
	  hash.cpp

GLT_HOME = ../..
INCLUDE  = -I$(GLT_HOME)/src/png
ARCHIVE = libglt.a

default: recurse lib

include $(GLT_HOME)/gcc/Makefile.inc

