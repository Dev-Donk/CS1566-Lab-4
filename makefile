# -lXi -lXmu assuming these were needed for WSL?

LIBS = -lglut -lGLEW -lGLU -lm -lGL

lab4: lab4.c myLib.o initShader.o
	gcc -o lab_4 lab4.c myLib.o initShader.o $(LIBS)

triangle_ctm: triangle_ctm.c initShader.o
	gcc -o triangle_ctm triangle_ctm.c initShader.o $(LIBS)

initShader.o: initShader.c initShader.h
	gcc -c initShader.c

myLib.o: myLib.c myLib.h
	gcc -c myLib.c
