#include <stdio.h>
#define MAX_SIZE 10
// Function to input a matrix
void inputMatrix(int rows, int cols, int matrix[rows][cols])
{
    printf("Enter the elements of the matrix:\n");
    int i,j;
    for(i = 0; i < rows; i++) 
	{
        for(j = 0; j < cols; j++) 
		{
            printf("Enter element at position (%d, %d): ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to display a matrix
void displayMatrix(int rows, int cols, int matrix[rows][cols]) 
{
    printf("Matrix:\n");
    int i,j;
    for (i = 0; i < rows; i++) 
	{
        for (j = 0; j < cols; j++) 
		{
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void addMatrices(int rows, int cols, int matrix1[rows][cols], int matrix2[rows][cols], int result[rows][cols]) 
{
	int i,j;
    for (i = 0; i < rows; i++) 
	{
        for (j = 0; j < cols; j++) 
		{
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// Function to subtract two matrices
void subtractMatrices(int rows, int cols, int matrix1[rows][cols], int matrix2[rows][cols], int result[rows][cols]) 
{
	int i,j;
    for (i = 0; i < rows; i++) 
	{
        for (j = 0; j < cols; j++) 
		{
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

// Function to multiply two matrices
void multiplyMatrices(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols2]) 
{
	int i,j,k;
    for (i = 0; i < rows1; ++i) 
	{
        for (j = 0; j < cols2; ++j) 
		{
            result[i][j] = 0;
            for (k = 0; k < cols1; ++k) 
			{
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}
void transpose3x3(int mat[3][3], int transposed[3][3]) 
{
	int i,j;
    for (i = 0; i < 3; i++) 
	{
        for (j = 0; j < 3; j++) 
		{
            transposed[i][j] = mat[j][i];
        }
    }
}

int determinant(int n, int matrix[2][2]) 
{

	int det = (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
	printf("%d",det);
    return det;
    
}
int determinant3x3(int matrix[3][3])
{
	int det;
	det = matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[2][1] * matrix[1][2])
        - matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[2][0] * matrix[1][2])
        + matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[2][0] * matrix[1][1]);
    
	return det;
}
int main() 
{
    

 	int choice1;
 	printf("Choose the operation:-\n");
 	printf("1. Matrix operation\n");
 	printf("2. solving Elec. ckt\n-->");
 	scanf("%d",&choice1);
 	int rows, cols;
 	int matrix1[3][3], matrix2[3][3], result[3][3],transposed[3][3];
 	
 	
 	int choice;
 	int choice2;
 	int choice4;
 	switch(choice1)
 	{
 		
 		case 1:
 			printf("\n\nPerform Operation On :\n");
 			printf("\n1. Both Matrix");
 			printf("\n2. Single Matrix\n-->");
 			scanf("%d",&choice4);
 			switch(choice4)
 			{
 				case 1:
 					printf("Enter the number of rows and columns for the matrices: ");
		 		
			    
					    scanf("%d %d", &rows, &cols);
					
					    
					
					    // Input the first matrix
					    inputMatrix(rows, cols, matrix1);
					    displayMatrix(rows, cols, matrix1);
					
					    // Input the second matrixm
					    inputMatrix(rows, cols, matrix2);
					    displayMatrix(rows, cols, matrix2);
				    
					    // Menu for operation selection
					    printf("Choose the operation:\n");
					    printf("1. Addition\n");
					    printf("2. Subtraction\n");
					    printf("3. Multiplication\n");
					    printf("Enter your choice (1-3): ");
					    scanf("%d", &choice);
				
					    switch (choice) 
						{
					        case 1:
					            addMatrices(rows, cols, matrix1, matrix2, result);
					            printf("Result of addition:\n");
					            displayMatrix(rows, cols, result);
					            break;
					
					        case 2:
					            subtractMatrices(rows, cols, matrix1, matrix2, result);
					            printf("Result of subtraction:\n");
					            displayMatrix(rows, cols, result);
					            break;
					
					        case 3:
					            // Check if multiplication is possible
					            if (cols != rows) 
								{
					                printf("Multiplication is not possible. Number of columns in the first matrix must be equal to the number of rows in the second matrix.\n");
					            } 
								else 
								{
					                multiplyMatrices(rows, cols, matrix1, cols, rows, matrix2, result);
					                printf("Result of multiplication:\n");
					                displayMatrix(rows, cols, result);
					            }
					            break;
							
					        default:
					            printf("Invalid choice!\n");
					            break;
					    }
				break;
				
				case 2:	  printf("Enter the number of rows and columns for the matrices: ");
		 		
			    
					    scanf("%d %d", &rows, &cols);
					
					    
					
					    // Input the first matrix
					    inputMatrix(rows, cols, matrix1);
					    displayMatrix(rows, cols, matrix1);  
					    
					    printf("Choose the operation:\n");
					    printf("1. Transpose\n");
					    printf("2. Inverse\n");
					    printf("3. Determinant\n");
					    
					    printf("Enter your choice (1-3): ");
					    scanf("%d", &choice);
					    
					    switch(choice)
					    {
					    	case 1:
								transpose3x3(matrix1, transposed);
		
							    // Display the original and transposed matrices
							    printf("Original Matrix:\n");
							    int i,j;
							    for (i = 0; i < 3; i++) 
								{
							        for (j = 0; j < 3; j++) 
									{
							            printf("%d\t", matrix1[i][j]);
							        }
							        printf("\n");
							    }
							
							    printf("\nTransposed Matrix:\n");
							    for (i = 0; i < 3; i++) 
								{
							        for (j = 0; j < 3; j++) 
									{
							            printf("%d\t", transposed[i][j]);
							        }
							        printf("\n");
							    }
								break;
							
							case 2:
								
						}
			 }
		 
			    break;
		
		case 2:	    
				
				printf("\nchoose the circuit :-\n");
				printf("\n1. Tee(T) network\n");
				
				
				scanf("%d",&choice2);
				int R1,R2,R3,V1,V2;
				float I1,I2,I;
				int tmatrix[2][2],t1matrix[2][2],t2matrix[2][2];
				int DT;
				int DT1, DT2, DT3;
				int ckt_choice;
				switch(choice2)
				{
					
					case 1:
					printf("\nDetails of ckt :- \n");
					printf("1. With two voltage source \n");
					printf("2. With one current and one voltage source \n");
					printf("3. With two current source\n-->");
					scanf("%d",&ckt_choice);
					
					
					switch(ckt_choice)
					{
						case 1:printf("\n|-----R1-------R2------|\n|          |           |\n|          |           |\nV1         R3          V2\n|          |           |\n|          |           |\n|----------|-----------|");
						
								printf("\n\nEnter value of R1,R2 and R3 respectively = ");
								scanf("%d%d%d",&R1,&R2,&R3);
								printf("\nR1 = %d R2 = %d R3 = %d",R1,R2,R3);
								printf("\n\nEnter value of V1 and V2 respectively = ");
								scanf("%d%d",&V1,&V2);	
								printf("\nV1 = %d V2 = %d ",V1,V2);
								
								tmatrix[0][0] = R1 + R3;
								tmatrix[0][1] = R3;
								tmatrix[1][0] = R3;
								tmatrix[1][1] = R2 + R3;
								printf("\n\nMatrix DT -> \n");
								displayMatrix(2, 2, tmatrix);
								DT = determinant(2, tmatrix);
								printf("\nDeterminant of tMatrix= %d\n",DT);
								t1matrix[0][0] = V1;
								t1matrix[0][1] = R3;
								t1matrix[1][0] = V2;
								t1matrix[1][1] = R2 + R3;
								printf("\nMatrix DT1 -> \n");
								displayMatrix(2, 2, t1matrix);
								DT1 = determinant(2, t1matrix);
								printf("\nDeterminant of t1Matrix = %d\n",DT1);
								t2matrix[0][0] = R1 + R3;
								t2matrix[0][1] = V1;
								t2matrix[1][0] = R3;
								t2matrix[1][1] = V2;
								printf("\nMatrix DT2 -> \n");
								displayMatrix(2, 2, t2matrix);
								DT2 = determinant(2, t2matrix);
								printf("\nDeterminant of t2Matrix = %d\n",DT2);
								I1 = (float)DT1/DT;
								I2 = (float)DT2/DT;
								I = I1 + I2;
								printf("\n\nCurrent through R1 = %f Amp",I1);
								printf("\n\nCurrent through R2 = %f Amp",I2);
								printf("\n\nCurrent through R3 = %f Amp",I);
							break;
						case 2:printf("\n|-----R1-------R2------|\n|          |           |\n|          |           |\nI1         R3          V1\n|          |           |\n|          |           |\n|----------|-----------|");
								
								printf("\n\nEnter value of R1,R2 and R3 respectively = ");
								scanf("%d%d%d",&R1,&R2,&R3);
								printf("\nR1 = %d R2 = %d R3 = %d",R1,R2,R3);
								printf("\n\nEnter value of V1 = ");
								scanf("%d",&V1);	
								printf("\nV1 = %d",V1);
								printf("\n\nEnter value of I1 = ");
								scanf("%f",&I1);	
								printf("\nI1 = %f",I1);
								
								tmatrix[0][0] = -R1 - R3;
								tmatrix[0][1] = R3;
								tmatrix[1][0] = R3;
								tmatrix[1][1] = -R2 - R3;
								printf("\n\nMatrix DT -> \n");
								displayMatrix(2, 2, tmatrix);
								DT = determinant(2, tmatrix);
								printf("\nDeterminant of tMatrix= %d\n",DT);

								t2matrix[0][0] = -R1 - R3;
								t2matrix[0][1] = 0;
								t2matrix[1][0] = R3;
								t2matrix[1][1] = V1;
								printf("\nMatrix DT2 -> \n");
								displayMatrix(2, 2, t2matrix);
								DT2 = determinant(2, t2matrix);
								printf("\nDeterminant of t2Matrix = %d\n",DT2);
								
								I2 = (float)DT2/DT;
								I = I1 + I2;
								printf("\n\nCurrent through R1 = %f Amp",I1);
								printf("\n\nCurrent through R2 = %f Amp",I2);
								printf("\n\nCurrent through R3 = %f Amp",I);
							break;
						case 3:printf("\n|-----R1-------R2------|\n|          |           |\n|          |           |\nI1         R3          I2\n|          |           |\n|          |           |\n|----------|-----------|");
								printf("\n\nEnter value of R1,R2 and R3 respectively = ");
								scanf("%d%d%d",&R1,&R2,&R3);
								printf("\nR1 = %d R2 = %d R3 = %d",R1,R2,R3);
								printf("\n\nEnter value of I1 and I2 respectively = ");
								scanf("%f%f",&I1,&I2);	
								printf("\nI1 = %f I2 = %f ",I1,I2);
								
								//In this type of ckt no need to use matrix operation we can calculate current through each resistance directly
								printf("\n\nCurrent through R1 = %f Amp",I1);
								printf("\n\nCurrent through R2 = %f Amp",I2);
								printf("\n\nCurrent through R3 = %f Amp",I1+I2);
					}
					break;
					
			}
	}
    

    return 0;
}


