// Challenge: Galactic Resource Manager - Create a program to calculate and manage a space empire’s resources over time, including Minerals, Energy, and Alloys.

#include <iostream>

using namespace std;

int main()
{
	// Resource Input : Ask the player to input the empire’s monthly production and consumption for 1) Minerals, 2) Energy, and 3) Alloys
	cout << "Welcome to Sun IndustriesTM Galactic Resource Manager.\n\nThis simple program will help you track minerals, energy and alloys.\n\nPlease enter your monthly Mineral production: ";
	int minePro;
	cin >> minePro;

	cout << "Please enter your monthly Mineral consumption: ";
	int mineCon;
	cin >> mineCon;

	cout << "Please enter your monthly Energy production: ";
	int nrgPro;
	cin >> nrgPro;

	cout << "Please enter your monthly Energy consumption: ";
	int nrgCon;
	cin >> nrgCon;

	cout << "Please enter your monthly Alloy production: ";
	int alloyPro;
	cin >> alloyPro;

	cout << "Please enter your monthly Alloy consumption: ";
	int alloyCon;
	cin >> alloyCon;

	// For each resource, calculate the net production(production minus consumption) and display the net values.

	int mineNet = minePro - mineCon;
	int nrgNet = nrgPro - nrgCon;
	int alloyNet = alloyPro - alloyCon;

	cout << "\nThank you for you ongoing contributions to Sun IndustriesTM.\n\nNet Resources Per Month:\n";
	cout << "- Minerals: " << mineNet << endl;
	cout << "- Energy: " << nrgNet << endl;
	cout << "- Alloys: " << alloyNet << endl;

	// Based on the net production, calculate total resources accumulated after 6 months and 12 months.

	cout << "\nTotal Resources After 6 Month:\n";
	cout << "- Minerals: " << (mineNet * 6) << endl;
	cout << "- Energy: " << (nrgNet * 6) << endl;
	cout << "- Alloys: " << (alloyNet * 6) << endl;

	cout << "\nTotal Resources After 12 Month:\n";
	cout << "- Minerals: " << (mineNet * 12) << endl;
	cout << "- Energy: " << (nrgNet * 12) << endl;
	cout << "- Alloys: " << (alloyNet * 12) << endl;

	// Alloy Conversion : Use 50 units of Minerals to produce 10 units of Alloys. Calculate how many additional Alloys can be produced from surplus Minerals after 6 and 12 months.

	cout << "\nAdditional Alloys Produces From Surplus Minerals:\n";
	cout << "- After 6 Months: " << ((mineNet * 6) /5) << endl;
	cout << "- After 12 Months: " << ((mineNet * 12) / 5) << endl;
	cout << "\nThank you for using the Sun IndustriesTM Galactic Resource Manager.\nSun IndustriesTM. Building a better tomorrow.\n";
}