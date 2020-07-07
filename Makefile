output: rdynamic.cpp
	g++ -o Rdynamic rdynamic.cpp
$(info ************type ./Rdynamic to run refinement of KS.************)
clean:
	rm -f *.o output
	
