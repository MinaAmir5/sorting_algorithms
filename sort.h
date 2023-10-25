#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

#define UP 0
#define DOWN 1

/**
 * enum bool - Enumeration of Boolean values.
 * @false: Equals 0.
 * @true: Equals 1.
 */
typedef enum bool
{
	false = 0,
	true
} bool;

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *, size_t);
void print_list(const listint_t *);

void insertion_sort_list(listint_t **);
void quick_sort(int *, unsigned int);
void radix_sort(int *, unsigned int);
void bubble_sort(int *, unsigned int);
void cocktail_sort_list(listint_t **);
void selection_sort(int *, unsigned int);
void bitonic_sort(int *, unsigned int);
void shell_sort(int *, unsigned int);
void heap_sort(int *, unsigned int);
void counting_sort(int *, unsigned int);
void merge_sort(int *, unsigned int);
void quick_sort_hoare(int *, unsigned int);

#endif /* SORT_H */
