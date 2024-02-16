#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

void display_elf_header(int fd);
void check_elf_file(unsigned char *e_ident);

int main(int argc, char **argv)
{
    int fd;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: elf_header elf_filename\n");
        exit(98);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(98);
    }

    display_elf_header(fd);
    close(fd);
    return 0;
}

void display_elf_header(int fd)
{
    Elf64_Ehdr header;
    int i;

    if (read(fd, &header, sizeof(header)) != sizeof(header))
    {
        fprintf(stderr, "Error: Failed to read ELF header\n");
        exit(98);
    }

    check_elf_file(header.e_ident);

    /* Display information from header.e_ident and other fields... */
    printf("Magic:  ");
    for (i = 0; i < EI_NIDENT; i++)
        printf("%02x ", header.e_ident[i]);
    printf("\n");

    /* Display Class, Data, Version, etc. */
    /* Note: You'll need to interpret the fields according to the ELF specification. */

}

void check_elf_file(unsigned char *e_ident)
{
    if (e_ident[EI_MAG0] != ELFMAG0 ||
        e_ident[EI_MAG1] != ELFMAG1 ||
        e_ident[EI_MAG2] != ELFMAG2 ||
        e_ident[EI_MAG3] != ELFMAG3)
    {
        fprintf(stderr, "Error: Not an ELF file\n");
        exit(98);
    }
}


