#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
/*main function */
int main(void) {
    vector numbers;
    int value;
    vector_init(&numbers);
    if (!vector_append(&numbers, 10) ||
        !vector_append(&numbers, 20) ||
        !vector_append(&numbers, 30) ||
        !vector_append(&numbers, 40) ||
        !vector_append(&numbers, 50)) {
        fprintf(stderr, "Error: Failed to append an element.\n");
        vector_destroy(&numbers);
        return EXIT_FAILURE;
    }

    printf("Elements: ");

    for (size_t i = 0; i < numbers.size; i++) {
        printf("%d ", numbers.data[i]);
    }

    printf("\nSize: %zu\n", numbers.size);
    printf("Capacity: %zu\n", numbers.capacity);

    printf("Elements: ");
    vector_pop_back(&numbers);

    for (size_t i = 0; i < numbers.size; i++) {
        printf("%d ", numbers.data[i]);
    }

    printf("\nSize: %zu\n", numbers.size);
    printf("Capacity: %zu\n", numbers.capacity);

    if (vector_get(&numbers, 2, &value)) {
        printf("Element at index 2: %d\n", value);
    } else {
        fprintf(stderr, "Error: Invalid index or output pointer.\n");
    }

    if (!vector_get(&numbers, 5, &value)) {
        printf("Correctly rejected invalid index 5.\n");
    }

    if (vector_set(&numbers, 2, 99)) {
        printf("Successfully updated element at index 2.\n");
    } else {
        fprintf(stderr, "Error: Failed to set element at index 2.\n");
    }

    if (vector_get(&numbers, 2, &value)) {
        printf("Element at index 2: %d\n", value);
    }

    if (!vector_set(&numbers, 5, 100)) {
        printf("Correctly rejected invalid index 5.\n");
    }
    vector_destroy(&numbers);
    return EXIT_SUCCESS;
}
