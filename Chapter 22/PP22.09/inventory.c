#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readline.h"

#define NAME_LEN 25
#define MAX_PARTS 100

struct part {
    int number;
    char name[NAME_LEN+1];
    int on_hand;
} inventory[MAX_PARTS];

int num_parts = 0;   /* number of parts currently stored */

int find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);
void dump(void);
void restore(void);
void merge(int argc, char *argv[]);

int main(int argc, char *argv[])
{
    char code;

    for (;;) {
        printf("Enter operation code: ");
        scanf(" %c", &code);
        while (getchar() != '\n')   /* skips to end of line */
        ;
        switch (code) {
            case 'i': insert();
                        break;
            case 's': search();
                        break;
            case 'u': update();
                        break;
            case 'p': print();
                        break;
            case 'd': dump();
                        break;
            case 'r': restore();
                        break;
            case 'm': merge(argc, argv);
                        break;
            case 'q': return 0;
            default:  printf("Illegal code\n");
        }
        printf("\n");
    }
}

int find_part(int number)
{
    int i;

    for (i = 0; i < num_parts; i++)
        if (inventory[i].number == number)
            return i;
    return -1;
}


void insert(void)
{
    int part_number;

    if (num_parts == MAX_PARTS) {
        printf("Database is full; can't add more parts.\n");
        return;
    }

    printf("Enter part number: ");
    scanf("%d", &part_number);
    if (find_part(part_number) >= 0) {
        printf("Part already exists.\n");
        return;
    }

    inventory[num_parts].number = part_number;
    printf("Enter part name: ");
    read_line(inventory[num_parts].name, NAME_LEN);
    printf("Enter quantity on hand: ");
    scanf("%d", &inventory[num_parts].on_hand);
    num_parts++;
}

void search(void)
{
    int i, number;

    printf("Enter part number: ");
    scanf("%d", &number);
    i = find_part(number);
    if (i >= 0) {
        printf("Part name: %s\n", inventory[i].name);
        printf("Quantity on hand: %d\n", inventory[i].on_hand);
    } else
        printf("Part not found.\n");
}

void update(void)
{
    int i, number, change;

    printf("Enter part number: ");
    scanf("%d", &number);
    i = find_part(number);
    if (i >= 0) {
        printf("Enter change in quantity on hand: ");
        scanf("%d", &change);
        inventory[i].on_hand += change;
    } else
        printf("Part not found.\n");
}

void print(void)
{
    int i;

    printf("Part Number   Part Name                  "
            "Quantity on Hand\n");
    for (i = 0; i < num_parts; i++)
        printf("%7d       %-25s%11d\n", inventory[i].number,
            inventory[i].name, inventory[i].on_hand);
}

void dump(void)
{
    char output_file_name[100];
    printf("Enter name of output file: ");
    scanf("%s", output_file_name);

    FILE *output_file;

    if ((output_file = fopen(output_file_name, "wb")) == NULL) {
        fprintf(stderr, "%s can't be opened\n", output_file_name);
        exit(EXIT_FAILURE);
    }

    fwrite(inventory, sizeof(struct part), num_parts, output_file);
    fclose(output_file);
}

void restore(void)
{
    char input_file_name[100];
    printf("Enter name of input file: ");
    scanf("%s", input_file_name);

    FILE *input_file;

    if ((input_file = fopen(input_file_name, "rb")) == NULL) {
        fprintf(stderr, "%s can't be opened\n", input_file_name);
        exit(EXIT_FAILURE);
    }

    num_parts = fread(inventory, sizeof(struct part), MAX_PARTS, input_file);
    fclose(input_file);
}

void merge(int argc, char*argv[])
{
    FILE *first_input, *second_input, *merge;
    struct part part1, part2;
    int number1, number2;

    if (argc != 4) {
        char *file_name = strrchr(argv[0], '\\');
        file_name++;
        fprintf(stderr, "usage: %s input-file-1 input-file-2 merge-file\n", file_name);
        exit(EXIT_FAILURE);
    }

    if ((first_input = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "%s can't be opened\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if ((second_input = fopen(argv[2], "rb")) == NULL) {
        fprintf(stderr, "%s can't be opened\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    if ((merge = fopen(argv[3], "wb")) == NULL) {
        fprintf(stderr, "%s can't be written\n", argv[3]);
        exit(EXIT_FAILURE);
    }

    number1 = fread(&part1, sizeof(struct part), 1, first_input);
    number2 = fread(&part2, sizeof(struct part), 1, second_input);
    while (number1 == 1 && number2 == 1)
    {
        if (part1.number < part2.number) {
            fwrite(&part1, sizeof(struct part), 1, merge);
            number1 = fread(&part1, sizeof(struct part), 1, first_input);
        } else if (part1.number > part2.number) {
            fwrite(&part2, sizeof(struct part), 1, merge);
            number2 = fread(&part2, sizeof(struct part), 1, second_input);
        } else {
            if (strcmp(part1.name, part2.name) != 0)
                fprintf(stderr, "Names don't match for part %d, using the name %s\n",
                        part1.number, part1.name);
            part1.on_hand += part2.on_hand;
            fwrite(&part1, sizeof(struct part), 1, merge);
            number1 = fread(&part1, sizeof(struct part), 1, first_input);
            number2 = fread(&part2, sizeof(struct part), 1, second_input);
        }
    }

    while (number1 == 1)
    {
        fwrite(&part1, sizeof(struct part), 1, merge);
        number1 = fread(&part1, sizeof(struct part), 1, first_input);
    }

    while (number2 == 1)
    {
        fwrite(&part2, sizeof(struct part), 1, merge);
        number2 = fread(&part2, sizeof(struct part), 1, second_input);
    }

    fclose(first_input);
    fclose(second_input);
    fclose(merge);
}