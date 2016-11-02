#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(){
  printf("Statistics for directory: \n");
  int size = 0;
  DIR *stream = opendir(".");
  struct dirent *cur;
  struct stat file;
  printf("Directories: \n");
  while((cur=readdir(stream))){ //open and print subdirectories
    if(cur->d_type & DT_DIR)
    printf("\t%s\n",cur->d_name);
  }
  closedir(stream);

  printf("Regular Files: \n"); //open and print regular files
  stream = opendir(".");
  while((cur=readdir(stream))){
    if(cur->d_type & DT_REG){
    printf("\t%s",cur->d_name);
    stat(cur->d_name,&file);
    size += file.st_size;
    printf("\t %lld Bytes\n",file.st_size);
  }
  }
  closedir(stream);
  printf("Total Directory Size: %d Bytes\n",size);
  return 0;

}
