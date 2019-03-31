#include "premium.h"
#include<iomanip>

premium::premium(string nom1,string prenom1,string lieu1,string d1,float prix1,int tente1):reservation(nom1,prenom1,lieu1,d1,prix1),tente(tente1)
{
}

//premium::premium(string nom1,string prenom1,string lieu1,int j1,int m1,int a1,float prix1,int tente1):reservation(nom1,prenom1,lieu1,date(j1,m1,a1)),tente(tente1)
//{
//}

void premium::saisir()
{
	cout<<"Saisir le nom"<<endl;
	cin>>nom;
	cout<<"Saisir le prenom"<<endl;
	cin>>prenom;
	
	int rep;
	do{
		cout<<"La tente est pour 1 ou 2 personnes?"<<endl;
		cin>>rep;
	}
	while(rep!=1 && rep!=2);
	tente=rep;

	/*int rep1;
	do
	{
	cout<<"1 ou 2 repas?"<<endl;
	cin>>rep1;
	}while(rep1!=1 && rep1!=2);
	repas=rep1;*/
}

premium::~premium(void)
{
}

ostream& operator<<(ostream& out,premium& p)
{
	//out<<setw(10)<<"2"<<setw(10)<<p.nom<<" "<<setw(10)<<p.prenom<<" "<<setw(10)<<p.lieu<<setw(10)<<p.getD().getJ()<<"/"<<p.getD().getM()<<"/"<<p.getD().getA()<<setw(10)<<p.prix<<setw(10)<<p.tente<<endl;
	//1 pour reservation basique 2 pour reservation premium
	out<<setw(12)<<2<<setw(12)<<p.nom<<setw(12)<<p.prenom<<setw(12)<<p.lieu<<setw(12)<<p.d<<setw(12)<<p.prix<<setw(12)<<p.tente<<endl;
	return out;
}

istream& operator>>(istream& in,premium& p)
{
	reservation *r=&p;
	in>>*r;
	
	/*in>>p.nom;
	in>>p.prenom;
	in>>p.lieu;
	in>>p.d;
	in>>p.prix;*/
	in>>p.tente;

	return in;
}



void premium::afficher()
{
	//cout<<setw(10)<<nom<<" "<<setw(10)<<prenom<<" "<<setw(10)<<lieu<<setw(10)<<getD().getJ()<<"/"<<getD().getM()<<"/"<<getD().getA()<<setw(10)<<prix<<setw(10)<<tente<<endl;
	cout<<setw(12)<<nom<<setw(12)<<prenom<<setw(12)<<lieu<<setw(12)<<d<<setw(12)<<prix<<setw(12)<<tente<<endl;
}

premium::premium(const premium& p)
{
	nom=p.nom;
	prenom=p.prenom;
	lieu=p.lieu;
	d=p.d;
	prix=p.prix;
	tente=p.tente;
	//repas=p.repas;
}