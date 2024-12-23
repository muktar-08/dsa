#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int coeff, x, y, z;  // Coefficient and powers of x, y, z
    struct Node *next;
};

typedef struct Node *NODE;

// Create a new node
NODE createNode(int coeff, int x, int y, int z) {
    NODE temp = (NODE)malloc(sizeof(struct Node));
    temp->coeff = coeff;
    temp->x = x;
    temp->y = y;
    temp->z = z;
    temp->next = temp; // Circular link
    return temp;
}

// Insert a term at the end
NODE insertEnd(NODE head, int coeff, int x, int y, int z) {
    NODE temp = createNode(coeff, x, y, z);
    if (!head) return temp;
    NODE cur = head;
    while (cur->next != head) cur = cur->next;
    cur->next = temp;
    temp->next = head;
    return head;
}

// Display the polynomial
void display(NODE head) {
    if (!head) {
        printf("Polynomial is empty.\n");
        return;
    }
    NODE cur = head;
    do {
        printf("%+dx^%dy^%dz^%d ", cur->coeff, cur->x, cur->y, cur->z);
        cur = cur->next;
    } while (cur != head);
    printf("\n");
}

// Add two polynomials
NODE addPolynomials(NODE poly1, NODE poly2) {
    NODE sum = NULL;
    NODE p1 = poly1, p2;
    do {
        sum = insertEnd(sum, p1->coeff, p1->x, p1->y, p1->z);
        p1 = p1->next;
    } while (p1 != poly1);

    p2 = poly2;
    do {
        NODE temp = sum;
        int found = 0;
        do {
            if (temp->x == p2->x && temp->y == p2->y && temp->z == p2->z) {
                temp->coeff += p2->coeff;
                found = 1;
                break;
            }
            temp = temp->next;
        } while (temp != sum);

        if (!found) sum = insertEnd(sum, p2->coeff, p2->x, p2->y, p2->z);
        p2 = p2->next;
    } while (p2 != poly2);

    return sum;
}

int main() {
    NODE poly1 = NULL, poly2 = NULL, polySum = NULL;

    // Create POLY1
    printf("Creating POLY1...\n");
    poly1 = insertEnd(poly1, 6, 2, 2, 1);  // 6x^2y^2z
    poly1 = insertEnd(poly1, -4, 0, 1, 5); // -4yz^5
    poly1 = insertEnd(poly1, 3, 3, 1, 1);  // 3x^3yz
    poly1 = insertEnd(poly1, 2, 1, 5, 1);  // 2xy^5z
    poly1 = insertEnd(poly1, -2, 1, 1, 3); // -2xyz^3

    // Create POLY2
    printf("Creating POLY2...\n");
    poly2 = insertEnd(poly2, 1, 2, 2, 1);  // 1x^2y^2z
    poly2 = insertEnd(poly2, 5, 0, 1, 5);  // 5yz^5
    poly2 = insertEnd(poly2, -3, 3, 1, 1); // -3x^3yz

    // Display POLY1 and POLY2
    printf("POLY1: ");
    display(poly1);
    printf("POLY2: ");
    display(poly2);

    // Add POLY1 and POLY2
    printf("Adding POLY1 and POLY2...\n");
    polySum = addPolynomials(poly1, poly2);

    // Display POLYSUM
    printf("POLYSUM: ");
    display(polySum);

    return 0;
}
