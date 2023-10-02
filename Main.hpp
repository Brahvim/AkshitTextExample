#pragma once
#include "PrintUtils.hpp"
#include "StringUtils.hpp"
#include "NaturalWriter.hpp"

namespace VendingMachine {

	const std::vector<std::string>
		DRINK_NUMBERS = { "one", "two", "three", "four" },
		DRINKS_LIST_FORMATTED = { "Water", "Cola", "Lemonade", "Strawberry Milkshake" },
		DRINKS_LIST_LOWERCASE = StringUtils::convertCopyToLowercase(VendingMachine::DRINKS_LIST_FORMATTED);

	const size_t NUM_DRINKS = VendingMachine::DRINKS_LIST_FORMATTED.size();

	const std::vector<std::vector<std::string>> DRINKS_NAMES_TOKENS = []() {
		std::vector<std::vector<std::string>> toRet;
		toRet.reserve(VendingMachine::DRINKS_LIST_LOWERCASE.size());
		for (auto &s : VendingMachine::DRINKS_LIST_LOWERCASE)
			toRet.push_back(StringUtils::splitStringBySpaces(s));

		return toRet;
	}();


	void welcome(void);

	void promptForDrink(void);

	void writeDrinksList(void);

	void printDrinksList(void);

	std::string getUserInputLine();

	int checkDrinkInput(void);

	int getDrinkFromNumberName(const std::string_view);

	int getDrinkFromNumericalSymbol(const std::string &);

	void serveDrink(const int);

	void reportIncorrectInput(void);

	void sayGoodbye(void);

};
