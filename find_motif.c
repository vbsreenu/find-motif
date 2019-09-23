/*
Program for quick short sequence search in a fasta file

Usage: program_name genome_file.fa reads(kmers).fa

Sreenu Vattipally
MRC-CVR, University of Glasgow
Glasgow, UK

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "find_motif.h"

#define LINE_LEN 1024

int main (int argc, char **argv){

	FILE *input;
	char nuc, buffer[LINE_LEN+1],rev_seq[LINE_LEN+1],name[LINE_LEN+1],sbstr[50], flag=0;
	unsigned long long found;

	// Define unlimited char array
	CharArray c;
	// Initialize the array with size 51200
	initCharArray(&c, 51200);

	name[0]='\0';

	// Read the first input file and fill in the array c

	if((input = fopen(argv[1], "r"))!=NULL){ 
		while((nuc = fgetc(input))!=EOF) { 
			if (feof(input)) break; 

			if(nuc=='>') flag=1;
			if(nuc=='\n') flag=0;

			if(nuc!='\n' && flag==0) insertCharArray(&c, nuc);
			} fclose(input);
		} // End of reading the first file

	// Read the k-mer(short reads) file. Each kmer (short read) length should be less than 1024bp.

    	if((input = fopen(argv[2], "r"))!=NULL){ 
		while (!feof(input)) { 
			fgets(buffer,LINE_LEN,input); 
			if(feof(input)) break; 
			
			buffer[strlen(buffer)-1]='\0'; 

			if(buffer[0]=='>') {
				strcpy(name,buffer);
				printf("%s\n",name);
			}

			else{
			       printf("%s\n",buffer);	
				found=0;
				TempLate(buffer,rev_seq); 
				// Searching...
				found=KR2(buffer,strlen(buffer), c.array,c.used); 
				if(strcmp(buffer,rev_seq)!=0) found+=KR2(rev_seq,strlen(rev_seq), c.array,c.used); 
				//printf("%lld\n",found); 
			}
		} fclose(input);
	}
}
