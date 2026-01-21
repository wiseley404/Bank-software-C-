/**
 * \file CompteExceptionException.cpp
 * \brief Implantation de la classe CompteException et de ses héritiers
 * \author Petiton Wiseley / Monkam Mafoho Leinah
 * \version 1.0
 */
#include "CompteException.h"

using namespace std;


/**
 * \brief Constructeur de la classe de base CompteException
 * \param p_raison chaîne de caractères représentant la raison de l'erreur
 */
CompteException::CompteException(const std::string& p_raison): 
                std::runtime_error(p_raison){}


/**
 * \brief Constructeur de la classe CompteDejaPresentException en initialisant la classe de base CompteException.
 *        La classe représente des erreurs liees a la requete de creation d'un nouveau compte
 *        avec un numero de compte deja present dans le systeme.
 * \param p_raison chaîne de caractères représentant la raison de l'erreur
 */
CompteDejaPresentException::CompteDejaPresentException(const std::string& p_raison):
                            CompteException(p_raison){}


/**
 * \brief Constructeur de la classe CompteAbsentException en initialisant la classe de base CompteException.
 *        La classe représente des erreurs liees a la requete pour acceder a un compte
 *        qui n'existe pas sur le systeme.
 * \param p_raison chaîne de caractères représentant la raison de l'erreur
 */
CompteAbsentException::CompteAbsentException(const std::string& p_raison):
                       CompteException(p_raison){}

