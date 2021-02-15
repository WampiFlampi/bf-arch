#include <stack>
#include <iostream>

#include "graphics/graphics.h"


using namespace std;

void iterate(int size,char sc[],vector<int> my,vector<int> mx, Window win, Window src) {
    vector<int> mem(20,0);
    stack<int> st;
    int nest = 0;
    int point = 0;
    int nav = 0;
    int line = 1;
    char out = 0;
    Window wout(60,9,50,25);
    box(wout.win,0,0);
    wout.refresh();
   

for(int n = 0;n<size;n++) {

    instruct(my,mx,sc,n,src);


    switch(nest) {
    
        
        default:
            switch(sc[n]) {
                case '[':
                    nest++;
                case ']':
                    nest--;
                    break;

                default:
                    break;
            }
            break;
        
        
        case 0:  
            switch(sc[n]) {

                 //defining languauge rules
                case '>':
                        point++;
                        break;
                case '<':
                        point--;
                        break;
                case '+':
                        mem[point]++;
                        break;
                case '-':
                        mem[point]--;
                        break;
                case '.':
                        out = mem[point];
                        wout.print(out,1,line);
                        line++;  
                        wout.refresh();
                        break;

                case '[':
                        if ( mem[point] == 0) {
                            nest = 1;

                        }else {
                            st.push(n);
                            }
                        break;
                case ']':
                        if ( mem[point] != 0) {
                            n = st.top();
                        }else {
                            st.pop();
                        }
                        break;	
            }
            break;
        }
    render(mem,point,win);	
  }
 }

