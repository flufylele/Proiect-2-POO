#include <iostream>
using namespace std;

class Pret
{
public:
    virtual int CalculPret()=0;
};

class Ingrediente
{
public:
    float sos_rosii,sos_bbq; //Sos
    float mozzarella,parmezan,cheddar; //Branza
    float sunca,vita,pepperoni,bacon,chorizo,pui,ton,carnati; //Carne
    float rosii,masline,ceapa,jalapeno,ardei,ciuperci,porumb; //Legume
    static const float pret_sos_rosii=0.08,pret_sos_bbq=0.20;
    static const float pret_mozzarella=0.08,pret_parmezan=0.08,pret_cheddar=0.14;
    static const float pret_sunca=0.25,pret_vita=0.25,pret_pepperoni=0.25,pret_bacon=0.25,pret_chorizo=0.25,pret_pui=0.25,pret_ton=0.25,pret_carnati=0.25;
    static const float pret_rosii=0.25,pret_masline=0.25,pret_ceapa=0.25,pret_jalapeno=0.25,pret_ardei=0.25,pret_ciuperci=0.25,pret_porumb=0.25;

};



//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------




class Pizza : public Pret
{
protected:
    Ingrediente ingrediente;
    int vegetarian;
    static const int manopera=2;
public:
    int size;
    Pizza();
    int CalculPret();
    virtual void Afisare();


};

Pizza::Pizza()
{
   ingrediente.sos_rosii=0;  ingrediente.sos_bbq=0;
   ingrediente.mozzarella=0;   ingrediente.parmezan=0;   ingrediente.cheddar=0;
   ingrediente.sunca=0; ingrediente.vita=0; ingrediente.pepperoni=0; ingrediente.bacon=0; ingrediente.chorizo=0; ingrediente.pui=0; ingrediente.ton=0; ingrediente.carnati=0;
   ingrediente.rosii=0; ingrediente.masline=0; ingrediente.ceapa=0; ingrediente.jalapeno=0; ingrediente.ardei=0; ingrediente.ciuperci=0; ingrediente.porumb=0;
}

int Pizza::CalculPret()
{
    return manopera+ingrediente.sos_rosii*ingrediente.pret_rosii + ingrediente.sos_bbq*ingrediente.pret_sos_bbq
    + ingrediente.mozzarella*ingrediente.pret_mozzarella + ingrediente.parmezan*ingrediente.pret_parmezan + ingrediente.cheddar*ingrediente.pret_cheddar
    + ingrediente.sunca*ingrediente.pret_sunca + ingrediente.vita*ingrediente.pret_vita + ingrediente.pepperoni*ingrediente.pret_pepperoni + ingrediente.bacon*ingrediente.pret_bacon + ingrediente.chorizo*ingrediente.pret_chorizo + ingrediente.pui*ingrediente.pret_pui + ingrediente.ton*ingrediente.pret_ton + ingrediente.carnati* ingrediente.pret_carnati;
    + ingrediente.rosii*ingrediente.pret_rosii + ingrediente.masline*ingrediente.pret_masline + ingrediente.ceapa*ingrediente.pret_ceapa + ingrediente.jalapeno*ingrediente.pret_jalapeno + ingrediente.ardei*ingrediente.pret_ardei + ingrediente.ciuperci*ingrediente.pret_ciuperci + ingrediente.porumb*ingrediente.pret_porumb;
}

void Pizza::Afisare()
{
    cout<<"Tipul de pizza nu a fost ales";
}



//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------




class Margerita : public Pizza
{
    public:
    Margerita();
    friend istream& operator >>(istream &in,Margerita &);
    Margerita operator = (const Margerita&);
     void Afisare();
    void Preparare(int );

};

Margerita::Margerita()
{
    vegetarian=0;
    ingrediente.sos_bbq=0; ingrediente.sos_rosii=0;
   ingrediente.parmezan=0;   ingrediente.cheddar=0 ;
   ingrediente.sunca=0; ingrediente.vita=0; ingrediente.pepperoni=0; ingrediente.bacon=0; ingrediente.chorizo=0; ingrediente.pui=0; ingrediente.ton=0; ingrediente.carnati=0;
   ingrediente.rosii=0; ingrediente.masline=0; ingrediente.ceapa=0; ingrediente.jalapeno=0; ingrediente.ardei=0; ingrediente.ciuperci=0; ingrediente.porumb=0;
}

istream& operator >>(istream&in,Margerita &a)
{
cout<<"\nCe dimensiune doriti sa aiba pizza? 1. Mica | 2. Medie | 3. Mare\n";
int marime;
in>>marime;
a.size=marime;


    return in;
}

Margerita Margerita::operator=(const Margerita &a)
{
    size=a.size;

}

void Margerita::Preparare(int x)
{
    size =x;
       if(x==1) //mica
   {
       ingrediente.sos_rosii=40;
        ingrediente.mozzarella=45;
   }

   if(x==2) //medie
   {
        ingrediente.sos_rosii=75;
        ingrediente.mozzarella=80;
   }

   if(x==3) //mare
   {
        ingrediente.sos_rosii=95;
        ingrediente.mozzarella=100;
   }

}


void Margerita::Afisare()
{
    cout<<"Pizza Margerita";
}


//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------




class Diavola : public Pizza
{public:
    Diavola();
    friend istream& operator >>(istream &in,Diavola &);
    Diavola operator = (const Diavola&);
    void Afisare();
    void Preparare(int );
};

Diavola::Diavola()
{
    vegetarian=0;
    ingrediente.sos_bbq=0;
    ingrediente.parmezan=0;   ingrediente.cheddar=0;
   ingrediente.sunca=0; ingrediente.vita=0;  ingrediente.bacon=0;  ingrediente.pui=0; ingrediente.ton=0; ingrediente.carnati=0;
    ingrediente.masline=0; ingrediente.ceapa=0; ingrediente.jalapeno=0; ingrediente.ardei=0; ingrediente.ciuperci=0; ingrediente.porumb=0;
}

istream& operator >>(istream&in,Diavola &a)
{
cout<<"\nCe dimensiune doriti sa aiba pizza? 1. Mica | 2. Medie | 3. Mare\n";
int marime;
in>>marime;
a.size=marime;


    return in;
}

Diavola  Diavola::operator = (const Diavola& a)
{
    size=a.size;
}

void Diavola::Afisare()
{
    cout <<"Pizza Diavola";
}

void Diavola::Preparare(int x)
{
    size =x;
       if(x==1) //mica
   {
       ingrediente.sos_rosii=15;
        ingrediente.mozzarella=25;
        ingrediente.pepperoni=20;
        ingrediente.rosii=15;
        ingrediente.chorizo=20;
   }

   if(x==2) //medie
   {
        ingrediente.sos_rosii=30;
        ingrediente.mozzarella=45;
        ingrediente.pepperoni=30;
        ingrediente.rosii=20;
        ingrediente.chorizo=30;
   }

   if(x==3) //mare
   {
        ingrediente.sos_rosii=35;
        ingrediente.mozzarella=55;
        ingrediente.pepperoni=35;
        ingrediente.rosii=22;
        ingrediente.chorizo=35;
   }

}



//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------




class Carnivora : public Pizza
{public:
    Carnivora();
    friend istream& operator >>(istream &in,Carnivora &);
    Carnivora operator = (const Carnivora&);
    void Preparare(int );
    void Afisare();

};

Carnivora::Carnivora()
{
    vegetarian=0;
    ingrediente.sos_bbq=0;
    ingrediente.parmezan=0;   ingrediente.cheddar=0;
   ingrediente.sunca=0; ingrediente.bacon=0; ingrediente.chorizo=0; ingrediente.pui=0; ingrediente.ton=0;
   ingrediente.rosii=0; ingrediente.masline=0; ingrediente.ceapa=0; ingrediente.jalapeno=0; ingrediente.ardei=0; ingrediente.ciuperci=0; ingrediente.porumb=0;
}

void Carnivora::Preparare(int x)
{
    size =x;
       if(x==1) //mica
   {
       ingrediente.sos_rosii=15;
        ingrediente.mozzarella=25;
        ingrediente.pepperoni=20;
        ingrediente.vita=20;
        ingrediente.carnati=20;
   }

   if(x==2) //medie
   {
        ingrediente.sos_rosii=30;
        ingrediente.mozzarella=45;
        ingrediente.pepperoni=30;
        ingrediente.vita=30;
        ingrediente.carnati=30;
   }

   if(x==3) //mare
   {
        ingrediente.sos_rosii=35;
        ingrediente.mozzarella=55;
        ingrediente.pepperoni=35;
        ingrediente.vita=35;
        ingrediente.carnati=35;
   }

}

istream& operator >>(istream&in, Carnivora &a)
{
cout<<"\nCe dimensiune doriti sa aiba pizza? 1. Mica | 2. Medie | 3. Mare\n";
int marime;
in>>marime;
a.size=marime;


    return in;
}

void Carnivora::Afisare()
{
    cout <<"Pizza Carnivora";
}

Carnivora Carnivora::operator = (const Carnivora& a)
{
    size=a.size;
}



//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------




class Mediterraneo: public Pizza
{
    public:
    Mediterraneo();
    friend istream& operator >>(istream &in,Mediterraneo &);
    Mediterraneo operator = (const Mediterraneo&);
    void Preparare(int );
    void Afisare();

};

Mediterraneo::Mediterraneo()
{
    vegetarian=1;
    ingrediente.sos_bbq=0;
   ingrediente.mozzarella=0;   ingrediente.parmezan=0;
   ingrediente.sunca=0; ingrediente.vita=0; ingrediente.pepperoni=0; ingrediente.bacon=0; ingrediente.chorizo=0; ingrediente.pui=0; ingrediente.ton=0; ingrediente.carnati=0;
    ingrediente.ceapa=0; ingrediente.jalapeno=0; ingrediente.ardei=0; ingrediente.porumb=0;
}

void  Mediterraneo::Preparare(int x)
{
    size =x;
       if(x==1) //mica
   {
       ingrediente.sos_rosii=70;
          ingrediente.cheddar=20;
        ingrediente.rosii=20;
        ingrediente.masline=20;
        ingrediente.ciuperci=20;
   }

   if(x==2) //medie
   {
        ingrediente.sos_rosii=100;
          ingrediente.cheddar=30;
        ingrediente.rosii=30;
        ingrediente.masline=30;
        ingrediente.ciuperci=30;
   }

   if(x==3) //mare
   {
        ingrediente.sos_rosii=100;
        ingrediente.cheddar=60;
        ingrediente.rosii=60;
        ingrediente.masline=60;
        ingrediente.ciuperci=60;
   }

}

istream& operator >>(istream&in, Mediterraneo &a)
{
cout<<"\nCe dimensiune doriti sa aiba pizza? 1. Mica | 2. Medie | 3. Mare\n";
int marime;
in>>marime;
a.size=marime;


    return in;
}

Mediterraneo Mediterraneo::operator=(const Mediterraneo &a)
{
    size=a.size;
}

void Mediterraneo::Afisare()
{
    cout <<"Pizza Mediterraneo";
}



//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------




class Pomodoro: public Pizza
{
    public:
    Pomodoro();
    friend istream& operator >>(istream &in,Pomodoro &);
    Pomodoro operator = (const Pomodoro&);
    void Preparare(int );
    void Afisare();

};


Pomodoro::Pomodoro()
{
    vegetarian=1;
    ingrediente.sos_rosii=0;
   ingrediente.mozzarella=0;
   ingrediente.sunca=0; ingrediente.vita=0; ingrediente.pepperoni=0; ingrediente.bacon=0; ingrediente.chorizo=0; ingrediente.pui=0; ingrediente.ton=0; ingrediente.carnati=0;
    ingrediente.jalapeno=0; ingrediente.ardei=0; ingrediente.ciuperci=0;
}


void  Pomodoro::Preparare(int x)
{
    size =x;
       if(x==1) //mica
   {
      ingrediente.sos_bbq=40;
        ingrediente.cheddar=20;
        ingrediente.parmezan=20;
        ingrediente.rosii=20;
        ingrediente.masline=20;
        ingrediente.ciuperci=20;
         ingrediente.ceapa=20;
         ingrediente.porumb=20;
   }

   if(x==2) //medie
   {
        ingrediente.sos_bbq=70;
          ingrediente.cheddar=40;
          ingrediente.parmezan=40;
        ingrediente.rosii=30;
        ingrediente.masline=30;
        ingrediente.ciuperci=30;
         ingrediente.ceapa=30;
         ingrediente.porumb=30;
   }

   if(x==3) //mare
   {
        ingrediente.sos_bbq=100;
        ingrediente.cheddar=40;
        ingrediente.parmezan=40;
        ingrediente.rosii=35;
        ingrediente.masline=35;
        ingrediente.ciuperci=35;
         ingrediente.ceapa=35;
         ingrediente.porumb=35;
   }

}

istream& operator >>(istream&in, Pomodoro &a)
{
cout<<"\nCe dimensiune doriti sa aiba pizza? 1. Mica | 2. Medie | 3. Mare\n";
int marime;
in>>marime;
a.size=marime;


    return in;
}

Pomodoro Pomodoro::operator=(const Pomodoro &a)
{
    size=a.size;
}

void Pomodoro::Afisare()
{
    cout <<"Pizza Pomodoro";
}



//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------




template <class T> class Meniu
{
    public:

        int index;
        float pret;
        Pizza * comanda=new T[100];

        Meniu()
        {
            index=0;
            pret=0;
        }


        Meniu& operator+=(float a)
        {
            index=index+a;
            return *this;
       }

        float calcul(int marime)
        {
            T* ob1=dynamic_cast<T*>(&comanda[index]);
            ob1->Preparare(marime);
            return ob1->CalculPret();
        }
};




int main()
{
int nr,marime;
Meniu<Margerita> meniu1; Meniu <Diavola> meniu2; Meniu <Carnivora> meniu3; Meniu <Mediterraneo> meniu4; Meniu <Pomodoro> meniu5;
int optiune,optiune1, optiune2;


cout<<"--------------------------------------Bine ati venit la OricumPicamLaExamenPizza!--------------------------------------\n\nDoiriti sa comandati? 1. Da | 2. Nu\n";
cin>>optiune1;
while(optiune1<1||optiune1>2)
{
 cout<<"Optiune invalida! Va rugam incercati din nou\n";
 cin>>optiune1;
}
cout<<"\n";

do
{
switch(optiune1)
{
    case 1:
        {
                        cout<<"Doriti sa comandati online? 1. Da 2. Nu\n";
                        cin>>optiune2;
                        while(optiune2<1||optiune2>2)
                                {
                                 cout<<"Optiune invalida! Va rugam incercati din nou\n";
                                 cin>>optiune2;
                                }
                        cout<<'\n';

                            if(optiune2==2)
                                {
                                        cout<<"Cate pizza doriti sa comandati?  ";
                                        cin>>nr;
                                        for(int i=1;i<=nr;i++)
                                        {
                                            cout<<"\nMeniul nostru este: 1. Pizza Margerita | 2. Pizza Diavola | 3. Pizza Carnivora | 4. Pizza Mediterraneo | 5.  Pizza Pomodoro\n";
                                            cin>>optiune;
                                                    while(optiune<1||optiune>5)
                                                    {
                                                        cout<<"Optiune invalida! Va rugam incercati din nou\n";
                                                        cin>>optiune; cout<<"\n";
                                                    }
                                            cout<<"\n\n";

                                            switch(optiune)
                                            {
                                            case 1:
                                                {
                                                    cout<<"Marime: 1. Mica | 2. Medie | 3. Mare\n";
                                                    cin>>marime;
                                                    while(marime<1||marime>3)
                                                    {
                                                        cout<<"Optiune invalida! Va rugam incercati din nou\n";
                                                        cin>>marime; cout<<"\n";
                                                    }
                                                    meniu1.pret+=meniu1.calcul(marime);
                                                    meniu1+=1;

                                                break;
                                            }
                                        case 2:
                                            {
                                                cout<<"Marime: 1. Mica | 2. Medie | 3. Mare\n";
                                                cin>>marime;
                                                    while(marime<1||marime>3)
                                                    {
                                                        cout<<"Optiune invalida! Va rugam incercati din nou\n";
                                                        cin>>marime; cout<<"\n";
                                                    }
                                                meniu2.pret+=meniu2.calcul(marime);
                                                meniu2+=1;
                                                break;
                                            }
                                        case 3:
                                            {
                                                cout<<"Marime: 1. Mica | 2. Medie | 3. Mare\n";
                                                cin>>marime;
                                                    while(marime<1||marime>3)
                                                    {
                                                        cout<<"Optiune invalida! Va rugam incercati din nou\n";
                                                        cin>>marime; cout<<"\n";
                                                    }
                                                meniu3.pret+=meniu3.calcul(marime);
                                                meniu3+=1;
                                                break;
                                            }
                                        case 4:
                                            {
                                                cout<<"Marime: 1. Mica | 2. Medie | 3. Mare\n";
                                                cin>>marime;
                                                    while(marime<1||marime>3)
                                                    {
                                                        cout<<"Optiune invalida! Va rugam incercati din nou\n";
                                                        cin>>marime; cout<<"\n";
                                                    }
                                                meniu4.pret+=meniu4.calcul(marime);
                                                meniu4+=1;
                                                break;
                                            }
                                        case 5:
                                            {
                                                cout<<"Marime: 1. Mica | 2. Medie | 3. Mare\n";
                                                cin>>marime;
                                                    while(marime<1||marime>3)
                                                    {
                                                        cout<<"Optiune invalida! Va rugam incercati din nou\n";
                                                        cin>>marime; cout<<"\n";
                                                    }
                                                meniu5.pret+=meniu5.calcul(marime);
                                                meniu5+=5;
                                                break;
                                            }
                                        default:
                                            {
                                                cout<<"\nOptiune invalida!";
                                            }
                                        }
                                    }

                            }
                        if(optiune2==1)
                            {           cout<<"Introduceti distanta fata de pizzerie in km\n";
                                        int distanta; cin>>distanta; if(distanta<10) distanta=10; cout<<'\n';
                                        cout<<"Cate pizza doriti sa comandati?  ";
                                        cin>>nr;
                                        for(int i=1;i<=nr;i++)
                                        {
                                            cout<<"\nMeniul nostru este: 1. Pizza Margerita | 2. Pizza Diavola | 3. Pizza Carnivora | 4. Pizza Mediterraneo | 5.  Pizza Pomodoro\n";
                                            cin>>optiune;
                                                    while(optiune<1||optiune>5)
                                                    {
                                                        cout<<"Optiune invalida! Va rugam incercati din nou\n";
                                                        cin>>optiune; cout<<"\n";
                                                    }
                                            cout<<"\n\n";

                                            switch(optiune)
                                            {
                                            case 1:
                                                {
                                                    cout<<"Marime: 1. Mica | 2. Medie | 3. Mare\n";
                                                    cin>>marime;
                                                    while(marime<1||marime>3)
                                                    {
                                                        cout<<"Optiune invalida! Va rugam incercati din nou\n";
                                                        cin>>marime; cout<<"\n";
                                                    }
                                                    float temp;
                                                    temp=meniu1.calcul(marime);
                                                    temp+=(0.05*(distanta/10))*temp;
                                                    meniu1.pret+=temp;
                                                    meniu1+=1;
                                                break;
                                            }
                                        case 2:
                                            {
                                                cout<<"Marime: 1. Mica | 2. Medie | 3. Mare\n";
                                                cin>>marime;
                                                    while(marime<1||marime>3)
                                                    {
                                                        cout<<"Optiune invalida! Va rugam incercati din nou\n";
                                                        cin>>marime; cout<<"\n";
                                                    }
                                                    float temp;
                                                    temp=meniu2.calcul(marime);
                                                    temp+=(0.05*(distanta/10))*temp;
                                                    meniu2.pret+=temp;
                                                    meniu2+=1;
                                                break;
                                            }
                                        case 3:
                                            {
                                                cout<<"Marime: 1. Mica | 2. Medie | 3. Mare\n";
                                                cin>>marime;
                                                    while(marime<1||marime>3)
                                                    {
                                                        cout<<"Optiune invalida! Va rugam incercati din nou\n";
                                                        cin>>marime; cout<<"\n";
                                                    }
                                                    float temp;
                                                    temp=meniu3.calcul(marime);
                                                    temp+=(0.05*(distanta/10))*temp;
                                                    meniu3.pret+=temp;
                                                    meniu3+=1;
                                                break;
                                            }
                                        case 4:
                                            {
                                                cout<<"Marime: 1. Mica | 2. Medie | 3. Mare\n";
                                                cin>>marime;
                                                    while(marime<1||marime>3)
                                                    {
                                                        cout<<"Optiune invalida! Va rugam incercati din nou\n";
                                                        cin>>marime; cout<<"\n";
                                                    }
                                                    float temp;
                                                    temp=meniu4.calcul(marime);
                                                    temp+=(0.05*(distanta/10))*temp;
                                                    meniu4.pret+=temp;
                                                    meniu4+=1;
                                                break;
                                            }
                                        case 5:
                                            {
                                                cout<<"Marime: 1. Mica | 2. Medie | 3. Mare\n";
                                                cin>>marime;
                                                    while(marime<1||marime>3)
                                                    {
                                                        cout<<"Optiune invalida! Va rugam incercati din nou\n";
                                                        cin>>marime; cout<<"\n";
                                                    }
                                                    float temp;
                                                    temp=meniu5.calcul(marime);
                                                    temp+=(0.05*(distanta/10))*temp;
                                                    meniu5.pret+=temp;
                                                    meniu5+=1;
                                                break;
                                            }
                                        default:
                                            {
                                                cout<<"\nOptiune invalida!";
                                            }
                                        }
                                    }

                            }


                                    cout<<"Mai doriti sa comandati si altceva? 1. Da | 2. Nu\n";
                                    int optiune3; cin>>optiune3;
                                    if(optiune3==2) optiune1=0;
                                    cout<<"\n\n";
                                    break;
            }




        default:
            {
                  cout<<"Multumim ca ati comandat de la noi!\n\n-----------------------------------------------------------------------------------\n\n";
                  break;
            }

   }
}while (optiune1==1);


float pret_normal=meniu1.pret+meniu2.pret+meniu3.pret;
float pret_veg=meniu4.pret+meniu5.pret;

cout<<"Dupa aceasta rulare au fost vandute : "<<meniu1.index<<" pizza Margerita, "<<meniu2.index<< " pizza Diavola, "<<meniu3.index<< " pizza Carnivora, "<<meniu4.index<<" pizza Mediterraneo, "<< meniu5.index<< " pizza Pomodoro\n";
cout<<"Din vanzarea pizzei normale s-au strans "<< pret_normal<< " lei\n";
cout<<"Din vanzarea pizzei vegetariene s-au strans " <<pret_veg<< " lei\n";
cout<<"Per total s-au strans " << pret_normal+pret_veg<<" lei\n\n";










    return 0;
}
