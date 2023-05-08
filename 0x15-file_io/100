#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

#define EI_NIDENT 16

/* ELF header structure */
typedef struct {
	    unsigned char e_ident[EI_NIDENT]; /* ELF identification */
	        uint16_t e_type; /* Object file type */
		    uint16_t e_machine; /* Machine type */
		        uint32_t e_version; /* Object file version */
			    uint64_t e_entry; /* Entry point address */
			        uint64_t e_phoff; /* Program header offset */
				    uint64_t e_shoff; /* Section header offset */
				        uint32_t e_flags; /* Processor-specific flags */
					    uint16_t e_ehsize; /* ELF header size */
					        uint16_t e_phentsize; /* Size of program header entry */
						    uint16_t e_phnum; /* Number of program header entries */
						        uint16_t e_shentsize; /* Size of section header entry */
							    uint16_t e_shnum; /* Number of section header entries */
							        uint16_t e_shstrndx; /* Section name string table index */
} Elf64_Ehdr;

/* ELF identification */
typedef struct {
	    unsigned char magic[EI_NIDENT]; /* Magic number and other info */
} Elf_Ident;

/* Display an ELF header */
void display_elf_header(const Elf64_Ehdr *elf_header) {
	int i;
	printf("ELF Header:\n");
	        printf("  Magic:   ");
		    for (i = 0; i < EI_NIDENT; i++) {
			            printf("%02x ", elf_header->e_ident[i]);
				        }
		        printf("\n");
			    printf("  Class:                             ");
			        switch (elf_header->e_ident[4]) {
					        case 1: printf("ELF32\n"); break;
							        case 2: printf("ELF64\n"); break;
									        default: printf("Invalid\n"); break;
											     }
				    printf("  Data:                              ");
				        switch (elf_header->e_ident[5]) {
						        case 1: printf("2's complement, little endian\n"); break;
								        case 2: printf("2's complement, big endian\n"); break;
										        default: printf("Invalid\n"); break;
												     }
					    printf("  Version:                           %u (current)\n", elf_header->e_ident[6]);
					        printf("  OS/ABI:                            ");
						    switch (elf_header->e_ident[7]) {
							            case 0: printf("UNIX - System V\n"); break;
									            case 3: printf("UNIX - GNU/Linux\n"); break;
											            default: printf("Unknown\n"); break;
													         }
						        printf("  ABI Version:                       %u\n", elf_header->e_ident[8]);
							    printf("  Type:                              ");
							        switch (elf_header->e_type) {
									        case 1: printf("REL (Relocatable file)\n"); break;
											        case 2: printf("EXEC (Executable file)\n"); break;
													        case 3: printf("DYN (Shared object file)\n"); break;
															        case 4: printf("CORE (Core file)\n"); break;
																	        default: printf("Unknown\n"); break;
																			     }
								    printf("  Entry point address:               0x%lx\n", elf_header->e_entry);
}

/* Main function */
int main(int argc, char *argv[]) {
	int fd;
	 Elf64_Ehdr elf_header;
	if (argc != 2) {
		            fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
			            return 98;
				        }
	      
		    

	
		        fd = open(argv[1], O_RDONLY);
			    if (fd == -1) {
				            fprintf(stderr, "Error: Cannot open file '%s': %s\n", argv[1], strerror(errno));
					            return 1;
						        }

	
			        if (read(fd, &elf_header, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr)) {
					        fprintf(stderr, "Error: Cannot read ELF header: %s\n", strerror(errno));
						        close(fd);
							        return 1;
								    }

				    display_elf_header(&elf_header);

				  
				        close(fd);
					    return 0;
}

