#ifndef MAIN_H
#define MAIN_H

#define BUFFER_SIZE 1024
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <errno.h>
#include <stdbool.h>
#include  <elf.h>

void check_elf(unsigned char *header);
void print_magic(unsigned char *header);
void print_class(unsigned char *header);
void print_data(unsigned char *header);
void print_version(unsigned char *header);
void print_abi(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);
int _putchar(char);
ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
size_t my_strlen(char *str);


#endif
