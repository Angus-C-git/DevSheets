#include <stdlib.h>
#include <stdio.h>

char *get_enviroment_vars(char *varibale_name);


int main(int argc, char const *argv[]) {
    printf("Get Enviroment variable $PATH: %s\n", get_enviroment_vars("PATH"));
    
    // store all the enviroment
    // variables on the system in an
    // array of strings.
    extern char **environ;
    
    return 0;
}

/**
 * Returns the enviroment variable for a 
 * given variable name.
 * 
*/
char *get_enviroment_vars(char *varibale_name) {

    // getenv returns NULL if the variable is not set
    char *enviroment_varibale = getenv(varibale_name);

    return enviroment_varibale;
}