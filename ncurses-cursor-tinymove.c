
//////////////////////////////////////////////
//////////////////////////////////////////////
// !Author:   Spartrekus
// !License:  GNU, Please distribute author, GNU info, source code, + GNU Licence
// !date:     2017 
// !Compile:  gcc -lncurses file.c -o file 
// !Run:      ./file 
//////////////////////////////////////////////
//////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/stat.h>
#include <dirent.h>
#include <sys/types.h>
#include <unistd.h> 
#include <ncurses.h>
#include <time.h>

///////////////////////////////////////////////////////////
int main( int argc, char *argv[])
{
     /////////////////////////////////////////////////
     /*
     char mybakfile[PATH_MAX];
     strncpy( mybakfile, "" , PATH_MAX );
     strncat( mybakfile , getenv( "HOME" ) , PATH_MAX - strlen( mybakfile ) -1 );
     strncat( mybakfile , "/.nsc.bak" , PATH_MAX - strlen( mybakfile ) -1 );
     */
     /////////////////////////////////////////////////
     

   char cwd[PATH_MAX];
   int posy, posx; 
   int cellx , celly;
   celly = 15; 
   cellx = 15; 
   char cellcontent[PATH_MAX];
   char clipboard[PATH_MAX];
   double clippile = 0;
   int gameover_nsc = 0;
   int i , j , foo;
   FILE *fp;
   FILE *fp1;
   FILE *fp2;

   initscr();			
   curs_set( 0 );
   int ch ; 
   int rows, cols;  
   getmaxyx( stdscr, rows, cols);

   void drawit(){
        int rows, cols;  
        getmaxyx( stdscr, rows, cols);
        erase();
        mvprintw( 5 , 5, "Hello World !!!");	/* Print Hello World		  */
        mvprintw(  celly , cellx , "#" );
        mvprintw(rows-2 , 0, "[Y=%d, X=%d]", celly , cellx );
        mvprintw(rows-1 , 0, "<Press Key to Continue>");
   }


	initscr();			/* Start curses mode 		  */
        curs_set( 0 );

        while ( gameover_nsc == 0)
        {
           drawit();
	   refresh();			/* Print it on to the real screen */
           ch = getch();
           if ( ch == 'j' ) celly+=1;
           if ( ch == 'k' ) celly-=1;
           if ( ch == 'l' ) cellx+=1;
           if ( ch == 'h' ) cellx-=1;
           if ( ch == 'q' ) gameover_nsc = 1;
           if ( ch == 'g' ) 
           {
              ch = getch(); 
              if ( ch == 'g' ) {  celly=0; cellx=0;   }
           }
 
        }

        curs_set( 1 );
	endwin();			/* End curses mode		  */
	return 0;
}




