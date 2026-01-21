/**
 * \file CompteException.h qui contient l'interface de la classe CompteException et de ses héritiers.
 * \brief Hiérarchie de classe pour la gestion des erreurs liées aux comptes.
 *
 * Ces classes constituent la hiérarchie pour la gestion de 
 * l’exception liée aux comptes. Elle maintient les données nécessaires à
 * la sauvegarde des renseignements de l'erreur.  Cette classe et sa
 * hiérarchie sont intéressantes lors de l'utilisation des exceptions.
 *
 * En release, définir la constante NDEBUG pour désactiver les Macros
 *
 * <pre>
 * Classes:
 * std::runtime_error              Classe de base des exceptions a l'execution d'une requete.
 * CompteException:                Classe de base des exceptions de compte.
 * CompteDejaPresentException:     Classe de gestion des erreurs d'existence de Compte.
 * CompteAbsentException:          Classe de gestion des erreurs d'absence de Compte.
 * 
 * Attributs:
 *      std::string  m_raison:     La raison de l'echec a l'execution d'une requete.
 * 
 * </pre>
 * 
 * \author Petiton Wiseley / Monkam Mafoho Leinah
 * \version 1.0
 */

#ifndef COMPTEEXCEPTION_H
#define COMPTEEXCEPTION_H

#include <stdexcept>
#include <string>

/**
 * \class CompteException
 * \brief Classe de base des exceptions de compte.
 */
class CompteException : public std::runtime_error
{
  public:
    CompteException(const std::string& p_raison);
    ~CompteException() throw() {};
};

/**
 * \class CompteDejaPresentException
 * \brief Classe pour la gestion des erreurs de compte deja present.
 */

class CompteDejaPresentException : public CompteException
{
public:
  CompteDejaPresentException(const std::string& p_raison);
};


/**
 * \class CompteAbsentException
 * \brief Classe pour la gestion des erreurs de compte absent
 */

class CompteAbsentException : public CompteException
{
public:
  CompteAbsentException(const std::string& p_raison);
};


#endif /* COMPTEEXCEPTION_H */

