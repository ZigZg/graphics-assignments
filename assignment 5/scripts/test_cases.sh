#!/bin/sh

# Not filtered (faster)
./inst/a5 -input data/scene06_bunny_1k.txt -size 300 300 -output 06.png -shadows -bounces 4
./inst/a5 -input data/scene10_sphere.txt   -size 300 300 -output 10.png -shadows -bounces 4
./inst/a5 -input data/scene11_cube.txt     -size 300 300 -output 11.png -shadows -bounces 4
./inst/a5 -input data/scene12_vase.txt     -size 300 300 -output 12.png -shadows -bounces 4 
./inst/a5 -input data/scene13_diamond.txt  -size 300 300 -output 13.png -shadows -bounces 4 

# Filtered
./inst/a5 -input data/scene06_bunny_1k.txt -size 300 300 -output 06f.png -shadows -bounces 4 -jitter -filter
./inst/a5 -input data/scene10_sphere.txt   -size 300 300 -output 10f.png -shadows -bounces 4 -jitter -filter
./inst/a5 -input data/scene11_cube.txt     -size 300 300 -output 11f.png -shadows -bounces 4 -jitter -filter
./inst/a5 -input data/scene12_vase.txt     -size 300 300 -output 12f.png -shadows -bounces 4 -jitter -filter
./inst/a5 -input data/scene13_diamond.txt  -size 300 300 -output 13f.png -shadows -bounces 4 -jitter -filter

# For comparison

# Not filtered (faster)
./sample_solution/a5soln_mac -input data/scene06_bunny_1k.txt -size 300 300 -output s06.png -shadows -bounces 4
./sample_solution/a5soln_mac -input data/scene10_sphere.txt   -size 300 300 -output s10.png -shadows -bounces 4
./sample_solution/a5soln_mac -input data/scene11_cube.txt     -size 300 300 -output s11.png -shadows -bounces 4
./sample_solution/a5soln_mac -input data/scene12_vase.txt     -size 300 300 -output s12.png -shadows -bounces 4 
./sample_solution/a5soln_mac -input data/scene13_diamond.txt  -size 300 300 -output s13.png -shadows -bounces 4 

# Filtered
./sample_solution/a5soln_mac -input data/scene06_bunny_1k.txt -size 300 300 -output s06f.png -shadows -bounces 4 -jitter -filter
./sample_solution/a5soln_mac -input data/scene10_sphere.txt   -size 300 300 -output s10f.png -shadows -bounces 4 -jitter -filter
./sample_solution/a5soln_mac -input data/scene11_cube.txt     -size 300 300 -output s11f.png -shadows -bounces 4 -jitter -filter
./sample_solution/a5soln_mac -input data/scene12_vase.txt     -size 300 300 -output s12f.png -shadows -bounces 4 -jitter -filter
./sample_solution/a5soln_mac -input data/scene13_diamond.txt  -size 300 300 -output s13f.png -shadows -bounces 4 -jitter -filter
