#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <elf.h>
#include <errno.h>

#define ERROR(msg) do { perror(msg); exit(98); } while (0)

int main(int argc, char *argv[]) {
    int fd, i, n;
    Elf64_Ehdr header;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
        return 98;
    }

    if ((fd = open(argv[1], O_RDONLY)) == -1)
        ERROR("open");

    if ((n = read(fd, &header, sizeof(header))) != sizeof(header))
        ERROR("read");

    if (header.e_ident[EI_MAG0] != ELFMAG0 ||
        header.e_ident[EI_MAG1] != ELFMAG1 ||
        header.e_ident[EI_MAG2] != ELFMAG2 ||
        header.e_ident[EI_MAG3] != ELFMAG3) {
        fprintf(stderr, "%s: not an ELF file\n", argv[1]);
        return 98;
    }

    printf("Magic:   ");
    for (i = 0; i < EI_NIDENT; i++)
        printf("%02x ", header.e_ident[i]);
    printf("\n");

    printf("Class:                             ");
    switch (header.e_ident[EI_CLASS]) {
    case ELFCLASSNONE:
        printf("none\n");
        break;
    case ELFCLASS32:
        printf("ELF32\n");
        break;
    case ELFCLASS64:
        printf("ELF64\n");
        break;
    default:
        printf("<unknown: %d>\n", header.e_ident[EI_CLASS]);
        break;
    }

    printf("Data:                              ");
    switch (header.e_ident[EI_DATA]) {
    case ELFDATANONE:
        printf("none\n");
        break;
    case ELFDATA2LSB:
        printf("2's complement, little endian\n");
        break;
    case ELFDATA2MSB:
        printf("2's complement, big endian\n");
        break;
    default:
        printf("<unknown: %d>\n", header.e_ident[EI_DATA]);
        break;
    }

    printf("Version:                           ");
    switch (header.e_ident[EI_VERSION]) {
    case EV_NONE:
        printf("none\n");
        break;
    case EV_CURRENT:
        printf("1 (current)\n");
        break;
    default:
        printf("<unknown: %d>\n", header.e_ident[EI_VERSION]);
        break;
    }

    printf("OS/ABI:                            ");
    switch (header.e_ident[EI_OSABI]) {
    case ELFOSABI_SYSV:
        printf("UNIX System V ABI\n");
        break;
    case ELFOSABI_HPUX:
        printf("HP-UX ABI\n");
        break;
    case ELFOSABI_NETBSD:
        printf("NetBSD ABI\n");
        break;
    case ELFOSABI_LINUX:
        printf("Linux ABI\n");
        break;
    case ELFOSABI_SOLARIS:
        printf("Solaris ABI\n");
        break;
    case ELFOSABI_AIX:
        printf("AIX ABI\n");
        break;
    case ELFOSABI_IRIX:
        printf("IRIX ABI\n");
        break;
    case ELFOSABI_FREEBSD:
        printf("FreeBSD ABI\n");
        break;
    case ELFOSABI_TRU64:
        printf("Tru64 UNIX ABI\n");
    }
    return (i);
}

