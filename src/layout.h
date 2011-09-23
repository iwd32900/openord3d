// This file contains compile time parameters which affect the entire
// DrL program.

#define VERSION "3.2 5/5/2006"

// compile time parameters for MPI message passing
#define MAX_PROCS 256	   // maximum number of processors
#define MAX_FILE_NAME 250   // max length of filename
#define MAX_INT_LENGTH 4   // max length of integer suffix of intermediate .coord file

// Compile time adjustable parameters for the Density grid

/*
// new values for OpenOrd -- too much memory for 3D on a 32-bit address space!
#define GRID_SIZE 1000			// size of Density grid
#define VIEW_SIZE 4000.0		// actual physical size of layout plane
								// these values use more memory but have
								// little effect on performance or layout
								
#define RADIUS 10				// radius for density fall-off:
								// larger values tends to slow down
								// the program and clump the data

#define HALF_VIEW 2000			// 1/2 of VIEW_SIZE
#define VIEW_TO_GRID .25		// ratio of GRID_SIZE to VIEW_SIZE
*/

/*
// original values for VxOrd
#define GRID_SIZE 400			// size of VxOrd Density grid
#define VIEW_SIZE 1600.0		// actual physical size of VxOrd plane
#define RADIUS 10				// radius for density fall-off

#define HALF_VIEW 800			// 1/2 of VIEW_SIZE
#define VIEW_TO_GRID .25		// ratio of GRID_SIZE to VIEW_SIZE
*/

// small values for 3D clustering on 32-bit machines!
#define GRID_SIZE 128			// size of VxOrd Density grid
// not used anywhere:
//#define VIEW_SIZE 512.0		// actual physical size of VxOrd plane
#define RADIUS 5				// radius for density fall-off

// To avoid reaching outsie the DensityGrid when converting real coordinates to grid positions,
// for -HALF_VIEW <= xyz <= +HALF_VIEW,
// 0 + RADIUS <= ((xyz + HALF_VIEW + 0.5) * VIEW_TO_GRID) < GRID_SIZE - RADIUS
// This is NOT POSSIBLE when xyz == -HALF_VIEW ...
#define HALF_VIEW 256			// 1/2 of VIEW_SIZE
//#define VIEW_TO_GRID 0.25		// ratio of GRID_SIZE to VIEW_SIZE
#define VIEW_TO_GRID (GRID_SIZE - 2*RADIUS - 1) / (2.0 * HALF_VIEW)		// ratio of GRID_SIZE to VIEW_SIZE

