#include <stdio.h> // header file standard io
#include <string.h> // header file header defines one variable type, one macro, and various functions for manipulating arrays of characters.
#include <stdlib.h>// header file standard library
#include <dirent.h>
//The <dirent.h> header defines the following data type through typedef:
//DIR
//A type representing a directory stream.
//It also defines the structure dirent which includes the following members:
#include <sys/types.h>


/**
 * Main
 */
int main(int argc, char **argv)
{
  char *name; // pointer to name
  // Parse command line
  if(argc > 1)
  {
    name = strdup(argv[1]); //The strdup() function is used to duplicate a string //copying value argv[1] setting to name;
  } else 
  {
    name = "."; // if there is no arg[v], the value is "."
  }
 
  // Open directory
  DIR *dir; //The DIR data type represents a directory stream. *dir is a pointer to a directory stream.
  struct dirent *sd; // sd is now set to a new type of data. created by a struct. 
  dir = opendir(name); // location of the directory to open with the *dir pointer. open the directory with the name provided. this sets dir to a function that opens the passed in directory. 

  if(dir == NULL) // if there is no directory...print the following. 
  {
    printf("Unable to open the directory. Were sorry!"); // print this
    exit(1); // exit. 
  }

  // Repeatly read and print entries

  while((sd=readdir(dir)) != NULL)
  {
    printf("%s\n", sd->d_name);
  }

  return 0;
}