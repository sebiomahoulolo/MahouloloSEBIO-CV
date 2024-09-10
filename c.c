using System;

public class ArbreDecision
{
    private Noeud _racine;

    public ArbreDecision()
    {
        // Création de la racine
        _racine = new Noeud("Age");

        // Création des noeuds fils de la racine
        Noeud noeudAgeInf30 = new Noeud("< 30 ans", _racine);
        Noeud noeudAgeSup30 = new Noeud(">= 30 ans", _racine);

        // Création des noeuds fils de "Age < 30 ans"
        Noeud noeudExerciceInf3fois = new Noeud("Exercice < 3 fois/semaine", noeudAgeInf30);
        Noeud noeudExerciceSup3fois = new Noeud("Exercice >= 3 fois/semaine", noeudAgeInf30);

        // Création des feuilles de "Exercice < 3 fois/semaine"
        Noeud feuilleMauvaiseSante1 = new Noeud("Mauvaise santé", noeudExerciceInf3fois);
        Noeud feuilleBonneSante1 = new Noeud("Bonne santé", noeudExerciceInf3fois);

        // Création des feuilles de "Exercice >= 3 fois/semaine"
        Noeud feuilleMauvaiseSante2 = new Noeud("Mauvaise santé", noeudExerciceSup3fois);
        Noeud feuilleBonneSante2 = new Noeud("Bonne santé", noeudExerciceSup3fois);

        // Création des noeuds fils de "Age >= 30 ans"
        Noeud noeudAlimentationEquilibree = new Noeud("Alimentation équilibrée", noeudAgeSup30);
        Noeud noeudAlimentationNonEquilibree = new Noeud("Alimentation non équilibrée", noeudAgeSup30);

        // Création des feuilles de "Alimentation équilibrée"
        Noeud feuilleBonneSante3 = new Noeud("Bonne santé", noeudAlimentationEquilibree);
        Noeud feuilleMauvaiseSante3 = new Noeud("Mauvaise santé", noeudAlimentationEquilibree);

        // Création des feuilles de "Alimentation non équilibrée"
        Noeud feuilleMauvaiseSante4 = new Noeud("Mauvaise santé", noeudAlimentationNonEquilibree);
        Noeud feuilleBonneSante4 = new Noeud("Bonne santé", noeudAlimentationNonEquilibree);
    }

    public string PredireSante(int age, int frequenceExercice, bool alimentationEquilibree)
    {
        Noeud noeudCourant = _racine;

        while (!noeudCourant.EstFeuille())
        {
            if (noeudCourant.Nom == "Age")
            {
                noeudCourant = age < 30 ? noeudCourant.FilsGauche : noeudCourant.FilsDroit;
            }
            else if (noeudCourant.Nom == "Exercice")
            {
                noeudCourant = frequenceExercice < 3 ? noeudCourant.FilsGauche : noeudCourant.FilsDroit;
            }
            else if (noeudCourant.Nom == "Alimentation")
            {
                noeudCourant = alimentationEquilibree ? noeudCourant.FilsGauche : noeudCourant.FilsDroit;
            }
        }

        return noeudCourant.Nom;
    }
}

public class Noeud
{
    public string Nom { get; set; }

    public Noeud FilsGauche { get; set; }

    public Noeud FilsDroit { get; set; }

    public Noeud(string nom)
    {
        Nom = nom;
    }

    public Noeud(string nom, Noeud parent)
    {
        Nom = nom;
        parent.FilsGauche = this;
    }

    public bool EstFeuille()
    {
        return FilsGauche == null && FilsDroit == null;
    }
}
