#include<bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#ifdef _WIN32
#include <windows.h>
#endif

#define MAX 256

int browse_pets(); // Now only one prototype without arguments
int browse_breeds(int a);

void print_species_file();
void print_breed1_file();
void print_breed2_file();
void print_breed3_file();
void know_breed(int a,int b);
int post_know();
void buy_breed(int a,int b);
void adoption_certificate(int a,int b,int c);

void manager_menu();
int mn_choice();
void consequence(int a);

static void to_lowercase(std::string &s) {
    for (auto &ch : s) {
        ch = (char)std::tolower((unsigned char)ch);
    }
}

int main()
{
    system("COLOR 0A");
    std::cout << "\n\n_";
    std::cout << "\n_\n\n\n\n";
    std::cout << "\t\t\t\t\t\t\t\t\t\t\t\t\tPET ADOPTION CENTER\n\n\n\n\n";
    char name[20];
    std::string mn = "manager";
    std::string cst = "customer";

    std::cout << "Hello, Welcome to our PET ADOPTION CENTER\n\n\n\n";
    std::cout << "Enter your role: ";
    std::string role;
    std::getline(std::cin, role);

    system("pause");
    system("cls");

    {
        std::string role_lower = role;
        std::string cst_lower = cst;
        std::string mn_lower = mn;
        to_lowercase(role_lower);
        to_lowercase(cst_lower);
        to_lowercase(mn_lower);

        if (role_lower == cst_lower) {
            std::cout << "ENTER YOUR NAME: ";
            std::string uname;
            std::getline(std::cin, uname);
            strncpy(name, uname.c_str(), sizeof(name));
            name[sizeof(name)-1] = '\0';

            system("COLOR 0B");
            system("cls");
            std::cout << "\n\n\n\n\t\t\t\t\t\t Hello " << name << "\n";
            std::cout << "\t\t\t\t\t\tLooking to add a pet to your family ? Find one at this pet adoption center ......\n";
            int species_ = browse_pets();
            int breed_ = browse_breeds(species_);
            know_breed(species_, breed_);
            int ans_ = post_know();

            const char animal1[] = "Cockatiel";
            const char animal2[] = "Hyacinth Macaw";
            const char animal3[] = "Budgerigar";
            const char animal4[] = "Green Cheeked Conure";
            char animal5[20] = "Electus Parrot";
            const char animal6[] = "Persian Cats";
            const char animal7[] = "British Shorthairs";
            const char animal8[] = "Ragdoll";
            const char animal9[] = "Maine Coon";
            const char animal10[] = "Siamese Cats";
            const char animal11[] = "Golden Retreiver";
            const char animal12[] = "Poodle";
            const char animal13[] = "Siberian Husky";
            const char animal14[] = "German Shepherd";
            const char animal15[] = "Labrador Retriever";

            int ans, species, breed;
            ans = ans_; species = species_; breed = breed_;
            std::cout << ans << " " << species << " " << breed << "\n"; // debug

            char animal[20];

            if (ans == 121 || ans == 89) {
                if (species == 1) {
                    if (breed == 1) {
                        strcpy(animal, animal1);
                    } else if (breed == 2) {
                        strcpy(animal, animal2);
                    } else if (breed == 3) {
                        strcpy(animal, animal3);
                    } else if (breed == 4) {
                        strcpy(animal, animal4);
                    } else if (breed == 5) {
                        strcpy(animal, animal5);
                    }

                } else if (species == 2) {
                    if (breed == 1) {
                        strcpy(animal, animal6);
                    } else if (breed == 2) {
                        strcpy(animal, animal7);
                    } else if (breed == 3) {
                        strcpy(animal, animal8);
                    } else if (breed == 4) {
                        strcpy(animal, animal9);
                    } else if (breed == 5) {
                        strcpy(animal, animal10);
                    }

                } else if (species == 3) {
                    if (breed == 1) {
                        strcpy(animal, animal11);
                    } else if (breed == 2) {
                        strcpy(animal, animal12);
                    } else if (breed == 3) {
                        strcpy(animal, animal13);
                    } else if (breed == 4) {
                        strcpy(animal, animal14);
                    } else if (breed == 5) {
                        strcpy(animal, animal15);
                    }

                }
                system("cls");
                std::cout << "\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\tADOPTION CERTIFICATE\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                std::cout << "\t\t\t\t\t\t\t\t\t\tThis is to certify that \n\t\t\t\t\t\t\t\t\t\t\t" << name
                          << " \n\t\t\t\t\t\t\t\t\t\thas adopted \n\t\t\t\t\t\t\t\t\t\t\t" << animal
                          << " \n\t\t\t\t\t\t\t\t\t\tAnd invited into their forever home.\n\n\n";
            }
        } else if (role_lower == mn_lower) {
            std::cout << "ENTER YOUR ID: ";
            std::string manager_id;
            std::getline(std::cin, manager_id);
            strncpy(name, manager_id.c_str(), sizeof(name));
            name[sizeof(name)-1] = '\0';

            system("COLOR 0E");
            system("cls");
            std::cout << "Hello Manager!!\n\n";
            manager_menu();
            int choice = mn_choice();
            consequence(choice);
        }
    }

    return 0;
}


void print_file_content(const std::string &filename) {
    std::ifstream file(filename);
    if(!file.is_open()) {
        std::cout << "\nFile does not exist";
        return;
    }
    std::cout << "\n\n\n\n\n\n";
    std::string line;
    while(std::getline(file, line)) {
        std::cout << line << "\n";
    }
    std::cout << "\n\n";
}

void print_species_file()
{
    print_file_content("species.txt");
}

void print_breed1_file()
{
    system("cls");
    print_file_content("breed1.txt");
}

void print_breed2_file()
{
    system("cls");
    print_file_content("breed2.txt");
}

void print_breed3_file()
{
    system("cls");
    print_file_content("breed3.txt");
}


int browse_pets() // single definition with no parameter
{
    print_species_file();
    std::cout << "\n";
    int a;
    std::cin >> a;
    if(a>=1 && a<=3)
    {
        return a;
    }
    else
    {
        system("cls");
        std::cout << "\n\n\n\t\tInvalid choice\n\n";
        std::cin.clear();std::cin.ignore(INT_MAX, '\n');
        return browse_pets();
    }
}


int browse_breeds(int a)
{
    std::cout<<"Choose your favourite breed of pets:\n\n";
    int n;
    if(a==1)
    {
        std::cout << "\t\tMake your choice:\n\n\n\n";
        print_breed1_file();
        std::cin >> n;
        return n;

    }
    else if(a==2)
    {
        std::cout << "\t\tMake your choice:\n\n";
        print_breed2_file();
        std::cin >> n;
        return n;

    }
    else if(a==3)
    {
        std::cout << "\t\tMake your choice:\n\n";
        print_breed3_file();
        std::cin >> n;
        return n;
    }
    else return -1;
}

void print_breed_info(const std::string &filename) {
    std::ifstream file(filename, std::ios::in|std::ios::app);
    if(!file.is_open()) {
        std::cout<<"\nFile does not exist";
        return;
    }
    char c;
    while(file.get(c)) {
        std::cout << c;
    }
    file.close();
}

void know_breed(int a,int b)
{
    std::string filename;
    if(a==1&&b==1) filename="cockatiel.txt";
    else if(a==1&&b==2) filename="Hyacinth Macaw.txt";
    else if(a==1&&b==3) filename="Budgerigar.txt";
    else if(a==1&&b==4) filename="Green Cheeked Conure.txt";
    else if(a==1&&b==5) filename="Eclectus Parrot.txt";
    else if(a==2&&b==1) filename="Persian Cat.txt";
    else if(a==2&&b==2) filename="British Shorthair.txt";
    else if(a==2&&b==3) filename="Ragdoll.txt";
    else if(a==2&&b==4) filename="Maine Coon.txt";
    else if(a==2&&b==5) filename="Siamese Cats.txt";
    else if(a==3&&b==1) filename="Golden Retriever.txt";
    else if(a==3&&b==2) filename="Poodle.txt";
    else if(a==3&&b==3) filename="Siberian Husky.txt";
    else if(a==3&&b==4) filename="German Shepherd.txt";
    else if(a==3&&b==5) filename="Labrador Retriever.txt";

    if(!filename.empty()) {
        print_breed_info(filename);
    } else {
        std::cout<<"\nFile does not exist";
    }
}


int post_know()
{
    std::cout<<"Enter 'y' for yes and 'n' for no :\n";
    std::string c;
    std::cin >> c;
    if (c=="y" || c=="Y")
    {
        std::cout<<"Thank you for adopting the pet.\nYou have found your new friend.\n";
        return 121;
    }
    else if (c=="n" || c=="N")
    {
        std::cout<<"Thank you for visiting.\n";
        std::exit(1);
    }

    else  return post_know();
}



void manager_menu()
{
    std::cout<<"\t\tWhat would you like to do?\n\n";
    std::cout<<"\t\tPress 1 to add pets.\n\n";
    std::cout<<"\t\tPress 2 to update status of pets.\n\n";
    std::cout<<"\t\tPress 3 to delete records.\n\n";
    std::cout<<"\t\tPress 4 to exit.\n\n";
}

int mn_choice()
{
    std::cout<<"\nEnter your choice:\n";
    int a;
    std::cin >> a;
    if(a>=1&&a<=4)
    {
        return a;
    }
    else
    {
        system("cls");
        std::cout<<"\n\n\n\t\tInvalid choice\n\n";
        manager_menu();
        std::cin.clear();std::cin.ignore(INT_MAX, '\n');
        return mn_choice();
    }
}


void consequence(int a)
{
    std::cin.ignore(INT_MAX, '\n'); // clear leftover newline

    if(a==1)
    {
        int n;
        std::cout<<"In which species do you want to add pets?\n";
        print_species_file();
        std::cin >> n;std::cin.ignore(INT_MAX, '\n');
        std::string filename;
        if(n==1) filename="breed1.txt";
        else if(n==2) filename="breed2.txt";
        else if(n==3) filename="breed3.txt";
        else {
            system("cls");
            std::cout<<"Invalid choice\n";
            consequence(a);
            return;
        }

        std::ofstream fptr(filename, std::ios::app);
        if(!fptr.is_open()) {
            std::cout<<"Cannot open file to append.\n";
            return;
        }

        std::cout<<"------------------------------------------------------\n";
        std::cout<<" Input the number of breeds to be added : ";
        int count; std::cin >> count;std::cin.ignore(INT_MAX, '\n');
        std::cout<<" The lines are : \n";
        for(int i = 0; i < count+1;i++)
        {
            std::string str;
            std::getline(std::cin, str);
            fptr << str << "\n";
        }
        fptr.close();

        {
            std::ifstream rfptr(filename);
            std::cout<<"\n The content of the file is  :\n";
            char ch;
            while(rfptr.get(ch)) {
                std::cout<<ch;
            }
            std::cout<<"\n\n";
        }
    }
    else if(a==2)
    {
        int n;
        print_species_file();
        std::cout<<"\n";
        std::cin >> n;std::cin.ignore(INT_MAX, '\n');

        if(n==1)
        {
            std::cout<<"\t\tMake your choice:\n\n";
            print_breed1_file();
        }
        else if(n==2)
        {
            std::cout<<"\t\tMake your choice:\n\n";
            print_breed2_file();
        }
        else if(n==3)
        {
            std::cout<<"\t\tMake your choice:\n\n";
            print_breed3_file();
        }
        else
        {
            consequence(a);
            return;
        }

        std::cout<<"\n\n Name of the file is the same as that of the animal :\n";
        std::cout<<"-------------------------------------------------------------\n";
        std::cout<<" Input the file name to be opened : ";
        std::string fname;
        std::getline(std::cin, fname);

        while(!fname.empty() && isspace((unsigned char)fname.back()))
            fname.pop_back();

        std::ifstream fptr1(fname);
        if(!fptr1.is_open())
        {
            std::cout<<"Unable to open the input file!!\n";
            consequence(a);
            return;
        }

        std::string temp = "temp.txt";
        std::ofstream fptr2(temp);
        if(!fptr2.is_open())
        {
            std::cout<<"Unable to open a temporary file to write!!\n";
            fptr1.close();
            return;
        }

        std::cout<<" Input the content of the new line : ";
        std::string newln;
        std::getline(std::cin, newln);

        std::cout<<" Input the line no you want to replace : ";
        int lno;
        std::cin >> lno;std::cin.ignore(INT_MAX, '\n');

        fptr1.clear();
        fptr1.seekg(0,std::ios::beg);
        std::vector<std::string> lines;
        {
            std::string line;
            while(std::getline(fptr1, line)) {
                lines.push_back(line);
            }
        }
        fptr1.close();

        if(lno > 0 && lno <= (int)lines.size()) {
            lines[lno-1] = newln;
        }

        for(auto &line: lines) {
            fptr2 << line << "\n";
        }

        fptr2.close();

        std::remove(fname.c_str());
        std::rename(temp.c_str(), fname.c_str());
        std::cout<<" Replacement done successfully..!! \n";

    }

    else if(a==3)
    {
        int n;
        system("cls");
        std::cout<<"Enter for which species you want to delete the breed: ";
        print_species_file();
        std::cin >> n;std::cin.ignore(INT_MAX, '\n');
        std::string filename;
        if(n==1) filename="breed1.txt";
        else if(n==2) filename="breed2.txt";
        else if(n==3) filename="breed3.txt";
        else {
            system("cls");
            std::cout<<"Invalid choice\n";
            consequence(a);
            return;
        }

        {
            std::ifstream fp1(filename);
            if(!fp1.is_open()) {
                std::cout<<"\nUnable to open file\n";
                return;
            }

            std::cout<<"\nCurrent file content:\n";
            {
                fp1.clear();
                fp1.seekg(0,std::ios::beg);
                char ch;
                while(fp1.get(ch)) {
                    std::cout<<ch;
                }
            }

            fp1.clear();
            fp1.seekg(0,std::ios::beg);
            std::cout<<"\nEnter line number to delete the line: ";
            int line;std::cin>>line;std::cin.ignore(INT_MAX, '\n');

            fp1.clear();
            fp1.seekg(0,std::ios::beg);
            std::vector<std::string> lines;
            {
                std::string ln;
                while(std::getline(fp1, ln)) {
                    lines.push_back(ln);
                }
            }
            fp1.close();

            if(line>0 && line<=(int)lines.size()) {
                lines.erase(lines.begin()+(line-1));
            }

            std::ofstream fp2("temp.txt");
            for(auto &l: lines) {
                fp2<<l<<"\n";
            }
            fp2.close();

            std::remove(filename.c_str());
            std::rename("temp.txt", filename.c_str());

            std::cout<<"\nModified file:\n";
            {
                std::ifstream fp3(filename);
                if(fp3.is_open()) {
                    char ch;
                    while(fp3.get(ch)) {
                        std::cout<<ch;
                    }
                    fp3.close();
                }
            }

            std::cout<<"\n";
        }
    }
    else if(a==4)
    {
        return;
    }
}
