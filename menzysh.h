#ifndef MENZYSH_H
#define MENZYSH_H


#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>

#define CMDFAILERR 0

void _puts(char *s);
char *m_strcat(char *destination, char *source);
int m_strcmp(char *string1, char *string2);
int m_atoi(char *s);
char *m_strcpy(char *destination, char *source);
unsigned int m_strlen(char *s);
void m_prompt(void);
void m_EOF(char *linepointer);
char *m_gethome_dir(char **env);
char *m_getOldPwd(char **env);
void m_exit_shell(char **linepointer_copy);
void m_invok_child(char **linepointer_copy, char *name, char **env, size_t mprm);
int m_strncmp(const char *string1, const char *string2, size_t n);
int m_change_dirs(char *path, char **env);
void m_execmd(char **linepointer_copy, char *name, char **env, size_t mprm);
void m_environ_print(char **linepointer_copy, char **env);
char **m_get_pathtok(char **env);
void m_error_msg(char *name, size_t mprm, char **linepointer_copy);
char **m_parse_token(char *linepointer, const char *delimit);
void m_free_argv(char **linepointer_copy);
void m_free_before_exit(char **linepointer_copy);
void _handle(int signals);
int main(int ac, char **av, char **env);
int check_spaces(char *linepointer);

/*int errnum = 0, *p = &errnum;*/

#endif
