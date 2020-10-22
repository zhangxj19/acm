#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <queue>
#include <list>
#include <string>
#include <set>
#include <algorithm>
#include <exception>
#include <curses.h>
#include <thread>
#include <functional>

#include <climits>
// #include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>


#define UP(i,x,y) for(int i = x; i <= y; i++ )
#define DOWN(i,x,y) for (int i = x; i >=y; i-- )
#define HEAD '@'
// #define BODY '@'
#define EMPTY 0
#define FULL 1
#define STARTX 10
#define STARTY 10
#define MONEY '$'

using namespace std;

char ground[24][80];
bool game_over;
int score;

char rand_body(){
	return (rand()%10 + '0');
}

void swap(char& a,char& b){
	char t = a;
	a = b;
	b = t;
}

void init_ground(){
	game_over = FALSE;
	score = 0;
	UP(i,1,22){
		UP(j,1,78){
			if( rand()%1000 > 990 ){
				ground[i][j] = rand_body();
			}
			else{
				ground[i][j] = EMPTY;
			}
		}
	}
}

void draw_ground(){
	box(stdscr,'|','-');
	UP(i,0,23){
		UP(j,0,79){
			if( ground[i][j] != EMPTY ){
				mvaddch(i,j,ground[i][j]);
			}
		}
	}
	refresh();		
}


void clearer(){
	// cout << "clearer started" << endl;
	int t = time(0);
	while(1){
		if ( time(0) - t > 3){
			clear();
			refresh();
			t = time(0);
		}
	}
}

void initial(){
	initscr();
	cbreak();
	// nonl();
	noecho();
	// intrflush(stdscr,FALSE);
	keypad(stdscr,TRUE);
	refresh();
}

class snake
{
protected:
	struct body{
		char ch;
		int x,y;
		body * next;
		body * pre;
		body(int xx,int yy,char cc):x(xx),y(yy),ch(cc),next(NULL),pre(NULL){};
	};
	body * head;
	body * rear;
	char derection;
public:
	snake(int x,int y){ //@*
		derection = 'd';
		head = new body(x,y,HEAD);
		head->next = new body(x,y-1,rand_body());
		rear = head->next;
		rear->pre = head;

	};
	// ~snake();
	void draw_snake(){
		body * p = head->next;
		mvaddch(head->x,head->y,head->ch);
		while(p){
			mvaddch(p->x,p->y,p->ch);
			p=p->next;
		}
		refresh();
	}

	void eat(){
		ground[head->x][head->y] = EMPTY;
		ground[rand()%22+1][rand()%78+1] = rand_body();
		score++;
	}

	void move(char ch){
		bool no_move = FALSE;
		switch(ch){
			case 'w':{
				if ( derection == 's' ) no_move = TRUE;
				break;
			}
			case 's':{
				if ( derection == 'w' ) no_move = TRUE;
				break;
			}
			case 'a':{
				if ( derection == 'd' ) no_move = TRUE;
				break;
			}
			case 'd':{
				if ( derection == 'a' ) no_move = TRUE;
				break;
			}
			default: no_move = TRUE; break;
		}
		if ( no_move ){
			return;
		}
		else{
			derection = ch;
		}
		switch(ch){
			case 'w':{// up
				up();
				break;
			}
			case 's':{//down
				down();
				break;
			}
			case 'a':{//left
				left();
				break;
			}
			case 'd':{//right
				right();
				break;
			}
		}
		if(head->x == 0 || head->x== 23 || head->y==0 || head->y == 79 || crush() ){
			game_over = TRUE;
			return;
		}
		if( ground[head->x][head->y] != EMPTY ){
			eat();
		}
		else{
			// body * p = rear;
			rear = rear->pre;
			rear->next = NULL;
			// delete p;
		}
		clear();
		draw_snake();
		draw_ground();
	}

	void move(){
		switch(derection){
			case 'w':{// up
				up();
				break;
			}
			case 's':{//down
				down();
				break;
			}
			case 'a':{//left
				left();
				break;
			}
			case 'd':{//right
				right();
				break;
			}
		}
		if(head->x == 0 || head->x== 23 || head->y==0 || head->y == 79 || crush() ){
			game_over = TRUE;
			return;
		}
		if(ground[head->x][head->y] != EMPTY){
			eat();
		}
		else{
			// body * p = rear;
			rear = rear->pre;
			rear->next = NULL;
			// delete p;
		}
		clear();
		draw_snake();
		draw_ground();
	}

	void auto_mover(){
		int t = clock();
		while(1){
			if( clock() - t > 100000 ){
				t = clock();
				move();
			}
			if(game_over) break;
		}		
	}
	void up(){
		int nx = (head->x)-1,ny = (head->y);
		body * p;
		if( ground[nx][ny] != EMPTY ){
			p = new body(nx,ny,ground[nx][ny]);
			p->next = head;
			head->pre = p;
			swap(p->ch,head->ch);
			head = p;
		}
		else if ( ground[nx][ny] == EMPTY ){
			p = new body(nx,ny,HEAD);
			p->next = head;
			head->pre = p;
			head = p;
			p = head->next;
			while( p->next ){
				swap(p->ch,p->next->ch);
				p = p->next;
			}
		}
	}
	void down(){
		int nx = (head->x)+1,ny = (head->y);
		body * p;
		if( ground[nx][ny] != EMPTY ){
			p = new body(nx,ny,ground[nx][ny]);
			p->next = head;
			head->pre = p;
			swap(p->ch,head->ch);
			head = p;
		}
		else if ( ground[nx][ny] == EMPTY ){
			p = new body(nx,ny,HEAD);
			p->next = head;
			head->pre = p;
			head = p;
			p = head->next;
			while( p->next ){
				swap(p->ch,p->next->ch);
				p = p->next;
			}
		}
	}
	void left(){
		int nx = (head->x),ny = (head->y)-1;
		body * p;
		if( ground[nx][ny] != EMPTY ){
			p = new body(nx,ny,ground[nx][ny]);
			p->next = head;
			head->pre = p;
			swap(p->ch,head->ch);
			head = p;
		}
		else if ( ground[nx][ny] == EMPTY ){
			p = new body(nx,ny,HEAD);
			p->next = head;
			head->pre = p;
			head = p;
			p = head->next;
			while( p->next ){
				swap(p->ch,p->next->ch);
				p = p->next;
			}
		}
	}
	void right(){
		int nx = (head->x),ny = (head->y)+1;
		body * p;
		if( ground[nx][ny] != EMPTY ){
			p = new body(nx,ny,ground[nx][ny]);
			p->next = head;
			head->pre = p;
			swap(p->ch,head->ch);
			head = p;
		}
		else if ( ground[nx][ny] == EMPTY ){
			p = new body(nx,ny,HEAD);
			p->next = head;
			head->pre = p;
			head = p;
			p = head->next;
			while( p->next ){
				swap(p->ch,p->next->ch);
				p = p->next;
			}
		}
	}	
	bool crush(){
		body * p = head->next;
		while(p){
			if( p->x == head->x && p->y == head->y ){
				return TRUE;
			}
			else{
				p = p->next;
			}
		}
		return FALSE;
	}
};

const char * int_to_char(int n){
	if ( n == 0 ) return "0";
	char * ans;
	stack<char> s;
	while ( n > 0 ){
		s.push(n%10);
		n /= 10;
	}
	int l = s.size();
	ans = new char[l];
	UP(i,0,l-1){
		ans[i] = s.top()+'0';
		s.pop();
	}
	return ans;
}

void show_end(){
	clear();
	box(stdscr,'|','-');
	mvaddstr(12,34,"Game Over");
	mvaddstr(13,34,"Your score is");
	mvaddstr(13,50,int_to_char(score));
	refresh();
	beep();
	int t = time(0);
	while(1){
		if ( time(0) - t > 1 ) break;
	}
}



int main(int argc, char const *argv[])
{
	srand(time(NULL));
	initial();
	while(1){
		init_ground();
		char ch; 
		snake s(STARTX,STARTY);
		s.draw_snake();
		draw_ground();
		thread th(&snake::auto_mover,&s);
		for(;;){
			if(game_over){
				break;
			}
			ch = getch();
			s.move(ch);
		}
		th.join();
		show_end();
		clear();
		refresh();		
	}
	endwin();
	return 0;
}
