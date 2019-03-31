
#include"reservation.h"
#include"premium.h"
#include<iostream>
#include<string>
using namespace std;
#include<fstream>
#include<vector>
#include<iomanip>
void present()
{
cout<<"Les Emplacements possibles sont"<<endl;
cout<<"1)    Camping Tastour   10/3    80DT"<<endl;
cout<<"2)    Camping Morneg    11/3    60DT"<<endl;
cout<<"3)    Camping Ain Drahem    18/3    70DT"<<endl;
cout<<"4)    Camping Ain Dhab    25/3    60DT"<<endl;
}

void ouvrir()
{
	fstream f;
	f.open("rsv.txt",ios::in|ios::out|ios::app);
}

void remplir()
{
fstream f;
f.open("pj.txt",ios::in|ios::out|ios::app);

int choix_e;
char choix_r;
reservation r;
premium p;
cout<<"Saisir votre choix "<<endl;
cin>>choix_e;
if(choix_e==1)
{
	cout<<"B:reservation basique    P:reservation premium"<<endl;
	cin>>choix_r;
	//cout<<"choix_r="<<choix_r<<endl;
	if(choix_r=='B' || choix_r=='b')
	{
	r.setLieu("Tastour");
	r.setD("10/03/2018");
	//cin>>r;
	r.saisir();
	r.setPrix(80);
	f<<r;
	}
	else if(choix_r=='P' || choix_r=='p')
	{
	p.setLieu("Tastour");
	p.setD("10/03/2018");
	//cin>>p;
	p.saisir();
	p.setPrix(80);
	if(p.getTente()==1)
		p.addPrix(10);
	if(p.getTente()==2)
		p.addPrix(20);

	/*if(p.getRepas()==1)
		p.addPrix(5);
	if(p.getRepas()==2)
		p.addPrix(10);*/
	f<<p;
	}
}
else if(choix_e==2 )
{
	cout<<"B:reservation basique    P:reservation premium"<<endl;
	cin>>choix_r;
	if(choix_r=='B' || choix_r=='b')
	{
	r.setLieu("Mornag");
	r.setD("11/03/2018");
	r.saisir();
	//cin>>r;
	r.setPrix(60);
	f<<r;
	}
	else if(choix_r=='P' || choix_r=='p')
	{
	p.setLieu("Mornag");
	r.setD("11/03/2018");
	p.saisir();
	//cin>>p;
	p.setPrix(60);
	if(p.getTente()==1)
		p.addPrix(10);
	if(p.getTente()==2)
		p.addPrix(20);

	/*if(p.getRepas()==1)
		p.addPrix(5);
	if(p.getRepas()==2)
		p.addPrix(10);*/
	f<<p;
	}
}
else if(choix_e==3)
{
	cout<<"B:reservation basique    P:reservation premium"<<endl;
	cin>>choix_r;
	if(choix_r=='B' || choix_r=='b')
	{
	r.setLieu("AinDrahem");
	r.setD("18/03/2018");
	//cin>>r;
	r.saisir();
	r.setPrix(70);
	f<<r;
	}
	else if(choix_r=='P' || choix_r=='p')
	{
	p.setLieu("AinDrahem");
	p.setD("18/03/2018");
	//cin>>p;
	p.saisir();
	p.setPrix(70);
	if(p.getTente()==1)
		p.addPrix(10);
	if(p.getTente()==2)
		p.addPrix(20);

	/*if(p.getRepas()==1)
		p.addPrix(5);
	if(p.getRepas()==2)
		p.addPrix(10);*/
	f<<p;
	}
}
else if(choix_e==4)
{
	cout<<"B:reservation basique    P:reservation premium"<<endl;
	cin>>choix_r;
	if(choix_r=='B' || choix_r=='b')
	{
	r.setLieu("AinDhab");
	r.setD("25/03/2018");
	//cin>>r;
	r.saisir();
	r.setPrix(60);
	f<<r;
	}
	else if(choix_r=='P' || choix_r=='p')
	{
	p.setLieu("AinDhab");
	p.setD("25/03/2018");
	//cin>>p;
	p.saisir();
	p.setPrix(60);
	if(p.getTente()==1)
		p.addPrix(10);
	if(p.getTente()==2)
		p.addPrix(20);

	/*if(p.getRepas()==1)
		p.addPrix(5);
	if(p.getRepas()==2)
		p.addPrix(10);*/
	f<<p;
	}
}

f.close();

//affiche();
}







void modifier()
{
	vector<reservation*>data;
	int choix;
	fstream f1;
	f1.open("pj.txt",ios::in||ios::out||ios::app);
	if(!f1.is_open())
		exit(-1);
	while(1)
	{
	f1>>choix;
	if(f1.eof())
		break;

	if(choix==1)
	{
		reservation *r = new reservation;
		f1>>*r;
		data.push_back(r);
	}
	else if(choix==2)
	{
		premium *p = new premium;
		f1>>*p;
		data.push_back(p);
	}
	}
	f1.close();
	cout<<"La taille du tableau est"<<data.size()<<endl;
	cout<<setw(50)<<"Liste des reservations"<<endl;
	cout<<"indice"<<endl;
	for(unsigned int j=0;j<data.size();j++)
	{
	cout<<setw(5)<<j;
	data[j]->afficher();
	}
	
	//cout<<"size"<<tab.size()<<endl;
	if(typeid(*data[1])==typeid(premium))
		cout<<1<<endl;
	else cout<<0<<endl;
	int ind;
	cout<<"Saisir l'indice du reservation a editer"<<endl;
	cin>>ind;
	

	if(typeid(*data[ind])==typeid(reservation))
	{
		reservation *r = new reservation(*data[ind]);
		cout<<setw(10)<<"Modifier"<<endl;
		cout<<"1:Nom    2:Prenom"<<endl;
		int choice;
		cin>>choice;
		if(choice==1)
		{
			string newNom;
			cin>>newNom;
			r->setNom(newNom);
		}
		else if(choice==2)
		{
			string newPrenom;
			cin>>newPrenom;
			r->setPrenom(newPrenom);

		}
		
		data.erase(data.begin()+ind);
		data.insert(data.begin()+ind,r);
		fstream file2;
		file2.open("pj.txt",ios::in|ios::out|ios::trunc);
		for(int i=0;i<data.size();i++)
		{
		if(typeid(*data[i])==typeid(reservation))
		file2<<*data[i];

		else if(typeid(*data[i])==typeid(premium))
			{premium *p2=new premium(static_cast<premium&>(*data[i]));

			file2<<*p2;}
		}
		file2.close();
	}
	else if(typeid(*data[ind])==typeid(premium))
	{	//r=new premium(static_cast<premium&>(*tab[ind])) ;
		premium *p=new premium(static_cast<premium&>(*data[ind]));
		
		/*cout<<"affichage de p"<<endl;
		cout<<*p;
		cout<<endl;
		*/

		
		

		cout<<setw(10)<<"Modifier"<<endl;
		cout<<"1:Nom    2:Prenom    3:Tente"<<endl;
		int choice;
		cin>>choice;
		if(choice==1)
		{
			string newNom;
			cin>>newNom;
			p->setNewNom(newNom);
		}
		else if(choice==2)
		{
			string newPrenom;
			cin>>newPrenom;
			p->setNewPrenom(newPrenom);

		}
		else if(choice==3)
		{
			int t;
			//cin>>t;
			do{cout<<"Nouveau Nb de pers/tente"<<endl;
			cin>>t;}
			while(t!=1 && t!=2);
			if(p->getTente()<t)
				p->addPrix(10);
			else if(p->getTente()>t)
				p->addPrix(-10);
			p->setNewTente(t);

		}

		data.erase(data.begin()+ind);
		data.insert(data.begin()+ind,p);

		cout<<setw(50)<<"Liste des reservations2"<<endl;
		cout<<"indice"<<endl;
		for(unsigned int j1=0;j1<data.size();j1++)
		{
		cout<<setw(5)<<j1;
		data[j1]->afficher();
		}

		/*fstream d;
		d.open("justforp.txt",ios::in|ios::out|ios::trunc);*/
		

		fstream file3;
		file3.open("pj.txt",ios::in|ios::out|ios::trunc);
		premium *p2=new premium();

		for(int i=0;i<data.size();i++)
		{
		if(typeid(*data[i])==typeid(reservation))
		file3<<*data[i];

		else if(typeid(*data[i])==typeid(premium))
			{premium *p2=new premium(static_cast<premium&>(*data[i]));

			file3<<*p2;}
		}

		//d.close();
		file3.close();
		
	}
	
}




void supprimer()
{
	cout<<"Suppression"<<endl;
	vector<reservation*>temp;
	int choix;
	fstream fsup;
	fsup.open("pj.txt",ios::in||ios::out||ios::app);
	if(!fsup.is_open())
		exit(-1);
	while(1)
	{
	fsup>>choix;
	if(fsup.eof())
		break;

	if(choix==1)
	{
		reservation *r = new reservation;
		fsup>>*r;
		temp.push_back(r);
	}
	else if(choix==2)
	{
		premium *p = new premium;
		fsup>>*p;
		temp.push_back(p);
	}
	}
	fsup.close();
	cout<<"La taille du tableau est"<<temp.size()<<endl;
	cout<<setw(50)<<"Liste des reservations"<<endl;
	cout<<"indice"<<endl;
	for(unsigned int j=0;j<temp.size();j++)
	{
	cout<<setw(5)<<j;
	temp[j]->afficher();
	}

	int ind1;
	cout<<"Saisir l'indice du reservation a supprimer"<<endl;
	cin>>ind1;
	temp.erase(temp.begin()+ind1);
	
	cout<<setw(50)<<"Liste des reservations"<<endl;
	cout<<"indice"<<endl;
	for(unsigned int j=0;j<temp.size();j++)
	{
	cout<<setw(5)<<j;
	temp[j]->afficher();
	}

	fstream file4;
		file4.open("pj.txt",ios::in|ios::out|ios::trunc);
		premium *p2=new premium();

		for(int i=0;i<temp.size();i++)
		{
		if(typeid(*temp[i])==typeid(reservation))
		file4<<*temp[i];

		else if(typeid(*temp[i])==typeid(premium))
			{premium *p2=new premium(static_cast<premium&>(*temp[i]));

			file4<<*p2;}
		}

		file4.close();
}

void trier()
{
	vector<reservation*>trie1;
	int choi;
	fstream ftrie;
	ftrie.open("pj.txt",ios::in||ios::out||ios::app);
	if(!ftrie.is_open())
		exit(-4);
	while(1)
	{
	ftrie>>choi;
	if(ftrie.eof())
		break;

	if(choi==1)
	{
		reservation *r = new reservation;
		ftrie>>*r;
		trie1.push_back(r);
	}
	else if(choi==2)
	{
		premium *p = new premium;
		ftrie>>*p;
		trie1.push_back(p);
	}
	}
	ftrie.close();

	for(unsigned int j=0;j<trie1.size();j++)
	{
	cout<<setw(5)<<j;
	trie1[j]->afficher();
	}

	vector<reservation*>trie2;
	for(unsigned int j=0;j<trie1.size();j++)
	{
		
		int min=j;
		for(int j1=0;j1<trie1.size();j1++)
		{
			if(trie1[j1]->getPrix()<trie1[min]->getPrix())
				{
					min=j1;
					//cout<<"min= "<<min<<endl;
				}
		}
		/*cout<<"j="<<j<<"trie1avant**************"<<endl;
		for(unsigned int d=0;d<trie1.size();d++)
	{
	cout<<setw(5)<<j;
	trie1[d]->afficher();
	}
		cout<<"**************"<<endl;*/

		
		if(typeid(*trie1[min])==typeid(reservation))
			{
			reservation* rmin=new reservation(*trie1[min]);
			trie2.push_back(rmin);
			//trie1.erase(trie1.begin()+min);
			trie1[min]->setPrix(120);
			}
		else if(typeid(*trie1[min])==typeid(premium))
			{
			premium *pmin=new premium(static_cast<premium&>(*trie1[min]));
			trie2.push_back(pmin);
			trie1[min]->setPrix(120);
			//trie1.erase(trie1.begin()+min);
			}

	//trie2.push_back(trie1[min]);
	//trie1.erase(trie1.begin()+min);

	//trie1[min]->setPrix(120);
	/*if(trie1.size()==1)
			trie2.push_back(trie1[0]);*/

	/*cout<<endl<<"trie2*******************"<<endl;
	for(unsigned int s=0;s<trie2.size();s++)
	{
	cout<<setw(5)<<s;
	trie2[s]->afficher();
	}
	cout<<"*******************"<<endl;*/

		if(trie1.size()==1)
			{
			trie2.push_back(trie1[0]);
			/*cout<<"apres le truc"<<endl;
			cout<<endl<<"trie2*******************"<<endl;*/
			/*for(unsigned int s=0;s<trie2.size();s++)
			{
			cout<<setw(5)<<s;
			trie2[s]->afficher();
			}
			cout<<"*******************"<<endl;*/
			}
		

	/*cout<<"j="<<j<<"trie1apres**************"<<endl;
		for(unsigned int d=0;d<trie1.size();d++)
	{
	cout<<setw(5)<<j;
	trie1[d]->afficher();
	}
		cout<<"**************"<<endl;*/

	}
	cout<<endl<<"apres trie"<<endl;
	for(unsigned int j=0;j<trie2.size();j++)
	{
	cout<<setw(5)<<j;
	trie2[j]->afficher();
	}

	fstream file5;
		file5.open("pj.txt",ios::in|ios::out|ios::trunc);
		premium *p2=new premium();

		for(int i=0;i<trie2.size();i++)
		{
		if(typeid(*trie2[i])==typeid(reservation))
		file5<<*trie2[i];

		else if(typeid(*trie2[i])==typeid(premium))
			{premium *p2=new premium(static_cast<premium&>(*trie2[i]));

			file5<<*p2;}
		}

		file5.close();

}


void affiche()
{
	vector<reservation*>taffich;
	int choiee;
	fstream faffich;
	faffich.open("pj.txt",ios::in||ios::out||ios::app);
	if(!faffich.is_open())
		exit(-4);
	while(1)
	{
	faffich>>choiee;
	if(faffich.eof())
		break;

	if(choiee==1)
	{
		reservation *r = new reservation;
		faffich>>*r;
		taffich.push_back(r);
	}
	else if(choiee==2)
	{
		premium *p = new premium;
		faffich>>*p;
		taffich.push_back(p);
	}
	}
	faffich.close();

	for(unsigned int j=0;j<taffich.size();j++)
	{
	cout<<setw(5)<<j;
	taffich[j]->afficher();
	}

}

void main()
{
cout<<"                             G E S T I O N :: A G E N C E :: D E :: C A M P I N G"<<endl<<endl<<endl;	
while(1){
cout<<"A:Afficher    R:remmplir    M:Modifier    S:Supprimer    T:trier    E:Exit"<<endl;
char ch;
cin>>ch;
if(ch=='R' || ch=='r')
	{present();
     remplir();
	affiche();}
else if(ch=='M' || ch=='m')
	modifier();
else if(ch=='S' || ch=='s')
	supprimer();
else if(ch=='E' || ch=='e')
	exit(-3);
else if(ch=='T' || ch=='t')
	trier();
else if(ch=='A' || ch=='a')
	affiche();

cout<<endl<<endl;
}
//present();
//remplir();
//modifier();
//supprimer();	

//int choix;
//reservation r1;
//premium p;
//fstream f;
//f.open("rsv.txt",ios::in|ios::out|ios::app);
//f>>choix;
//f>>r1;
//f>>choix;
//f>>choix;
//f>>p;
//cout<<r1;
//cout<<p;


//reservation r;
//cin>>r;
//cout<<r;


system("pause");

}