# basic-unsupervised-classification

Classifying two-dimensional data into patterns with k-means algorithm.

Author: [yikouniao](https://github.com/yikouniao)  
Project link: https://github.com/yikouniao/basic-unsupervised-classifications  

### main.cpp

`main` function. The arguments are `***.exe dat/1.txt`.

### k-means.cpp/.h

k-means algorithm on `Dat` in `dat.cpp/.h`.

### dat.cpp/.h

Data structure.
 * `XY` : array for two-dimensional data
 * `Pattern` : `enum` for patterns
 * `PatternCenter` : array of `XY`, recording center of patterns
 * `SingleDat` : containing `XY` and `Pattern`
 * `Dat` : vector of `SingleDat`, containing all data

### dat/1.txt

A text file for storing data. The format is `"x_0\ty_0\n...x_n\ty_n\n..."`. As a flag of ending, the last line is a `'#'`.