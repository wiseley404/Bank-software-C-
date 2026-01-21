/**
 * \file validationFormat.h
 * \brief Fichier qui contient l'interface d'un ensemble de fonctions de validation.
 * \author Petiton Wiseley
 * \version 1.0
 */
#ifndef VALIDATIONFORMAT_H
#define VALIDATIONFORMAT_H

#include <string>
#include <fstream>


namespace util
{
const char ESPACE = ' ';
const char TIRET = '-';
const std::string CHIFFRES = "0123456789";

bool validerFormatNom(const std::string& p_nom); 
bool validerFormatFichier(std::istream& p_is);
bool validerFormatDate(const std::string& p_date);
bool validerFormatNumero(const std::string& p_numero);
} //namespace util
#endif /* VALIDATIONFORMAT_H */

