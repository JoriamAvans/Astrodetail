#include "userInput.h"

userInput::userInput()
{

}

userInput::~userInput()
{
}

void userInput::startInput() //NEEDS CHANGE
{
	std::cout << "Choose your preferred input type" << std::endl;
	std::cout << "You can choose: \'ID\' to input an astroid ID" << std::endl;
	std::cout << "You can choose: \'DATE\' to input a start date" << std::endl
			  << "When putting in a date you will see all the data from that date and the 7 days following" << std::endl;
	getRqType();
}

void userInput::getRqType()
{
	std::cout << "Enter preferred type: ";
	std::cin >> strRqType;
	std::cout << std::endl;
	if (checkRqType() == false) {
		std::cout << "Incorrect request type" << std::endl;
		std::cout << "Please use \'ID\' or \'DATE\'" << std::endl << std::endl;
		getRqType();
	}
	if (strRqType == "ID")
		getAstroidID();
	
	if (strRqType == "DATE")
		getDate();
}

void userInput::getAstroidID()
{
	bool AllowContinue = false;
	while (AllowContinue == false) {

		std::cout << "Please enter Astroid ID in 7 numbers" << std::endl;

		std::cin >> strAstroidID;
		std::cout << std::endl;
		
		if (checkAstroidID() == false) {
			std::cout << "Incorrect astroid ID format" << std::endl;
			std::cout << "Please use max 7 numbers only" << std::endl;
		}
		else if (checkAstroidID() == true)
		{
			AllowContinue = true;
		}
	}
	std::cout << "You have chosen the Astroid: " << strAstroidID << std::endl;
}

void userInput::getDate()
{
	std::cout << "Please enter day in DD format" << std::endl;
	getDay();
	checkDay();
	std::cout << "You have chosen the day: " << strDay << std::endl;

	std::cout << "Please enter month in MM format" << std::endl;
	getMonth();
	checkMonth();
	std::cout << "You have chosen the month: " << strMonth << std::endl;

	std::cout << "Please enter year in YYYY format" << std::endl;
	getYear();
	checkYear();
	std::cout << "You have chosen the year: " << strYear << std::endl;

	strDate = strYear + '-' + strMonth + '-' + strDay;

	std::cout <<
		"The date you entered was: " <<
		strDate << std::endl << std::endl;
}

void userInput::getDay()
{
	std::cin >> strDay;
	std::cout << std::endl;
	if (checkDay() == false) {
		std::cout << "Incorrect day format" << std::endl;
		std::cout << "Please use format DD" << std::endl;
		getDay();
	}

}

void userInput::getMonth()
{
	std::cin >> strMonth;
	std::cout << std::endl;
	if (checkMonth() == false) {
		std::cout << "Incorrect month format" << std::endl;
		std::cout << "Please use format MM" << std::endl;
		getMonth();
	}
}

void userInput::getYear()
{
	std::cin >> strYear;
	std::cout << std::endl;
	if (checkYear() == false) {
		std::cout << "Incorrect year format" << std::endl;
		std::cout << "Please use format YYYY" << std::endl;
		getYear();
	}
}

bool userInput::checkYear()
{

	//CHECK IF THE VALUE CONTAINS ONLY DIGITS
	for (int i = 0; i < strYear.length(); i++)
	{
		if (isdigit(strYear[i]) == false)
			return false;
	}

	//CHECK BOUNDARIES OF THE DIGITS
	if (stoi(strYear) < 1950 || stoi(strYear) > 2022)
		return false;
	//CHECK STRING LENGTH
	if (strYear.length() != 4)
		return false;

	return true;
}

bool userInput::checkMonth()
{
	//CHECK IF THE VALUE CONTAINS ONLY DIGITS
	for (int i = 0; i < strMonth.length(); i++)
	{
		if (isdigit(strMonth[i]) == false)
			return false;
	}

	//CHECK BOUNDARIES OF THE DIGITS
	if (stoi(strMonth) < 0 || stoi(strMonth) > 12)
		return false;

	//CHECK STRING LENGTH
	if (strMonth.length() != 2)
		return false;

	return true;
}

bool userInput::checkDay()
{
	//CHECK IF THE VALUE CONTAINS ONLY DIGITS
	for (int i = 0; i < strDay.length(); i++)
	{
		if (isdigit(strDay[i]) == false)
			return false;
	}

	//CHECK BOUNDARIES OF THE DIGITS
	//(This does not take into account different month lenghts)
	if (stoi(strDay) < 0 || stoi(strDay) > 31)
		return false;

	//CHECK STRING LENGTH
	if (strDay.length() != 2)
		return false;

	return true;
}

bool userInput::checkAstroidID()
{

	//CHECK IF THE VALUE CONTAINS ONLY DIGITS
	for (int i = 0; i < strAstroidID.length(); i++)
	{
		if (isdigit(strAstroidID[i]) == false)
			return false;
	}

	//CHECK STRING LENGTH
	if (strAstroidID.length() != 7) //7 is the amount of numbers in an ID
		return false;

	return true;
}

bool userInput::checkRqType()
{
	if (strRqType == "ID" || strRqType == "DATE")
		return true;
	return false;
}


