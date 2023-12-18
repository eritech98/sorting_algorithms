#ifndef ERICK_H
#define ERICK_H
#include <stdlib.h>
#include <stdio.h>

/*Comparison Macros*/
#define UP 0
#define DOWN 1

/**
* enum boo - Enumarate
* @false: Must be 0
* @true: Must be 1
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
	
/*For printing helper funcs*/
 
void print_list(const listint_t *list);
void print_array(const int *array, size_t size);

/*For sorting alGORIMS*/
void bubble_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
void quick_sort(int *array, size_t size);
void selection_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);

#endif
