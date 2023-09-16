#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

typedef struct
{
    int row;
    int col;
    int val;
} Element;

typedef struct
{
    int row;
    int col;
    int NumElement;
    Element* elements;
} SparseMatrix;

SparseMatrix* transpose(SparseMatrix* matrix);

int main()
{
    int m, n, NumNonzero;
    printf("Enter the size of rows and colums, the number of non-zero terms: ");
    scanf_s("%d %d %d", &m, &n, &NumNonzero);

    SparseMatrix* matrix = (SparseMatrix*)malloc(sizeof(SparseMatrix));
    matrix->row = m;
    matrix->col = n;
    matrix->NumElement = NumNonzero;
    matrix->elements = (Element*)malloc(NumNonzero * sizeof(Element));

    printf("Enter row, column, and value pairs in order:\n");
    for (int i = 0; i < NumNonzero; i++)
    {
        scanf_s("%d %d %d", &(matrix->elements[i].row), &(matrix->elements[i].col), &(matrix->elements[i].val));
    }

    SparseMatrix* transposed = transpose(matrix);

    printf("The transposed of the matrix is:\n");
    for (int i = 0; i < transposed->NumElement; i++)
    {
        printf("%d %d %d\n", transposed->elements[i].row, transposed->elements[i].col, transposed->elements[i].val);
    }

    free(matrix->elements);
    free(matrix);
    free(transposed->elements);
    free(transposed);

    system("pause");

    return 0;
}

SparseMatrix* transpose(SparseMatrix* matrix)
{
    SparseMatrix* result = (SparseMatrix*)malloc(sizeof(SparseMatrix));
    result->row = matrix->col;
    result->col = matrix->row;
    result->NumElement = matrix->NumElement;

    result->elements = (Element*)malloc(result->NumElement * sizeof(Element));

    int* NumElementsRow = (int*)calloc(matrix->col, sizeof(int));

    for (int i = 0; i < matrix->NumElement; i++)
    {
        NumElementsRow[matrix->elements[i].col]++;
    }

    int* change = (int*)calloc(matrix->col, sizeof(int));
    change[0] = 0;
    for (int i = 1; i < matrix->col; i++)
    {
        change[i] = change[i - 1] + NumElementsRow[i - 1];
    }

    for (int i = 0; i < matrix->NumElement; i++)
    {
        int j = matrix->elements[i].col;
        int index = change[j];
        result->elements[index].row = matrix->elements[i].col;
        result->elements[index].col = matrix->elements[i].row;
        result->elements[index].val = matrix->elements[i].val;
        change[j]++;
    }

    free(NumElementsRow);
    free(change);

    return result;
}
