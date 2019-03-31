#include "reservation.h"

#include<iomanip>

reservation::reservation(string nom1,string prenom1,string lieu1,string d1,float prix1):nom(nom1),prenom(prenom1),lieu(lieu1),d(d1),prix(prix1)
{
}

void reservation::saisir()
{
	cout<<"Saisir le nom"<<endl;
	cin>>nom;
	cout<<"Saisir le prenom"<<endl;
	cin>>prenom;
	/*cout<<"Saisir le lieu"<<endl;
	cin>>lieu;*/
	
}

reservation::~reservation(void)
{
}

ostream& operator<<(ostream& out,reservation& r)
{
	//out<<setw(10)<<"1"<<setw(10)<<r.nom<<" "<<setw(10)<<r.prenom<<" "<<setw(10)<<r.lieu<<setw(10)<<r.getD().getJ()<<"/"<<r.getD().getM()<<"/"<<r.getD().getA()<<setw(10)<<r.prix<<endl;
	//1 pour reservation basique 2 pour reservation premium
	out<<setw(12)<<1<<setw(12)<<r.nom<<setw(12)<<r.prenom<<setw(12)<<r.lieu<<setw(12)<<r.d<<setw(12)<<r.prix<<endl;
	return out;
}
istream& operator>>(istream& in,reservation& r)
{
	
	in>>r.nom;
	in>>r.prenom;
	in>>r.lieu;
	in>>r.d;
	in>>r.prix;

	return in;
}


void reservation::afficher()
{
//cout<<setw(10)<<nom<<" "<<setw(10)<<prenom<<" "<<setw(10)<<lieu<<setw(10)<<getD().getJ()<<"/"<<getD().getM()<<"/"<<getD().getA()<<setw(10)<<prix<<endl;
	cout<<setw(12)<<nom<<setw(12)<<prenom<<setw(12)<<lieu<<setw(12)<<d<<setw(12)<<prix<<endl;
}