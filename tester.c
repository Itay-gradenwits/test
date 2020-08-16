#include "ErrorCode.h"
#include "Matrix.h"
#include "stdio.h"
#include "string.h"

void matrix_print(PMatrix matrix) {
 uint32_t height, width;  
    matrix_getHeight(matrix, &height);
    matrix_getWidth(matrix, &width);
     double value;
    for(uint32_t i = 0; i < height; i++) {
        for(uint32_t j = 0; j < height; j++) {
            matrix_getValue(matrix, i, j ,&value);
            printf("%f ,", value);
        }
        printf("\n");
    }
}
void initialize_matrix (PMatrix matrix, uint32_t height, uint32_t width, double startValue, double difference) {
    for(uint32_t rowIdx = 0; rowIdx < height; rowIdx++) {
        for(uint32_t colIdx = 0; colIdx < width; colIdx++) {
            matrix_setValue(matrix, rowIdx, colIdx ,startValue);
            startValue+=difference;
        }
    }
}

int main() {
PMatrix lhs_1 = NULL;
PMatrix rhs_1 = NULL;
ErrorCode errorCreateLhs_1 = matrix_create(&lhs_1,5,5);
ErrorCode errorCreateRhs_1 = matrix_create(&rhs_1,5,5);
if(!error_isSuccess(errorCreateLhs_1)) {
    matrix_destroy(lhs_1);
    matrix_destroy(rhs_1);
    printf("Error at create Lhs_1: %s",error_getErrorMessage(errorCreateLhs_1));
    if(!error_isSuccess(errorCreateRhs_1)) {
         printf("Error at create Rhs_1: %s",error_getErrorMessage(errorCreateRhs_1));
    }
    return 1;
}
initialize_matrix(lhs_1, 5, 5, 21, 1);
initialize_matrix(rhs_1, 5, 5, 21, 1);
PMatrix multiplyLhs1AndRhs1Result = NULL;
PMatrix sumLhs1AndRhs1Result = NULL;
ErrorCode multiplyLhs1AndRhs1Error = matrix_multiplyMatrices(&multiplyLhs1AndRhs1Result, lhs_1, rhs_1);
ErrorCode sumLhs1AndRhs1Error = matrix_add(&sumLhs1AndRhs1Result, lhs_1, rhs_1);
ErrorCode multiplyLhs1ByScalar = matrix_multiplyWithScalar(lhs_1, 3); 
ErrorCode copyRhs1ToLhs1 = matrix_copy(&lhs_1, rhs_1);
if(!error_isSuccess(multiplyLhs1AndRhs1Error)) {
    printf("Error at multiply lhs_1 to rhs_1: %s -- (wrong because the multipication is possible)\n",error_getErrorMessage(multiplyLhs1AndRhs1Error));
}
else {
    printf("your multiplication of lhs_1 and rhs_1 is:\n");
    matrix_print(multiplyLhs1AndRhs1Result);
    printf("\nand the actual multiplication is:\n3615, 3730, 3845, 3960, 4075\n4390, 4530, 4670, 4810, 4950\n5165, 5330, 5495, 5660, 5825\n5940, 6130, 6320, 6510, 6700\n6715, 6930, 7145, 7360, 7575");   
}
if(!error_isSuccess(sumLhs1AndRhs1Error)) {
    printf("Error at add lhs_1 to rhs_1: %s -- (wrong! because the sum is possible)\n",error_getErrorMessage(sumLhs1AndRhs1Error));
}
else {
    printf("your sum of lhs_1 and rhs_1 is:\n");
    matrix_print(sumLhs1AndRhs1Result);
    printf("\nand the actual sum is:\n42, 44, 46, 48, 50\n52, 54, 56, 58, 60\n62, 64, 66, 68, 70\n72, 74, 76, 78, 80\n82, 84, 86, 88, 90");   
}
if(!error_isSuccess(multiplyLhs1ByScalar)) {
    printf("Error at multiply lhs1 by the scalar 3: %s -- (wrong! because you can multiplie lhs_1 by scalar 3)\n",error_getErrorMessage(multiplyLhs1ByScalar));
}
else {
    printf("Your lhs1 multiply by scalar 3 is:\n");
    matrix_print(lhs_1);
    printf("and the actual lhs1 multiply scalar 3 is:\n63, 66, 69, 72, 75\n78, 81, 84, 87, 90\n93, 96, 99, 102, 105\n108, 111, 114, 117, 120\n123, 126, 129, 132, 135");
}
if(!error_isSuccess(copyRhs1ToLhs1)) {
    printf("Error at copy lhs_1 to rhs_1: %s -- (wrong! because you can copy rhs_1 to lhs_1)\n",error_getErrorMessage(copyRhs1ToLhs1));
}
else {
    printf("your new lhs1 that is the copy of rhs1 is:\n");
    matrix_print(lhs_1);
    printf("and the actual multiplication is:\n");
    matrix_print(rhs_1);   
}

PMatrix lhs_2 = NULL;
PMatrix rhs_2 = NULL;
ErrorCode errorCreateLhs_2 = matrix_create(&lhs_2,3,5);
ErrorCode errorCreateRhs_2 = matrix_create(&rhs_2,5,3);
if(!error_isSuccess(errorCreateLhs_2)) {
    matrix_destroy(lhs_2);
    matrix_destroy(rhs_2);
    printf("Error at create Lhs_2: %s",error_getErrorMessage(errorCreateLhs_2));
    if(!error_isSuccess(errorCreateRhs_2)) {
         printf("Error at create Rhs_1: %s",error_getErrorMessage(errorCreateRhs_2));
    }
    return 1;
}
initialize_matrix(lhs_2, 3, 5, 5 , -4);
initialize_matrix(rhs_1, 5, 3, 9, 0);
PMatrix multiplyLhs2AndRhs2Result = NULL;
PMatrix sumLhs2AndRhs2Result = NULL;
ErrorCode multiplyLhs2AndRhs2Error = matrix_multiplyMatrices(&multiplyLhs2AndRhs2Result, lhs_2, rhs_2);
ErrorCode sumLhs2AndRhs2Error = matrix_add(&sumLhs2AndRhs2Result, lhs_2, rhs_2);
ErrorCode multiplyLhs2ByScalar = matrix_multiplyWithScalar(lhs_2, 100); 
ErrorCode copyRhs2ToLhs2 = matrix_copy(&lhs_2, rhs_2);
if(!error_isSuccess(multiplyLhs2AndRhs2Error)) {
    printf("Error at multiply lhs_2 to rhs_2: %s -- (wrong! because the multipication is possible)\n",error_getErrorMessage(multiplyLhs2AndRhs2Error));
}
else {
    printf("your multiplication of lhs_2 and rhs_2 is:\n");
    matrix_print(multiplyLhs2AndRhs2Result);
    printf("\nand the actual multiplication is:\n-135, -135, -135\n-1035, -1035, -1035\n-1935, -1935, -1935");   
}
if(!error_isSuccess(sumLhs2AndRhs2Error)) {
    printf("Error at add lhs_2 to rhs_2: %s -- (correct! because the sum is indeed impossible)\n",error_getErrorMessage(sumLhs2AndRhs2Error));
}
else {
    printf("the sum of lhs2 and rhs2 is impossible but your sum of lhs_2 and rhs_2 is:\n");
    matrix_print(sumLhs2AndRhs2Result);
       
}
if(!error_isSuccess(multiplyLhs1ByScalar)) {
    printf("Error at multiply lhs2 by the scalar 100: %s -- (wrong! because you can multiply lhs2 with scalar 100)\n",error_getErrorMessage(multiplyLhs2ByScalar));
}
else {
    printf("Your lhs2 multiply scalar 100 is:");
    matrix_print(lhs_2);
    printf("and the actual lhs2 multiply by scalar 100 is:\n50, 10, -30, -70, -110\n-150, -190, -230, -270, -310\n-350, -390, -430, -470, -510");
}
if(!error_isSuccess(copyRhs2ToLhs2)) {
    printf("Error at copy lhs_2 to rhs_2: %s -- (wrong! because the copy is possible)\n",error_getErrorMessage(copyRhs2ToLhs2));
}
else {
    printf("your new lhs2 that is the copy of rhs2 is:\n");
    matrix_print(lhs_2);
    printf("and the actual multiplication is:\n");
    matrix_print(rhs_2);   
}
 matrix_destroy(lhs_1);
 matrix_destroy(lhs_2);
 matrix_destroy(rhs_1); 
 matrix_destroy(rhs_2);

    return 0;
}