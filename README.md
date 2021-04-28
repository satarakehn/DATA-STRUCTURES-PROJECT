# PROJECT
This project was intended to function as a small git clone.

When the program is run, we instantly deploy into a new repository. Here we have a menu displayed, that allows us to add files to commit, remove files from commit, commit files, or
to checkout previous commit versions.

The header file miniGit.hpp stores all our data structure and class declarations. The cpp file miniGit.cpp contains their implementations.

Finally, the driver file contains the repository interface/menu. When 1 is pressed, we should be able to add a file to commit.

When 2 is pressed, we should be able to remove a file from commit.

When 3 is pressed, we should be able to commit a file, this will record the current file version to our commit number, with a corresponding file name in the following format.
foo##.txt where ## are two digits telling us the file version. Of course, we can have cpp and hpp files as well, but txt is the quintissential example.

When 4 is pressed, we can check out previous versions. This will copy all the files from a previous version history to our local repository. This is the entire point of version control,
we can get all the files in a previous version in history before we changed them, we can do a rollback.

We were not allowed to use the copy function in file system. So I created my own copy function that will copy any file we want, by specifying the input file name, and the desired output
file name.
