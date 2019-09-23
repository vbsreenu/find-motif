#!/bin/bash

#	Script to download GFF file rom GenBank using an accession number
#	It uses NCBI's eutils API (https://www.ncbi.nlm.nih.gov/books/NBK25497/)

#       Usage: getGffFromGenbank.sh accessionNumber

#       Dr. Sreenu Vattipally
#	MRC-University of Glasgow Centre for Virus Research
#	Glasgow, UK
#


wget -O $1.gff https://www.ncbi.nlm.nih.gov/sviewer/viewer.cgi?tool=portal\&save=file\&db=nuccore\&report=gff3\&id=$1\&extrafeat=null
