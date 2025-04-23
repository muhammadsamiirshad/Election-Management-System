#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <windows.h> // For colors and sleep function
#include <conio.h>   // For getch()
#include <thread>    // For sleep duration
#include <chrono>    // For time handling
using namespace std;

// Colors for console text
enum Color {
    BLACK = 0,
    BLUE = 1,
    GREEN = 2,
    CYAN = 3,
    RED = 4,
    MAGENTA = 5,
    BROWN = 6,
    LIGHTGRAY = 7,
    DARKGRAY = 8,
    LIGHTBLUE = 9,
    LIGHTGREEN = 10,
    LIGHTCYAN = 11,
    LIGHTRED = 12,
    LIGHTMAGENTA = 13,
    YELLOW = 14,
    WHITE = 15
};

// Utility functions for improved UI
void setColor(Color textColor, Color bgColor = BLACK) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (textColor + (bgColor * 16)));
}

void resetColor() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
}

void clearScreen() {
    system("cls");
}

void printCentered(const string& text, int width = 80) {
    int padding = (width - text.length()) / 2;
    cout << string(padding, ' ') << text << endl;
}

void printHeader(const string& header, Color textColor = LIGHTCYAN, Color bgColor = BLACK) {
    clearScreen();
    setColor(textColor, bgColor);
    cout << string(80, '=') << endl;
    printCentered(header);
    cout << string(80, '=') << endl << endl;
    resetColor();
}

void printProgressBar(int percentage) {
    const int barWidth = 70;
    cout << "[";
    int pos = barWidth * percentage / 100;
    for (int i = 0; i < barWidth; ++i) {
        if (i < pos) cout << "=";
        else if (i == pos) cout << ">";
        else cout << " ";
    }
    cout << "] " << percentage << " %\r";
    cout.flush();
}

void loadingAnimation(const string& message, int duration = 10) {
    cout << message;
    for (int i = 0; i <= 100; i += 10) {
        printProgressBar(i);
        Sleep(duration * 10);
    }
    cout << endl;
}

// Draw a box with title and options (without using vectors)
void drawBox(const string& title, const string options[], int optionCount) {
    int width = 60;
    int maxOptionLength = title.length();
    
    // Find max option length
    for (int i = 0; i < optionCount; i++) {
        if (options[i].length() > maxOptionLength) {
            maxOptionLength = options[i].length();
        }
    }
    width = max(width, maxOptionLength + 10);
    
    // Top border
    setColor(YELLOW);
    cout << "+" << string(width - 2, '=') << "+" << endl;
    
    // Title
    cout << "|";
    setColor(LIGHTCYAN);
    cout << setw((width - 2) / 2 + title.length() / 2) << title;
    setColor(YELLOW);
    cout << setw((width - 2) / 2 - title.length() / 2) << "|" << endl;
    
    // Separator
    cout << "+" << string(width - 2, '=') << "+" << endl;
    
    // Options
    setColor(WHITE);
    for (int i = 0; i < optionCount; i++) {
        setColor(YELLOW);
        cout << "|";
        setColor(WHITE);
        cout << " " << options[i];
        setColor(YELLOW);
        cout << string(width - options[i].length() - 3, ' ') << "|" << endl;
    }
    
    // Bottom border
    cout << "+" << string(width - 2, '=') << "+" << endl;
    resetColor();
}

string getPasswordInput() {
    string password;
    char ch;
    while ((ch = _getch()) != 13) { // 13 is Enter key
        if (ch == 8) { // Backspace
            if (!password.empty()) {
                password.pop_back();
                cout << "\b \b";
            }
        } else {
            password += ch;
            cout << "*";
        }
    }
    cout << endl;
    return password;
}

class PersonalInfo
{
protected:
	string name;
	int age;
	string CNIC;
	string gender;
	string address;
	string region;

public:
	PersonalInfo()
	{
		name = "no";
		age = 0;
		CNIC = "no";
		gender = "no";
		address = "no";
		region = "no";
	}
	void inputData()
	{
		cin.ignore();
		cout << "Enter Name: ";
		getline(cin, name);

		cout << "Enter age: ";
		cin >> age;

		cin.ignore();
		cout << "Enter Gender: ";
		getline(cin, gender);

		cout << "Enter Address: ";
		getline(cin, address);

		cout << "Enter CNIC: ";
		getline(cin, CNIC);
	}
	string getName()
	{
		return name;
	}
	string getCnic()
	{
		return CNIC;
	}
	string getGender()
	{
		return gender;
	}
	string getAddress()
	{
		return address;
	}
	string getRegion()
	{
		return region;
	}

	int getAge()
	{
		return age;
	}
	void setName(string n)
	{
		name = n;
	}

	void setAddress(string add)
	{
		address = add;
	}
	void setGender(string gnd)
	{
		gender = gnd;
	}
	void setCNIC(string cnic)
	{
		CNIC = cnic;
	}
	void setRegion(string reg)
	{
		region = reg;
	}
	void setAge(int a)
	{
		age = a;
	}
};
class Login
{
protected:
	string userName;
	string Password;

public:
	virtual bool login(string, string) = 0;

	virtual ~Login() {}
};
// class PresidingOfficer;
// class Candidate;
class Result
{
	string region;
	int regdVote;
	int castVote;
	string candidate;
	string party;
	int votes;

public:
	string getRegion()
	{
		return region;
	}
	int getRegdVote()
	{
		return regdVote;
	}
	int getCastVote()
	{
		return castVote;
	}
	string getCandidate()
	{
		return candidate;
	}
	string getParty()
	{
		return party;
	}
	int getVotes()
	{
		return votes;
	}

	void setRegion(string reg)
	{
		region = reg;
	}
	void setRegdVote(int r)
	{
		regdVote = r;
	}
	void setCastVote(int c)
	{
		castVote = c;
	}
	void setCandidate(string c)
	{
		candidate = c;
	}
	void setParty(string p)
	{
		party = p;
	}
	void setVotes(int v)
	{
		votes = v;
	}
	Result *loadresultDataFromFile(int size)
	{
		Result *temp = new Result[size];
		ifstream inFile("result.txt");
		if (inFile.is_open())
		{
			for (int i = 0; i < size; i++)
			{
				string line;
				if (getline(inFile, line))
				{
					stringstream ss(line);
					string regdStr, castVoteStr, votesStr;
					getline(ss, temp[i].region, ',');
					getline(ss, regdStr, ',');
					getline(ss, castVoteStr, ',');
					getline(ss, temp[i].candidate, ',');
					getline(ss, temp[i].party, ',');
					getline(ss, votesStr);

					temp[i].regdVote = stoi(regdStr);
					temp[i].castVote = stoi(castVoteStr);
					temp[i].votes = stoi(votesStr);
				}
				else
				{
					cout << "Error reading line from file(loadResultDataFromFile).\n";
				}
			}

			inFile.close();
		}
		else
		{
			cout << "Error in opening File(result.txt).\n";
		}
		return temp;
	}
	void writeResult(Result *result, int size)
	{
		ofstream outFile("result.txt");
		if (!outFile)
		{
			cout << "Error in opening File(candidate.txt" << endl;
			return;
		}
		for (int i = 0; i < size; i++)
		{
			outFile << result[i].getRegion() << "," << result[i].getRegdVote() << "," << result[i].getCastVote() << "," << result[i].getCandidate() << "," 
					<< result[i].getParty() << "," << result[i].getVotes() << endl;
		}
		outFile.close();
	}
};

class Candidate : public PersonalInfo
{
	string partyName;
	string symbol;
	// int obtainedVotes;
public:
	void CountVotes()
	{
	}
	int getCountVotes()
	{
		return 1;
	}
	string getSymbol()
	{
		return symbol;
	}
	string getpName()
	{
		return partyName;
	}
	void setSymbol(string s)
	{
		symbol = s;
	}
	void setPName(string pName)
	{
		partyName = pName;
	}
	Candidate *loadCandidateDataFromFile(int size)
	{
		Candidate *temp = new Candidate[size];
		ifstream inFile("candidate.txt");
		if (inFile.is_open())
		{
			for (int i = 0; i < size; i++)
			{
				string line;
				if (getline(inFile, line))
				{
					stringstream ss(line);
					string ageStr;
					getline(ss, temp[i].name, ',');
					getline(ss, ageStr, ',');
					getline(ss, temp[i].CNIC, ',');
					getline(ss, temp[i].gender, ',');
					getline(ss, temp[i].address, ',');
					getline(ss, temp[i].region, ',');
					getline(ss, temp[i].partyName, ',');

					getline(ss, temp[i].symbol);

					// getline(ss,obtainedVotesStr);
					temp[i].age = stoi(ageStr);
					// temp[i].obtainedVotes=stoi(obtainedVotesStr);
				}
				else
				{
					cout << "Error reading line from file(loadACandidateDataFromFile).\n";
				}
			}

			inFile.close();
		}
		else
		{
			cout << "Error in opening File(candidate.txt).\n";
		}
		return temp;
	}
};

class Voter : public PersonalInfo
{
	int hasVoted;

public:
	int getHasVoted()
	{
		return hasVoted;
	}

	Voter *loadVoterDataFromFile(int size)
	{
		Voter *temp = new Voter[size];
		ifstream inFile("voter.txt");
		if (inFile.is_open())
		{
			for (int i = 0; i < size; i++)
			{
				string line;
				if (getline(inFile, line))
				{
					stringstream ss(line);
					string ageStr, hasVotedStr;
					getline(ss, temp[i].name, ',');
					getline(ss, ageStr, ',');
					getline(ss, temp[i].CNIC, ',');
					getline(ss, temp[i].gender, ',');
					getline(ss, temp[i].address, ',');
					getline(ss, temp[i].region, ',');

					getline(ss, hasVotedStr);
					temp[i].hasVoted = stoi(hasVotedStr);
					// getline(ss,obtainedVotesStr);
					temp[i].age = stoi(ageStr);
					// temp[i].obtainedVotes=stoi(obtainedVotesStr);
				}
				else
				{
					cout << "Error reading line from file(loadACandidateDataFromFile).\n";
				}
			}

			inFile.close();
		}
		else
		{
			cout << "Error in opening File(candidate.txt).\n";
		}
		return temp;
	}
	void viewCandidates(Candidate *cand, int size)
	{
		cout << "The candidates in your region are: " << endl;
		int c = 1;
		cout << left << setw(15) << "Candidate" << left << setw(15) << "Party" << left << setw(20) << "Symbol" << endl;
		for (int i = 0; i < size; i++)
		{
			if (cand[i].getRegion() == this->region)
			{
				cout << left << setw(15) << cand[i].getName() << left << setw(15) << cand[i].getpName() << left << setw(20) << cand[i].getSymbol() << endl;
				c++;
			}
		}
		if (c == 1)
		{
			cout << "There is no Candidate in this region." << endl;
		}
	}

	void castVote(Candidate *cand, int cSize, Result *result, int rSize)
	{
		if (this->getHasVoted() == 0)
		{
			cout << "The candidates in your region are: " << endl;
			string p;
			int c = 1, check = 0;
			cout << left << setw(15) << "Candidate" << left << setw(15) << "Party" << left << setw(20) << "Symbol" << endl;
			for (int i = 0; i < cSize; i++)
			{
				if (cand[i].getRegion() == this->region)
				{
					cout << left << setw(15) << cand[i].getName() << left << setw(15) << cand[i].getpName() << left << setw(20) << cand[i].getSymbol() << endl;
					c++;
				}
			}
			if (c == 1)
			{
				cout << "There is no Candidate in this region." << endl;
			}
			do
			{
				cout << "Enter the party Name You want to give Vote(As same as Shown): ";
				cin >> p;
				for (int i = 0; i < cSize; i++)
				{
					if (cand[i].getRegion() == this->region && cand[i].getpName() == p)
					{
						check = 1;
						break;
					}
				}
			} while (check != 1);

			if (check == 1)
			{
				this->hasVoted = 1;
				for (int i = 0; i < rSize; i++)
				{
					if (result[i].getRegion() == this->region)
					{
						int cv = result[i].getCastVote();
						cv++;
						result[i].setCastVote(cv);
						if (result[i].getParty() == p)
						{
							int gv = result[i].getVotes();
							gv++;
							result[i].setVotes(gv);
						}
					}
				}
				cout << "Your Vote is Casted." << endl;
			}
		}
		else
		{
			cout << "You have already cast the vote." << endl;
		}
	}
	void writeVoterData(Voter *voter, int size)
	{
		ofstream outFile("voter.txt");
		if (!outFile)
		{
			cout << "Error in opening File(candidate.txt" << endl;
			return;
		}
		for (int i = 0; i < size; i++)
		{
			outFile << voter[i].getName() << "," << voter[i].getAge() << "," << voter[i].getCnic() << "," << voter[i].getGender() << "," 
					<< voter[i].getAddress() << "," << voter[i].getRegion() << "," << voter[i].getHasVoted() << endl;
		}
		outFile.close();
	}
};

class PresidingOfficer : public PersonalInfo, public Login
{

public:
	string getUsername()
	{
		return userName;
	}
	string getPassword()
	{
		return Password;
	}
	bool login(string uName, string psw) override
	{
		if (uName == this->userName && psw == this->Password)
		{
			cout << "****Presiding Office Login is Successful****" << endl;
			return true;
		}
		return false;
	}
	void setUsername(string uName)
	{
		userName = uName;
	}
	void setPsw(string Psw)
	{
		Password = Psw;
	}

	void viewCandidates(Candidate *cand, int size)
	{
		cout << "Candidate List: " << endl;
		int c = 1;
		cout << left << setw(15) << "Candidate" << left << setw(15) << "CNIC" << left << setw(15) << "Party" << left << setw(20) << "Symbol" << endl;
		for (int i = 0; i < size; i++)
		{
			if (cand[i].getRegion() == this->region)
			{
				cout << left << setw(15) << cand[i].getName() << left << setw(15) << cand[i].getCnic() << left << setw(15) << cand[i].getpName() << left << setw(20) << cand[i].getSymbol() << endl;
				c++;
			}
		}
		if (c == 1)
		{
			cout << "There is no Candidate." << endl;
		}
	}
	void viewVoter(Voter *voter, int size)
	{
		cout << "Voter List: " << endl;
		int c = 1;
		cout << left << setw(15) << "Name" << left << setw(15) << "CNIC" << left << setw(20) << "Address" << endl;
		for (int i = 0; i < size; i++)
		{
			if (voter[i].getRegion() == this->region)
			{
				cout << left << setw(15) << voter[i].getName() << left << setw(15) << voter[i].getCnic() << left << setw(20) << voter[i].getAddress() << endl;
				c++;
			}
		}
		if (c == 1)
		{
			cout << "There is no  Voter." << endl;
		}
	}
	bool checkParty(Candidate *cand, int size, string p, string reg)
	{
		for (int i = 0; i < size; i++)
		{
			if (cand[i].getpName() == p && cand[i].getRegion() == reg)
			{
				return true;
			}
		}
		return false;
	}
	bool checkSymbol(Candidate *cand, int size, string s, string reg)
	{
		for (int i = 0; i < size; i++)
		{
			if (cand[i].getSymbol() == s && cand[i].getRegion() == reg)
			{
				return true;
			}
		}
		return false;
	}
	bool checkCnic(Candidate *cand, int size, string cnic, string reg)
	{
		for (int i = 0; i < size; i++)
		{
			if (cand[i].getCnic() == cnic && cand[i].getRegion() == reg)
			{
				return true;
			}
		}
		return false;
	}

	Candidate *addCandidates(Candidate *cand, int &size)
	{

		Candidate *temp = new Candidate[size + 1];
		for (int i = 0; i < size; i++)
		{
			temp[i] = cand[i];
		}
		string pName, symbl;
		temp[size].inputData();

		string cnic = temp[size].getCnic();
		if (checkCnic(cand, size, cnic, region))
		{
			cout << "The Candidate with this CNIC Already Existed.Please Enter new CNIC: ";
			getline(cin, cnic);
		}
		temp[size].setCNIC(cnic);
		temp[size].setRegion(region);
		cout << "Enter Party Name(Can't be Modified): ";
		getline(cin, pName);
		if (checkParty(cand, size, pName, region))
		{
			cout << "This Party is already existed.Please Enter New Party Name: ";
			getline(cin, pName);
		}
		temp[size].setPName(pName);
		cout << "Enter Party Symbol(Can't be Modified): ";
		getline(cin, symbl);
		if (checkSymbol(cand, size, symbl, region))
		{
			cout << "This Party is already existed.Please Enter New Symbol: ";
			getline(cin, symbl);
		}
		temp[size].setSymbol(symbl);

		cout << "Candidate Added Successfully." << endl;
		cout << endl;
		size++;

		delete[] cand;
		writeCandidateDataToFile(temp, size);
		return temp;
	}

	void candidateDataToResult(Candidate *cand, int size, Voter *voter, int vSize)
	{

		ofstream outFile("result.txt", ios::app);
		if (!outFile)
		{
			cout << "Error in opening File(candidate.txt" << endl;
			return;
		}
		int v = 0;
		for (int i = 0; i < vSize; i++)
		{
			if (voter[i].getRegion() == cand[size - 1].getRegion())
			{
				v++;
			}
		}

		outFile << cand[size - 1].getRegion() << "," << v << "," << 0 << "," << cand[size - 1].getName() << "," 
				<< cand[size - 1].getpName() << "," << 0 << endl;

		outFile.close();
	}

	void writeCandidateDataToFile(Candidate *cand, int size)
	{
		ofstream outFile("candidate.txt");
		if (!outFile)
		{
			cout << "Error in opening File(candidate.txt" << endl;
			return;
		}
		for (int i = 0; i < size; i++)
		{
			outFile << cand[i].getName() << "," << cand[i].getAge() << "," << cand[i].getCnic() << "," << cand[i].getGender() << "," 
					<< cand[i].getAddress() << "," << cand[i].getRegion() << "," << cand[i].getpName() << "," << cand[i].getSymbol() << endl;
		}
		outFile.close();
	}

	bool checkCnic(Voter *voter, int size, string cnic)
	{
		for (int i = 0; i < size; i++)
		{
			if (voter[i].getCnic() == cnic)
			{
				return true;
			}
		}
		return false;
	}

	Voter *addVoter(Voter *voter, int &size, Result *result, int rSize)
	{
		Voter *temp = new Voter[size + 1];
		for (int i = 0; i < size; i++)
		{
			temp[i] = voter[i];
		}
		temp[size].inputData();
		string cnic = temp[size].getCnic();
		if (checkCnic(voter, size, cnic))
		{
			cout << "The Voter with this CNIC Already Existed.Please Enter new CNIC: ";
			getline(cin, cnic);
		}
		temp[size].setCNIC(cnic);
		temp[size].setRegion(region);
		cout << "Voter Added Successfully." << endl;
		cout << endl;

		for (int i = 0; i < rSize; i++)
		{
			if (result[i].getRegion() == region)
			{
				int c = 0;
				c = result[i].getRegdVote();
				c++;
				result[i].setRegdVote(c);
			}
		}
		size++;

		delete[] voter;
		writeVoterDataToFile(temp, size);
		return temp;
	}
	void writeVoterDataToFile(Voter *voter, int size)
	{
		ofstream outFile("voter.txt");
		if (!outFile)
		{
			cout << "Error in opening File(candidate.txt" << endl;
			return;
		}
		for (int i = 0; i < size; i++)
		{
			outFile << voter[i].getName() << "," << voter[i].getAge() << "," << voter[i].getCnic() << "," << voter[i].getGender() << "," 
					<< voter[i].getAddress() << "," << voter[i].getRegion() << "," << 0 << endl;
		}
		outFile.close();
	}
	int getCnicIndex(Candidate *cand, int size)
	{
		string cnic;
		cout << "Enter CNIC of Candidate You want to update INFO: ";
		cin >> cnic;

		for (int i = 0; i < size; i++)
		{
			if (cand[i].getCnic() == cnic)
			{
				return i;
			}
		}
		return -1;
	}
	bool checkCnic(Candidate *cand, int size, string cnic)
	{
		for (int i = 0; i < size; i++)
		{
			if (cand[i].getCnic() == cnic)
			{
				return true;
			}
		}
		return false;
	}
	void updateCandidate(Candidate *cand, int size)
	{
		int i = getCnicIndex(cand, size);
		cout << endl;
		if (i != -1)
		{
			cout << "Name: " << cand[i].getName() << endl;
			cout << "Age: " << cand[i].getAge() << endl;
			cout << "Gender: " << cand[i].getGender() << endl;
			cout << "Address: " << cand[i].getAddress() << endl;
			cout << "CNIC: " << cand[i].getCnic() << endl;
			char choice;

			do
			{
				cout << endl;
				cout << "-----Update Candidate Info-----" << endl;
				cout << "1-Update Name" << endl;
				cout << "2-Update Age" << endl;
				cout << "3-Update Gender" << endl;
				cout << "4-Update Address" << endl;
				cout << "5-Update CNIC" << endl;
				cout << "6-Exit" << endl;
				cout << endl;
				cout << "Enter Your Choice: ";
				cin >> choice;
				string n, add, cnic, g, uName;
				int a;
				switch (choice)
				{
				case '1':
					cin.ignore();
					cout << "Enter New Name: ";
					getline(cin, n);
					cand[i].setName(n);
					break;
				case '2':
					cout << "Enter New Age: ";
					cin >> a;
					cand[i].setAge(a);
					cin.ignore();
					break;
				case '3':
					cout << "Enter New Gender: ";
					cin >> g;
					cand[i].setGender(g);
					break;
				case '4':
					cout << "Enter New Address: ";
					cin >> add;
					cand[i].setAddress(add);
					break;
				case '5':
					cout << "Enter New CNIC: ";
					cin >> cnic;

					if (checkCnic(cand, size, cnic))
					{
						cin.ignore();
						cout << "CNIC must be Unique(Enter New CNIC): ";
						getline(cin, cnic);
					}
					cand[i].setCNIC(cnic);
					break;

				case '6':
					cout << endl;
					cout << "Exiting..." << endl;
					cout << endl;
					break;
				default:
					cout << "Invalid Number." << endl;
					break;
				}
			} while (choice != '6');
		}
		else
		{
			cout << "The Candidate with this CNIC does not exists." << endl;
		}
	}

	int getVoterCnicIndex(Voter *voter, int size)
	{
		string cnic;
		cout << "Enter CNIC of Candidate You want to update INFO: ";
		cin >> cnic;

		for (int i = 0; i < size; i++)
		{
			if (voter[i].getCnic() == cnic)
			{
				return i;
			}
		}
		return -1;
	}
	void updateVoter(Voter *voter, int size)
	{
		int i = getVoterCnicIndex(voter, size);
		cout << endl;
		if (i != -1)
		{
			cout << "Name: " << voter[i].getName() << endl;
			cout << "Age: " << voter[i].getAge() << endl;
			cout << "Gender: " << voter[i].getGender() << endl;
			cout << "Address: " << voter[i].getAddress() << endl;
			cout << "CNIC: " << voter[i].getCnic() << endl;
			char choice;

			do
			{
				cout << endl;
				cout << "-----Update Voter Info-----" << endl;
				cout << "1-Update Name" << endl;
				cout << "2-Update Age" << endl;
				cout << "3-Update Gender" << endl;
				cout << "4-Update Address" << endl;
				cout << "5-Update CNIC" << endl;
				cout << "6-Exit" << endl;
				cout << endl;
				cout << "Enter Your Choice: ";
				cin >> choice;
				string n, add, cnic, g, uName;
				int a;
				switch (choice)
				{
				case '1':
					cin.ignore();
					cout << "Enter New Name: ";
					getline(cin, n);
					voter[i].setName(n);
					break;
				case '2':
					cout << "Enter New Age: ";
					cin >> a;
					voter[i].setAge(a);
					cin.ignore();
					break;
				case '3':
					cout << "Enter New Gender: ";
					cin >> g;
					voter[i].setGender(g);
					break;
				case '4':
					cout << "Enter New Address: ";
					cin >> add;
					voter[i].setAddress(add);
					break;
				case '5':
					cout << "Enter New CNIC: ";
					cin >> cnic;

					if (checkCnic(voter, size, cnic))
					{
						cin.ignore();
						cout << "CNIC must be Unique(Enter New CNIC): ";
						getline(cin, cnic);
					}
					voter[i].setCNIC(cnic);
					break;

				case '6':
					cout << endl;
					cout << "Exiting..." << endl;
					cout << endl;
					break;
				default:
					cout << "Invalid Number." << endl;
					break;
				}
			} while (choice != '6');
		}
		else
		{
			cout << "The Voter with this CNIC does not exists." << endl;
		}
	}

	int getDeletingVoterIndex(Voter *voter, int size, string cnic)
	{

		for (int i = 0; i < size; i++)
		{
			if (voter[i].getCnic() == cnic && voter[i].getRegion() == this->region)
			{
				return i;
			}
		}
		return -1;
	}
	int getDeletingCandidateIndex(Candidate *cand, int size, string cnic)
	{

		for (int i = 0; i < size; i++)
		{
			if (cand[i].getCnic() == cnic && cand[i].getRegion() == this->region)
			{
				return i;
			}
		}
		return -1;
	}
	Voter *deleteVoter(Voter *voter, int &vSize, Result *result, int rSize)
	{
		string cnic;
		cout << "Enter the CNIC of Voter You want to delete: ";
		cin >> cnic;
		int voterTodelete = getDeletingVoterIndex(voter, vSize, cnic);
		if (voterTodelete != -1)
		{
			Voter *temp = new Voter[vSize - 1];
			int tempIndex = 0;
			for (int i = 0; i < vSize; i++)
			{
				if (i != voterTodelete)
				{
					temp[tempIndex++] = voter[i];
				}
			}
			vSize--;
			delete[] voter;
			cout << "Voter Removed Successfully." << endl;

			for (int i = 0; i < rSize; i++)
			{
				if (result[i].getRegion() == this->region)
				{
					int c = result[i].getRegdVote();
					if (c != 0)
					{
						c--;
					}
					result[i].setRegdVote(c);
				}
			}
			return temp;
		}
		else
		{
			cout << "The voter with this CNIC does not exists in this Region." << endl;
			return voter;
		}
	}

	Candidate *deleteCandidate(Candidate *cand, int &cSize, Result *result, int &rSize, int candTodelete)
	{

		if (candTodelete != -1)
		{
			Candidate *temp = new Candidate[cSize - 1];
			int tempIndex = 0;
			for (int i = 0; i < cSize; i++)
			{
				if (i != candTodelete)
				{
					temp[tempIndex++] = cand[i];
				}
			}
			ofstream outFile("result.txt");
			if (!outFile)
			{
				cout << "Error in opening File(result.txt)" << endl;
			}
			for (int i = 0; i < rSize; i++)
			{
				if (result[i].getRegion() != this->region || result[i].getParty() != cand[candTodelete].getpName())
				{
					outFile << result[i].getRegion() << "," << result[i].getRegdVote() << "," << result[i].getCastVote() << "," << result[i].getCandidate() << "," 
							<< result[i].getParty() << "," << result[i].getVotes() << endl;
				}
			}

			outFile.close();

			cSize--;
			rSize--;

			delete[] cand;
			cout << "Candidate Removed Successfully." << endl;

			return temp;
		}
		else
		{
			cout << "The Candidate with this CNIC does not exists in this Region." << endl;
			return cand;
		}
	}

	PresidingOfficer *changePassword(PresidingOfficer *po, int size)
	{
		string cnic;
		cin.ignore();
		cout << "Enter Your CNIC: " << endl;
		getline(cin, cnic);

		int index = -1;

		for (int i = 0; i < size; i++)
		{
			if (po[i].getCnic() == cnic && this->getCnic() == cnic)
			{
				index = i;
				break;
			}
		}
		if (index != -1)
		{
			cout << "Your Prevois Password is: " << po[index].getPassword() << endl;
			string pass;
			cout << "Enter New Password: ";
			getline(cin, pass);
			po[index].setPsw(pass);

			cout << "Password Updated Successfuly." << endl;
			ofstream outFile("po.txt");
			if (!outFile)
			{
				cout << "Error in opening File" << endl;
			}
			for (int i = 0; i < size; i++)
			{
				outFile << po[i].getName() << "," << po[i].getAge() << "," << po[i].getCnic() << "," << po[i].getGender() << "," << po[i].getAddress() << "," << po[i].getRegion() << "," << po[i].getUsername() << "," << po[i].getPassword() << endl;
			}
			outFile.close();
			return po;
		}
		else
		{
			cout << "Wrong CNIC" << endl;
			return po;
		}
	}

	PresidingOfficer *loadPoDataFromFile(int size)
	{
		PresidingOfficer *temp = new PresidingOfficer[size];
		ifstream inFile("po.txt");
		if (inFile.is_open())
		{
			for (int i = 0; i < size; i++)
			{
				string line;
				if (getline(inFile, line))
				{
					stringstream ss(line);
					string ageStr;
					getline(ss, temp[i].name, ',');
					getline(ss, ageStr, ',');
					getline(ss, temp[i].CNIC, ',');
					getline(ss, temp[i].gender, ',');
					getline(ss, temp[i].address, ',');
					getline(ss, temp[i].region, ',');

					getline(ss, temp[i].userName, ',');
					getline(ss, temp[i].Password);
					temp[i].age = stoi(ageStr);
				}
				else
				{
					cout << "Error reading line from file(loadPODataFromFile).\n";
				}
			}

			inFile.close();
		}
		else
		{
			cout << "Error in opening File(po.txt).\n";
		}
		return temp;
	}

	// virtual ~PresidingOfficer(){}
};

void showPartyresult(Result *result, int rSize, string reg, string name, string p, string sym)
{

	for (int i = 0; i < rSize; i++)
	{
		if (result[i].getRegion() == reg && result[i].getParty() == p)
		{

			cout << left << setw(25) << name << left << setw(25) << p << left << setw(25) << sym << left << setw(20) << result[i].getVotes() << endl;
		}
	}
}

void showRegionResult(Candidate *cand, int cSize, Result *result, int rSize, string reg)
{
	cout << "\t\t\t" << reg << endl;
	cout << "\t\t\t-----" << endl;
	// int stop=0;
	string pg;
	for (int i = 0; i < cSize; i++)
	{
		if (cand[i].getRegion() == reg)
		{

			pg = cand[i].getpName();

			if (result[i].getParty() == pg && result[i].getRegion() == reg)
			{
				cout << "Registered Voter: " << result[i].getRegdVote() << "\t\t"
					 << "Vote-Casted: " << result[i].getCastVote() << endl
					 << endl;
				cout << left << setw(25) << "Candidate" << left << setw(25) << "Party" << left << setw(25) << "Symbol" << left << setw(20) << "Votes" << endl;
				break;
			}
		}
	}

	for (int i = 0; i < cSize; i++)
	{
		if (cand[i].getRegion() == reg)
		{
			string n = cand[i].getName();
			string p = cand[i].getpName();
			string s = cand[i].getSymbol();

			showPartyresult(result, rSize, reg, n, p, s);
		}
	}
}

void showResult(PresidingOfficer *po, int pSize, Result *result, int rSize, Candidate *cand, int cSize)
{
	cout << endl;
	cout << setw(30) << "=======================================\n";
	cout << setw(30) << "%%%%%%%%%%% Result of each Region %%%%%%%%%%%\n";
	cout << setw(30) << "=======================================\n\n\n";
	string reg;
	for (int i = 0; i < pSize; i++)
	{
		reg = po[i].getRegion();
		showRegionResult(cand, cSize, result, rSize, reg);
	}
}

class ElectionCommission : public Login
{
public:
	ElectionCommission()
	{
		userName = "admin";
		Password = "1234";
	}
	ElectionCommission *loadAdminDataFromFile()
	{
		ElectionCommission *temp = new ElectionCommission;
		ifstream inFile("admin.txt");
		if (inFile.is_open())
		{
			string line;
			if (getline(inFile, line))
			{
				stringstream ss(line);
				getline(ss, temp->userName, ',');
				getline(ss, temp->Password);
			}
			else
			{
				cout << "Error reading line from file(loadAdminDataFromFile).\n";
			}

			inFile.close();
		}
		else
		{
			cout << "Error in opening File(admin.txt).\n";
		}
		return temp;
	}
	bool login(string uName, string psw) override
	{
		if (uName == this->userName && psw == this->Password)
		{
			cout << "****Admin Login is Successful****" << endl;
			return true;
		}
		return false;
	}
	bool checkCnic(PresidingOfficer *po, int size, string cnic)
	{
		for (int i = 0; i < size; i++)
		{
			if (po[i].getCnic() == cnic)
			{
				return true;
			}
		}
		return false;
	}
	bool checkUser(PresidingOfficer *po, int size, string uName)
	{
		for (int i = 0; i < size; i++)
		{
			if (po[i].getUsername() == uName)
			{
				return true;
			}
		}
		return false;
	}

	PresidingOfficer *addPo(PresidingOfficer *po, int &size)
	{
		PresidingOfficer *temp = new PresidingOfficer[size + 1];
		for (int i = 0; i < size; i++)
		{
			temp[i] = po[i];
		}
		string n, cnic, gndr, add, reg, uName, Psw;
		int ag;
		cout << "Enter the details of Presiding Officer." << endl;
		cin.ignore();
		cout << "Enter Name: ";
		getline(cin, n);
		temp[size].setName(n);
		// getline(cin,temp[size].name)
		cout << "Enter age: ";
		cin >> ag;
		temp[size].setAge(ag);
		cin.ignore();
		cout << "Enter CNIC: ";
		getline(cin, cnic);
		if (checkCnic(po, size, cnic))
		{
			cin.ignore();
			cout << "CNIC must be Unique(Enter New CNIC): ";
			getline(cin, cnic);
		}
		temp[size].setCNIC(cnic);
		cout << "Enter Gender: ";
		getline(cin, gndr);
		temp[size].setGender(gndr);
		cout << "Enter Address: ";
		getline(cin, add);
		temp[size].setAddress(add);
		cout << "Enter Region(Please Enter this field Correctly-You not Update it Later): ";
		getline(cin, reg);
		temp[size].setRegion(reg);

		cout << "Also Provide log in functionality to presiding officer." << endl;
		cout << "Enter Username: ";
		cin >> uName;
		if (checkUser(po, size, uName))
		{
			cout << "Already Existed.Enter New Username: ";
			cin >> uName;
		}
		temp[size].setUsername(uName);
		cout << "Enter Password: ";
		cin >> Psw;
		temp[size].setPsw(Psw);

		cout << "Presiding Officer Added Successfully." << endl;
		cout << endl;
		size++;

		delete[] po;
		writePoDataToFile(temp, size);
		return temp;
	}

	void writePoDataToFile(PresidingOfficer *po, int size)
	{
		ofstream outFile("po.txt");
		if (!outFile)
		{
			cout << "Error in opening File" << endl;
			return;
		}
		for (int i = 0; i < size; i++)
		{
			outFile << po[i].getName() << "," << po[i].getAge() << "," << po[i].getCnic() << "," << po[i].getGender() << "," << po[i].getAddress() << "," << po[i].getRegion() << "," << po[i].getUsername() << "," << po[i].getPassword() << endl;
		}
		outFile.close();
	}

	int getCnicIndex(PresidingOfficer *po, int size)
	{
		string cnic;
		cout << "Enter CNIC of PO You want to update INFO: ";
		cin >> cnic;

		for (int i = 0; i < size; i++)
		{
			if (po[i].getCnic() == cnic)
			{
				return i;
			}
		}
		return -1;
	}
	void updatePo(PresidingOfficer *po, int size)
	{
		int i = getCnicIndex(po, size);
		cout << endl;
		if (i != -1)
		{
			cout << "Name: " << po[i].getName() << endl;
			cout << "Age: " << po[i].getAge() << endl;
			cout << "Gender: " << po[i].getGender() << endl;
			cout << "Address: " << po[i].getAddress() << endl;
			cout << "CNIC: " << po[i].getCnic() << endl;
			cout << "Username: " << po[i].getUsername() << endl;
			char choice;

			do
			{
				cout << endl;
				cout << "-----Update PO Info-----" << endl;
				cout << "1-Update Name" << endl;
				cout << "2-Update Age" << endl;
				cout << "3-Update Gender" << endl;
				cout << "4-Update Address" << endl;
				cout << "5-Update CNIC" << endl;
				cout << "6-Update Username" << endl;
				cout << "7-Exit" << endl;
				cout << endl;
				cout << "Enter Your Choice: ";
				cin >> choice;
				string n, add, cnic, g, uName;
				int a;
				switch (choice)
				{
				case '1':
					cin.ignore();
					cout << "Enter New Name: ";
					getline(cin, n);
					po[i].setName(n);
					break;
				case '2':
					cout << "Enter New Age: ";
					cin >> a;
					po[i].setAge(a);
					cin.ignore();
					break;
				case '3':
					cout << "Enter New Gender: ";
					cin >> g;
					po[i].setGender(g);
					break;
				case '4':
					cout << "Enter New Address: ";
					cin >> add;
					po[i].setAddress(add);
					break;
				case '5':
					cout << "Enter New CNIC: ";
					cin >> cnic;
					if (checkCnic(po, size, cnic))
					{
						cout << "CNIC must be Unique(Enter New CNIC): ";
						getline(cin, cnic);
					}
					po[i].setCNIC(cnic);
					break;
				case '6':
					cout << "Enter New Username: ";
					cin >> uName;
					if (checkUser(po, size, uName))
					{
						cout << "Already Existed.Enter New Username: ";
						cin >> uName;
					}
					po[i].setUsername(uName);
					break;
				case '7':
					cout << endl;
					cout << "Exiting..." << endl;
					cout << endl;
					break;
				default:
					cout << "Invalid Number." << endl;
					break;
				}
			} while (choice != '7');
		}
		else
		{
			cout << "The PO with this CNIC does not exists." << endl;
		}
	}
	void viewPo(PresidingOfficer *po, int size)
	{
		cout << "Presiding Officers Detail: " << endl;
		int c = 1;
		cout << left << setw(15) << "Name" << left << setw(15) << "CNIC" << left << setw(20) << "Region" << endl;
		for (int i = 0; i < size; i++)
		{
			cout << left << setw(15) << po[i].getName() << left << setw(15) << po[i].getCnic() << left << setw(20) << po[i].getRegion() << endl;
			c++;
		}
		if (c == 1)
		{
			cout << "There is no Presiding Officer." << endl;
		}
	}
	int getDeletingPoIndex(PresidingOfficer *po, int size, string cnic)
	{

		for (int i = 0; i < size; i++)
		{
			if (po[i].getCnic() == cnic)
			{
				return i;
			}
		}
		return -1;
	}

	PresidingOfficer *deletePo(PresidingOfficer *po, int &pSize, Result *result, int rSize, Candidate *cand, int cSize, Voter *voter, int vSize, int poTodelete)
	{

		if (poTodelete != -1)
		{
			PresidingOfficer *temp = new PresidingOfficer[pSize - 1];
			int tempIndex = 0;
			for (int i = 0; i < cSize; i++)
			{
				if (i != poTodelete)
				{
					temp[tempIndex++] = po[i];
				}
			}
			ofstream resultFile("result.txt");
			ofstream candFile("candidate.txt");
			ofstream voterFile("voter.txt");
			if (!resultFile || !candFile || !voterFile)
			{
				cout << "Error in opening Files(mul.txt)" << endl;
			}

			for (int i = 0; i < rSize; i++)
			{
				if (result[i].getRegion() != po[poTodelete].getRegion())
				{
					resultFile << result[i].getRegion() << "," << result[i].getRegdVote() << "," << result[i].getCastVote() << "," << result[i].getCandidate() << "," 
							   << result[i].getParty() << "," << result[i].getVotes() << endl;
				}
			}

			for (int i = 0; i < cSize; i++)
			{
				if (cand[i].getRegion() != po[poTodelete].getRegion())
				{
					candFile << cand[i].getName() << "," << cand[i].getAge() << "," << cand[i].getCnic() << "," << cand[i].getGender() << "," 
							 << cand[i].getAddress() << "," << cand[i].getRegion() << "," << cand[i].getpName() << "," << cand[i].getSymbol() << endl;
				}
			}

			for (int i = 0; i < vSize; i++)
			{
				if (voter[i].getRegion() != po[poTodelete].getRegion())
				{
					voterFile << voter[i].getName() << "," << voter[i].getAge() << "," << voter[i].getCnic() << "," << voter[i].getGender() << "," 
							  << voter[i].getAddress() << "," << voter[i].getRegion() << "," << voter[i].getHasVoted() << endl;
				}
			}

			resultFile.close();
			candFile.close();
			voterFile.close();

			pSize--;

			delete[] po;
			cout << "PO Removed Successfully." << endl;

			return temp;
		}
		else
		{
			cout << "The PO with this CNIC does not exists in this Region." << endl;
			return po;
		}
	}

	void anouceResult()
	{
	}

	void logOut()
	{
	}
};

int findFileSize(const string &filename)
{
	int size = 0;
	ifstream inFile(filename);
	if (!inFile)
	{
		cout << "Error opening File.";
		return size;
	}

	string line;
	while (getline(inFile, line))
	{
		size++;
	}
	return size;
}
int main()
{
    Login *l;
    ElectionCommission *ec = new ElectionCommission;

    int poFileSize = findFileSize("po.txt");
    PresidingOfficer *po = new PresidingOfficer[poFileSize];
    po = po->loadPoDataFromFile(poFileSize);
    PresidingOfficer *loggedPo = nullptr;

    int candidateFileSize = findFileSize("candidate.txt");
    Candidate *candidate = new Candidate[candidateFileSize];
    candidate = candidate->loadCandidateDataFromFile(candidateFileSize);

    int voterFileSize = findFileSize("voter.txt");
    Voter *voter = new Voter[voterFileSize];
    voter = voter->loadVoterDataFromFile(voterFileSize);
    Voter *loggedVoter = nullptr;

    int resultFileSize = findFileSize("result.txt");
    Result *result = new Result[resultFileSize];
    result = result->loadresultDataFromFile(resultFileSize);

    char choice, adminChoice, voterChoice;
    int poChoice;
    string userName, Psw;
    int check = 0;
    string cnic;

    bool startVoting = false;
    bool anounceResult = false;

    clearScreen();
    
    // Welcome animation
    setColor(LIGHTCYAN);
    cout << string(80, '=') << endl;
    printCentered("ELECTION MANAGEMENT SYSTEM");
    cout << string(80, '=') << endl << endl;
    resetColor();
    
    loadingAnimation("Initializing System... ", 5);
    Sleep(300);
    
    do {
        clearScreen();
        setColor(LIGHTCYAN);
        cout << string(80, '=') << endl;
        printCentered("ELECTION MANAGEMENT SYSTEM");
        cout << string(80, '=') << endl << endl;
        resetColor();
        
        const string options[] = {
            "1. Election Commission Login",
            "2. Presiding Officer Login",
            "3. Voter Login",
            "4. View Result of Election",
            "5. Exit"
        };
        
        int optionCount = anounceResult ? 5 : 4;
        
        drawBox("MAIN MENU", options, optionCount);
        
        cout << endl;
        setColor(YELLOW);
        cout << "Enter your choice: ";
        resetColor();
        cin >> choice;
        
        while ((choice < '1' || (choice > '4' && anounceResult) || (choice > '3' && !anounceResult)) && choice != '5') {
            setColor(LIGHTRED);
            cout << "Invalid input! Please enter a number between 1-" << (anounceResult ? "4" : "3") << " or 5 to exit: ";
            resetColor();
            cin >> choice;
        }

        switch (choice)
        {
        case '1': // Election Commission Login
            {
                if (!anounceResult) {
                    printHeader("ELECTION COMMISSION LOGIN");
                    
                    cin.ignore();
                    setColor(WHITE);
                    cout << "Username: ";
                    resetColor();
                    getline(cin, userName);
                    
                    setColor(WHITE);
                    cout << "Password: ";
                    resetColor();
                    Psw = getPasswordInput();
                    
                    l = ec;
                    if (l->login(userName, Psw)) {
                        setColor(LIGHTGREEN);
                        cout << "Login successful!" << endl;
                        loadingAnimation("Loading admin panel... ", 3);
                        resetColor();

                        do {
                            printHeader("ELECTION COMMISSION DASHBOARD");
                            const string adminOptions[] = {
                                "1. Add Presiding Officer",
                                "2. Update Presiding Officer",
                                "3. Delete Presiding Officer",
                                "4. View Presiding Officers",
                                "5. Start Polling",
                                "6. Announce Result",
                                "7. Exit Program"
                            };
                            
                            drawBox("ADMIN MENU", adminOptions, 7);
                            
                            cout << endl;
                            setColor(YELLOW);
                            cout << "Enter your choice: ";
                            resetColor();
                            cin >> adminChoice;

                            switch (adminChoice) {
                            case '1':
                                if (!startVoting) {
                                    printHeader("ADD PRESIDING OFFICER");
                                    po = ec->addPo(po, poFileSize);
                                    setColor(LIGHTGREEN);
                                    cout << "\nPresiding Officer added successfully!" << endl;
                                    resetColor();
                                    cout << "Press any key to continue...";
                                    _getch();
                                } else {
                                    setColor(LIGHTRED);
                                    cout << "Error: Polling has already started. Cannot add new presiding officers." << endl;
                                    resetColor();
                                    Sleep(2000);
                                }
                                break;

                            case '2':
                                if (!startVoting) {
                                    printHeader("UPDATE PRESIDING OFFICER");
                                    ec->updatePo(po, poFileSize);
                                    ec->writePoDataToFile(po, poFileSize);
                                    setColor(LIGHTGREEN);
                                    cout << "\nPresiding Officer updated successfully!" << endl;
                                    resetColor();
                                    cout << "Press any key to continue...";
                                    _getch();
                                } else {
                                    setColor(LIGHTRED);
                                    cout << "Error: Polling has already started. Cannot update presiding officers." << endl;
                                    resetColor();
                                    Sleep(2000);
                                }
                                break;

                            case '3':
                                if (!startVoting) {
                                    printHeader("DELETE PRESIDING OFFICER");
                                    setColor(WHITE);
                                    cout << "Enter the CNIC of Presiding Officer to delete: ";
                                    resetColor();
                                    cin >> cnic;
                                    
                                    int poTodelete = ec->getDeletingPoIndex(po, poFileSize, cnic);
                                    
                                    if (poTodelete != -1) {
                                        loadingAnimation("Deleting presiding officer... ", 2);
                                        po = ec->deletePo(po, poFileSize, result, resultFileSize, candidate, candidateFileSize, voter, voterFileSize, poTodelete);
                                        ec->writePoDataToFile(po, poFileSize);
                                        
                                        // Reload all data
                                        candidateFileSize = findFileSize("candidate.txt");
                                        voterFileSize = findFileSize("voter.txt");
                                        resultFileSize = findFileSize("result.txt");
                                        candidate = candidate->loadCandidateDataFromFile(candidateFileSize);
                                        voter = voter->loadVoterDataFromFile(voterFileSize);
                                        result = result->loadresultDataFromFile(resultFileSize);
                                        
                                        setColor(LIGHTGREEN);
                                        cout << "Presiding Officer deleted successfully!" << endl;
                                        resetColor();
                                    } else {
                                        setColor(LIGHTRED);
                                        cout << "Error: No Presiding Officer found with this CNIC." << endl;
                                        resetColor();
                                    }
                                    cout << "Press any key to continue...";
                                    _getch();
                                } else {
                                    setColor(LIGHTRED);
                                    cout << "Error: Polling has already started. Cannot delete presiding officers." << endl;
                                    resetColor();
                                    Sleep(2000);
                                }
                                break;

                            case '4':
                                printHeader("VIEW PRESIDING OFFICERS");
                                setColor(LIGHTCYAN);
                                cout << string(60, '=') << endl;
                                cout << left << setw(20) << "Name" << left << setw(20) << "CNIC" << left << setw(20) << "Region" << endl;
                                cout << string(60, '=') << endl;
                                resetColor();
                                
                                ec->viewPo(po, poFileSize);
                                
                                cout << "\nPress any key to continue...";
                                _getch();
                                break;

                            case '5':
                                printHeader("START POLLING");
                                if (!startVoting) {
                                    loadingAnimation("Starting polling process... ", 4);
                                    startVoting = true;
                                    setColor(LIGHTGREEN);
                                    cout << "\nPolling has successfully started! Voters can now cast their votes." << endl;
                                    resetColor();
                                } else {
                                    setColor(LIGHTRED);
                                    cout << "Polling is already in progress!" << endl;
                                    resetColor();
                                }
                                Sleep(2000);
                                break;

                            case '6':
                                printHeader("ANNOUNCE RESULTS");
                                loadingAnimation("Calculating election results... ", 5);
                                anounceResult = true;
                                startVoting = false;
                                
                                if (anounceResult) {
                                    showResult(po, poFileSize, result, resultFileSize, candidate, candidateFileSize);
                                }
                                setColor(LIGHTGREEN);
                                cout << "\nResults have been announced successfully!" << endl;
                                resetColor();
                                cout << "Press any key to continue...";
                                _getch();
                                adminChoice = '7';
                                break;

                            case '7':
                                setColor(YELLOW);
                                cout << "\nExiting admin panel..." << endl;
                                resetColor();
                                Sleep(1000);
                                break;

                            default:
                                setColor(LIGHTRED);
                                cout << "Invalid choice. Please try again." << endl;
                                resetColor();
                                Sleep(1500);
                                break;
                            }
                        } while (adminChoice != '7');
                    } else {
                        setColor(LIGHTRED);
                        cout << "Error: Incorrect username or password!" << endl;
                        resetColor();
                        Sleep(2000);
                    }
                } else {
                    setColor(LIGHTRED);
                    cout << "Results have already been announced. Election Commission login is closed." << endl;
                    resetColor();
                    Sleep(2000);
                }
                break;
            }

        case '2': // Presiding Officer Login
            if (!startVoting && !anounceResult) {
                if (poFileSize != 0) {
                    printHeader("PRESIDING OFFICER LOGIN");
                    
                    setColor(WHITE);
                    cout << "Username: ";
                    resetColor();
                    cin >> userName;
                    
                    setColor(WHITE);
                    cout << "Password: ";
                    resetColor();
                    cin >> Psw;
                    
                    int c = 0;
                    for (int i = 0; i < poFileSize; i++) {
                        if (po[i].getUsername() == userName) {
                            l = &po[i];
                            c++;
                            loggedPo = &po[i];
                            break;
                        }
                    }
                    
                    if (c == 0) {
                        setColor(LIGHTRED);
                        cout << "Error: User not found!" << endl;
                        resetColor();
                        Sleep(2000);
                        break;
                    }
                    
                    if (l->login(userName, Psw) && c == 1) {
                        setColor(LIGHTGREEN);
                        cout << "Login successful!" << endl;
                        loadingAnimation("Loading Presiding Officer panel... ", 3);
                        resetColor();

                        do {
                            printHeader("PRESIDING OFFICER DASHBOARD");
                            setColor(LIGHTCYAN);
                            printCentered("Region: " + loggedPo->getRegion());
                            cout << endl;
                            resetColor();
                            
                            const string poOptions[] = {
                                "1. Add Candidate",
                                "2. Add Voter",
                                "3. View Candidate List",
                                "4. View Voter List",
                                "5. Update Candidate Info",
                                "6. Update Voter Info",
                                "7. Delete Candidate",
                                "8. Delete Voter",
                                "9. Change Password",
                                "10. Exit"
                            };
                            
                            drawBox("PO MENU", poOptions, 10);
                            
                            cout << endl;
                            setColor(YELLOW);
                            cout << "Enter your choice: ";
                            resetColor();
                            cin >> poChoice;

                            switch (poChoice) {
                            case 1: // Add Candidate
                                printHeader("ADD CANDIDATE");
                                candidate = loggedPo->addCandidates(candidate, candidateFileSize);
                                loggedPo->candidateDataToResult(candidate, candidateFileSize, voter, voterFileSize);
                                resultFileSize++;
                                result = result->loadresultDataFromFile(resultFileSize);
                                setColor(LIGHTGREEN);
                                cout << "\nCandidate added successfully!" << endl;
                                resetColor();
                                cout << "Press any key to continue...";
                                _getch();
                                break;

                            case 2: // Add Voter
                                printHeader("ADD VOTER");
                                voter = loggedPo->addVoter(voter, voterFileSize, result, resultFileSize);
                                result->writeResult(result, resultFileSize);
                                setColor(LIGHTGREEN);
                                cout << "\nVoter added successfully!" << endl;
                                resetColor();
                                cout << "Press any key to continue...";
                                _getch();
                                break;

                            case 3: // View Candidates
                                printHeader("CANDIDATE LIST");
                                setColor(LIGHTCYAN);
                                cout << string(70, '=') << endl;
                                cout << left << setw(20) << "Candidate" << left << setw(20) << "CNIC" << left << setw(15) << "Party" << left << setw(15) << "Symbol" << endl;
                                cout << string(70, '=') << endl;
                                resetColor();
                                
                                loggedPo->viewCandidates(candidate, candidateFileSize);
                                
                                cout << "\nPress any key to continue...";
                                _getch();
                                break;

                            case 4: // View Voters
                                printHeader("VOTER LIST");
                                setColor(LIGHTCYAN);
                                cout << string(60, '=') << endl;
                                cout << left << setw(20) << "Name" << left << setw(20) << "CNIC" << left << setw(20) << "Address" << endl;
                                cout << string(60, '=') << endl;
                                resetColor();
                                
                                loggedPo->viewVoter(voter, voterFileSize);
                                
                                cout << "\nPress any key to continue...";
                                _getch();
                                break;

                            case 5: // Update Candidate
                                printHeader("UPDATE CANDIDATE");
                                loggedPo->updateCandidate(candidate, candidateFileSize);
                                loggedPo->writeCandidateDataToFile(candidate, candidateFileSize);
                                setColor(LIGHTGREEN);
                                cout << "\nCandidate information updated successfully!" << endl;
                                resetColor();
                                cout << "Press any key to continue...";
                                _getch();
                                break;

                            case 6: // Update Voter
                                printHeader("UPDATE VOTER");
                                loggedPo->updateVoter(voter, voterFileSize);
                                loggedPo->writeVoterDataToFile(voter, voterFileSize);
                                setColor(LIGHTGREEN);
                                cout << "\nVoter information updated successfully!" << endl;
                                resetColor();
                                cout << "Press any key to continue...";
                                _getch();
                                break;

                            case 7: // Delete Candidate
                                {
                                    printHeader("DELETE CANDIDATE");
                                    setColor(WHITE);
                                    cout << "Enter the CNIC of Candidate to delete: ";
                                    resetColor();
                                    cin >> cnic;
                                    
                                    int candTodelete = loggedPo->getDeletingCandidateIndex(candidate, candidateFileSize, cnic);
                                    
                                    if (candTodelete != -1) {
                                        loadingAnimation("Deleting candidate... ", 2);
                                        candidate = loggedPo->deleteCandidate(candidate, candidateFileSize, result, resultFileSize, candTodelete);
                                        loggedPo->writeCandidateDataToFile(candidate, candidateFileSize);
                                        result = result->loadresultDataFromFile(resultFileSize);
                                        
                                        setColor(LIGHTGREEN);
                                        cout << "Candidate deleted successfully!" << endl;
                                        resetColor();
                                    } else {
                                        setColor(LIGHTRED);
                                        cout << "Error: No candidate found with this CNIC in your region." << endl;
                                        resetColor();
                                    }
                                    cout << "Press any key to continue...";
                                    _getch();
                                }
                                break;

                            case 8: // Delete Voter
                                printHeader("DELETE VOTER");
                                voter = loggedPo->deleteVoter(voter, voterFileSize, result, resultFileSize);
                                loggedPo->writeVoterDataToFile(voter, voterFileSize);
                                result->writeResult(result, resultFileSize);
                                cout << "Press any key to continue...";
                                _getch();
                                break;

                            case 9: // Change Password
                                printHeader("CHANGE PASSWORD");
                                po = loggedPo->changePassword(po, poFileSize);
                                cout << "Press any key to continue...";
                                _getch();
                                break;

                            case 10: // Exit
                                setColor(YELLOW);
                                cout << "\nExiting Presiding Officer panel..." << endl;
                                resetColor();
                                Sleep(1000);
                                break;

                            default:
                                setColor(LIGHTRED);
                                cout << "Invalid choice. Please try again." << endl;
                                resetColor();
                                Sleep(1500);
                                break;
                            }
                        } while (poChoice != 10);
                    } else {
                        setColor(LIGHTRED);
                        cout << "Error: Incorrect password!" << endl;
                        resetColor();
                        Sleep(2000);
                    }
                } else {
                    setColor(LIGHTRED);
                    cout << "No presiding officers found in the system!" << endl;
                    resetColor();
                    Sleep(2000);
                }
            } else {
                if (startVoting) {
                    setColor(LIGHTRED);
                    cout << "Polling is currently in progress. Presiding Officer logins are disabled." << endl;
                } else {
                    setColor(LIGHTRED);
                    cout << "Results have been announced. Presiding Officer logins are closed." << endl;
                }
                resetColor();
                Sleep(2000);
            }
            break;

        case '3': // Voter Login
            if (startVoting) {
                if (voterFileSize != 0) {
                    printHeader("VOTER LOGIN");
                    
                    setColor(WHITE);
                    cout << "Enter Your CNIC (without dashes): ";
                    resetColor();
                    cin >> cnic;
                    
                    check = 0;
                    for (int i = 0; i < voterFileSize; i++) {
                        if (voter[i].getCnic() == cnic) {
                            check++;
                            loggedVoter = &voter[i];
                            break;
                        }
                    }
                    
                    if (check != 0 && loggedVoter->getHasVoted() == 0) {
                        loadingAnimation("Verifying voter identity... ", 3);
                        setColor(LIGHTGREEN);
                        cout << "Voter verified successfully!" << endl;
                        resetColor();
                        Sleep(1000);

                        do {
                            printHeader("VOTER PORTAL");
                            setColor(LIGHTCYAN);
                            printCentered("Region: " + loggedVoter->getRegion());
                            cout << endl;
                            resetColor();
                            
                            const string voterOptions[] = {
                                "1. View Candidates",
                                "2. Cast Vote",
                                "3. Exit"
                            };
                            
                            drawBox("VOTER MENU", voterOptions, 3);
                            
                            cout << endl;
                            setColor(YELLOW);
                            cout << "Enter your choice: ";
                            resetColor();
                            cin >> voterChoice;

                            switch (voterChoice) {
                            case '1': // View Candidates
                                printHeader("AVAILABLE CANDIDATES");
                                setColor(LIGHTCYAN);
                                cout << string(60, '=') << endl;
                                cout << left << setw(20) << "Candidate" << left << setw(20) << "Party" << left << setw(20) << "Symbol" << endl;
                                cout << string(60, '=') << endl;
                                resetColor();
                                
                                loggedVoter->viewCandidates(candidate, candidateFileSize);
                                
                                cout << "\nPress any key to continue...";
                                _getch();
                                break;

                            case '2': // Cast Vote
                                printHeader("CAST YOUR VOTE");
                                loggedVoter->castVote(candidate, candidateFileSize, result, resultFileSize);
                                loggedVoter->writeVoterData(voter, voterFileSize);
                                result->writeResult(result, resultFileSize);
                                
                                if (loggedVoter->getHasVoted() == 1) {
                                    setColor(LIGHTGREEN);
                                    cout << "\nThank you for voting!" << endl;
                                    loadingAnimation("Registering your vote... ", 3);
                                    cout << "Your vote has been successfully recorded." << endl;
                                    resetColor();
                                    voterChoice = '3'; // Exit after voting
                                }
                                
                                cout << "Press any key to continue...";
                                _getch();
                                break;

                            case '3': // Exit
                                setColor(YELLOW);
                                cout << "\nExiting voter portal..." << endl;
                                resetColor();
                                Sleep(1000);
                                break;

                            default:
                                setColor(LIGHTRED);
                                cout << "Invalid choice. Please try again." << endl;
                                resetColor();
                                Sleep(1500);
                                break;
                            }
                        } while (voterChoice != '3');
                    } else {
                        setColor(LIGHTRED);
                        if (check == 0) {
                            cout << "Error: No voter found with this CNIC!" << endl;
                        } else {
                            cout << "You have already cast your vote." << endl;
                        }
                        resetColor();
                        Sleep(2000);
                    }
                } else {
                    setColor(LIGHTRED);
                    cout << "No voters found in the system!" << endl;
                    resetColor();
                    Sleep(2000);
                }
            } else {
                if (anounceResult) {
                    setColor(LIGHTRED);
                    cout << "Voting has ended. Results have been announced." << endl;
                } else {
                    setColor(LIGHTRED);
                    cout << "Voting has not started yet. Please wait for the announcement." << endl;
                }
                resetColor();
                Sleep(2000);
            }
            break;

        case '4': // View Results
            if (anounceResult) {
                printHeader("ELECTION RESULTS");
                setColor(LIGHTCYAN);
                cout << string(80, '=') << endl;
                printCentered("OFFICIAL ELECTION RESULTS");
                cout << string(80, '=') << endl << endl;
                resetColor();
                
                showResult(po, poFileSize, result, resultFileSize, candidate, candidateFileSize);
                
                setColor(YELLOW);
                cout << "\nDo you want to close the Election Results (Y/n): ";
                resetColor();
                char c;
                cin >> c;
                
                if (c == 'Y' || c == 'y') {
                    printHeader("ADMIN VERIFICATION");
                    setColor(WHITE);
                    cout << "Username: ";
                    resetColor();
                    cin >> userName;
                    
                    setColor(WHITE);
                    cout << "Password: ";
                    resetColor();
                    cin >> Psw;
                    
                    if (userName == "admin" && Psw == "1234") {
                        loadingAnimation("Closing election results... ", 3);
                        anounceResult = false;
                        setColor(LIGHTGREEN);
                        cout << "Election results successfully closed." << endl;
                        resetColor();
                    } else {
                        setColor(LIGHTRED);
                        cout << "Error: Invalid credentials. Only admin can close election results." << endl;
                        resetColor();
                    }
                }
                Sleep(2000);
            } else {
                setColor(LIGHTRED);
                cout << "Results have not been announced yet!" << endl;
                resetColor();
                Sleep(2000);
            }
            break;

        case '5': // Exit
            loadingAnimation("Exiting system... ", 3);
            setColor(YELLOW);
            cout << "\nThank you for using the Election Management System!" << endl;
            resetColor();
            break;
        }
    } while (choice != '5');

    // Clean up memory
    delete[] voter;
    delete[] candidate;
    delete[] po;
    delete[] result;
    delete ec;

    return 0;
}
