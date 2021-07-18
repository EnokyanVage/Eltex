#include <termios.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <signal.h>
#include <stdlib.h>
#include <curses.h>
#include <fcntl.h>
#include <errno.h>

void sig_winch(int signo)
{
    struct winsize size;
    ioctl(fileno(stdout), TIOCGWINSZ, (char *) &size);
    resizeterm(size.ws_row, size.ws_col);
    nodelay(stdscr, 1);
    while (wgetch(stdscr) != ERR);
    nodelay(stdscr, 0);
}
void myread(char **text)
{
    echo();
    int i = 0;
    int ch;
    move(0, 0);
    while ((ch = wgetch(stdscr)) != KEY_F(4)) {
        int x = 0,y = 0;
        getyx(stdscr, y, x);
        switch(ch)
        {
            case KEY_LEFT:              
			    wmove(stdscr,y, x-1);
			break;
            case KEY_RIGHT:             
                wmove( stdscr, y, x+1 );
                break;
            case KEY_UP:                
                wmove( stdscr, y-1, x );
                break;
            case KEY_DOWN:              
                wmove( stdscr, y+1, x );
                break;
            case KEY_BACKSPACE:
                getyx(stdscr, y, x);
                mvwaddch(stdscr, y, x, ' ');
                wrefresh(stdscr);
                wmove(stdscr, y, x);
                break;
            default:
                text[y][x] = (char)ch;
        }
    }
    noecho();
}
void open_file(char *filename,char **text)
{
    FILE *fp;
    fp = fopen(filename,"r");
    int i = 0;
   if (fp == NULL) perror("Error");
   else
   {
    move(0, 0);  
    while(!feof(fp) && i < 1){
        fgets(text[i], 100, fp);
        wprintw(stdscr,"%s",text[i]);
        i++;
    }
    move(0, 0);  

    fclose (fp);
   }
}
void save_file(char *filename,char **text)
{
    FILE *file;
    file = fopen(filename,"w");
    
    for(int i = 0; i < 100; i++)
    {
        for(int j = 0; j<100; j++)
        {
            if(text[i][j] != '\0')
            {
                fwrite(&text[i][j],sizeof(char),1,file);
            }
        }
    }
    fclose(file);
}

int main(int argc, char ** argv)
{
    char filename[20];
    char **text;
    text = (char**)calloc(sizeof(char*), 100);
    for(int i = 0; i < 100; i++)
    {
        text[i] = (char*)calloc(sizeof(char), 100);
    }
    initscr();
    signal(SIGWINCH, sig_winch);
    curs_set(1);
    noecho();
    keypad(stdscr, 1);
    mousemask(BUTTON1_CLICKED, NULL);
    int key;
    struct winsize size;
    ioctl(fileno(stdout), TIOCGWINSZ, (char *) &size);
    while((key = wgetch(stdscr)) != KEY_F(3))
    {
		key = wgetch(stdscr);
        refresh();
        key = getch();
        switch(key)
        {
            case KEY_F(1):
                echo();
                move(size.ws_row-1, 0); 
                printw("FILE NAME: ");
                wgetnstr(stdscr, filename, 20);
                open_file(filename,text);
                move(0, 0); 
                noecho();
                break;
            case KEY_F(2):
                echo();
                move(size.ws_row-1, 0); 
                printw("FILE NAME: ");
                wgetnstr(stdscr, filename, 20);
                save_file(filename,text);
                move(0, 0);
                noecho(); 
                break;
            case KEY_F(5):
                myread(text);
                break;
        }
    }
endwin();
exit(EXIT_SUCCESS);
}