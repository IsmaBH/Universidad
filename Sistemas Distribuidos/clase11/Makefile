JFLAGS = -g
JC = javac

.SUFFIXES: .java .class

.java.class:
	$(JC) $(JFLAGS) $*.java

CLASSES = \
	  Proyecto2.java\
	  PoligonoIrreg.java\
	  PoligonoReg.java\
	  Coordenada.java\
	  SortDistance.java\
	  SortArea.java\

default: classes

classes: $(CLASSES:.java=.class)

clean:
	$(RM) *.class

run:
	java Proyecto2
