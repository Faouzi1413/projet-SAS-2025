#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define max 20
#define MAX 300
 int N , choix ;
bool isOpened = false ;
typedef struct {
	int ID ;
	char nom [max] ;
	char prenom [max] ;
	int numeroMaillot ;
	char poste [max] ;
	int age ;
	int buts ;
} JOUEUR  ;

int compte = 9 ;
int IDcompteur = 10 ;
JOUEUR joueur [MAX] = {
        {1,"Lionel", "Messi", 1, 'attaquant', 34,  672},
        {2,"Cristiano", " Ronaldo", 2, 'attaquant', 36, 674},
        {3,"Neymar ", " Jr", 3, 'attaquant', 29, 11, 350},
        {4,"Kevin ", " De Bruyne", 4, 'milieu', 30,  85},
        {5,"Virgil ", " van Dijk", 5, 'defenseur', 30, 10},
        {6,"Manuel", " Neuer", 6, 'gardien', 35, 1},
        {7,"Sadio", " Mané", 7, 'attaquant', 29, 10},
        {8,"Luka", " Modrić", 8, 'milieu', 35, 10},
        {9,"Giorgio", " Chiellini", 9, 'defenseur', 37, 3},
        {10,"Alisson", " Becker", 10, 'gardien', 28, 1}
    };



void menu ()
{
	printf ("\n\n\n\n\n") ;
	printf ("\t\t\t==============MENU==============\n\n") ;
	printf ("\t\t\t 1. Ajouter un joueur : \n") ;
	printf ("\t\t\t 2. Afficher la liste de tous les joueurs : \n") ;
	printf ("\t\t\t 3. Modifier un joueur : \n") ;
	printf ("\t\t\t 4. Supprimer un joueur : \n") ;
	printf ("\t\t\t 5. Rechercher un joueur : \n") ;
	printf ("\t\t\t 6. Statistiques : \n") ;
	printf ("\t\t\t====autre choix pour quitter===== \n\n") ;

}


void ajouter ()
{
	int choix ;
  do {

  	printf ("\t\t========  entrez 1 pour Ajouter un nouveau joueur =============\n\n") ;
  	printf ("\t\tentrez 2 pour Ajouter plusieurs joueurs en une seule operation\n\n") ;
  	scanf ("%d", &choix);

  
     

      switch (choix)
      {
      	case  1 :
      		if (compte < MAX){

		  printf ("ajouter le nom pour joueur %d :", compte + 1) ;
		  scanf ("%s", joueur[compte].nom );
		  printf ("ajouter le prenom pour joueur %d :", compte + 1) ;
		  scanf ("%s" , joueur[compte].prenom) ;

		  do {

		  printf ("ajouter le numero de maillot pour joueur %d entre 1 - 99 :", compte + 1) ;
		  scanf ("%d", &joueur[compte].numeroMaillot);
	} while (joueur[compte].numeroMaillot < 1 || joueur[compte].numeroMaillot > 100 );
		  printf ("ajouter la poste pour joueur %d :", compte + 1) ;
		  scanf ("%s" , joueur[compte].poste) ;
		  do {

		  printf ("ajouter l age pour joueur %d entre 15 - 40 :", compte + 1) ;
		  scanf ("%d", &joueur[compte].age);
	} while (joueur[compte].age < 14 || joueur[compte].age > 40 );
		  printf ("ajouter le nombre de buts marque par le joueur %d :", compte + 1) ;
		  scanf ("%d", &joueur[compte].buts);
		  printf ("le joueur %d ajoute avec succes :\n", compte + 1 ) ;
		  joueur[compte].ID = IDcompteur++ ;
		  compte ++ ;
		  printf ("**************************************************\n\n") ;
	}
	 else
	      printf ("Le tableau de joueurs est plein.\n") ;

		  break ;

		  case 2 :

		  	printf ("veuillez entrer le nombre de joueurs ") ;
		  	scanf ("%d" , &N);
		  	if (compte + N < MAX)
			  {

		  	for (int i = 0 ; i < N ; i ++ )
		  	{
		  printf ("ajouter le nom pour joueur %d :", compte + 1) ;
		  scanf ("%s", joueur[compte].nom );
		  printf ("ajouter le prenom pour joueur %d :", compte + 1) ;
		  scanf ("%s" , joueur[compte].prenom) ;

		  do {

		  printf ("ajouter le numero de maillot pour joueur %d entre 1 - 99 :", compte + 1) ;
		  scanf ("%d", &joueur[compte].numeroMaillot);
	} while (joueur[compte].numeroMaillot < 1 || joueur[compte].numeroMaillot > 100 );
		  printf ("ajouter la poste pour joueur %d :", compte + 1) ;
		  scanf ("%s" , joueur[compte].poste) ;
		  do {

		  printf ("ajouter l age pour joueur %d entre 15 - 40 :", compte + 1) ;
		  scanf ("%d", &joueur[compte].age);
	} while (joueur[compte].age < 14 || joueur[compte].age > 40 );
		  printf ("ajouter le nombre de buts marque par le joueur %d :", compte + 1) ;
		  scanf ("%d", &joueur[compte].buts);
		  printf ("le joueur %d ajoute avec succes :\n", compte + 1 ) ;
		  joueur[compte].ID = IDcompteur++ ;
		  compte ++ ;
		  printf ("**************************************************\n\n") ;
		}
    }
    	else
    	printf ("Le tableau de joueurs est plein.\n") ;
		   break ;

		   default :
		   	printf ("veuillez entrer 1 ou 2 : \n") ;
		   	break ;

		}
      }  while (choix != 0);
	}


	void affiche ()
	{
	  JOUEUR temp = {} ;
	  int choix , trouve ;
	  char poste[max] ;

	  printf ("\t\t\t **************MENU**********************\n") ;
	  printf ("\t\t\t 1 pour les joueurs par ordre alphabtique.\n") ;
	  printf ("\t\t\t 2 pour les joueurs par age.\n") ;
	  printf ("\t\t\t 3 les joueurs par poste.\n") ;
	  printf ("\t\t\t *****************************************\n") ;
	  scanf ("%d", &choix) ;

	  switch (choix)
	  {
	   case 1 :

	  for (int i = 0 ; i < compte - 1 ; i ++ )
	  {
	  	for (int j = 0 ; j < compte - i - 1 ; j ++ )
	  	{
	  		if (strcmp (joueur[j].nom, joueur[j + 1].nom) > 0)
	  		{
				temp = joueur[j];
				joueur [j] = joueur [j + 1];
				joueur [j + 1] = temp;
			  }
		  }
	  }

	  for (int i = 0 ; i < compte ; i ++ )
	  {
	  	printf ("\n\n\t\t\===le joueur : %d==== \n", i + 1) ;
	  	printf ("\t\t\tle nom : %s \n", joueur[i].nom ) ;
	  	printf ("\t\t\tle prenom : %s \n", joueur[i].prenom) ;
	  	printf ("\t\t\tle numero de Maillot : %d \n", joueur[i].numeroMaillot) ;
	  	printf ("\t\t\tl age : %d \n", joueur[i].age ) ;
	  	printf ("\t\t\tle poste : %s \n", joueur[i].poste ) ;
	  	printf ("\t\t\tle nombre des buts : %d  \n", joueur[i].buts ) ;
	  	printf ("\t\t\tle ID : %d  \n", joueur[i].ID ) ;
	  	printf ("\t\t**************************\n\n") ;

	  }
	  break ;

	  case 2 :

	   for (int i = 0 ; i < compte - 1 ; i ++ )
	  {
	  	for (int j = 0 ; j < compte - i - 1 ; j ++ )
	  	{
	  		if (strcmp (joueur[j].nom, joueur[j + 1].nom) > 0)
	  		{
				temp = joueur[j];
				joueur [j] = joueur [j + 1];
				joueur [j + 1] = temp;
			  }
		  }
	  }

	   for (int i = 0 ; i < compte ; i ++ )
	  {
	  	printf ("\t\t\n\n===le joueur : %d==== \n", i + 1) ;
	  	printf ("\t\t\tle nom : %s \n", joueur[i].nom ) ;
	  	printf ("\t\t\tle prenom : %s \n", joueur[i].prenom) ;
	  	printf ("\t\t\tle numero de Maillot : %d \n", joueur[i].numeroMaillot) ;
	  	printf ("\t\t\tl age : %d \n", joueur[i].age ) ;
	  	printf ("\t\t\tle poste : %s \n", joueur[i].poste ) ;
	  	printf ("\t\t\tle nombre des buts : %d  \n", joueur[i].buts ) ;
	  	printf ("\t\t\tle ID : %d  \n", joueur[i].ID ) ;
	  	printf ("\t\t**************************\n\n") ;

	  }
	  break ;

	  case 3 :

	  	printf ("veuillez saisir le poste :\n") ;
	  	scanf ("%s" , poste) ;
	  	trouve = 0 ;
	  	for (int i = 0 ; i < compte ; i ++ )
	  	{
	  	  if (strcmp (joueur[i].poste, poste) == 0)
		 {

	  	printf ("\n\n\t\t\===le joueur : %d==== \n", i + 1) ;
	  	printf ("\t\t\tle nom : %s \n", joueur[i].nom ) ;
	  	printf ("\t\t\tle prenom : %s \n", joueur[i].prenom) ;
	  	printf ("\t\t\tle numero de Maillot : %d \n", joueur[i].numeroMaillot) ;
	  	printf ("\t\t\tl age : %d \n", joueur[i].age ) ;
	  	printf ("\t\t\tle poste : %s \n", joueur[i].poste ) ;
	  	printf ("\t\t\tle nombre des buts : %d  \n", joueur[i].buts ) ;
	  	printf ("\t\t\tle ID : %d  \n", joueur[i].ID ) ;
	  	printf ("\t\t**************************\n\n") ;
		trouve = 1 ;
		  }
	   }
	  if (trouve == 0 )
	  printf ("\t\t\tPas de joueur a ce poste!") ;
      break ;
    }
}

      void modifie ()
      {
      	int id ;
      	do {

      	printf ("\t\t\t **************MENU**********************\n") ;
      	printf ("\t\t\t 1 pour Modifier le poste d un joueur.\n") ;
      	printf ("\t\t\t 2 pour Modifier l age d un joueur.\n") ;
      	printf ("\t\t\t 3 pour Modifier le nombre de buts marques par un joueur.\n") ;
      	printf ("\t\t\t ========================================\n") ;
      	scanf ("%d" , &choix) ;
      } while (choix < 1 || choix > 3) ;
      	switch (choix)
      	{
      		case 1 :
      			printf ("vueillez entrer l ID de joueur pour modifie : \n") ;
      			scanf ("%d" , &id) ;

      			for (int i = 0 ; i < compte ; i ++ )
      			{
      				if (id == joueur[i].ID)
      				{
      					printf ("veuillez entrer nouveau poste pour joueur %d \n",i + 1) ;
      					scanf ("%s",  joueur[i].poste) ;
      					printf ("le poste modifie succes .\n") ;
      					break ;
					}
				  }
				  break ;
      			case 2 :
      					printf ("vueillez entrer l ID de joueur pour modifie : \n") ;
      			scanf ("%d" , &id) ;

      			for (int i = 0 ; i < compte ; i ++ )
      			{
      				if (id == joueur[i].ID)
      				{
      					printf ("veuillez entrer nouveau age pour joueur %d \n",i + 1) ;
      					scanf ("%d", &joueur[i].age) ;
      					printf ("l age modifie succes .\n") ;
      					break ;
					  }
				  }
				  break ;
      			case 3 :
				  	printf ("vueillez entrer l ID de joueur pour modifie : \n") ;
      			    scanf ("%d" , &id) ;

      			for (int i = 0 ; i < compte ; i ++ )
      			{
      				if (id == joueur[i].ID)
      				{
      					printf ("veuillez entrer nouveau nombre des burs marque par joueur %d \n",i + 1) ;
      					scanf ("%d", &joueur[i].buts) ;
      					printf ("le nombre des buts modifie succes .\n") ;
      					break ;
					  }
				  }
				  break ;
		      }
	  }

	  void supprime ()
	  {
	  	    int id ;

	  		printf ("vueillez entrer l ID de joueur pour supprime : \n") ;
      	    scanf ("%d" , &id) ;

      	    for (int i = 0 ; i < compte ; i ++ )
      	    {
      	    	if (id == joueur[i].ID)
      	    	{
      	    	 for (int j = i ; j < compte - 1 ; j ++ )
				   {
				   	joueur[j] = joueur[j + 1] ;
					   }
				  }
				  compte -- ;
				  printf ("le joueur a ete supprimer!\n");
				  break ;
			  }

	  }


	void recherche ()
	{
		int id , choix ;
		char nom [max] ;

		do {

		printf ("\t\t\t 1 pour rechercher un joueur par Identifiant :\n") ;
		printf ("\t\t\t 2 pour rechercher un joueur par Nom :\n") ;
		scanf ("%d" , &choix) ;
	}
		while (choix < 1 || choix > 2) ;


		switch (choix)
		{
			case 1 :
		printf ("\t\t\t veuillez entrer l ID de joueur :\n");
		scanf ("%d", &id) ;
		int trouve = 0 ;
		for (int i = 0 ; i < compte ; i ++ )
		{
			if (joueur[i].ID == id )
			{
			printf ("\t\t\t Le joueur que tu cherches est : \n\n");
			printf ("\t\t\t le joueur %d : \n", i + 1) ;
	  	    printf ("\t\t\t le nom %s : \n", joueur[i].nom ) ;
	  	    printf ("\t\t\t le prenom %s : \n", joueur[i].prenom) ;
	   	    printf ("\t\t\t le numero de Maillot %d : \n", joueur[i].numeroMaillot) ;
	  	    printf ("\t\t\t l age %d : \n", joueur[i].age ) ;
	  	    printf ("\t\t\t le poste %s : \n", joueur[i].poste ) ;
	  	    printf ("\t\t\t le ID %d : \n", joueur[i].ID ) ;
			trouve = 1 ;
			break ;
	    }
		}
		if (trouve != 1)
		printf ("\t\t\t le joueur n est pas trouve ! \n") ;
		break ;

		case 2 :
			printf ("\t\t\t veuillez entrer le nom de joueur :\n");
			scanf ("%s", nom) ;
			trouve = 0 ;
			for (int i = 0 ; i < compte ; i ++ )
			{
				if (strcmp(joueur[i].nom , nom) == 0) {

			printf ("\t\t\t Le joueur que tu cherches est : \n\n");
			printf ("\t\t\t le joueur %d : \n", i + 1) ;
	  	    printf ("\t\t\t le nom %s : \n", joueur[i].nom ) ;
	  	    printf ("\t\t\t le prenom %s : \n", joueur[i].prenom) ;
	   	    printf ("\t\t\t le numero de Maillot %d : \n", joueur[i].numeroMaillot) ;
	  	    printf ("\t\t\t l age %d : \n", joueur[i].age ) ;
	  	    printf ("\t\t\t le poste %s : \n", joueur[i].poste ) ;
	  	    printf ("\t\t\t le ID %d : \n", joueur[i].ID ) ;
			trouve = 1 ;
			break ;
				}
			}
		if (trouve != 1)
		printf ("\t\t\t le joueur n est pas trouve ! \n") ;
		break ;

		default :
			printf ("\t\t\t veuillez entrer le choi 1 ou 2 \n") ;
	}
  }

      void statistique ()
      {
      	float somme = 0 , moyanne = 0 ;
      	JOUEUR temp = {} ;
      	int maxInd , minAgeInd , maxAgeInd ;

      	do {

      	printf ("===================================MENU============================================\n\n") ;
      	printf ("1. pour Afficher le nombre total de joueurs dans l equipe.\n") ;
      	printf ("2. pour Afficher l age moyen des joueurs. \n") ;
      	printf ("3. pour Afficher les joueurs ayant marque plus de X buts (X introduit par l utilisateur).\n") ;
      	printf ("4. pour Afficher le meilleur buteur (joueur avec le maximum de buts).\n") ;
      	printf ("5. pour Afficher le joueur le plus jeune et le plus age\n\n") ;
      	printf ("=================================votre choi========================================\n") ;
      	scanf ("%d" , &choix) ;
      } while (choix < 1 || choix > 5) ;

      switch (choix)
      {
      	case 1 :

      	printf ("le nombre total de joueurs dans l equipe est : %d",compte) ;
		  break ;

		  case 2 :
		  for (int i = 0 ; i < compte ; i ++ )
		  {
		  	somme += joueur[i].age ;
			  }
      	printf ("\t\t\tl age moyanne des joueurs est : %.2f \n\n",moyanne = somme / compte) ;
		  break ;

		  case 3 :
		  	printf ("\t\t\t veuillez entrer le nombre des buts : \n") ;
		  	scanf ("%d" , &N);

	   printf ("\t====les joueurs ayant marque plus de %d buts sont : ==== \n\n",N) ;
	   for (int  i= 0 ; i < compte ; i ++ )
	  {
	  	if ( N <= joueur[i].buts)
		  {
	  	printf ("\t\t\tle nom : %s \n", joueur[i].nom ) ;
	  	printf ("\t\t\tle prenom : %s \n", joueur[i].prenom) ;
	  	printf ("\t\t\tle numero de Maillot : %d \n", joueur[i].numeroMaillot) ;
	  	printf ("\t\t\tl age : %d \n", joueur[i].age ) ;
	  	printf ("\t\t\tle poste : %s \n", joueur[i].poste ) ;
	  	printf ("\t\t\tle nobre des buts : %d  \n", joueur[i].buts ) ;
	  	printf ("\t\t\tle ID : %d  \n", joueur[i].ID ) ;
	  	printf ("\t\t***************************\n\n") ;
		  }
	  }
	  break ;

	  case 4 :
	  	    maxInd = 0 ;
            for (int i = 1; i < compte; i++) {
            if (joueur[i].buts > joueur[maxInd].buts) {
            maxInd = i;
          }
        }
        printf("Le meilleur buteur est : %s %s avec %d buts.\n", joueur[maxInd].nom, joueur[maxInd].prenom, joueur[maxInd].buts);
	  	break ;

	  	case 5 :

	  		  minAgeInd = 0;
			  maxAgeInd = 0;
              for (int i = 1; i < compte; i++) {
              if (joueur[i].age < joueur[minAgeInd].age)
              minAgeInd = i;
              if (joueur[i].age > joueur[maxAgeInd].age)
              maxAgeInd = i;
          }
           printf("Le joueur le plus jeune est : %s %s (%d ans)\n", joueur[minAgeInd].nom, joueur[minAgeInd].prenom, joueur[minAgeInd].age);
           printf("Le joueur le plus age est : %s %s (%d ans)\n", joueur[maxAgeInd].nom, joueur[maxAgeInd].prenom, joueur[maxAgeInd].age);
		   break ;
	  }
   }

   int main(int argc, char *argv[]) {


	int choix ;


    do {
        
          menu () ;


	scanf ("%d", &choix) ;


	switch (choix)
	{


		case 1:
			ajouter () ;
			
			break ;

        case 2 :
			affiche () ;
            
			break ;

			case 3 :
			modifie () ;
            

			break ;

			case 4 :
			supprime () ;
            

			break ;

			case 5 :
			recherche () ;
            

			break ;

			case 6 :
				statistique () ;
                

				break ;

            case 0 :
                printf("\n merci baucoup d utilise notre application !!! ");
                break ;

			default :

                printf ("choix invalide \n") ;

				break ;


	}


} while (choix != 0);


	return 0;
}