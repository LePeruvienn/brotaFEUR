#include <string>

/* 
 * This fiels is sued to store all the strings that can be usefull,
 * It used to i dont have to always a declare a new var when using one
 *
 * - All `std::strings` starts with __STRING__
 * - All `char` starts with __CHAR__
 */

/* strings */
constexpr std::string __STRING_EMPTY__ = "";

/* chars */
constexpr char __CHAR_JUMP_LINE__ = "\n";
constexpr char __CHAR_TAB__ = "\t";
