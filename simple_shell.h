#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <dirent.h>
#include <signal.h>

/*constants*/
#define KA 1     
#define KB 2    
#define KC 3  
#define KD -1   
#define min(x, y) (((x) < (y)) ? (x) : (y))

/**
 *struct map - a struct that maps a command name to a function 
 *
 *@command_name: name of the command
 *@func: the function that executes the command
 */

typedef struct ke               
{
	char *kf;               
	void (*kg)(char **kh);  
} ki;                           

extern char **kj;  
extern char *kl;   
extern char **km;  
extern char *kn;  
extern int ko;     

/*helpers*/
void kp(char *, int);     
char **kq(char *, char *);  
void kr(char *);            
int ks(char *);             
void kt(char *, char *);    

/*helpers2*/
int ku(char *, char *);    
char *kv(char *, char *);
int kw(char *, char *);     
int kx(char *, char *);     
char *ky(char *, char);     

/*helpers3*/
char *kz(char *, char *, char **);                 
int kaa(char *);                                       
void *kab(void *kac, unsigned int kad, unsigned int kae);  
void kaf(int);       
void kag(char *);    

/*utils*/
int kah(char *);                
void kai(char **, int);         
char *kaj(char *);              
void (*kak(char *))(char **); 
char *kal(char *);              

/*built_in*/
void kam(char **);        
void kan(char **);       

/*main*/
extern void kao(void);              
extern void kap(char **kaq, int kar);     

#endif /*SIMPLE_SHELL_H*/
