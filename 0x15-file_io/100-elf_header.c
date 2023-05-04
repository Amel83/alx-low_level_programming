nclude <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <elf.h>

#define BUF_SIZE 128

void print_error(char *msg) {
	fprintf(stderr, "Error: %s\n", msg);
	exit(98);
}

void elf_header(char *filename) {
	int fd = open(filename, O_RDONLY);
	if (fd < 0) {
		print_error(strerror(errno));
	}

	
	Elf64_Ehdr header;
	ssize_t num_read = read(fd, &header, sizeof(header));
	if (num_read < 0) {
		print_error(strerror(errno));
	}
	if (num_read < sizeof(header)) {
		print_error("File too small to contain ELF header");
	}
	
	
	if (memcmp(header.e_ident, ELFMAG, SELFMAG) != 0) {
	print_error("File is not an ELF file");
	}
	
	print header information
	printf("ELF Header:\n");
	// printf("  Magic:   ");
	// for (int i = 0; i < SELFMAG; i++) {
	// printf("%02x ", header.e_ident[i]);
	// }
	// printf("\n");
	// printf("  Class:                             ");
	// switch (header.e_ident[EI_CLASS]) {
	// case ELFCLASSNONE:
	// printf("none\n");
	// break;
	// case ELFCLASS32:
	// printf("ELF32\n");
	// break;
	// case ELFCLASS64:
	// printf("ELF64\n");
	// break;
	// default:
	// printf("<unknown>\n");
	// break;
	// }
	// printf("  Data:                              ");
	// switch (header.e_ident[EI_DATA]) {
	// case ELFDATANONE:
	// printf("none\n");
	// break;
	// case ELFDATA2LSB:
	// printf("2's complement, little endian\n");
	// break;
	// case ELFDATA2MSB:
	// printf("2's complement, big endian\n");
	// break;
	// default:
	printf("<unknown>\n");
	break;
	}
	printf("  Version:                           %d (current)\n", header.e_ident[EI_VERSION]);
	printf("  OS/ABI:                            ");
switch (header.e_ident[EI_OSABI]) {
case ELFOSABI_NONE:
	printf("UNIX - System V\n");
	break;
case ELFOSABI_SYSV:
	printf("UNIX - System V\n");
	break;
case ELFOSABI_HPUX:
	printf("HP-UX\n");
	break;
case ELFOSABI_NETBSD:
	printf("NetBSD\n");
	break;
case ELFOSABI_LINUX:
	printf("Linux\n");
	break;
case ELFOSABI_SOLARIS:
	printf("Solaris\n");
	break;
case ELFOSABI_IRIX:
	printf("IRIX\n");
	break;
case ELFOSABI_FREEBSD:
	printf("FreeBSD\n");
	break;
case ELFOSABI_TRU64:
	printf("TRU64 UNIX\n");
	break;
case ELFOSABI_ARM:
	printf("ARM architecture\n");
	break;
case ELFOSABI_STANDALONE:
	printf("Standalone (embedded) application

