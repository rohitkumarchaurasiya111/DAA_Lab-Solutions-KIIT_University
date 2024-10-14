/* Huffman coding assigns variable length code words to fixed length input characters based on their frequencies
or probabilities of occurrence. Given a set of characters along with their frequency of occurrences, write a c 
program to construct a Huffman tree.
Note# 
●Declare a structure SYMBOL having members alphabet and frequency. Create a Min-Priority Queue, keyed on frequency attributes. 
●Create an array of structures where size=number of alphabets.
Input:      
Enter the number of distinct alphabets: 6
Enter the alphabets:     	a      	b      	c      	d      	e      	f
Enter its frequencies:   	45    	13    	12    	16    	9      	5
Output:
In-order traversal of the tree (Huffman): a  c  b  f  e  d */
#include <stdio.h>
#include <stdlib.h>


typedef struct {
    char alphabet;
    int frequency;
} SYMBOL;


typedef struct HuffmanNode {
    SYMBOL symbol;
    struct HuffmanNode *left, *right;
} HuffmanNode;


HuffmanNode* createNode(char alphabet, int frequency) {
    HuffmanNode* newNode = (HuffmanNode*)malloc(sizeof(HuffmanNode));
    newNode->symbol.alphabet = alphabet;
    newNode->symbol.frequency = frequency;
    newNode->left = newNode->right = NULL;
    return newNode;
}


void swap(HuffmanNode** a, HuffmanNode** b) {
    HuffmanNode* temp = *a;
    *a = *b;
    *b = temp;
}


void minHeapify(HuffmanNode* heap[], int size, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left]->symbol.frequency < heap[smallest]->symbol.frequency)
        smallest = left;

    if (right < size && heap[right]->symbol.frequency < heap[smallest]->symbol.frequency)
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        minHeapify(heap, size, smallest);
    }
}


void buildMinHeap(HuffmanNode* heap[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--)
        minHeapify(heap, size, i);
}


HuffmanNode* extractMin(HuffmanNode* heap[], int* size) {
    HuffmanNode* minNode = heap[0];
    heap[0] = heap[*size - 1];
    (*size)--;
    minHeapify(heap, *size, 0);
    return minNode;
}


void insertMinHeap(HuffmanNode* heap[], int* size, HuffmanNode* newNode) {
    (*size)++;
    int i = *size - 1;
    while (i && newNode->symbol.frequency < heap[(i - 1) / 2]->symbol.frequency) {
        heap[i] = heap[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap[i] = newNode;
}


HuffmanNode* buildHuffmanTree(SYMBOL symbols[], int n) {
    int size = n;
    HuffmanNode* heap[n];

    for (int i = 0; i < n; i++) {
        heap[i] = createNode(symbols[i].alphabet, symbols[i].frequency);
    }

    buildMinHeap(heap, size);

    while (size > 1) {
        HuffmanNode* left = extractMin(heap, &size);
        HuffmanNode* right = extractMin(heap, &size);

        HuffmanNode* newNode = createNode('$', left->symbol.frequency + right->symbol.frequency);
        newNode->left = left;
        newNode->right = right;

        insertMinHeap(heap, &size, newNode);
    }

    return extractMin(heap, &size);
}


void inorderTraversal(HuffmanNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        if (root->symbol.alphabet != '$') 
            printf("%c ", root->symbol.alphabet);
        inorderTraversal(root->right);
    }
}

int main() {
    int n;

    printf("Enter the number of distinct alphabets: ");
    scanf("%d", &n);

    SYMBOL symbols[n];
    printf("Enter the alphabets: ");
    for (int i = 0; i < n; i++) {
        scanf(" %c", &symbols[i].alphabet);
    }

    printf("Enter their frequencies: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &symbols[i].frequency);
    }

    
    HuffmanNode* root = buildHuffmanTree(symbols, n);

    
    printf("In-order traversal of the tree (Huffman): ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
