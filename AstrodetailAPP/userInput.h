#pragma once
#include <string>
#include <iostream>
class userInput
{
public:
	userInput();
	~userInput();
public:
	void getInputs();
	void getDate();
	void getRqType();

	void getDay();
	void getMonth();
	void getYear();

	bool checkYear();
	bool checkMonth();
	bool checkDay();
	
	bool checkAstroidID();
	bool checkRqType();

	std::string strDate;
	std::string strYear;
	std::string strMonth;
	std::string strDay;
	std::string strAstroidID;
	std::string strRqType;
};
