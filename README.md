# OpenFlights
# Team Suiiiiii - Rahul, Pranav, Yugal, Subash

## Introduction
For our final project we decided to explore the OpenFlights dataset which is an open source data set of flight routes and airport. Using this dataset we were hoping to find the shortest path between two airports. We first created a weighted directed graph by using both routes.dat and airport.dat files. The graph itself was implemented using an adjacency list where the weight of each edge was represnted by calculating the distance between vertices. We also implemented both Floyd-Warshall and A* algorithim in order to find the shortest path between two airports.

## Run the program
First clone the code from github.
Then create a build file for you to build the project:
```
mkdir build
cd build
```

Now run cmake:
```
cmake..
```

Next make and run the main file:
```
make main
./main
```

Now you will see a selection of airports to choose from. Follow the directions in the terminal to find the shortest path.
## Running tests
In order to make and run test cases:
```
make tests
./tests
```


# File Organization

## lib
This folder contains the raw dataset in .csv form.

## entry
This folder has main.cpp.

## src
This folder has helper files and functions for creation of objects and organization of data.
It also contains DFS.cpp, which is where we implement this traversal.
floyd.cpp contains the implementation of Floyd-Warshall.
Lastly, Our A* Algorithm is contained in traversal.cpp


## tests
This folder has tests.cpp which contains test cases to verify validity of output.

## Presentaion Video Link

# Output:
![output](https://user-images.githubusercontent.com/90521146/207231862-140d0f33-e620-42b4-a577-7d16d64fcdec.png)