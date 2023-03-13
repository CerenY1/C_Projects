#include <stdio.h>
#include <stdlib.h>

int printMainMenu(void){//It shows the main menu and takes input from the user.
	int option;
	printf("---------------\n");
	printf("OPERATIONS:\n");
	printf("---------------\n");
	printf("1. Seat Info\n");
	printf("2. Update Prices\n");
	printf("3. Sell a ticket\n");
	printf("4. Current cash info\n");
	printf("5. Quit\n");
	printf("Select your operation :\n");
	scanf("%d",&option);
    return (option);
	
}

void printSeatInformation(int levela,int levelb,int levelc,int leveld){//Displays the current number of seats.
	printf("Current Seat Information :\n");
	printf("                 Level A : %d\n",levela);
	printf("                 Level B : %d\n",levelb);
	printf("                 Level C : %d\n",levelc);
	printf("                 Level D : %d\n",leveld);
	
}

void printTicketPrices(int pricea,int priceb,int pricec,int priced){//Shows the current price list.
    printf("Current Price Information :\n");
    printf("                  Level A : %d\n",pricea);
    printf("                  Level B : %d\n",priceb);
    printf("                  Level C : %d\n",pricec);
    printf("                  Level D : %d\n",priced);
    
}

void CashInfo(int x){//Calculates the total money.
   printf("******************************************\n");
   printf("Current cash information : %dTL\n",x);
   printf("******************************************\n");  
	
}

int seatControl(char seatInfo,int numberOfSold,int levela,int levelb,int levelc,int leveld){//Checks whether there are enough seats in the sections.
	if(seatInfo=='A'){
		if(numberOfSold>levela){
		  
		  return (0);}//Returns 0 if there are not enough seats.
		else
		  return (1);//Returns 1 if there are enough seats		   
	}
	else if(seatInfo=='B'){
		if(numberOfSold>levelb){
		  
		  return (0);}
		else 
		  return (1);			
	}
	else if(seatInfo=='C'){
		if(numberOfSold>levelc){
		  	
		  return (0);}
		else
		  return (1);		
	}
	else if(seatInfo=='D'){
		if(numberOfSold>leveld){
		  return (0);}
		else 
		  return (1);		
	}
}

int updatePrices(char select){//It updates the money by taking input from the user.
	int new_prices;

    printf("Enter new price for Level %c :\n",select);
	scanf(" %d",&new_prices);
	return (new_prices);

	printf("Level %c ticket price is updated to %d\n",select,new_prices);
	printf("**************************************\n");
    

    	
}



int sell(char seat,int numberOfSold,int levela,int levelb,int levelc,int leveld){
	//If there is enough stock, it shows the invoice and returns the number of seats remaining.
	//If there is not enough stock, it ensures that the number of seats remains constant by stating that it is not in stock.
    int pricea,priceb,pricec,priced;
	int result;
	result=seatControl(seat,numberOfSold,levela, levelb, levelc, leveld);
	if(result==0 && seat=='A'){
	  printf("SORRY...Level A tickets are out of stock.\n");
	  levela=levela;
	  return(levela);}
	else if(result==1 && seat=='A'){
	  printf("%d Seats from Level %c is sold.\n",numberOfSold,seat);
	  levela-=numberOfSold;  
    return(levela);}
    
	else if(result==0 && seat=='B'){
	  printf("SORRY...Level B tickets are out of stock.\n");
	  levelb=levelb;
	  return(levelb);}
	else if(result==1 && seat=='B'){
	  printf("%d Seats from Level %c is sold.\n",numberOfSold,seat);
	  levelb-=numberOfSold;
	return(levelb);}
	
	else if(result==0 && seat=='C'){
	  printf("SORRY...Level C tickets are out of stock.\n");
	  levelc=levelc;
	  return(levelc);	}
	else if(result==1 && seat=='C'){
	  printf("%d Seats from Level %c is sold.\n",numberOfSold,seat);
	  levelc-=numberOfSold;
	return(levelc);}
	
	else if(result==0 && seat=='D'){
	  printf("SORRY...Level D tickets are out of stock.\n");
	  leveld=leveld;
	  return(leveld);	}
	else if(result==1 && seat=='D'){
	  printf("%d Seats from Level %c is sold.\n",numberOfSold,seat);
	  leveld-=numberOfSold;
	return(leveld);}
	 

	  }

int CalculateBill(char seat,int ticketPrice,int numberOfSold){
	//It shows the amount to be paid by multiplying the number of tickets purchased with the current ticket price.
    int money=0;
	money+=(ticketPrice*numberOfSold);
	return(money);
}



int main() {
	int option;
	int levela=40,levelb=40,levelc=40,leveld=40;
	int pricea=100,priceb=80,pricec=60,priced=40;
	int numberOfSold,new_price;
	int money=0 ,operation,x,y;
	char seat,select;
	int result;
	do{ 
	   option=printMainMenu();
	   if(option==1){//If the user selects option 1, it calls the MainMenu function.
	   	 printSeatInformation(levela,levelb,levelc,leveld);
	   }
	   else if(option==2){
	   	do{//If the user chooses option 2, it calls the updatePrices function to update the price.
	   	printf("**************************************\n");
	    printTicketPrices(pricea, priceb, pricec, priced);
        printf("**************************************\n");
	    printf("Select level to update :\n");
    	scanf(" %c",&select);
	   	new_price=updatePrices(select);
	    if(select=='A'){
    	pricea=new_price;
    	}
	    else if(select=='B'){
	    priceb=new_price;
	    }
	    else if(select=='C'){
	    pricec=new_price;
	    }
	    else if(select=='D'){
	    priced=new_price;
	    }
	    printTicketPrices(pricea, priceb, pricec, priced);
	    printf("**************************************\n");
        printf("---------------\nOPERATIONS :\n---------------\n1. Continue to update price\n2. Return main menu\nSelect your operation :\n");
        scanf("%d",&operation);
        printf("**************************************\n");
        }while(operation==1);
        
	    }
	   else if(option==3){
	   	//If there is enough stock and tickets are sold, the invoice calls the CalculateBill function and displays the number of seats remaining.
	   		do{
	   	 printSeatInformation(levela,levelb,levelc,leveld);
	   	 printTicketPrices(pricea,priceb,pricec,priced);
	   	 printf("Select level :\n");
         scanf(" %c",&seat); 
	   	 printf("Enter number of tickets for Level %c seat :\n",seat);
		 scanf(" %d",&numberOfSold);
	   	 y=sell(seat,numberOfSold,levela,levelb,levelc,leveld);
	   	 result=seatControl(seat,numberOfSold,levela, levelb, levelc, leveld);
	   	 
	   	 if(seat=='A' && result==1){
	   	 	levela=y;
	   	 	x=CalculateBill(seat,pricea,numberOfSold);
	   	 	money+=x;
	   	 	printf("Your bill is %d TL\n",x);
		 }
		 else if(seat=='B' && result==1){
		 	levelb=y;
		    x=CalculateBill(seat,priceb,numberOfSold);
		    money+=x;
		 	printf("Your bill is %d TL\n",x);
		 }
	   	 else if(seat=='C' && result==1){
	   	 	levelc=y;
		    x=CalculateBill(seat,pricec,numberOfSold);
		    money+=x;
		 	printf("Your bill is %d TL\n",x);
		 }
		 else if(seat=='D' && result==1){
		 	leveld=y;
	        x=CalculateBill(seat,priced,numberOfSold);
	        money+=x;
		 	printf("Your bill is %d TL\n",x);
		 }
	   	 printSeatInformation(levela,levelb,levelc,leveld);
	   	 printf("**************************************\n");
         printf("---------------\nOPERATIONS :\n---------------\n1. Continue to sell a ticket\n2. Return main menu\nSelect your operation :");
         scanf("%d",&operation);
         printf("**************************************\n");
     }while(operation==1);
	   }	
	   else if(option==4){//It displays the total money by calling the CashInfo function.
	   	 CashInfo(money);
	   }
	   
	}while(option!=5);
	
    CashInfo(money);	
    printf("Bye!!");	
	
	
	
	
	return 0;
}
