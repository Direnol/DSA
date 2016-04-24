#!/usr/bin/gnuplot
set terminal png size 800,480 enhanced font 'Arial, 9'

set style line 1 linecolor rgb 'red' linetype 1 linewidth 4
set style line 2 linecolor rgb 'blue' linetype 2 linewidth 1

set border linewidth 1
set key top left
set grid
set mytics 0
set format y "%.6f"
set xlabel "Number of elements" font "Arial, 16"
set format x "%.0f" 
set ylabel "Execution time (sec)" font "Arial, 16"
set xtics 100000 font "Arial, 12"
set ytics font "Arial, 12"
set rmargin 4
set tmargin 2
set mxtics

set output 'Add.png'
plot "./test/bstree_add.dat" using 1:2 title "BSTree add" with linespoints ls 1,\
     "./test/hashtab_add.dat" using 1:2 title "HASHTAB add" with linespoints ls 2,\

set output 'look.png'
plot "./test/bstree_lookup.dat" using 1:2 title "BSTree lookup" with linespoints ls 1,\
	 "./test/hashtab_lookup_KPHash.dat" using 1:2 title "HASHTAB lookup" with linespoints ls 2,\
	 
set output "hash_look.png"
plot "./test/hashtab_lookup_KPHash.dat" using 1:2 title "HASHTAB KP look" with linespoints ls 1,\
	 "./test/hashtab_lookup_JENKINSash.dat" using 1:2 title "HASHTAB_JENKINGS_look" with linespoints ls 2,\
	
set output "hash_q.png"
plot "./test/hashtab_lookup_KPHash.dat" using 1:3 title "HASHTAB KP collision" with linespoints ls 1,\
	 "./test/hashtab_lookup_JENKINSash.dat" using 1:3 title "HASHTAB JENKINGS collision" with linespoints ls 2
	
