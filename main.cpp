#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string.h>
#include <graphics.h>

using namespace std;

int main()
{
	// pocetno
	int gdriver=DETECT;
	int gmode;
	initgraph(&gdriver, &gmode, NULL);
	setbkcolor(BLACK);
	setcolor(WHITE);
	rulesafter:
	int o,l,g,pokusaji=6,guess;
	cleardevice();
	//MAIN MENU
	settextstyle(10,HORIZ_DIR,4);
	bgiout << "VJESALA" <<endl;
	outstreamxy(240,10);
	settextstyle(10,HORIZ_DIR,2);
	bgiout << "1.START" <<endl;
	outstreamxy(240,120);
	bgiout << "2.RULES" <<endl;
	outstreamxy(240,180);
	bgiout << "3.EXIT" <<endl;
	outstreamxy(240,240);
	settextstyle(10,HORIZ_DIR,1);
	bgiout << "Upisi broj pored odabira " <<endl;
	outstreamxy(5,450);
	o=getch();
	switch(o){
		case '1':{
		// IGRICA
		cleardevice();
	    line(60,400,120,400);
	    line(90,400,90,100);
	    line(90,100,180,100);
	    line(180,100,180,150);
	    string rijec;
        string Listarijeci[99];
	
		srand(time(NULL));
	    ifstream nasumicna;
	    nasumicna.open("Rijeci.txt");
	    
	    for(int i=0; i<99;i++){
	    	nasumicna>>Listarijeci[i];
	    };
	    int nasumicnibroj = rand() %100;
	    rijec = Listarijeci[nasumicnibroj];
	    nasumicna.close();
	    string upitnik(rijec.length(),'*');
	    for(int i=0;i<rijec.length();i++){
	       moveto(10+(50*i),450);
	       lineto(30+(50*i),450);
	       bgiout<<"*"<<endl;
	       outstreamxy(15+(50*i),410);
	   }
		while(pokusaji >= 0){
		bool CorrectGuess=false;
	    char guess=getch();
	    for(int i=0;i<rijec.length();i++){
	    	if(rijec[i] == guess){
	    	CorrectGuess=true;
	    	upitnik[i]=guess;
	    	bgiout << guess <<endl;
	    	outstreamxy(15+(50*i),410);
	    	}
	    }	 if(rijec==upitnik){
	       delay(2000);
	       cleardevice();
	       settextstyle(10,HORIZ_DIR,5);
	       bgiout<<"YOU WIN"<<endl;
	       outstreamxy(200,220);
	       delay(4000);
	       cleardevice();
	       settextstyle(10,HORIZ_DIR,2);
	       bgiout<<"Da li zelite nastaviti?(d/n)"<<endl;
	       outstreamxy(180,220);
	       g=getch();
	       switch(g){
	       	case 'd':{
	       		goto rulesafter;
	       		break;}
			    default:{
	       		break;}
	       }
	    }
	    
	    	if(CorrectGuess==false){
	    		bgiout << guess <<endl;
	    		outstreamxy(400+(20*pokusaji),200);
	    pokusaji--;}
	    switch(pokusaji){
	    	case 6:{
	    		break;
	    	}
	    	case 5:{
	    		circle(180,165,15);
	    		break;
	        }
	       case 4:{
	       	line(180,180,180,320);
	    	break;	
	       }
	       case 3:{
	        moveto(140,240);
		    lineto(180,200);
	       	break;
	  }
	       case 2:{
	       	moveto(220,240);
		    lineto(180,200);
		    break;
	       }
	       case 1:{
	        moveto(140,360);
		    lineto(180,320);
	       	break;
	       }
	       case 0:{
	       moveto(220,360);
		   lineto(180,320);
		   delay(1000);
		   pokusaji=-1;
		   cleardevice();
		   settextstyle(10,HORIZ_DIR,5);
		   bgiout<<"YOU LOSE"<<endl;
	       outstreamxy(200,220);
	       delay(4000);
	       cleardevice();
	       settextstyle(10,HORIZ_DIR,2);
	       bgiout<<"Da li zelite nastaviti?(d/n)"<<endl;
	       outstreamxy(180,220);
	       g=getch();
	       switch(g){
	       	case 'd':{
	       		goto rulesafter;
	       		break;}
			    default:{
	       		break;}
	       }
		 break;}
	       }
	       }
	       break;
	    }
	    //pravila
		case '2':{
		cleardevice();
		settextstyle(9,HORIZ_DIR,1);
		bgiout<<"Pravila igre su vrlo jednostavna:"<<endl;
		outstreamxy(10,120);
		bgiout<<"Program ce sam da odabere rijec."<<endl;
	    outstreamxy(10,140);
	    bgiout<<"Vi pogadate rijec."<<endl;
	    outstreamxy(10,160); 
	    bgiout<<"Sve rijeci su iz engleskoj jezika"<<endl;
		outstreamxy(10,180);
		bgiout<<"Zbog nemogucnosti pisanja nekih slova"<<endl;
		outstreamxy(10,200);
		bgiout<<"Ima te 6 pokusaja"<<endl;
	    outstreamxy(10,220);
	    bgiout<<"Da li zelite nastaviti?(d/n)"<<endl;
	    outstreamxy(10,240);
	    l=getch();
	    switch(l){
	    case 'd':
	    	goto rulesafter;
	    	break;
		default:
			break;
			  }
		}
		//EXIT
		case '3':{
			break;
		}
	}
	closegraph();
	return 0;
}

