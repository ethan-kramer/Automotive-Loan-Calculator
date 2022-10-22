/**
file: <AutomativeLoanCalculator>.cpp
by: Ethan Kramer
org: COP 2001, Spring 2021, CRN: 10410
desc: <Collect the price, annual percentage rate and
term in years from the user. Then calculate the monthly payment, total of payments and total
interest paid on the loan and display all values back to the user in a financial form format>
*/
#include<iostream>		// console output library
#include<iomanip>		// includes std::fixed and std::setprecision()
#include <string>
#include <math.h>		// for std::pow() --> exponents

const int LINE_LENGTH = 60;
int main()
{

	double price = 0.0, annualRate = 0.0;
	int term = 0;

	// get price, term(in years), and apr

	std::cout << "Enter price: ";
	std::cin >> price;

	std::cout << "Enter Term (in years): ";
	std::cin >> term;

	std::cout << "Enter Annual Percentage Rate (APR): ";
	std::cin >> annualRate;

	//calculate internal rate
	double internalRate = annualRate / 100.0 / 12.0;

	//calculate internal term
	int internalTerm = term * 12;

	//calculate monthly payment
	double monthlyPayment = price * internalRate / (1 - (std::pow(1.0 + internalRate, -internalTerm)));

	//calculate total of payments
	double totalPayments = internalTerm * monthlyPayment;

	//calculate total interest paid on the loan
	float interestPaid = totalPayments - price;	

	//format price spacing
	std::string priceLabel = "Price: ";		// 7 characters, value is 8 characters, line length = 60 --> 60-7-8=45 spaces
	int priceSpaces = LINE_LENGTH - priceLabel.length() - (std::to_string(price).length() - 4);
	priceLabel.replace(priceLabel.length() - 1, 1, priceSpaces, ' ');

	//format term spacing
	std::string termLabel = "Term (In Years): ";  //17 characters, value is 1 character
	int termSpaces = LINE_LENGTH - termLabel.length() - (std::to_string(term).length());
	termLabel.replace(termLabel.length() - 1, 1, termSpaces, ' ');

	//format rate spacing
	std::string rateLabel = "Rate (APR): ";
	int rateSpaces = LINE_LENGTH - rateLabel.length() - (std::to_string(annualRate).length() - 4);
	rateLabel.replace(rateLabel.length() - 1, 1, rateSpaces, ' ');

	//format monthly payment spacing
	std::string monthlyPaymentLabel = "Monthly Payment: ";
	int monthlyPaymentSpaces = LINE_LENGTH - monthlyPaymentLabel.length() - (std::to_string(monthlyPayment).length() - 4);
	monthlyPaymentLabel.replace(monthlyPaymentLabel.length() - 1, 1, monthlyPaymentSpaces, ' ');

	//format interest spacing
	std::string interestLabel = "Interest Paid: ";
	int interestSpaces = LINE_LENGTH - interestLabel.length() - (std::to_string(interestPaid).length() - 4);
	interestLabel.replace(interestLabel.length() - 1, 1, interestSpaces, ' ');

	//format total payment spacing
	std::string totalPaymentLabel = "Total Paid: ";
	int totalPaymentSpaces = LINE_LENGTH - totalPaymentLabel.length() - (std::to_string(totalPayments).length() - 4);
	totalPaymentLabel.replace(totalPaymentLabel.length() - 1, 1, totalPaymentSpaces, ' ');

	//output all values w/ proper formatting
	std::cout << "\n" << "\n" << "\n" << std::endl;
	std::cout << std::fixed << std::setprecision(2) << priceLabel << price << std::endl;	//gives correct formatting
	std::cout << termLabel << term << std::endl;
	std::cout << std::fixed << std::setprecision(2) << rateLabel << annualRate << "%" << std::endl;
	std::cout << std::fixed << std::setprecision(2) << monthlyPaymentLabel << monthlyPayment << std::endl;
	std::cout << "-----------------------------------------------------------" << std::endl;
	std::cout << std::fixed << std::setprecision(2) << interestLabel << interestPaid << std::endl;
	std::cout << std::fixed << std::setprecision(2) << totalPaymentLabel << totalPayments << std::endl;



	return 0;
}
