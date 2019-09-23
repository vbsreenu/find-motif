#!/bin/bash

#	Script to download fasta sequence from GenBank using an accession number
#	It uses NCBI's eutils API (https://www.ncbi.nlm.nih.gov/books/NBK25497/).
#
#	Usage: getSeqFromGenbank.sh accessionNumber
#	
#	Sreenu Vattipally
#
wget -O $1.fa https://eutils.ncbi.nlm.nih.gov/entrez/eutils/efetch.fcgi?db=nuccore\&id=$1\&rettype=fasta\&retmode=text
