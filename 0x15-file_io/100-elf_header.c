#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

#define ELF_MAGIC  "\x7f""ELF"

typedef struct {
    unsigned char magic[4];
    uint8_t class;
    uint8_t data;
    uint8_t version;
    uint8_t osabi;
    uint8_t abiversion;
    uint8_t pad[7];
    uint16_t type;
    uint16_t machine;
    uint32_t version_2;
    uint64_t entry;
    uint64_t phoff;
    uint64_t shoff;
    uint32_t flags;
    uint16_t ehsize;
    uint16_t phentsize;
    uint16_t phnum;
    uint16_t shentsize;
    uint16_t shnum;
    uint16_t shstrndx;
} elf_header_t;

void print_error(char* msg) 
{
	size_t i;
	int num_read;
    
	fprintf(stderr, "%s\n", msg);
	exit(98);
}
void print_hex(char* label, uint8_t* data, size_t size) {
	printf("%-35s", label);
	for (i = 0; i < size; i++)
	{
		printf("%02x", data[i]);
	}
	printf("\n");
}
void elf_header(char* filename)
	int fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		print_error(strerror(errno));
	}
	elf_header_t header;
	num_read = read(fd, &header, sizeof(header));
	if (num_read < 0) {
        print_error(strerror(errno));
	}
	else if (num_read != sizeof(header) || memcmp(header.magic, ELF_MAGIC, 4) != 0):
	{
		print_error("Not an ELF file");
    	}
	printf("ELF Header:\n");
	print_hex("Magic:", header.magic, 4);
	printf("%-35s%d\n", "Class:", header.class);
	printf("%-35s%s\n", "Data:", header.data == 1 ? "2's complement, little endian" : header.data == 2 ? "2's complement, big endian" : "Invalid");
	printf("%-35s%d\n", "Version:", header.version);
	printf("%-35s%s\n", "OS/ABI:", header.osabi == 0 ? "UNIX System V ABI" : header.osabi == 1 ? "HP-UX ABI" : header.osabi == 2 ? "NetBSD ABI" : header.osabi == 3 ? "Linux ABI" : header.osabi == 6 ? "Sun Solaris ABI" : "Invalid");
	printf("%-35s%d\n", "ABI Version:", header.abiversion);
	printf("%-35s%s\n", "Type:", header.type == 1 ? "REL (Relocatable file)" : header.type == 2 ? "EXEC (Executable file)" : header.type == 3 ? "DYN (Shared object file)" : header.type == 4 ? "CORE (Core file)" : "Invalid");
	printf("%-35s0x%lx\n", "Entry point address:", header.entry);
	if (close(fd) == -1)
	{
		print_error(strerror(errno));
	}
}
int main(int argc, char** argv)
	if (argc != 2) {
		print_error("Usage: elf_header elf_filename");
	}
	elf_header(argv[1]);
	}
