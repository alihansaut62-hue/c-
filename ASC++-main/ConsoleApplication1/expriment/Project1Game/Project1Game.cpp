#include <clocale>
#include <string>
#include <iostream>
#include <random>


using std::string;
using std::cout;
using std::endl;
using std::cin;



class Hiro {
private:
    string name;
    int health;
    int damage;
public:
    Hiro(string name, int health, int damage)
    {
        this->name = name;
        this->health = health;
        this->damage = damage;
	}

    ~Hiro()
    {
        cout << name << " is destroyed" << endl;
    }

    Hiro()
    {
        name = "Unknown";
        health = 0;
        damage = 0;
    }

    string getName()
    {
        return name;
	}

    int gethealth()
    {
        return health;
    }

    int getdamage()
    {
        return damage;
    }
    void takeDamageH(int dmg) {
        this->health -= dmg;


        if (health < 0) {
            health = 0;
        }
    }
};


class Monstr {
    string name;
    int health;
    int damage;
public:
    Monstr(string name, int health, int damage)
    {
        this->name = name;
        this->health = health;
        this->damage = damage;
    }


    ~Monstr()
    {
        cout << name << " is destroyed" << endl;
    }

    Monstr()
    {
        name = "Unknown";
        health = 100;
        damage = 10;
    }

    string getName()
    {
        return name;
    }

    int gethealth()
    {
        return health;
    }

    int getdamage()
    {
        return damage;
    }

    void takeDamageM(int dmg) {
        this->health -= dmg;


        if (health < 0) {
            health = 0;
        }
    }
};



int main()
{
    setlocale(LC_ALL, "Russian");

    Hiro hero1("Alex", 100, 15);
    Monstr monstr1("Panda", 100, 15);






    while (true)
    {




        int AtakHiro = 0;
        int HilHiro = 0;
		int AtakMonstr = 0;
        int HilMonstr = 0;




        string actions;
        cout << "если атакуете используйте (a) если хиляетесь (h)" << endl;
        cout << "для выхда нажмите (q)" << endl;
        cin >> actions;



        if (actions == "q") {
            cout << "вы вышли из игры" << endl;
            break;
        }
        else if (actions == "a"){
            std::random_device rd;
            std::mt19937 gen(rd());

            std::uniform_int_distribution<> dist(1, 4);

            AtakHiro = dist(gen);
            
            if (AtakHiro == 1 || AtakHiro == 2 || AtakHiro == 3) {
                std::random_device rd;
                std::mt19937 gen(rd());

                std::uniform_int_distribution<> dist(5, 20);

                AtakHiro = dist(gen);
                


                std::cout << "dammag Hiro" << AtakHiro << endl;
            }
            else
            {
                std::random_device rd;
                std::mt19937 gen(rd());

                std::uniform_int_distribution<> dist(5, 20);

                AtakHiro = dist(gen);
				AtakHiro = AtakHiro * 2;

                std::cout << "CRIT dammag Hiro" << AtakHiro << endl;

            }

		 

    }
        else if (actions == "h") {
            std::random_device rd;
            std::mt19937 gen(rd());

            std::uniform_int_distribution<> dist(5, 20);

            HilHiro = dist(gen);

            std::cout << "hil Hiro" << HilHiro << endl;
        }


        std::random_device rd;
        std::mt19937 gen(rd());

        std::uniform_int_distribution<> dist(1, 3);

        int AtakM = dist(gen);

        std::cout << "" << AtakM << endl;

        if (AtakM == 1 || AtakM == 2) {
            std::random_device rd;
            std::mt19937 gen(rd());

            std::uniform_int_distribution<> dist(5, 20);

            AtakMonstr = dist(gen);


            std::cout << "dammag monstr" << AtakMonstr << endl;
            
        }
        else if (AtakM == 3) {
            std::random_device rd;
            std::mt19937 gen(rd());

            std::uniform_int_distribution<> dist(5, 20);

            HilMonstr = dist(gen);

            std::cout << "hil monstr" << HilMonstr << endl;


        }









        hero1 =
            Hiro(hero1.getName(),
                hero1.gethealth() - AtakMonstr + HilHiro,
                hero1.getdamage() );

        cout << "Name: " << hero1.getName() << endl;
        cout << "Health: " << hero1.gethealth() << endl;
        cout << "Damage: " << hero1.getdamage() << endl;

        monstr1 =
            Monstr(monstr1.getName(),
                monstr1.gethealth() - AtakHiro + HilMonstr,
                monstr1.getdamage() );
        cout << "Name: " << monstr1.getName() << endl;
        cout << "Health: " << monstr1.gethealth() << endl;
        cout << "Damage: " << monstr1.getdamage() << endl;


        if (hero1.gethealth() <= 0) {
            cout << "Монстр победил!" << endl;
            break;
        }
        else if (monstr1.gethealth() <= 0) {
            cout << "Герой победил!" << endl;
            break;
        }


    }




		return 0;
}


