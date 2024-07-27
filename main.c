#include "readfile.h"
#include "add&sub.h"
#include "karatsuba.h"


int main(){
	char infile[100]; 	// Maximum filename length assumed to be 100 characters
	char outfile[100]; 	// Maximum filename length assumed to be 100 characters
    printf("Please enter the filename where the integers are stored : ");
    scanf("%s", infile);
    printf("Please enter the filename where the result is to be stored : ");
    scanf("%s", outfile);
    struct number num1, num2, result;
    getInt(infile,&num1, &num2);
	result= karatsuba(&num1,&num2);
	printInt(result, outfile);
	printf("Result has been written to %s \n", outfile);
	free(num1.num);
	free(num2.num);
	free(result.num);
	return 0;
} 
