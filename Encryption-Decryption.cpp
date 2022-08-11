#include <bits/stdc++.h>
using namespace std;

struct edSystem {

	void run() {

		while (true) {
			int choice = menu();

			if (choice == 1)
				Encrypt();
			else if (choice == 2)
				Decrypt();
			else
				break;
		}
	}

	int menu() {

		int choice = -1;

		while (choice == -1) {
			cout << "\n1) Encrypt a File\n"
					"2) Decrypt a File\n"
					"3) Exit\n"
					"Enter your choice:";
			cin >> choice;
			if (cin.fail())
				break;

			if (!(1 <= choice && choice <= 3)) {
				cout << "\n\nInvalid choice. try again!\n";
				choice = -1;
			}
		}

		return choice;
	}


	void Encrypt() {

	    char fileName[30], ch;
	    fstream fps, fpt;
	    cout<<"Enter the Name of File: ";
	    cin>>fileName;
	    fps.open(fileName, fstream::in);
	    if(!fps)
	    {
	        cout<<"\nError Occurred, Opening the Source File (to Read)!";
	        return;
	    }
	    fpt.open("tmp.txt", fstream::out);
	    if(!fpt)
	    {
	        cout<<"\nError Occurred, Opening/Creating the tmp File!";
	        return;
	    }
	    while(fps>>noskipws>>ch)
	    {
	        ch = ch+100;
	        fpt<<ch;
	    }
	    fps.close();
	    fpt.close();
	    fps.open(fileName, fstream::out);
	    if(!fps)
	    {
	        cout<<"\nError Occurred, Opening the Source File (to write)!";
	        return;
	    }
	    fpt.open("tmp.txt", fstream::in);
	    if(!fpt)
	    {
	        cout<<"\nError Occurred, Opening the tmp File!";
	        return;
	    }
	    while(fpt>>noskipws>>ch)
	        fps<<ch;
	    fps.close();
	    fpt.close();
	    cout<<"\nFile '"<<fileName<<"' Encrypted Successfully!";
	    cout<<endl;

	}

	void Decrypt() {
		  char fileName[30], ch;
		    fstream fps, fpt;
		    cout<<"Enter the Name of File: ";
		    cin>>fileName;
		    fps.open(fileName, fstream::out);
		    if(!fps)
		    {
		        cout<<"\nError Occurred while Opening the Source File!";
		        return;
		    }
		    fpt.open("tmp.txt", fstream::in);
		    if(!fpt)
		    {
		        cout<<"\nError Occurred while Opening/Creating tmp File!";
		        return;
		    }
		    while(fpt>>noskipws>>ch)
		    {
		        ch = ch-100;
		        fps<<ch;
		    }
		    fps.close();
		    fpt.close();
		    cout<<"\nFile '"<<fileName<<"' Decrypted Successfully!";
		    cout<<endl;
	}
};

int main(int argc, char **argv)
{
	edSystem service;
	service.run();

        return 0;
}
