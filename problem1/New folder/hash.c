#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

typedef struct Node {
    int* key; // Pointer to an array of integers
    int value;
    struct Node* next;
} Node;

typedef struct HashTable {
    Node* table[TABLE_SIZE];
} HashTable;

// Hash function
unsigned int hash(int* key, size_t size) {
    unsigned int hash = 0;
    for (size_t i = 2; i < size + 2; i++) { // Skip metadata (first two elements)
        hash = hash * 31 + key[i];
    }
    return hash % TABLE_SIZE;
}

// Comparison function
int compare_keys(int* key1, int* key2, size_t size) {
    for (size_t i = 2; i < size + 2; i++) { // Skip metadata (first two elements)
        if (key1[i] != key2[i]) {
            return 0; // Not equal
        }
    }
    return 1; // Equal
}

// Initialize hash table
HashTable* create_table() {
    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
    for (int i = 0; i < TABLE_SIZE; i++) {
        ht->table[i] = NULL;
    }
    return ht;
}

// Insert into hash table
void insert(HashTable* ht, int* key, size_t size, int value) {
    unsigned int index = hash(key, size);
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->key = (int*)malloc(size * sizeof(int));
    memcpy(new_node->key, key, size * sizeof(int));
    new_node->value = value;
    new_node->next = ht->table[index];
    ht->table[index] = new_node;
}

// Search in hash table
int search(HashTable* ht, int* key, size_t size) {
    unsigned int index = hash(key, size);
    Node* node = ht->table[index];
    while (node != NULL) {
        if (compare_keys(node->key, key, size)) {
            return node->value;
        }
        node = node->next;
    }
    return -1; // Not found
}

// Free the hash table
void free_table(HashTable* ht, size_t size) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* node = ht->table[i];
        while (node != NULL) {
            Node* temp = node;
            node = node->next;
            free(temp->key);
            free(temp);
        }
    }
    free(ht);
}

void print_array(int* arr, size_t size) {
    for (size_t i = 2; i < size + 2; i++) { // Skip metadata
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Assuming `large_int` arrays have the size of 5 integers
    size_t size = 5;

    HashTable* ht = create_table();

    int key1[] = {0, 5, 1, 6, 2, 3}; // Example key
    int key2[] = {0, 5, 4, 5, 6, 7}; // Example key
    int key3[] = {0, 5, 8, 9, 10, 11}; // Example key

    insert(ht, key1, size, 10);
    insert(ht, key2, size, 20);
    insert(ht, key3, size, 30);

    printf("Searching for key1: ");
    print_array(key1, size);
    printf("Value for key1: %d\n", search(ht, key1, size));

    printf("Searching for key2: ");
    print_array(key2, size);
    printf("Value for key2: %d\n", search(ht, key2, size));

    printf("Searching for key3: ");
    print_array(key3, size);
    printf("Value for key3: %d\n", search(ht, key3, size));

    free_table(ht, size);

    return 0;
}
