#pragma once
#include "reservation.h"
#include<iostream>
#include<string>

using namespace std;

class premium :public reservation
{
	int tente;
	//int repas;
public:
	premium(string="",string="",string="",string="1/1/1",float=1.11,int=1);
	//premium(string="",string="",string="",int=1,int=1,int=1,float=1.11,int=1);
	void saisir();
	~premium(void);
	friend ostream& operator<<(ostream&,premium&);
	friend istream& operator>>(istream&,premium&);

	void afficher();
	int getTente(){return tente;}
	void setTente(int newTente){tente=newTente;}
	//void setRepas(int r){repas=r;}
	//int getRepas(){return repas;}
	
	premium(const premium&);
	void addPrix(float prix1){prix+=prix1;}

	void setNewNom(string n){nom=n;}
	void setNewPrenom(string p){prenom=p;}
	void setNewTente(int t){tente=t;}
	//friend operator=()
};

