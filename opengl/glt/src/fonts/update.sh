#!/bin/sh
#
# For more LGPL binary fonts: http://www.minigui.org/
#

printf "#ifndef GLT_FONTS_H\n#define GLT_FONTS_H\n\n" > fonts.h
printf "/* Include all the compiled font sources */\n\n" > fonts.cpp

for i in *.fnt;
do
	export NAME=`basename $i .fnt`
	export CNAME=${NAME}Font
	printf "Processing %s...\n" ${NAME}
	printf "extern unsigned char %s[];\n" ${CNAME} >> fonts.h
	printf "#include \"%s\"\n" ${NAME}.cpp         >> fonts.cpp
	printf "unsigned char %s[] = \n" ${CNAME} > ${NAME}.cpp 
	bin2src -font $i >> ${NAME}.cpp
done


printf "\n#endif\n" >> fonts.h
