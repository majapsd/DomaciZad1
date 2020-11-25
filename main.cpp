#include <iostream>
#include <fstream>
using namespace std;
typedef struct{
    string ime;
    double prosek;
    int brIzostanka;
}ucenik;
int Unos(char imeFajla[20], ucenik u[100] ,int &n){
ifstream ulaz1(imeFajla);
if(!ulaz1){
    cout<<"Greska, fajl ne moze da se otvori";
return 1;
}
while (!ulaz1.eof())
{
   ulaz1>>u[n].ime>>u[n].prosek>>u[n].brIzostanka;
    n++;
}
ulaz1.close();
return 0;
}
void Sortiraj(ucenik u[100],int n)
{
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(u[i].ime>u[j].ime)
                swap(u[i],u[j]);
}
int main()
{
int n=0;
ucenik u[100];
if(Unos("grupa1.txt",u,n)==1)return 1;
if(Unos("grupa2.txt",u,n)) return 1;
if(Unos("grupa3.txt",u,n)) return 1;
Sortiraj(u,n);
ofstream izlaz("izvestaj.txt");
for(int i=0;i<n;i++){
izlaz<<u[i].ime<<" "<<u[i].prosek<<" ";
if(u[i].brIzostanka<5)
izlaz<<" je zadovoljio minimum rada na vezbama "<<endl;
else
izlaz<<" nije zadovoljio minimum rada na vezbama"<<endl;
}
izlaz.close();
return 0;
}
