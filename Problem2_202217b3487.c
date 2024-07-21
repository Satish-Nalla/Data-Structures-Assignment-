#include <stdio.h>
 
#define MAX 10
 
// Declare three arrays p1, p2, p3 of type structure poly.
// Each polynomial can have a maximum of ten terms.
// Addition result of p1 and p2 is stored in p3.
 
typedef struct {
    int coeff;
    int expo;
} poly;
 
int readPoly(poly p[]);
int addPoly(poly p1[], int t1, poly p2[], int t2, poly p3[]);
void displayPoly(poly p[], int terms);
 
int main() {
    poly p1[MAX], p2[MAX], p3[MAX];
    int t1, t2, t3;
 
    // Read and display first polynomial
    printf("\nEnter the first polynomial:\n");
    t1 = readPoly(p1);
    printf("\nFirst polynomial: ");
    displayPoly(p1, t1);
 
    // Read and display second polynomial
    printf("\nEnter the second polynomial:\n");
    t2 = readPoly(p2);
    printf("\nSecond polynomial: ");
    displayPoly(p2, t2);
 
    // Add two polynomials and display resultant polynomial
    t3 = addPoly(p1, t1, p2, t2, p3);
    printf("\n\nResultant polynomial after addition: ");
    displayPoly(p3, t3);
 
    printf("\n");
    return 0;
}
 
int readPoly(poly p[]) {
    int t1, i;
    printf("\nEnter the total number of terms in the polynomial: ");
    scanf("%d", &t1);
    printf("\nEnter the COEFFICIENT and EXPONENT in DESCENDING ORDER\n");
    for (i = 0; i < t1; i++) {
        printf("Enter the Coefficient(%d): ", i + 1);
        scanf("%d", &p[i].coeff);
        printf("Enter the Exponent(%d): ", i + 1);
        scanf("%d", &p[i].expo);
    }
    return t1;
}
 
int addPoly(poly p1[], int t1, poly p2[], int t2, poly p3[]) {
    int i, j, k;
    i = 0;
    j = 0;
    k = 0;
    while (i < t1 && j < t2) {
        if (p1[i].expo == p2[j].expo) {
            p3[k].coeff = p1[i].coeff + p2[j].coeff;
            p3[k].expo = p1[i].expo;
            i++;
            j++;
            k++;
        } else if (p1[i].expo > p2[j].expo) {
            p3[k].coeff = p1[i].coeff;
            p3[k].expo = p1[i].expo;
            i++;
            k++;
        } else {
            p3[k].coeff = p2[j].coeff;
            p3[k].expo = p2[j].expo;
            j++;
            k++;
        }
    }
 
    // For remaining terms of polynomial 1
    while (i < t1) {
        p3[k].coeff = p1[i].coeff;
        p3[k].expo = p1[i].expo;
        i++;
        k++;
    }
 
    // For remaining terms of polynomial 2
    while (j < t2) {
        p3[k].coeff = p2[j].coeff;
        p3[k].expo = p2[j].expo;
        j++;
        k++;
    }
 
    return k; // k is the number of terms in the resultant polynomial
}
 
void displayPoly(poly p[], int terms) {
    for (int k = 0; k < terms - 1; k++) {
        printf("%d(x^%d) + ", p[k].coeff, p[k].expo);
    }
    printf("%d(x^%d)", p[terms - 1].coeff, p[terms - 1].expo);
}