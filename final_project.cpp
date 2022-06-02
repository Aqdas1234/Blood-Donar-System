#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
struct date{
	int d;
	int m;
	int y;
};
struct patient{
	char name[20];
	long long  ph;
    char bld_gp[5];
	char city[20];
	date dt;
};
patient donar()
{      patient p;
	cout<<"enter the donar name:  ";
	   cin.ignore();
	   cin.getline(p.name,20);
		cout<<"enter donar\'s phone number: ";
		cin>>p.ph;
		cout<<"enter donar\'s blood group: ";
		cin>>p.bld_gp;
		cout<<"enter donar\'s city name:  ";
		cin>>p.city;
		cout<<"enter last date of donation formate(D/M/Y): ";
		cin>>p.dt.d>>p.dt.m>>p.dt.y;
		return(p);
}

void rename(patient pr)
{
	        fstream g("temporay.txt",ios::in);
            fstream file("bds_donor_data.txt",ios::out);
		while(!g.eof())
	{
		g.read( reinterpret_cast<char*>(&pr), sizeof(pr) );
   	if(g.eof())
    	break;
    	 file.write( reinterpret_cast<char*>(&pr), sizeof(pr));
	}	
	file.close();
	g.close();
	
}
int remove(patient pr,char n[],char bd_gp[])
{
	
	   int i=0;
		fstream file("bds_donor_data.txt",ios::in);
		fstream g("temporay.txt",ios::out|ios::app);
	while(!file.eof())
	{
		file.read( reinterpret_cast<char*>(&pr), sizeof(pr) );
    	if(file.eof())
    	break;
    	  	if(!(strcmp(pr.name,n)==0&&strcmp(pr.bld_gp,bd_gp)==0))
	{
			g.write( reinterpret_cast<char*>(&pr), sizeof(pr));
		
		}else i++;
	}
	g.close();
	file.close();


    rename(pr);
    return(i);
     
}
void show(patient pr)
{
	cout<<"Name:"<<pr.name<<endl;
	cout<<"Blood group:"<<pr.bld_gp<<endl;
	cout<<"city: "<<pr.city<<endl;
	cout<<"phone number: "<<pr.ph<<endl;
	cout<<"last date of donation formate(D/M/Y): "<<pr.dt.d<<"-"<<pr.dt.m<<"-"<<pr.dt.y;
	cout<<endl;
}
void update(patient pr);
void comb(patient pr);

main()
{   
    patient p,pr;
   
 	int n;
do
{
    cout<<"\t\t\t **********************************\n\n";
	cout<<"\t\t\t   BLOOD DONOR MANAGEMENT SOCIETY \n\n";
	cout<<"\t\t\t **********************************\n";
	cout<<"\t\t\t              * SONU *              \n\n\n";
	cout<<"To add donar record. press 1:\n";
	cout<<"To Search the donor\'s record based on name. press 2:\n";
	cout<<"To Search a list of donors based on blood group. press 3:\n";
	cout<<"To Update the  donor\'s record after successful donation. press 4:\n";
	cout<<"To Remove  donor\'s record due to some medical reasons. press 5:\n";
	cout<<"To show all data of file.press 6:\n ";
	cout<<"please select the option: ";
	cin>>n;
	if (n==1)
	{   
	fstream file("bds_donor_data.txt",ios::out|ios::app);
		p=donar();
	
		file.write(reinterpret_cast<char*>(&p), sizeof(p));
file.close();
	}
	
else	if(n==2)
	{     int i=0;
		cout<<"enter the donar\'s name whose you want to know the data :";
		 char n[20];
	cin.ignore();
	   cin.getline(n,20);
			fstream file("bds_donor_data.txt",ios::in);
			
				while(!file.eof())
	{
		file.read( reinterpret_cast<char*>(&pr), sizeof(pr) );
    	if(file.eof())
    	break;
 if(strcmp(pr.name,n)==0)
	{		
		show(pr);
		i++;	
			}
	}
	file.close();
	if(i==0){
		cout<<"such data is not found! \n ";
	}
}

else  if(n==3)
{
		int i=0;
		cout<<"Enter Blood group:";
		   char bd_gp[5];
		cin>>bd_gp;
	fstream file("bds_donor_data.txt", ios::in| ios::binary);
	while(!file.eof())
	{
		file.read( reinterpret_cast<char*>(&pr), sizeof(pr) );
	if(file.eof())
	break;
 if(strcmp(pr.bld_gp,bd_gp)==0)
	{	
	show(pr);
	i++;
}

}
file.close();
	if(i==0)
	{
		cout<<"such data is not found! \n ";
	}
}
else if(n==4)
{
	
	update(pr);
}
 else if(n==5)
{
			 char n[20];
	   char bd_gp[5];
	cout<<"enter the patient\'s name whose you want to delete the data : ";
	cin.ignore();
	   cin.getline(n,20);
	cout<<"and also its blood group: ";
	cin>>bd_gp;

int i=remove(pr,n,bd_gp);
	if(i==0)
{
	cout<<"such data is not found! \n ";
}
	else    cout<<"data has been deleted sucessfully!\n";
}

else if(n==6)
{     int a=0;
			fstream file("bds_donor_data.txt",ios::in);
			
				while(!file.eof())
	{
		file.read( reinterpret_cast<char*>(&pr), sizeof(pr) );
    	if(file.eof())
    	break;
    	show(pr);
    	a++;
		}
		file.close();
		
		if(a==0){
			cout<<"\n your file is empty! \n";
		}
}
else {
// cout<<"please select right option!";
//      cout<<".or if you want to exit then press 7: ";
//      cin>>n;
       break;
	  }
}while(n<7);
return 0;
}
void update(patient pr)
{     
int i=0,op;
do{

			 char n[20];
	   char bd_gp[5];
	cout<<"enter the patient\'s name whose you want to update the data : ";
		cin.ignore();
	   cin.getline(n,20);;
	cout<<"and also its blood group: ";
	cin>>bd_gp;
	cout<<"if you want to update only last date of donation then press 1:\n";
	cout<<"if you want to update whole data then press 2: ";
	cin>>op;
	if(op==1){
	
		fstream file("bds_donor_data.txt",ios::in);
		fstream g("copy.txt",ios::out);
	while(!file.eof())
	{
		file.read( reinterpret_cast<char*>(&pr), sizeof(pr) );
    	if(file.eof())
    	break;
    	  	if((strcmp(pr.name,n)==0&&strcmp(pr.bld_gp,bd_gp)==0))
	{        
	        
	   // patient p;
       cout<<"enter the new last date of donation formate(D/M/Y)";
       cin>>pr.dt.d>>pr.dt.m>>pr.dt.y;
     
        g.write( reinterpret_cast<char*>(&pr), sizeof(pr));
       	i++;
       
       }
	   }
	   g.close();
	   file.close();
int	k=remove(pr,n,bd_gp);
     comb(pr);
	   	if(i==0)
{
	cout<<"such data is not found! \n ";
}
	else    cout<<"data has been updated sucessfully!\n";
}
else if(op==2){

      // rename(pr);
	int i=remove(pr,n,bd_gp);
	
		fstream file("bds_donor_data.txt",ios::out|ios::app);
		pr=donar();
		file.write(reinterpret_cast<char*>(&pr), sizeof(pr));
     file.close();
     	   	if(i==0)
{
	cout<<"such data is not found! \n ";
}
	else    cout<<"data has been updated sucessfully!\n";
}
else break;
}while(false);

}
void comb(patient pr)
{
		
		fstream g("copy.txt",ios::in);
		fstream file("bds_donor_data.txt",ios::out|ios::app);
	while(!g.eof())
	{
		g.read( reinterpret_cast<char*>(&pr), sizeof(pr) );
    	if(g.eof())
    	break;
    	file.write( reinterpret_cast<char*>(&pr), sizeof(pr));
	}
	file.close();
	g.close();
}

