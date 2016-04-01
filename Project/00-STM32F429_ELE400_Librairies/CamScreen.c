

#include "CamScreen.h"
#include "CamProcessScreen.h"


/* TM_STMPE811_TouchData instance */
	TM_STMPE811_TouchData touchData;
/* TM_ILI9341_Button_t instance */
	TM_ILI9341_Button_t button;
	int8_t buttonPressed, button1, button2, button3, button4,button5, button6;
	
char str[30];	
int i;



extern void EcranAccueil(void){
	
	/* Clear LCD */
	ClrScreen();
	/* Delete Bouton existant */
	TM_ILI9341_Button_DeleteAll();
	
	TM_ILI9341_Puts(50, 90, "SkyRunner", &TM_Font_16x26, ILI9341_COLOR_GRAY, ILI9341_COLOR_RED);
	TM_ILI9341_Puts(35,180, "Camera sur cable", &TM_Font_11x18, ILI9341_COLOR_RED, ILI9341_COLOR_GRAY);
	TM_ILI9341_Puts(35,230, "Appuyer sur une touche", &TM_Font_7x10, ILI9341_COLOR_RED, ILI9341_COLOR_GRAY);
	TM_ILI9341_Puts(65,240, "pour commencer", &TM_Font_7x10, ILI9341_COLOR_RED, ILI9341_COLOR_GRAY);
	while(1){
		if (TM_STMPE811_ReadTouch(&touchData) == TM_STMPE811_State_Pressed) {
			
			ClrScreen();
			//TM_ILI9341_Puts(35, 260, "Camera sur cable", &TM_Font_11x18, ILI9341_COLOR_RED, ILI9341_COLOR_GRAY);
			//break;
		}
	}
}



extern void EcranConfig(void){

	
	
	/* Clear LCD */
	ClrScreen();
	
	/* Delete Bouton existant */
	TM_ILI9341_Button_DeleteAll();
	
	/* Button1 Retour � l'acceuil, default configuration */
	/* Red with black border and black font 11x18 */
	button.x = 1;
	button.y = 279;
	button.width = 90;
	button.height = 39;
	button.background = ILI9341_COLOR_RED;
	button.borderColor = ILI9341_COLOR_BLACK;
	button.color = ILI9341_COLOR_BLACK;
	button.font = &TM_Font_7x10;
	button.flags =  TM_BUTTON_FLAG_NOLABEL;
	/* Add button */
	button1 = TM_ILI9341_Button_Add(&button);
	
	/* Button2 Envoyer la config, default configuration */
	/* Red with black border and black font 11x18 */
	button.x = 148;
	button.y = 279;
	button.width = 90;
	button.height = 39;
	button.background = ILI9341_COLOR_RED;
	button.borderColor = ILI9341_COLOR_BLACK;
	button.color = ILI9341_COLOR_BLACK;
	button.font = &TM_Font_7x10;
	button.flags =  TM_BUTTON_FLAG_NOLABEL;
	/* Add button */
	button2 = TM_ILI9341_Button_Add(&button);
	
	
	/* Button3 Up lenght cable with image: fleche_haut_18x23 */
	button.x = 25;
	button.y = 90;
	button.width = 18;
	button.height = 23;
	button.borderColor = ILI9341_COLOR_BLACK;
	/* Use background image and no label */
	button.flags = TM_BUTTON_FLAG_NOLABEL | TM_BUTTON_FLAG_IMAGE;
	button.image = Fleche_Haut_18x23; 
	/* Add button */
	button3 = TM_ILI9341_Button_Add(&button);
	
	/* Button4 Down lenght cable with image: fleche_bas_18x23 */
	button.x = 25;
	button.y = 115;
	button.width = 18;
	button.height = 23;
	button.borderColor = ILI9341_COLOR_BLACK;
	/* Use background image and no label */
	button.flags = TM_BUTTON_FLAG_NOLABEL | TM_BUTTON_FLAG_IMAGE;
	button.image = Fleche_Bas_18x23; 
	/* Add button */
	button4 = TM_ILI9341_Button_Add(&button);
	
	/* Button5 Up accelaration with image: fleche_haut_18x23 */
	button.x = 25;
	button.y = 175;
	button.width = 18;
	button.height = 23;
	button.borderColor = ILI9341_COLOR_BLACK;
	/* Use background image and no label */
	button.flags = TM_BUTTON_FLAG_NOLABEL | TM_BUTTON_FLAG_IMAGE;
	button.image = Fleche_Haut_18x23; 
	/* Add button */
	button5 = TM_ILI9341_Button_Add(&button);
	
	/* Button6 Down accelaration with image: fleche_bas_18x23 */
	button.x = 25;
	button.y = 200;
	button.width = 18;
	button.height = 23;
	button.borderColor = ILI9341_COLOR_BLACK;
	/* Use background image and no label */
	button.flags = TM_BUTTON_FLAG_NOLABEL | TM_BUTTON_FLAG_IMAGE;
	button.image = Fleche_Bas_18x23; 
	/* Add button */
	button6 = TM_ILI9341_Button_Add(&button);
	
	/* Draw buttons */
	TM_ILI9341_Button_DrawAll();
	
	TM_ILI9341_Button_Enable(button1);
	
	
	/* Label for Button1 Retour � l'acceuil */
	TM_ILI9341_Puts(11,289, "Retour a", &TM_Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_RED);
	TM_ILI9341_Puts(9,303, "l'acceuil", &TM_Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_RED);
	
	/* Label for Button2 Envoi de la config */
	TM_ILI9341_Puts(162,289, "Envoi de", &TM_Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_RED);
	TM_ILI9341_Puts(160,303, "la config", &TM_Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_RED);
	
	
	
	TM_ILI9341_Puts(30,20, "Configuration du", &TM_Font_11x18, ILI9341_COLOR_RED, ILI9341_COLOR_WHITE);
	TM_ILI9341_Puts(65,40, "controleur", &TM_Font_11x18, ILI9341_COLOR_RED, ILI9341_COLOR_WHITE);
	
	TM_ILI9341_Puts(55,105, "Longeur \ndu cable", &TM_Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE);
	
	TM_ILI9341_Puts(55,190, "Acceleration du \nmoteur en m/s^2", &TM_Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE);
	
	
	while(1);
}




extern void EcranControle(void){
	/*Temp*/
	
	
	
	
	/*
	sprintf(str, "abcdf");

	controle_info.TableauErreur[0]->ErreurPresente = 0;
	controle_info.TableauErreur[1]->ErreurPresente = 1;
	controle_info.TableauErreur[2]->ErreurPresente = 0;
	controle_info.TableauErreur[3]->ErreurPresente = 0;
	controle_info.TableauErreur[0]->StrErreur[0] = str[0];
	//controle_info.TableauErreur[1]->StrErreur[]= "Error 2 test";
	//controle_info.TableauErreur[2]->StrErreur[30]= "Error 3 test 1234";
	*/
	
	/*
	controle_info.TableauErreur[1]=1;
	controle_info.TableauErreur[2]=1;
	controle_info.TableauErreur[3]=0;
	controle_info.TableauErreur[4]=1;
	controle_info.TableauErreur[5]=0;
	controle_info.TableauErreur[6]=0;
	controle_info.TableauErreur[7]=1;
	controle_info.TableauErreur[8]=0;
	*/
	
	
	
	/* Clear LCD */
	ClrScreen();
	/* Delete Bouton existant */
	TM_ILI9341_Button_DeleteAll();
	
	/* Button1 Retour � la config, default configuration */
	/* Red with black border and black font 11x18 */
	button.x = 148;
	button.y = 279;
	button.width = 90;
	button.height = 39;
	button.background = ILI9341_COLOR_RED;
	button.borderColor = ILI9341_COLOR_BLACK;
	button.color = ILI9341_COLOR_BLACK;
	button.font = &TM_Font_7x10;
	button.flags =  TM_BUTTON_FLAG_NOLABEL;
	/* Add button */
	button1 = TM_ILI9341_Button_Add(&button);
	
	
	/* Button2 Direction avant with image: fleche_haut_18x23 */
	button.x = 85;
	button.y = 40;
	button.width = 18;
	button.height = 23;
	button.borderColor = ILI9341_COLOR_BLACK;
	/* Use background image and no label */
	button.flags = TM_BUTTON_FLAG_NOLABEL | TM_BUTTON_FLAG_IMAGE;
	button.image = Fleche_Haut_18x23; 
	/* Add button */
	button2 = TM_ILI9341_Button_Add(&button);
	
	/* Button3 Direction arri�re cable with image: fleche_bas_18x23 */
	button.x = 105;
	button.y = 40;
	button.width = 18;
	button.height = 23;
	button.borderColor = ILI9341_COLOR_BLACK;
	/* Use background image and no label */
	button.flags = TM_BUTTON_FLAG_NOLABEL | TM_BUTTON_FLAG_IMAGE;
	button.image = Fleche_Bas_18x23; 
	/* Add button */
	button3 = TM_ILI9341_Button_Add(&button);
	
	
	
		/* Button 4,augmenter vitesse, default configuration */
	button.x = 70;	/* X location */
	button.y = 80;	/* Y location */
	button.width = 20;
	button.height = 20;
	button.background = ILI9341_COLOR_RED;
	button.borderColor = ILI9341_COLOR_BLACK;
	button.label = "+";
	button.color = ILI9341_COLOR_BLACK;
	button.font = &TM_Font_11x18;
	button.flags = 0;
	/* Add button */
	button4 = TM_ILI9341_Button_Add(&button);
	
	/* Button 5, diminuer vitesse, default configuration */
	button.x = 93;	/* X location */
	button.y = 80;	/* Y location */
	button.width = 20;
	button.height = 20;
	button.background = ILI9341_COLOR_WHITE;
	button.borderColor = ILI9341_COLOR_BLACK;
	button.label = "O";
	button.color = ILI9341_COLOR_BLACK;
	button.font = &TM_Font_11x18;
	button.flags = 0;
	/* Add button */
	button5 = TM_ILI9341_Button_Add(&button);
	
	/* Button 6, diminuer vitesse, default configuration */
	button.x = 116;	/* X location */
	button.y = 80;	/* Y location */
	button.width = 20;
	button.height = 20;
	button.background = ILI9341_COLOR_RED;
	button.borderColor = ILI9341_COLOR_BLACK;
	button.label = "-";
	button.color = ILI9341_COLOR_BLACK;
	button.font = &TM_Font_11x18;
	button.flags = 0;
	/* Add button */
	button6 = TM_ILI9341_Button_Add(&button);
	
	/* Draw buttons */
	TM_ILI9341_Button_DrawAll();
	
	TM_ILI9341_Puts(175,30, "S\nk-R\ny-u\n  u\n  n\n  n\n  e\n  r", &TM_Font_16x26, ILI9341_COLOR_RED, ILI9341_COLOR_WHITE);
	
	TM_ILI9341_Puts(5,3, "Status:", &TM_Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE);
	
	TM_ILI9341_Puts(180,3, "Bat:", &TM_Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE);
	
	TM_ILI9341_Puts(10,40, "Direction:", &TM_Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE);
	
	TM_ILI9341_Puts(10,75, "Vitesse\n voulu:", &TM_Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE);
	
	TM_ILI9341_Puts(10,120, "Position:", &TM_Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE);
	
	TM_ILI9341_Puts(80,120, "Vitesse reel:", &TM_Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE);
	
	TM_ILI9341_Puts(10,160,"Erreurs:", &TM_Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE);
	
	/* Label for Button2 Envoi de la config */
	TM_ILI9341_Puts(162,289, "Retour a", &TM_Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_RED);
	TM_ILI9341_Puts(160,303, "la config", &TM_Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_RED);
	
	
}
extern void RefreshEcranConfig(T_Config_Setting* Config_Setting){
	sprintf(str, ":%dcm     ", Config_Setting->LenghtCable);
	TM_ILI9341_Puts(115, 104, str, &TM_Font_11x18, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE);
	sprintf(str, ":%d     ", Config_Setting->Accelation);
	TM_ILI9341_Puts(165, 190, str, &TM_Font_11x18, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE);
}

extern void RefreshEcranControle(T_Controle_Information* Controle_Information){
	
	if(Controle_Information->ControllerStatus){
		TM_ILI9341_Puts(55,3,"Online ", &TM_Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE);
	}
	else{
		TM_ILI9341_Puts(55,3,"Offline", &TM_Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE);
	}
	
	sprintf(str, "%d%%", Controle_Information->BattLevel);
	TM_ILI9341_Puts(208,3, "    ", &TM_Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE);
	TM_ILI9341_Puts(208,3, str, &TM_Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE);
	
	if(Controle_Information->Direction){
		TM_ILI9341_Puts(10,52," Arriere", &TM_Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE);
	}
	else{
		TM_ILI9341_Puts(10,52,"  Avant ", &TM_Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE);
	}
	
	sprintf(str, "%dKM/H",Controle_Information->VitesseVoulu);
	TM_ILI9341_Puts(18,100, "       ", &TM_Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE);
	TM_ILI9341_Puts(18,100, str, &TM_Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE);
	
	sprintf(str, "%dcm",Controle_Information->Position);
	TM_ILI9341_Puts(18,133, "       ", &TM_Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE);
	TM_ILI9341_Puts(18,133, str, &TM_Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE);
	
	sprintf(str, "%dKM/H",Controle_Information->VitesseReel);
	TM_ILI9341_Puts(95,133, "       ", &TM_Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE);
	TM_ILI9341_Puts(95,133, str, &TM_Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE);
	
	//effacer error avant d'afficher ou faire refresh
	for(i=0;i<NombreErreur;++i){
		int j;
		/*
		if(Controle_Information->TableauErreur+i
		sprintf(str, "%s",Controle_Information->TableauErreur+i);
		TM_ILI9341_Puts(10,160,"Erreurs:", &TM_Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE);
		*/
	}
	
}







extern void ClrScreen(void){
	TM_ILI9341_Fill(ILI9341_COLOR_WHITE);
}
