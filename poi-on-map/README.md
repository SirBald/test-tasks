Working with POIs on a map
==========================

# Description

Point of interest (POI) is defined by its coordinates (x, y) and its name. E.g. (123, 456, "Kremlin").

# Tasks

1. Read POI definitions from a file. File structure: each line represents single POI with three values - two coordinates and
   a string. All fields are separated by spaces. Example of a line in the file:

   123 456 Kremlin
2. Given X, Y, and R, find all POIs that are located not farther than R from point with coordinates (X, Y).
3. For all points found in the step 2, find average distance and sample variance to the point with coordinates (X, Y).
4. For all points found in the step 2, convert their coordinates to Polar coordinates with the center in (X, Y).
5. Find minimal rectangle that contains all points found in the step 2. Rectangle sides are parallel to axes.
