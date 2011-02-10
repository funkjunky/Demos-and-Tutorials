CPP_SRC  = 	random.cpp observer.cpp observer2.cpp refcount.cpp refcount2.cpp shrink.cpp\
		string.cpp round.cpp hash.cpp lru.cpp

GLT_HOME = ../../..
INCLUDE  =
GLT_LIBS = -L$(GLT_HOME)/lib -lglutm -lglt -lpng -lz

ifdef WINDIR
LIBS     = $(GLT_LIBS) -lglut32 -lglu32 -lopengl32
else
LIBS     = $(GLT_LIBS) -L/usr/X11R6/lib -lglut -lGLU -lGL
endif

default: prog

include $(GLT_HOME)/gcc/Makefile.inc

