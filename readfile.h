//Assume that those numbers are written in contiguous way and length is an integer  with no prepended zeroes

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store a number along with its length in byte
struct number{
	int len;
	unsigned char *num;
};

// Function to create a dyamically allocated array to store a number
struct number makeInt(int SIZE){
	struct number a;
    a.num = (unsigned char*)malloc(SIZE);
	memset(a.num,0,SIZE);
	a.len = SIZE;
    return a;
}

// Function to convert a hexadecimal string to an array of unsigned char
int hextoint(char hex) {
	//Conversion of hex characters to decimal value 
    if (hex >= '0' && hex <= '9') {
        return hex - '0';
    } else if (hex >= 'a' && hex <= 'f') {
        return hex - 'a' + 10;
    } else if (hex >= 'A' && hex <= 'F') {
        return hex - 'A' + 10;
    }
    return -1;						// Invalid hexadecimal character
}
struct number hexToInt(char* hex,int size){
	struct number binInt= makeInt(size);
	for (int i=1; i<= size; i++) 	// Ignore the first byte containing 0x
		binInt.num[i-1]= (hextoint(hex[2*i])<<4) + hextoint(hex[2*i+1]);
	
	return binInt;
}

// Function to get the values from the file
void getInt(char* filename, struct number* num1, struct number* num2){
    char ch;
    int size[2]={0,0}; 				// Store the length of two numbers temporarily
    int count =0;
    FILE *file = fopen(filename, "r");
    if (file == NULL)
        printf("Unable to open the file.\n");
    else {
		while (fscanf(file, "%*s %d", &size[count]) == 1){
    		count++;
    	}
		rewind(file);	
		char buf1[2*size[0]+2];
		fscanf(file,"%s %*d", buf1);
		char buf2[2*size[1]+2];
		fscanf(file,"%s %*d", buf2);
		*num1= hexToInt(buf1,size[0]);
		*num2= hexToInt(buf2,size[1]);
		fclose(file);		
	}
}

// Function to print an integer stored in an array
void printInt(struct number integer, char* filename){
	FILE *file  = fopen(filename, "w");
    int flag=0;
    if (file != NULL) {
	    for(int i=0; i<integer.len; ++i){
	        if(flag!=0 || integer.num[i]!=0){
	            fprintf(file,"%02x",integer.num[i]);
	            flag=1;
	        }
		}
		fclose(file);
    }
    else {
        printf("Error opening file!\n");
    }
}
