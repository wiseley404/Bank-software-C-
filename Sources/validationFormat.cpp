/**
 * \file validationFormat.cpp
 * \brief  implémentation (définitions) des fonctions de validation
 * \author etudiant
 */
#include "validationFormat.h"
#include <string>
#include <cctype>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

namespace util
{
/**
 * \brief Vérifie la validité d'un nom
 * \param[in] p_nom une chaîne de caractères représentant le nom
 * \return un booléen indiquant si le nom est valide ou non
 */
bool 
validerFormatNom(const std::string& p_nom)
{
    bool valide = true;
    if(isalpha(p_nom[0]) && isalpha(p_nom[p_nom.size()-1]))
      {
      for (size_t i=0; i < p_nom.size(); i++)
        { 
          if(i==0 || i==p_nom.size()-1)
            {
            continue;
            }

          if (!(isalpha(p_nom[i]) ||  
                string ("éàÏïëñÑôÔòÒâÛÜüúÉÂœÈ -").find(p_nom[i]) != std::string::npos))
            {
              valide = false;
              break;
            }

          if(string (" -").find(p_nom[i]) != std::string::npos && 
             string (" -").find(p_nom[i+1]) != std::string::npos)
            {
              valide=false;
              break;
            }
        }
      }
    else
      {
        valide=false;
      }
  return valide;
}

/**
 * \brief Vérifie la validité d'un flux d'entrée
 * \param[in] p_is le flux d'entrée à valider
 * \return un booléen indiquant si le format du fichier est valide ou non
 */
bool 
validerFormatFichier(std::istream& p_is)
{
  bool valide = false;
  
  
  if(!p_is)
    {
      cerr << "Ouverture impossible" << endl;
      return 1;
    }
  else
    {
      vector <string> lignesDuFichier{};
      string ligne;
      
      while(getline(p_is, ligne))
        {
          lignesDuFichier.push_back(ligne);
        }
      for (size_t i {0}; i < lignesDuFichier.size(); ++i)
       {
        if((lignesDuFichier[i].empty())) 
          {
            valide = false;
          }
       }
          
        if(util::validerFormatNom(lignesDuFichier[0]))
          {
           if(util::validerFormatNom(lignesDuFichier[1]))
             {
              if(util::validerFormatDate(lignesDuFichier[2]))
                {
                  valide = true;
                }
             }
         }    
    }   
  
    return valide;
}

/**
 * \brief Vérifie la validité d'une date
 * \param[in] p_date un entier représentant la date au format jj mm aaaa
 * \return un booléen indiquant si la date est valide ou non
 */
bool
validerFormatDate(const std::string& p_date)
{
  bool valide = false;
  
  if (p_date.size() == 10)
    {
      if (p_date[2] == ESPACE && // format jj mm aaaa
          p_date[5] == ESPACE)
        {
          if (string ("0123").find(p_date[0]) != std::string::npos &&
              CHIFFRES.find(p_date[1]) != std::string::npos)
            {
              if (!(p_date[0] == '3' && //arrete le jour a 31
                    string ("23456789").find(p_date[1]) != std::string::npos))
                {
                  if(!(p_date[0] == '0' && //ne prend pas de valeur jour = 0
                       p_date[1] == '0'))
                    {
                      if (string ("01").find(p_date[3]) != std::string::npos &&
                          CHIFFRES.find(p_date[4]) != std::string::npos)
                        {
                          if(!(p_date[3] == '1' && //arrete le mois a 12
                             string ("3456789").find(p_date[4]) != std::string::npos))
                            {
                              if(!(p_date[3] == '0' && // ne prend pas de valeur mois = 0
                                   p_date[4] == '0'))
                                {
                                  if(string ("012").find(p_date[6]) != std::string::npos &&
                                     //prend que des annees a 2000 combien, exclus 3000+
                                     CHIFFRES.find(p_date[7]) != std::string::npos &&
                                     CHIFFRES.find(p_date[8]) != std::string::npos &&
                                     CHIFFRES.find(p_date[9]) != std::string::npos)
                                    {
                                      if(!(p_date[6] == '2' && p_date[7] =='0' &&
                                           p_date[8] == '2' && // arrete la naissance a 2025
                                           string ("6789").find(p_date[9]) != std::string::npos))
                                        {
                                          if(!(p_date[3] == '0' && p_date[4] == '2' &&
                                             p_date[0] =='3' ))//arrete fevrier a 29 
                                            {
                                              valide = true;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
  
  

  
  return valide;
}
/**
 * \brief Vérifie la validité d'un numéro de téléphone format XXX XXX-XXXX
 * \param[in] p_numero une chaîne de caractères représentant le numéro
 * \return un booléen indiquant si le numéro est valide ou non
 */
bool validerFormatNumero(const std::string& p_numero)
{
  bool valide = true;
  if (p_numero.size()==12 && p_numero[3]==ESPACE && p_numero[7]==TIRET) 
    {
      for (size_t i=0; i<p_numero.size (); i++)
        {
          if(i==3 || i==7)
            {
              continue;
            }
          if(!(isdigit(p_numero[i])))
            {
              valide = false;
            }
        }
    }
  else
    {
      valide = false;
    }
  return valide;
}

} //namespace util