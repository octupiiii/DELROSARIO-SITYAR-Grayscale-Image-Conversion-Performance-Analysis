#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

// Declare the external assembly function
extern void imgCvtGrayInttoFloat(size_t size, const uint8_t* input, float* output);

// C implementation of the conversion function
void imgCvtGrayInttoFloat_C(size_t size, const uint8_t* input, float* output) {
    for (size_t i = 0; i < size; i++) {
        output[i] = (float)input[i] / 255;
    }
}

// Function to print a matrix of integers
void printMatrixInt(const uint8_t* matrix, size_t width, size_t height) {
    printf("\nMatrix (Integer Values):\n");
    for (size_t i = 0; i < height; i++) {
        for (size_t j = 0; j < width; j++) {
            printf("%4u ", matrix[i * width + j]);
        }
        printf("\n");
    }
}

// Function to print a matrix of floats
void printMatrixFloat(const float* matrix, size_t width, size_t height) {
    printf("\nMatrix (Float Values):\n");
    for (size_t i = 0; i < height; i++) {
        for (size_t j = 0; j < width; j++) {
            printf("%6.2f ", matrix[i * width + j]);
        }
        printf("\n");
    }
}

int main() {
    size_t width, height;

    // Prompt the user for image dimensions (width and height)
    printf("Enter image height: ");
    scanf_s("%zu", &height);
    
    printf("Enter image width: ");
    scanf_s("%zu", &width);

   

    // Calculate the number of pixels (size of the input array)
    size_t size = width * height;

    // Dynamically allocate memory for the input and output arrays
    uint8_t* imgInt = (uint8_t*)malloc(size * sizeof(uint8_t));
    if (imgInt == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    float* imgFloatAsm = (float*)malloc(size * sizeof(float));
    float* imgFloatC = (float*)malloc(size * sizeof(float));
    if (imgFloatAsm == NULL || imgFloatC == NULL) {
        printf("Memory allocation failed!\n");
        free(imgInt);
        free(imgFloatAsm);
        free(imgFloatC);
        return 1;
    }

    // Ask the user if they want to input pixel values or generate them automatically
    char choice;
    printf("Manual (m) or Random (r) ");
    while (getchar() != '\n');  // Flush remaining characters
    scanf_s(" %c", &choice, 1);

    if (choice == 'm' || choice == 'M') {
        // Prompt the user to input the grayscale pixel values
        printf("Enter Value:\n");
        for (size_t i = 0; i < size; i++) {
            printf("Value %zu: ", i + 1);
            scanf_s("%hhu", &imgInt[i]);
        }
    } else if (choice == 'r' || choice == 'R') {
        // Seed the random number generator
        srand((unsigned int)time(NULL));

        // Generate random pixel values between 0 and 255
        for (size_t i = 0; i < size; i++) {
            imgInt[i] = rand() % 256; // Random value between 0 and 255
        }
    } else {
        printf("Error: Invalid choice\n");
        free(imgInt);
        free(imgFloatAsm);
        free(imgFloatC);
        return 1;
    }

    // Measure execution time for the assembly function
    clock_t startAsm = clock();
    imgCvtGrayInttoFloat(size, imgInt, imgFloatAsm);
    clock_t endAsm = clock();
    double elapsed_time_asm = (double)(endAsm - startAsm) / CLOCKS_PER_SEC;

    // Measure execution time for the C function
    clock_t startC = clock();
    imgCvtGrayInttoFloat_C(size, imgInt, imgFloatC);
    clock_t endC = clock();
    double elapsed_time_c = (double)(endC - startC) / CLOCKS_PER_SEC;

    // Print the input matrix
    printMatrixInt(imgInt, width, height);

    // Print the output matrices
    printf("\nAssembly Function Output:");
    printMatrixFloat(imgFloatAsm, width, height);

    printf("\nC Function Output:");
    printMatrixFloat(imgFloatC, width, height);

    // Print execution times
    printf("\nTime taken by Assembly function: %.6f seconds\n", elapsed_time_asm);
    printf("Time taken by C function: %.6f seconds\n", elapsed_time_c);

    // Validate the results by comparing the outputs
    int mismatch = 0;
    for (size_t i = 0; i < size; i++) {
        if (imgFloatAsm[i] != imgFloatC[i]) {
            mismatch = 1;
            printf("Mismatch at index %zu: Assembly=%.2f, C=%.2f\n",
                   i, imgFloatAsm[i], imgFloatC[i]);
        }
    }
    if (!mismatch) {
        printf("Both functions produced identical results!\n");
    }

    // Free allocated memory
    free(imgInt);
    free(imgFloatAsm);
    free(imgFloatC);

    return 0;
}

