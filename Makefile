exa: driver.o letters.o
	g++ driver.o letters.o -o exa

driver.o: driver.cpp
	g++ -c driver.cpp

letters.o: letters.cpp
	g++ -c letters.cpp

clean:
	rm letters.o
	rm driver.o	
