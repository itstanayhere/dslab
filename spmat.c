#include <stdio.h>

struct SparseMatrix 
{
    int row,col,value;
};

void transposeSparseMatrix(struct SparseMatrix matrix[], struct SparseMatrix transpose[], int size) 
{
    int k = 1;
    transpose[0].row=matrix[0].col;
    transpose[0].col=matrix[0].row;
    transpose[0].value=matrix[0].value;
    for (int i = 0; i < matrix[0].col; i++) 
    {
        for (int j = 1; j <= size; j++) 
        {
            if (matrix[j].col == i) 
            {
                transpose[k].row = matrix[j].col;
                transpose[k].col = matrix[j].row;
                transpose[k].value = matrix[j].value;
                k++;
            }
        }
    }
}

int main() 
{
    int rows, cols, nz;
    printf("Enter the number of rows and columns in the matrix: ");
    scanf("%d %d",&rows,&cols);
    printf("Enter the number of non-zero elements: ");
    scanf("%d",&nz);
    struct SparseMatrix matrix[nz+1], transpose[nz+1];
    matrix[0].row=rows;
    matrix[0].col=cols;
    matrix[0].value=nz;
    printf("Enter the row, column, and value of each non-zero element:\n");
    for (int i = 1; i <= nz; i++) 
    {
        printf("Element %d: ", i);
        scanf("%d %d %d", &matrix[i].row, &matrix[i].col, &matrix[i].value);
    }
    transposeSparseMatrix(matrix, transpose, nz);
    printf("\nTranspose of the sparse matrix:\n");
    printf("Row Column Value\n");
    for (int i = 0; i <= nz; i++) 
    {
        printf("%d     %d     %d\n", transpose[i].row, transpose[i].col, transpose[i].value);
    }
    return 0;
}