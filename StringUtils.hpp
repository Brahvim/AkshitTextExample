#pragma once
#include <string>
#include <vector>

namespace StringUtils {

#pragma region // `convertToString()` overloads.
	template <typename PrintElementT>
	std::string convertToString(const PrintElementT &);

	template <typename PrintElementT>
	std::vector<PrintElementT> convertToString(const std::vector<PrintElementT> &);
#pragma endregion

#pragma region // `StringUtils::convertToLowercase()` overloads.
	std::string convertToLowercase(std::string &);

	std::vector<std::string> &convertToLowercase(const std::vector<char *> &);

	/**
	 * @param list the vector of strings to convert the strings of, to lowercase.
	 * @return The modified vector passed in.
	 */
	std::vector<std::string> &convertToLowercase(const std::vector<std::string> &);

	/**
	 * @return A new vector, after copying and converting all string elements in the argument one, to lowercase.
	 */
	std::vector<std::string> convertCopyToLowercase(const std::vector<std::string> &);
#pragma endregion

	std::vector<std::string> splitStringBySpaces(const std::string &p_str);
	std::vector<std::string> splitStringByChar(const std::string &p_str, const char p_delimiter);

}
