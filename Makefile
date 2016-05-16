all: test_structure_d test_destination_d test_file test_fichier


structure_d.o : structure_d.c structure_d.h
	gcc -Wall -Wextra -c $<

test.o : test.c structure_d.h
	gcc -Wall -Wextra -c $<

test_structure_d : test.o structure_d.o
	gcc -Wall -Wextra -ansi $^ -o $@


structure_c.o : structure_c.c structure_c.h
	gcc -Wall -Wextra -c $<

test_struct_c.o : test_struct_c.c structure_c.h
	gcc -Wall -Wextra -c $<

test_struct_c : test_struct_c.o structure_c.o
	gcc -Wall -Wextra -ansi $^ -o $@


affectation_destination_d.o : affectation_destination_d.c affectation_destination_d.h
	gcc -Wall -Wextra -c $<

test_affect_d.o : test_affect_d.c
	gcc -Wall -Wextra -c $<

test_destination_d : test_affect_d.o affectation_destination_d.o structure_d.o
	gcc -Wall -Wextra -ansi $^ -o $@

file.o : file.c file.h
	gcc -Wall -Wextra -c $<

test_file.o : test_file.c
	gcc -Wall -Wextra -c $<

test_file : test_file.o file.o
	gcc -Wall -Wextra -ansi $^ -o $@

fichierbis.o : fichierbis.c 
	gcc -Wall -Wextra -c $<

test_fichier : fichierbis.o
	gcc -Wall -Wextra -ansi $^ -o $@

structure_contraintes.o : structure_contraintes.c structure_contraintes.h
	gcc -Wall -Wextra -c $<

test_contraintes : test_contraintes.c structure_contraintes.o
	gcc -Wall -Wextra -ansi $^ -o $@
