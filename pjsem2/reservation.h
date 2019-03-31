#pragma once
#include<iostream>
#include<string>

using namespace std;

class reservation
{
protected:
	string nom,prenom,lieu;
	string d;
	float prix;
public:
	reservation(string="",string="",string="",string="1/1/1",float=1.11);
	void virtual saisir();
	virtual~reservation(void);
	
	friend ostream& operator<<(ostream&,reservation&); 
	friend istream& operator>>(istream&,reservation&); 
	
	void virtual afficher();

	string getLieu(){return lieu;}
	void setLieu(string lieu1){lieu=lieu1;}
	
	string getD(){return d;}
	float getPrix(){return prix;}
	void setPrix(float p){prix=p;}
	string getNom(){return nom;}
	void setNom(string n){nom=n;}
	string getPrenom(){return prenom;}
	void setPrenom(string p){prenom=p;}
	void setDate(string d1){d=d1;}
	void setD(string d1){d=d1;}
};

