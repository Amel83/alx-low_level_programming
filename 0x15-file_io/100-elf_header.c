#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <elf.h>

#define BUF_SIZE 1024

void print_error(char *msg) {
	fprintf(stderr, "Error: %s: %s\n", msg, strerror(errno));
	exit(98);
}

void print_magic(unsigned char *e_ident) {
	int i;
	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++) {
		printf("%02x ", e_ident[i]);
	}
	printf("\n");
}

void print_class(unsigned char e_ident[EI_NIDENT]) {
	printf("  Class:                             ");
	switch (e_ident[EI_CLASS]) {
		case ELFCLASSNONE: printf("none\n"); break;
		case ELFCLASS32: printf("ELF32\n"); break;
		case ELFCLASS64: printf("ELF64\n"); break;
		default: printf("<unknown: %d>\n", e_ident[EI_CLASS]); break;
	}
}

void print_data(unsigned char e_ident[EI_NIDENT]) {
	printf("  Data:                              ");
	switch (e_ident[EI_DATA]) {
		case ELFDATANONE: printf("none\n"); break;
		case ELFDATA2LSB: printf("2's complement, little endian\n"); break;
		case ELFDATA2MSB: printf("2's complement, big endian\n"); break;
		default: printf("<unknown: %d>\n", e_ident[EI_DATA]); break;
	}
}

void print_version(unsigned char e_ident[EI_NIDENT]) {
	printf("  Version:                           ");
	if (e_ident[EI_VERSION] == EV_NONE) {
		printf("none\n");
	} else if (e_ident[EI_VERSION] == EV_CURRENT) {
		printf("1 (current)\n");
	} else {
		printf("<unknown: %d>\n", e_ident[EI_VERSION]);
	}
}

void print_osabi(unsigned char e_ident[EI_NIDENT]) {
	printf("  OS/ABI:                            ");
	switch (e_ident[EI_OSABI]) {
		case ELFOSABI_SYSV: printf("UNIX - System V\n"); break;
		case ELFOSABI_NETBSD: printf("UNIX - NetBSD\n"); break;
		case ELFOSABI_LINUX: printf("UNIX - Linux\n"); break;
		default: printf("<unknown: %d>\n", e_ident[EI_OSABI]); break;
	}
}

void print_abiversion(unsigned char e_ident[EI_NIDENT]) {
	printf("  ABI Version:                       %d\n", e_ident[EI_ABIVERSION]);
}

void print_type(Elf64_Half e_type) {
	printf("  Type:                              ");
	switch (e_type) {
		case ET_NONE: printf("NONE (None)\n"); break;
		case ET_REL: printf("REL (Relocatable file)\n"); break;
		case ET_EXEC: printf("EXEC (Executable file)\n"); break;
		case ET_DYN: printf("DYN (Shared object file)\n"); break;
		case ET_CORE: printf("CORE (Core file)\n"); break;
		default: printf("<unknown: %d>\n", e_type); break;
	}
}

void print_entry(Elf64_Addr e_entry) {
	printf("  Entry point address:               %p\n", (void *) e_entry);
}

int main(int argc, char *argv[]) {
	int fd;
	Elf64_Ehdr ehdr;

	if (argc != 2) {
		fprintf(stderr, "Usage: %s <ELF file>\n", argv[0]);
		exit(1);
	}

	
	fd = open(argv[1], O_RDONLY);
	if (fd == -1) {
		print_error("open");
	}
	
	
	if (read(fd, &ehdr, sizeof(ehdr)) != sizeof(ehdr)) {
		print_error("read");
	}
	
	printf("ELF Header:\n");
	print_magic(ehdr.e_ident);
	print_class(ehdr.e_ident);
	print_data(ehdr.e_ident);
	print_version(ehdr.e_ident);
	print_osabi(ehdr.e_ident);
	print_abiversion(ehdr.e_ident);
	print_type(ehdr.e_type);
	print_entry(ehdr.e_entry);
	
	
	if (close(fd) == -1) {
		print_error("close");
	}
	return 0;
}
