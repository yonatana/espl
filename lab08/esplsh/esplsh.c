#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

#define BUF_LEN 1024
static char command[BUF_LEN+1];
static int argc;
static char *argv[BUF_LEN+1];

/* read command and remove end of line if present */
int read_command() {
  int len;

  if(fgets(command, BUF_LEN, stdin)) {
    len = strlen(command);
    if(len>0 && command[len-1]=='\n')
      command[len-1] = '\0';
    return 1;
  } 
  
  return 0;
}

#define NO_SEP '\0'
#define EOC '\1'

/* split the command line into arguments and fill argv with pointers
   to the arguments */
void split_command() {
  char *s, sep;
  int between;

  between = 1;
  argc = 0;
  sep = NO_SEP;
  for(s = command; *s; ++s) {
    switch(*s) {
    case '\"': case '\'':
      if(sep==NO_SEP) {
        sep = *s;
      } else if(sep==*s) {
        sep = '\0';
      } 
      break;
    case '\\':
      ++s;
      break;
    case ' ':
      if(!sep) {
        between = 1;
        *s = '\0';
        continue;
      }
      break;
    }
    if(between) {
      argv[argc++] = s;
      between = 0;
    }
  }
  argv[argc] = NULL;
}

/* expand arguments, substitute shell variable values etc. */
void expand_args() {
  char **a = argv;
  while(*a) {
    if(**a=='"' || **a=='\'') { /* TODO: quotes can be in any place */
      *a = strdup(*a);
      memmove(*a, *a+1, strlen(*a));
      (*a)[strlen(*a)-1] = 0;
    } else {
      *a = strdup(*a);
    }
    /* TODO: eliminate escapes \ */
    /* TODO: expand environment variables */
    ++a;
  }
}


/* free arguments allocated during expansion */
void free_args() {
  char **a = argv;
  while(*a) {
    free(*a);
    ++a;
  }
}

/* run an external program */
void run_program() {
  int pid, status;
  static char ststr[8];

  /* TODO: input, *****output redirection**** */
  /* TODO: pipelines */
  /* TODO: background commands */
  //find the pipe and do both program in different proceese //apge 145 http://web.ipac.caltech.edu/staff/fmasci/home/CprogramsAndExamples.pdf
   char **a = argv;
    while(*a) { 
    if( **a=='|'') {  //find the pipelines
     /* create pipe */
    if (pipe(fileids) == -1){
	fprintf(stderr, "Error creating pipe - call a plumber\n");
	exit(1);
      }
 /* fork the process */
    if (( pid = fork() ) == -1){
      fprintf(stderr, "Bad fork - use three epees taped together\n");
      exit(1);
      }
      if (pid == 0) /* child process */
      {
      close(fileids[1]); /* close write end - child will read from pipe */
      read(fileids[0], buffer, 80); /* read at most 80 chars */
      printf("%s\n", buffer); /* and print out the message */
      close(fileids[0]); /* close read end of pipe - */
      } /* when both ends are closed, pipe disappears */
      else /* parent process */
      {
      close(fileids[0]); /* close read end - parent will write to pipe */
      write(fileids[1], "Hello World!", 80);
      close(fileids[1]); /* close write end of pipe... */
      wait(&status); /* wait until child is finished else output */
      /* might appear AFTER the system prompt! */
      }
    } 

    ++a;
  }
  if((pid=fork())>0) {
    waitpid(pid, &status, 0);
    sprintf(ststr, "%d", status);
    setenv("?", ststr, 1);
  } else if(pid==0) {
      if((argc > 2)&&(*(argv[argc-2]))== '>'){
	int fd = open(argv[argc-1],O_WRONLY|O_CREAT|O_TRUNC,0644);//open the file from the last point of the command code
	dup2(fd,1);//move the output from the screen to the choosen path
	argv[argc-2]=NULL; // so we wont do "ls ^%$#^", just "ls"
	close(fd);
      }
    execvp(argv[0], argv);
    perror(argv[0]);
  } else {
    perror(getenv("SHELL")); /* problem while forking, not due to a particular program */
  }
}

int main(int _argc, char **_argv) {
  /* clear shell variables and  re-assign a minimum set */
  clearenv();
  setenv("PATH", ":/bin:/usr/bin", 1);
  setenv("PROMPT", "$ ", 1);
  setenv("SHELL", _argv[0], 1);

  signal(SIGINT, SIG_IGN); /* ignore ^C */

  while(1) {
    printf("%s", getenv("PROMPT"));
    if(!read_command())
      break;
    split_command();
    if(!argc)
      continue;
    expand_args();
    /* process builtin commands */
    if(!strcmp(argv[0],"exit")) {
      break;
    } else if(!strcmp(argv[0],"set")) {
      if(argc!=3) {
        fprintf(stderr, "set: two arguments required\n");
        continue;
      }
      setenv(argv[1], argv[2], 1);
    } else if(!strcmp(argv[0], "cd")) {
      if(argc!=2) {
        fprintf(stderr, "cd: one argument required\n");
        continue;
      }
      if(chdir(argv[1])==-1) {
        perror("cd");
      }
    } else if(!strcmp(argv[0], "pwd")) {
      if(argc!=1) {
        fprintf(stderr, "pwd: no arguments allowed\n");
        continue;
      }
      printf("%s\n", getcwd(command, BUF_LEN));
    } else {
      /* run external command */
      run_program();
    }
    free_args();
  }
  printf("\n");

  return 0;
}
    

    
