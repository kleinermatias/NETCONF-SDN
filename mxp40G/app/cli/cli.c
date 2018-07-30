#include <readline/readline.h>
#include <readline/history.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#include "cli.h"

void myFunction();

int main (int argc, char **argv) {
    char *line;
    char parameters[256];
    char *pre = "./";   
    int status,result;
    char *expansion;
    int done=0;
    char prompt[PROMPT_MAX_LEN];

    
    chdir(CMD_DIR);
    
    /*! Desabilitar el AutoCompletar */
     
    //rl_bind_key('\t',rl_abort);
    
    /*! Habilita el uso del historial de comandos */
    using_history(); 
   
   rl_catch_signals = 0;
   signal(SIGINT,myFunction);//If program terminates go to assigned function "myFunction"

    
    while (!done) {
        
        // CLI input prompt
        memset(prompt, '\0', PROMPT_MAX_LEN);
        gethostname(prompt, PROMPT_MAX_LEN-strlen(PROMPT));
        strncpy(prompt+strlen(prompt), PROMPT, strlen(PROMPT));
        line = readline(prompt);
        
        // Command line processing        
        if (line) {
           
            if (strlen(line) > 0) {
                
                result = history_expand (line, &expansion);
          
                if (result)
                    fprintf (stderr, "%s\n", expansion);

                if (result < 0 || result == 2) {
                    free (expansion);
                    continue;
                }

                add_history (expansion);
            
                strncpy (line, expansion, sizeof (line) - 1);
                free (expansion);
                                
                if(strncmp("exit",line,4)==0) {
                    done=1;
                    return 0;
                }
                else if (strncmp("list",line,4)==0) {
                    register HIST_ENTRY **the_list;
                    register int i;

                    the_list = history_list ();
                    
                    if (the_list)
                        for (i = 0; the_list[i]; i++)
                            printf ("%d: %s\n", i + history_base, 
                                the_list[i]->line);
                }
                else
                {
                    strcpy(parameters, pre);
                    strcat(parameters, line);  
                    status = system(parameters);
                }     
            }
        }
    }
    
    return 0;
}

void myFunction()   {
    //fflush(stdout);
    //rl_clear_signals();
   //rl_save_prompt();
   //rl_clear_message();
   rl_on_new_line();
}



