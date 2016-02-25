set terminal png size 800,480 enhanced font 'Arial, 16'
set output 'sort.png'

set style line 1 linecolor rgb 'red' linetype 2 linewidth 2
set style line 2 linecolor rgb 'blue' linetype 3 linewidth 2
set style line 3 linecolor rgb 'green' linetype 6 linewidth 1

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

plot "csort.dat" using 1:2 title "CountingSort" with linespoints ls 3
 "bsort.dat" using 1:2 title "BubbleSort" with linespoints ls 2,\
 "qsort.dat" using 1:2 title "QuickSort" with linespoints ls 1,\

