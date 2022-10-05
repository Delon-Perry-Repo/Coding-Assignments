#include <stdio.h>
#include <string.h>

int main(){
	
	 char contInput[32] = "Y";
	 unsigned short playerNum = 1;
	 enum phoneType {noPhone = 0, Home, Work, Cell};
	 enum guardianType {noGuard = 0, Mother, Father, Grandmother, Grandfather, Other};
	 char fname1[32], fname2[32], fname3[32], fname4[32], fname5[32], fname6[32], fname7[32], fname8[32], fname9[32], fname10[32];
	 char lname1[32], lname2[32], lname3[32], lname4[32], lname5[32], lname6[32], lname7[32], lname8[32], lname9[32], lname10[32];
	 char fpname1[32], fpname2[32], fpname3[32], fpname4[32], fpname5[32], fpname6[32], fpname7[32], fpname8[32], fpname9[32], fpname10[32];
	 char lpname1[32], lpname2[32], lpname3[32], lpname4[32], lpname5[32], lpname6[32], lpname7[32], lpname8[32], lpname9[32], lpname10[32];
	 char streetName1[32], streetName2[32], streetName3[32], streetName4[32], streetName5[32], streetName6[32], streetName7[32], streetName8[32], streetName9[32], streetName10[32];
	 char phoneNum1[32], phoneNum2[32], phoneNum3[32], phoneNum4[32], phoneNum5[32], phoneNum6[32], phoneNum7[32], phoneNum8[32], phoneNum9[32], phoneNum10[32];
	 char city1[64], city2[64], city3[64], city4[64], city5[64], city6[64], city7[64], city8[64], city9[64], city10[64];
	 unsigned short streetNum1, streetNum2, streetNum3, streetNum4, streetNum5, streetNum6, streetNum7, streetNum8, streetNum9, streetNum10;
	 unsigned short birthYear1, birthYear2, birthYear3, birthYear4, birthYear5, birthYear6, birthYear7, birthYear8, birthYear9, birthYear10;
	 unsigned short phoneType1 = 0, phoneType2 = 0, phoneType3 = 0, phoneType4 = 0, phoneType5 = 0, phoneType6 = 0, phoneType7 = 0, phoneType8 = 0, phoneType9 = 0, phoneType10 = 0;
	 unsigned short parType1 = 0, parType2 = 0, parType3 = 0, parType4 = 0, parType5 = 0, parType6 = 0, parType7 = 0, parType8 = 0, parType9 = 0, parType10 = 0;
	 
	 while(*contInput == 'Y'){
	     
	     switch(playerNum){
	         
		 case 1 :
		 do{
		 printf("What is Player %d's first name?: ", playerNum);
		 scanf("%s", fname1);
		 if(strlen(fname1) > 32)
				printf("First name cannot be longer than 32 characters.\n");
		 }while(strlen(fname1) > 32);
		 
		 do{
		 printf("What is Player %d's last name?: ", playerNum);
		 scanf("%s", lname1);
		 if(strlen(lname1) > 32)
				printf("Last name cannot be longer than 32 characters.\n");
		 }while(strlen(lname1) > 32);
		 
		 do{
		 printf("What is Player %d's street number?: ", playerNum);
		 scanf("%hu", &streetNum1);
		 if(streetNum1 < 1 || streetNum1 > 9999){
				printf("Invalid street number.\n");
				scanf("%*[^\n]");
		 }
	     }while(streetNum1 < 1 || streetNum1 > 9999);
		 
		 do{
		 printf("What is Player %d's street name?: ", playerNum);
		 scanf(" %[^\n]s", streetName1);
		 if(strlen(streetName1) > 32)
				printf("Street name cannot be longer than 32 characters.\n");
		 }while(strlen(streetName1) > 32);
		 
		 do{
		 printf("What is Player %d's city?: ", playerNum); 
		 scanf(" %[^\n]s", city1);
		 if(strlen(city1) > 64)
				printf("City name cannot be longer than 64 characters.\n");
		 }while(strlen(city1) > 64);
		 
		 do{
		 printf("What is Player %d's date of birth?: ", playerNum);
		 scanf("%hu", &birthYear1);
		 if(birthYear1 < 2010 || birthYear1 > 2013){
				printf("Birth year must be between the years 2010 and 2013.\n");
				scanf("%*[^\n]");
		 }
		 }while(birthYear1 < 2010 || birthYear1 > 2013);
		 
		 do{
		 printf("What is the first name of Player %d's guardian?: ", playerNum);
		 scanf("%s", fpname1);
		 if(strlen(fpname1) > 32)
				printf("First name cannot be longer than 32 characters.\n");
		 }while(strlen(fpname1) > 32);
		 
		 do{
	     printf("What is the last name of Player %d's guardian?: ", playerNum);
		 scanf("%s", lpname1);
		 if(strlen(lpname1) > 32)
				printf("Last name cannot be longer than 32 characters.\n");
		 }while(strlen(lpname1) > 32);
		 
		 do{
		 printf("What is the phone number of Player %d's guardian? (XXX-XXX-XXXX): ", playerNum);
		 scanf("%s", phoneNum1);
		 if(strlen(phoneNum1) > 12 || strlen(phoneNum1) < 12)
				printf("Invalid phone number.\n");
		 }while(strlen(phoneNum1) > 12 || strlen(phoneNum1) < 12);
		 
		 do{
		 printf("What is the phone type of Player %d's guardian? (1-Home, 2-Work, 3-Cell): ", playerNum);
		 scanf("%hu", &phoneType1);
		  if((enum phoneType)phoneType1 < Home || phoneType1 > Cell){
				printf("Invalid phone type.\n");
				scanf("%*[^\n]");
		  }
		 }while((enum phoneType)phoneType1 < Home || phoneType1 > Cell);
			 
		 do{
		 printf("What is the guardian's relation to Player %d? (1-Mother, 2-Father, 3-Grandmother, 4-Grandfather, 5-Other): ", playerNum);
		 scanf("%hu", &parType1);
		  if((enum guardianType)parType1 > Other || parType1 < Mother){
				printf("Invalid guardian type.\n");
				scanf("%*[^\n]");
		  }
		 }while((enum guardianType)parType1 > Other || parType1 < Mother);
		 break;
		 
		 case 2:
		 do{
		 printf("What is Player %d's first name?: ", playerNum);
		 scanf("%s", fname2);
		 if(strlen(fname2) > 32)
				printf("First name cannot be longer than 32 characters.\n");
		 }while(strlen(fname2) > 32);
		 
		 do{
		 printf("What is Player %d's last name?: ", playerNum);
		 scanf("%s", lname2);
		 if(strlen(lname2) > 32)
				printf("Last name cannot be longer than 32 characters.\n");
		 }while(strlen(lname2) > 32);
		 
		 do{
		 printf("What is Player %d's street number?: ", playerNum);
		 scanf("%hu", &streetNum2);
		 if(streetNum2 < 1 || streetNum2 > 9999){
				printf("Invalid street number.\n");
				scanf("%*[^\n]");
		 }
	     }while(streetNum2 < 1 || streetNum2 > 9999);
		 
		 do{
		 printf("What is Player %d's street name?: ", playerNum);
		 scanf(" %[^\n]s", streetName2);
		 if(strlen(streetName2) > 32)
				printf("Street name cannot be longer than 32 characters.\n");
		 }while(strlen(streetName2) > 32);
		 
		 do{
		 printf("What is Player %d's city?: ", playerNum); 
		 scanf(" %[^\n]s", city2);
		 if(strlen(city2) > 64)
				printf("City name cannot be longer than 64 characters.\n");
		 }while(strlen(city2) > 64);
		 
		 do{
		 printf("What is Player %d's date of birth?: ", playerNum);
		 scanf("%hu", &birthYear2);
		 if(birthYear2 < 2010 || birthYear2 > 2013){
				printf("Birth year must be between the years 2010 and 2013.\n");
				scanf("%*[^\n]");
		 }
		 }while(birthYear2 < 2010 || birthYear2 > 2013);
		 
		 do{
		 printf("What is the first name of Player %d's guardian?: ", playerNum);
		 scanf("%s", fpname2);
		 if(strlen(fpname2) > 32)
				printf("First name cannot be longer than 32 characters.\n");
		 }while(strlen(fpname2) > 32);
		 
		 do{
	     printf("What is the last name of Player %d's guardian?: ", playerNum);
		 scanf("%s", lpname2);
		 if(strlen(lpname2) > 32)
				printf("Last name cannot be longer than 32 characters.\n");
		 }while(strlen(lpname2) > 32);
		 
		 do{
		 printf("What is the phone number of Player %d's guardian? (XXX-XXX-XXXX): ", playerNum);
		 scanf("%s", phoneNum2);
		 if(strlen(phoneNum2) > 12 || strlen(phoneNum2) < 12)
				printf("Invalid phone number.\n");
		 }while(strlen(phoneNum2) > 12 || strlen(phoneNum2) < 12);
		 
		 do{
		 printf("What is the phone type of Player %d's guardian? (1-Home, 2-Work, 3-Cell): ", playerNum);
		 scanf("%hu", &phoneType2);
		  if((enum phoneType)phoneType2 < Home || phoneType2 > Cell){
				printf("Invalid phone type.\n");
				scanf("%*[^\n]");
		  }
		 }while((enum phoneType)phoneType2 < Home || phoneType2 > Cell);
			 
		 do{
		 printf("What is the guardian's relation to Player %d? (1-Mother, 2-Father, 3-Grandmother, 4-Grandfather, 5-Other): ", playerNum);
		 scanf("%hu", &parType2);
		  if((enum guardianType)parType2 > Other || parType2 < Mother){
				printf("Invalid guardian type.\n");
				scanf("%*[^\n]");
		  }
		 }while((enum guardianType)parType2 > Other || parType2 < Mother);
		 break;
		 
		 case 3 :
		 do{
		 printf("What is Player %d's first name?: ", playerNum);
		 scanf("%s", fname3);
		 if(strlen(fname3) > 32)
				printf("First name cannot be longer than 32 characters.\n");
		 }while(strlen(fname3) > 32);
		 
		 do{
		 printf("What is Player %d's last name?: ", playerNum);
		 scanf("%s", lname3);
		 if(strlen(lname3) > 32)
				printf("Last name cannot be longer than 32 characters.\n");
		 }while(strlen(lname3) > 32);
		 
		 do{
		 printf("What is Player %d's street number?: ", playerNum);
		 scanf("%hu", &streetNum3);
		 if(streetNum3 < 3 || streetNum3 > 9999){
				printf("Invalid street number.\n");
				scanf("%*[^\n]");
		 }
	     }while(streetNum3 < 1 || streetNum3 > 9999);
		 
		 do{
		 printf("What is Player %d's street name?: ", playerNum);
		 scanf(" %[^\n]s", streetName3);
		 if(strlen(streetName3) > 32)
				printf("Street name cannot be longer than 32 characters.\n");
		 }while(strlen(streetName3) > 32);
		 
		 do{
		 printf("What is Player %d's city?: ", playerNum); 
		 scanf(" %[^\n]s", city3);
		 if(strlen(city3) > 64)
				printf("City name cannot be longer than 64 characters.\n");
		 }while(strlen(city3) > 64);
		 
		 do{
		 printf("What is Player %d's date of birth?: ", playerNum);
		 scanf("%hu", &birthYear3);
		 if(birthYear3 < 2010 || birthYear3 > 2013){
				printf("Birth year must be between the years 2010 and 2013.\n");
				scanf("%*[^\n]");
		 }
		 }while(birthYear3 < 2010 || birthYear3 > 2013);
		 
		 do{
		 printf("What is the first name of Player %d's guardian?: ", playerNum);
		 scanf("%s", fpname3);
		 if(strlen(fpname3) > 32)
				printf("First name cannot be longer than 32 characters.\n");
		 }while(strlen(fpname3) > 32);
		 
		 do{
	     printf("What is the last name of Player %d's guardian?: ", playerNum);
		 scanf("%s", lpname3);
		 if(strlen(lpname3) > 32)
				printf("Last name cannot be longer than 32 characters.\n");
		 }while(strlen(lpname3) > 32);
		 
		 do{
		 printf("What is the phone number of Player %d's guardian? (XXX-XXX-XXXX): ", playerNum);
		 scanf("%s", phoneNum3);
		 if(strlen(phoneNum3) > 12 || strlen(phoneNum3) < 12)
				printf("Invalid phone number.\n");
		 }while(strlen(phoneNum3) > 12 || strlen(phoneNum3) < 12);
		 
		 do{
		 printf("What is the phone type of Player %d's guardian? (1-Home, 2-Work, 3-Cell): ", playerNum);
		 scanf("%hu", &phoneType3);
		  if((enum phoneType)phoneType3 < Home || phoneType3 > Cell){
				printf("Invalid phone type.\n");
				scanf("%*[^\n]");
		  }
		 }while((enum phoneType)phoneType3 < Home || phoneType3 > Cell);
			 
		 do{
		 printf("What is the guardian's relation to Player %d? (1-Mother, 2-Father, 3-Grandmother, 4-Grandfather, 5-Other): ", playerNum);
		 scanf("%hu", &parType3);
		  if((enum guardianType)parType3 > Other || parType3 < Mother){
				printf("Invalid guardian type.\n");
				scanf("%*[^\n]");
		  }
		 }while((enum guardianType)parType3 > Other || parType3 < Mother);
		 break;
		 
		 case 4 :
		 do{
		 printf("What is Player %d's first name?: ", playerNum);
		 scanf("%s", fname4);
		 if(strlen(fname4) > 32)
				printf("First name cannot be longer than 32 characters.\n");
		 }while(strlen(fname4) > 32);
		 
		 do{
		 printf("What is Player %d's last name?: ", playerNum);
		 scanf("%s", lname4);
		 if(strlen(lname4) > 32)
				printf("Last name cannot be longer than 32 characters.\n");
		 }while(strlen(lname4) > 32);
		 
		 do{
		 printf("What is Player %d's street number?: ", playerNum);
		 scanf("%hu", &streetNum4);
		 if(streetNum4 < 1 || streetNum4 > 9999){
				printf("Invalid street number.\n");
				scanf("%*[^\n]");
		 }
	     }while(streetNum4 < 1 || streetNum4 > 9999);
		 
		 do{
		 printf("What is Player %d's street name?: ", playerNum);
		 scanf(" %[^\n]s", streetName4);
		 if(strlen(streetName4) > 32)
				printf("Street name cannot be longer than 32 characters.\n");
		 }while(strlen(streetName4) > 32);
		 
		 do{
		 printf("What is Player %d's city?: ", playerNum); 
		 scanf(" %[^\n]s", city4);
		 if(strlen(city4) > 64)
				printf("City name cannot be longer than 64 characters.\n");
		 }while(strlen(city4) > 64);
		 
		 do{
		 printf("What is Player %d's date of birth?: ", playerNum);
		 scanf("%hu", &birthYear4);
		 if(birthYear4 < 2010 || birthYear4 > 2013){
				printf("Birth year must be between the years 2010 and 2013.\n");
				scanf("%*[^\n]");
		 }
		 }while(birthYear4 < 2010 || birthYear4 > 2013);
		 
		 do{
		 printf("What is the first name of Player %d's guardian?: ", playerNum);
		 scanf("%s", fpname4);
		 if(strlen(fpname4) > 32)
				printf("First name cannot be longer than 32 characters.\n");
		 }while(strlen(fpname4) > 32);
		 
		 do{
	     printf("What is the last name of Player %d's guardian?: ", playerNum);
		 scanf("%s", lpname4);
		 if(strlen(lpname4) > 32)
				printf("Last name cannot be longer than 32 characters.\n");
		 }while(strlen(lpname4) > 32);
		 
		 do{
		 printf("What is the phone number of Player %d's guardian? (XXX-XXX-XXXX): ", playerNum);
		 scanf("%s", phoneNum4);
		 if(strlen(phoneNum4) > 12 || strlen(phoneNum4) < 12)
				printf("Invalid phone number.\n");
		 }while(strlen(phoneNum4) > 12 || strlen(phoneNum4) < 12);
		 
		 do{
		 printf("What is the phone type of Player %d's guardian? (1-Home, 2-Work, 3-Cell): ", playerNum);
		 scanf("%hu", &phoneType4);
		  if((enum phoneType)phoneType4 < Home || phoneType4 > Cell){
				printf("Invalid phone type.\n");
				scanf("%*[^\n]");
		  }
		 }while((enum phoneType)phoneType4 < Home || phoneType4 > Cell);
			 
		 do{
		 printf("What is the guardian's relation to Player %d? (1-Mother, 2-Father, 3-Grandmother, 4-Grandfather, 5-Other): ", playerNum);
		 scanf("%hu", &parType4);
		  if((enum guardianType)parType4 > Other || parType4 < Mother){
				printf("Invalid guardian type.\n");
				scanf("%*[^\n]");
		  }
		 }while((enum guardianType)parType4 > Other || parType4 < Mother);
		 break;
		 
		 case 5 :
		 do{
		 printf("What is Player %d's first name?: ", playerNum);
		 scanf("%s", fname5);
		 if(strlen(fname5) > 32)
				printf("First name cannot be longer than 32 characters.\n");
		 }while(strlen(fname5) > 32);
		 
		 do{
		 printf("What is Player %d's last name?: ", playerNum);
		 scanf("%s", lname5);
		 if(strlen(lname5) > 32)
				printf("Last name cannot be longer than 32 characters.\n");
		 }while(strlen(lname5) > 32);
		 
		 do{
		 printf("What is Player %d's street number?: ", playerNum);
		 scanf("%hu", &streetNum5);
		 if(streetNum5 < 1 || streetNum5 > 9999){
				printf("Invalid street number.\n");
				scanf("%*[^\n]");
		 }
	     }while(streetNum5 < 1 || streetNum5 > 9999);
		 
		 do{
		 printf("What is Player %d's street name?: ", playerNum);
		 scanf(" %[^\n]s", streetName5);
		 if(strlen(streetName5) > 32)
				printf("Street name cannot be longer than 32 characters.\n");
		 }while(strlen(streetName5) > 32);
		 
		 do{
		 printf("What is Player %d's city?: ", playerNum); 
		 scanf(" %[^\n]s", city5);
		 if(strlen(city5) > 64)
				printf("City name cannot be longer than 64 characters.\n");
		 }while(strlen(city5) > 64);
		 
		 do{
		 printf("What is Player %d's date of birth?: ", playerNum);
		 scanf("%hu", &birthYear5);
		 if(birthYear5 < 2010 || birthYear5 > 2013){
				printf("Birth year must be between the years 2010 and 2013.\n");
				scanf("%*[^\n]");
		 }
		 }while(birthYear5 < 2010 || birthYear5 > 2013);
		 
		 do{
		 printf("What is the first name of Player %d's guardian?: ", playerNum);
		 scanf("%s", fpname5);
		 if(strlen(fpname5) > 32)
				printf("First name cannot be longer than 32 characters.\n");
		 }while(strlen(fpname5) > 32);
		 
		 do{
	     printf("What is the last name of Player %d's guardian?: ", playerNum);
		 scanf("%s", lpname5);
		 if(strlen(lpname5) > 32)
				printf("Last name cannot be longer than 32 characters.\n");
		 }while(strlen(lpname5) > 32);
		 
		 do{
		 printf("What is the phone number of Player %d's guardian? (XXX-XXX-XXXX): ", playerNum);
		 scanf("%s", phoneNum5);
		 if(strlen(phoneNum5) > 12 || strlen(phoneNum5) < 12)
				printf("Invalid phone number.\n");
		 }while(strlen(phoneNum5) > 12 || strlen(phoneNum5) < 12);
		 
		 do{
		 printf("What is the phone type of Player %d's guardian? (1-Home, 2-Work, 3-Cell): ", playerNum);
		 scanf("%hu", &phoneType5);
		  if((enum phoneType)phoneType5 < Home || phoneType5 > Cell){
				printf("Invalid phone type.\n");
				scanf("%*[^\n]");
		  }
		 }while((enum phoneType)phoneType5 < Home || phoneType5 > Cell);
			 
		 do{
		 printf("What is the guardian's relation to Player %d? (1-Mother, 2-Father, 3-Grandmother, 4-Grandfather, 5-Other): ", playerNum);
		 scanf("%hu", &parType5);
		  if((enum guardianType)parType5 > Other || parType5 < Mother){
				printf("Invalid guardian type.\n");
				scanf("%*[^\n]");
		  }
		 }while((enum guardianType)parType5 > Other || parType5 < Mother);
		 break;
		 
		 case 6 :
		 do{
		 printf("What is Player %d's first name?: ", playerNum);
		 scanf("%s", fname6);
		 if(strlen(fname6) > 32)
				printf("First name cannot be longer than 32 characters.\n");
		 }while(strlen(fname6) > 32);
		 
		 do{
		 printf("What is Player %d's last name?: ", playerNum);
		 scanf("%s", lname6);
		 if(strlen(lname6) > 32)
				printf("Last name cannot be longer than 32 characters.\n");
		 }while(strlen(lname6) > 32);
		 
		 do{
		 printf("What is Player %d's street number?: ", playerNum);
		 scanf("%hu", &streetNum6);
		 if(streetNum6 < 1 || streetNum6 > 9999){
				printf("Invalid street number.\n");
				scanf("%*[^\n]");
		 }
	     }while(streetNum6 < 1 || streetNum6 > 9999);
		 
		 do{
		 printf("What is Player %d's street name?: ", playerNum);
		 scanf(" %[^\n]s", streetName6);
		 if(strlen(streetName6) > 32)
				printf("Street name cannot be longer than 32 characters.\n");
		 }while(strlen(streetName6) > 32);
		 
		 do{
		 printf("What is Player %d's city?: ", playerNum); 
		 scanf(" %[^\n]s", city6);
		 if(strlen(city6) > 64)
				printf("City name cannot be longer than 64 characters.\n");
		 }while(strlen(city6) > 64);
		 
		 do{
		 printf("What is Player %d's date of birth?: ", playerNum);
		 scanf("%hu", &birthYear6);
		 if(birthYear6 < 2010 || birthYear6 > 2013){
				printf("Birth year must be between the years 2010 and 2013.\n");
				scanf("%*[^\n]");
		 }
		 }while(birthYear6 < 2010 || birthYear6 > 2013);
		 
		 do{
		 printf("What is the first name of Player %d's guardian?: ", playerNum);
		 scanf("%s", fpname6);
		 if(strlen(fpname6) > 32)
				printf("First name cannot be longer than 32 characters.\n");
		 }while(strlen(fpname6) > 32);
		 
		 do{
	     printf("What is the last name of Player %d's guardian?: ", playerNum);
		 scanf("%s", lpname6);
		 if(strlen(lpname6) > 32)
				printf("Last name cannot be longer than 32 characters.\n");
		 }while(strlen(lpname6) > 32);
		 
		 do{
		 printf("What is the phone number of Player %d's guardian? (XXX-XXX-XXXX): ", playerNum);
		 scanf("%s", phoneNum6);
		 if(strlen(phoneNum6) > 12 || strlen(phoneNum6) < 12)
				printf("Invalid phone number.\n");
		 }while(strlen(phoneNum6) > 12 || strlen(phoneNum6) < 12);
		 
		 do{
		 printf("What is the phone type of Player %d's guardian? (1-Home, 2-Work, 3-Cell): ", playerNum);
		 scanf("%hu", &phoneType6);
		  if((enum phoneType)phoneType6 < Home || phoneType6 > Cell){
				printf("Invalid phone type.\n");
				scanf("%*[^\n]");
		  }
		 }while((enum phoneType)phoneType6 < Home || phoneType6 > Cell);
			 
		 do{
		 printf("What is the guardian's relation to Player %d? (1-Mother, 2-Father, 3-Grandmother, 4-Grandfather, 5-Other): ", playerNum);
		 scanf("%hu", &parType6);
		  if((enum guardianType)parType6 > Other || parType6 < Mother){
				printf("Invalid guardian type.\n");
				scanf("%*[^\n]");
		  }
		 }while((enum guardianType)parType6 > Other || parType6 < Mother);
		 break;
		 
		 case 7 :
		 do{
		 printf("What is Player %d's first name?: ", playerNum);
		 scanf("%s", fname7);
		 if(strlen(fname7) > 32)
				printf("First name cannot be longer than 32 characters.\n");
		 }while(strlen(fname7) > 32);
		 
		 do{
		 printf("What is Player %d's last name?: ", playerNum);
		 scanf("%s", lname7);
		 if(strlen(lname7) > 32)
				printf("Last name cannot be longer than 32 characters.\n");
		 }while(strlen(lname7) > 32);
		 
		 do{
		 printf("What is Player %d's street number?: ", playerNum);
		 scanf("%hu", &streetNum7);
		 if(streetNum7 < 1 || streetNum7 > 9999){
				printf("Invalid street number.\n");
				scanf("%*[^\n]");
		 }
	     }while(streetNum7 < 1 || streetNum7 > 9999);
		 
		 do{
		 printf("What is Player %d's street name?: ", playerNum);
		 scanf(" %[^\n]s", streetName7);
		 if(strlen(streetName7) > 32)
				printf("Street name cannot be longer than 32 characters.\n");
		 }while(strlen(streetName7) > 32);
		 
		 do{
		 printf("What is Player %d's city?: ", playerNum); 
		 scanf(" %[^\n]s", city7);
		 if(strlen(city7) > 64)
				printf("City name cannot be longer than 64 characters.\n");
		 }while(strlen(city7) > 64);
		 
		 do{
		 printf("What is Player %d's date of birth?: ", playerNum);
		 scanf("%hu", &birthYear7);
		 if(birthYear7 < 2010 || birthYear7 > 2013){
				printf("Birth year must be between the years 2010 and 2013.\n");
				scanf("%*[^\n]");
		 }
		 }while(birthYear7 < 2010 || birthYear7 > 2013);
		 
		 do{
		 printf("What is the first name of Player %d's guardian?: ", playerNum);
		 scanf("%s", fpname7);
		 if(strlen(fpname7) > 32)
				printf("First name cannot be longer than 32 characters.\n");
		 }while(strlen(fpname7) > 32);
		 
		 do{
	     printf("What is the last name of Player %d's guardian?: ", playerNum);
		 scanf("%s", lpname7);
		 if(strlen(lpname7) > 32)
				printf("Last name cannot be longer than 32 characters.\n");
		 }while(strlen(lpname7) > 32);
		 
		 do{
		 printf("What is the phone number of Player %d's guardian? (XXX-XXX-XXXX): ", playerNum);
		 scanf("%s", phoneNum7);
		 if(strlen(phoneNum7) > 12 || strlen(phoneNum7) < 12)
				printf("Invalid phone number.\n");
		 }while(strlen(phoneNum7) > 12 || strlen(phoneNum7) < 12);
		 
		 do{
		 printf("What is the phone type of Player %d's guardian? (1-Home, 2-Work, 3-Cell): ", playerNum);
		 scanf("%hu", &phoneType7);
		  if((enum phoneType)phoneType7 < Home || phoneType7 > Cell){
				printf("Invalid phone type.\n");
				scanf("%*[^\n]");
		  }
		 }while((enum phoneType)phoneType7 < Home || phoneType7 > Cell);
			 
		 do{
		 printf("What is the guardian's relation to Player %d? (1-Mother, 2-Father, 3-Grandmother, 4-Grandfather, 5-Other): ", playerNum);
		 scanf("%hu", &parType7);
		  if((enum guardianType)parType7 > Other || parType7 < Mother){
				printf("Invalid guardian type.\n");
				scanf("%*[^\n]");
		  }
		 }while((enum guardianType)parType7 > Other || parType7 < Mother);
		 break;
		 
		 case 8 :
		 do{
		 printf("What is Player %d's first name?: ", playerNum);
		 scanf("%s", fname8);
		 if(strlen(fname8) > 32)
				printf("First name cannot be longer than 32 characters.\n");
		 }while(strlen(fname8) > 32);
		 
		 do{
		 printf("What is Player %d's last name?: ", playerNum);
		 scanf("%s", lname8);
		 if(strlen(lname8) > 32)
				printf("Last name cannot be longer than 32 characters.\n");
		 }while(strlen(lname8) > 32);
		 
		 do{
		 printf("What is Player %d's street number?: ", playerNum);
		 scanf("%hu", &streetNum8);
		 if(streetNum8 < 1 || streetNum8 > 9999){
				printf("Invalid street number.\n");
				scanf("%*[^\n]");
		 }
	     }while(streetNum8 < 1 || streetNum8 > 9999);
		 
		 do{
		 printf("What is Player %d's street name?: ", playerNum);
		 scanf(" %[^\n]s", streetName8);
		 if(strlen(streetName8) > 32)
				printf("Street name cannot be longer than 32 characters.\n");
		 }while(strlen(streetName8) > 32);
		 
		 do{
		 printf("What is Player %d's city?: ", playerNum); 
		 scanf(" %[^\n]s", city8);
		 if(strlen(city8) > 64)
				printf("City name cannot be longer than 64 characters.\n");
		 }while(strlen(city8) > 64);
		 
		 do{
		 printf("What is Player %d's date of birth?: ", playerNum);
		 scanf("%hu", &birthYear8);
		 if(birthYear8 < 2010 || birthYear8 > 2013){
				printf("Birth year must be between the years 2010 and 2013.\n");
				scanf("%*[^\n]");
		 }
		 }while(birthYear8 < 2010 || birthYear8 > 2013);
		 
		 do{
		 printf("What is the first name of Player %d's guardian?: ", playerNum);
		 scanf("%s", fpname8);
		 if(strlen(fpname8) > 32)
				printf("First name cannot be longer than 32 characters.\n");
		 }while(strlen(fpname8) > 32);
		 
		 do{
	     printf("What is the last name of Player %d's guardian?: ", playerNum);
		 scanf("%s", lpname8);
		 if(strlen(lpname8) > 32)
				printf("Last name cannot be longer than 32 characters.\n");
		 }while(strlen(lpname8) > 32);
		 
		 do{
		 printf("What is the phone number of Player %d's guardian? (XXX-XXX-XXXX): ", playerNum);
		 scanf("%s", phoneNum8);
		 if(strlen(phoneNum8) > 12 || strlen(phoneNum8) < 12)
				printf("Invalid phone number.\n");
		 }while(strlen(phoneNum8) > 12 || strlen(phoneNum8) < 12);
		 
		 do{
		 printf("What is the phone type of Player %d's guardian? (1-Home, 2-Work, 3-Cell): ", playerNum);
		 scanf("%hu", &phoneType8);
		  if((enum phoneType)phoneType8 < Home || phoneType8 > Cell){
				printf("Invalid phone type.\n");
				scanf("%*[^\n]");
		  }
		 }while((enum phoneType)phoneType8 < Home || phoneType8 > Cell);
			 
		 do{
		 printf("What is the guardian's relation to Player %d? (1-Mother, 2-Father, 3-Grandmother, 4-Grandfather, 5-Other): ", playerNum);
		 scanf("%hu", &parType8);
		  if((enum guardianType)parType8 > Other || parType8 < Mother){
				printf("Invalid guardian type.\n");
				scanf("%*[^\n]");
		  }
		 }while((enum guardianType)parType8 > Other || parType8 < Mother);
		 break;
		 
		 case 9 :
		 do{
		 printf("What is Player %d's first name?: ", playerNum);
		 scanf("%s", fname9);
		 if(strlen(fname9) > 32)
				printf("First name cannot be longer than 32 characters.\n");
		 }while(strlen(fname9) > 32);
		 
		 do{
		 printf("What is Player %d's last name?: ", playerNum);
		 scanf("%s", lname9);
		 if(strlen(lname9) > 32)
				printf("Last name cannot be longer than 32 characters.\n");
		 }while(strlen(lname9) > 32);
		 
		 do{
		 printf("What is Player %d's street number?: ", playerNum);
		 scanf("%hu", &streetNum9);
		 if(streetNum9 < 1 || streetNum9 > 9999){
				printf("Invalid street number.\n");
				scanf("%*[^\n]");
		 }
	     }while(streetNum9 < 1 || streetNum9 > 9999);
		 
		 do{
		 printf("What is Player %d's street name?: ", playerNum);
		 scanf(" %[^\n]s", streetName9);
		 if(strlen(streetName9) > 32)
				printf("Street name cannot be longer than 32 characters.\n");
		 }while(strlen(streetName9) > 32);
		 
		 do{
		 printf("What is Player %d's city?: ", playerNum); 
		 scanf(" %[^\n]s", city9);
		 if(strlen(city9) > 64)
				printf("City name cannot be longer than 64 characters.\n");
		 }while(strlen(city9) > 64);
		 
		 do{
		 printf("What is Player %d's date of birth?: ", playerNum);
		 scanf("%hu", &birthYear9);
		 if(birthYear9 < 2010 || birthYear9 > 2013){
				printf("Birth year must be between the years 2010 and 2013.\n");
				scanf("%*[^\n]");
		 }
		 }while(birthYear9 < 2010 || birthYear9 > 2013);
		 
		 do{
		 printf("What is the first name of Player %d's guardian?: ", playerNum);
		 scanf("%s", fpname9);
		 if(strlen(fpname9) > 32)
				printf("First name cannot be longer than 32 characters.\n");
		 }while(strlen(fpname9) > 32);
		 
		 do{
	     printf("What is the last name of Player %d's guardian?: ", playerNum);
		 scanf("%s", lpname9);
		 if(strlen(lpname9) > 32)
				printf("Last name cannot be longer than 32 characters.\n");
		 }while(strlen(lpname9) > 32);
		 
		 do{
		 printf("What is the phone number of Player %d's guardian? (XXX-XXX-XXXX): ", playerNum);
		 scanf("%s", phoneNum9);
		 if(strlen(phoneNum9) > 12 || strlen(phoneNum9) < 12)
				printf("Invalid phone number.\n");
		 }while(strlen(phoneNum9) > 12 || strlen(phoneNum9) < 12);
		 
		 do{
		 printf("What is the phone type of Player %d's guardian? (1-Home, 2-Work, 3-Cell): ", playerNum);
		 scanf("%hu", &phoneType9);
		  if((enum phoneType)phoneType9 < Home || phoneType9 > Cell){
				printf("Invalid phone type.\n");
				scanf("%*[^\n]");
		  }
		 }while((enum phoneType)phoneType9 < Home || phoneType9 > Cell);
			 
		 do{
		 printf("What is the guardian's relation to Player %d? (1-Mother, 2-Father, 3-Grandmother, 4-Grandfather, 5-Other): ", playerNum);
		 scanf("%hu", &parType9);
		  if((enum guardianType)parType9 > Other || parType9 < Mother){
				printf("Invalid guardian type.\n");
				scanf("%*[^\n]");
		  }
		 }while((enum guardianType)parType9 > Other || parType9 < Mother);
		 break;
		 
		 default :
		 do{
		 printf("What is Player %d's first name?: ", playerNum);
		 scanf("%s", fname10);
		 if(strlen(fname10) > 32)
				printf("First name cannot be longer than 32 characters.\n");
		 }while(strlen(fname10) > 32);
		 
		 do{
		 printf("What is Player %d's last name?: ", playerNum);
		 scanf("%s", lname10);
		 if(strlen(lname10) > 32)
				printf("Last name cannot be longer than 32 characters.\n");
		 }while(strlen(lname10) > 32);
		 
		 do{
		 printf("What is Player %d's street number?: ", playerNum);
		 scanf("%hu", &streetNum10);
		 if(streetNum10 < 1 || streetNum10 > 9999){
				printf("Invalid street number.\n");
				scanf("%*[^\n]");
		 }
	     }while(streetNum10 < 1 || streetNum10 > 9999);
		 
		 do{
		 printf("What is Player %d's street name?: ", playerNum);
		 scanf(" %[^\n]s", streetName10);
		 if(strlen(streetName10) > 32)
				printf("Street name cannot be longer than 32 characters.\n");
		 }while(strlen(streetName10) > 32);
		 
		 do{
		 printf("What is Player %d's city?: ", playerNum); 
		 scanf(" %[^\n]s", city10);
		 if(strlen(city10) > 64)
				printf("City name cannot be longer than 64 characters.\n");
		 }while(strlen(city10) > 64);
		 
		 do{
		 printf("What is Player %d's date of birth?: ", playerNum);
		 scanf("%hu", &birthYear10);
		 if(birthYear10 < 2010 || birthYear10 > 2013){
				printf("Birth year must be between the years 2010 and 2013.\n");
				scanf("%*[^\n]");
		 }
		 }while(birthYear10 < 2010 || birthYear10 > 2013);
		 
		 do{
		 printf("What is the first name of Player %d's guardian?: ", playerNum);
		 scanf("%s", fpname10);
		 if(strlen(fpname10) > 32)
				printf("First name cannot be longer than 32 characters.\n");
		 }while(strlen(fpname10) > 32);
		 
		 do{
	     printf("What is the last name of Player %d's guardian?: ", playerNum);
		 scanf("%s", lpname10);
		 if(strlen(lpname10) > 32)
				printf("Last name cannot be longer than 32 characters.\n");
		 }while(strlen(lpname10) > 32);
		 
		 do{
		 printf("What is the phone number of Player %d's guardian? (XXX-XXX-XXXX): ", playerNum);
		 scanf("%s", phoneNum10);
		 if(strlen(phoneNum10) > 12 || strlen(phoneNum10) < 12)
				printf("Invalid phone number.\n");
		 }while(strlen(phoneNum10) > 12 || strlen(phoneNum10) < 12);
		 
		 do{
		 printf("What is the phone type of Player %d's guardian? (1-Home, 2-Work, 3-Cell): ", playerNum);
		 scanf("%hu", &phoneType10);
		  if((enum phoneType)phoneType10 < Home || phoneType10 > Cell){
				printf("Invalid phone type.\n");
				scanf("%*[^\n]");
		  }
		 }while((enum phoneType)phoneType10 < Home || phoneType10 > Cell);
			 
		 do{
		 printf("What is the guardian's relation to Player %d? (1-Mother, 2-Father, 3-Grandmother, 4-Grandfather, 5-Other): ", playerNum);
		 scanf("%hu", &parType10);
		  if((enum guardianType)parType10 > Other || parType10 < Mother){
				printf("Invalid guardian type.\n");
				scanf("%*[^\n]");
		  }
		 }while((enum guardianType)parType10 > Other || parType10 < Mother);
		 break;
		 
	     }
	     
		 ++playerNum;
		 if(playerNum > 10)
			 break;
		 printf("Would you like to continue user input? (Y - Yes or N - No): ");
         scanf(" %c", contInput);
        
	 }
}	 