#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

char* concat(const char *s1, const char *s2); 

int main(void) 
{
       	printf("Attempting to list files...\n");

	DIR *d;
	struct dirent *dir;
	d = opendir("../../posts/");
	if (d) 
	{
		while ((dir = readdir(d)) != NULL) 
		{
		       	if (dir->d_type == DT_REG) 
			{
				char *filepath = concat("../../posts/", dir->d_name);
				printf("Opening file: %s\n", filepath);
				
				FILE *fp;
				char buff[255];
				fp = fopen(filepath, "r");

				fgets(buff, 255, (FILE*)fp);
				printf("2 : %s\n", buff);

				flcose(fp);

	    		}
		}
		
		closedir(d);
    	} 
	else 
	{
		printf("Error opening directory.\n");
    	}
    
	return 0;
}

char* concat(const char *s1, const char *s2) 
{
	char *result = malloc(strlen(s1) + strlen(s2) + 1); // +1 for the null terminator
	strcpy(result, s1);
	strcat(result, s2);

	return result;
}

