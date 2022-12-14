run:
	rm -f application.exe
	g++ -g -std=c++11 -Wall application.cpp -o application.exe
	./application.exe
	
valgrind:
	valgrind --tool=memcheck --leak-check=yes ./application.exe

run_tests:
	rm -f tests.exe
	g++ -g -std=c++11 -Wall tests.cpp -o tests.exe
	./tests.exe

valgrind_tests:
	valgrind --tool=memcheck --leak-check=yes ./tests.exe
