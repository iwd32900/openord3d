Original code taken from http://www.cs.sandia.gov/~smartin/software.html on 22 Sept 2011.

Modifications to do 3-D layout by Ian W. Davis <ian.w.davis@gmail.com>

I've almost certainly broken *something*; in particular, I probably broke MPI processing. (Grep for
"TODO" to see where.) No parameters have been optimized for 3-D, except to make everything fit in
<3GB of memory. You can make GRID_SIZE even smaller if you have less memory than that. I also fixed
an apparent index-out-of-bounds error in DensityGrid, but my understanding of the code is
incomplete, so it's always possible I broke it more instead. At least the coarsen/refine cycle now
runs without errors, although I can't vouch for the quality of the results.

The AraNet example data in examples/iwd/ comes from Hwang, Rhee, Marcotte, and Lee (2011), Nature
Protocols, 6(9):1429.  It represents functional gene interactions in Arabidopsis thaliana.

For *viewing* the results of 3-D layout, I recommend creating "kinemages", ala the script
examples/iwd/make_kin.py. The KiNG software for viewing kinemages, along with documentation of the
full kinemage file format, is availble from http://kinemage.biochem.duke.edu.
