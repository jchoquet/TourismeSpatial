all: test_structure_d test_destination_d test_file test_fichier


structure_d.o : structure_d.c structure_d.h
	gcc -Wall -Wextra -c $<

test.o : test.c structure_d.h
	gcc -Wall -Wextra -c $<

test_structure_d : test.o structure_d.o
	gcc -Wall -Wextra -ansi $^ -o $@

affectation_destination_d.o : affectation_destination_d.c affectation_destination_d.h
	gcc -Wall -Wextra -c $<

test_destination_d : affectation_destination_d.o structure_d.o
	gcc -Wall -Wextra -ansi $^ -o $@

hafsa_file.o : hafsa_file.c hafsa_file.h
	gcc -Wall -Wextra -c $<

test_file.o : test_file.c
	gcc -Wall -Wextra -c $<

test_file : test_file.o hafsa_file.o
	gcc -Wall -Wextra -ansi $^ -o $@

fichierbis.o : fichierbis.c 
	gcc -Wall -Wextra -c $<

test_fichier : fichierbis.o
	gcc -Wall -Wextra -ansi $^ -o $@

structure_contraintes.o : structure_contraintes.c structure_contraintes.h
	gcc -Wall -Wextra -c $<

test_contraintes : test_contraintes.c structure_contraintes.o
	gcc -Wall -Wextra -ansi $^ -o $@
