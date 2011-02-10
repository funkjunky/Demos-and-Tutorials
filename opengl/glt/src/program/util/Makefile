CPP_SRC  = bin2src.cpp  dos2unix.cpp  text2src.cpp  unix2dos.cpp vrmlpars.cpp
GLT_HOME = ../../..
INCLUDE  =
GLT_LIBS = -L$(GLT_HOME)/lib -lglutm -lglt -lpng -lz

ifdef WINDIR
LIBS     = $(GLT_LIBS) -lglut32 -lglu32 -lopengl32
else
LIBS     = $(GLT_LIBS) -L/usr/X11R6/lib -lglut -lGLU -lGL -lX11 -lXmu
endif

default: prog

include $(GLT_HOME)/gcc/Makefile.inc

