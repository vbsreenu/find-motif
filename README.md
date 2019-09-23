# find-motif

Here are the BASH scripts and C program to extract nucleotide motifs from a genome sequence file.

Compile the C program and add to the path before you start using it:

* cc find_motif.c -o FIND_MOTIF *

Typical workflow to find motifs (which are in the motifs.fa file) is:

Download the Genome sequence and Gene Features file from GenBank:
  
* bash getGenBank NC_001806.2 *
* bash getGFF NC_001806.2 *


* FIND_MOTIF NC_001806.2.fa motifs.fa > NC_001806.2.motifs *

preprocess the gff file to extract motif regions:

* grep CDS NC_001806.2.gff |awk '{print $4,$5}' > temp1 *
* grep CDS NC_001806.2.gff |awk '{printf "%s %s ", $4,$5; for(i=9;i<=NF;i++) printf "%s ",$i; print "" }'|sed s/product=/\|/g|cut -d\| -f2 |cut -d\; -f1 > temp2 *

* paste temp1 temp2 > NC_001806.2.anno *

* awk '{if(NR==FNR){s[NR]=$1; e[NR]=$2; line[NR]=$0; i++;} else {printf "%s ", $0; for(j=1;j<=i;j++) {if($1>=s[j] && $1<=e[j]) print line[j];  }  print "";}}' NC_001806.2.anno NC_001806.2.motifs |awk 'NF>0{if(NF>1) {printf "%s\t%s\t%s\t",$1,$2,$3; for(i=4;i<=NF;i++) printf "%s ",$i; print ""} else print}' > NC_001806.2.res *
