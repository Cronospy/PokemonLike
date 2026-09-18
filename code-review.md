# Revue de code

## Structure du projet
* Le projet a une architecture claire avec les répertoires source et include, et une classe pour chaque objet.

* Il y a bien un script de compilation.

* Dans le readme il manque la description de la structure du projet. Mais il y a bien l'état d'avancée qui est indiqué.

----------------
## Fonctionalité du code

Le code contient ces fonctionnalités : 
* Usage d'un itérateur dans les boucles for (ex : dans la classe **set_of_pokemon**)
* Usage de vecteurs (ex : **array_of_pokemons** dans la classe **set_of_pokemon**)
* Usage de type auto (ex : dans la méthode **select_starter_pokemon** de la classe **game_engine**)
* Usage de design pattern Singleton dans la classe **pokedex**

----------------
## Clarté du code
* Les méthodes et classes ont des noms qui permettent de comprendre ce que font les classes et les méthodes, ce qui est bien.

----------------
## Contenu du code

* Pour la classe **pokemon** :
  * La classe définis tous les getters mais uniquement les setters utiles, ce qui est bien. Pour le setter **set_hit_points** ce serait bien de vérifier que les points de vies sont valides : la valeur de **new_hit_points** doit être positive et être inférieure à **max_hit_points**.
  * Pour l'initialisation de **max_hit_points** dans le constructeur de copie, tu as mis **max_hit_points(max_hit_points)** à la place de **max_hit_points(other.max_hit_points)**

* Pour la classe **set_of_pokemon**:
  * Dans le constructeur **set_of_pokemon**, il n'y a pas besoin d'instancier **array_of_pokemon** :
              
              set_of_pokemon::set_of_pokemon() {
                array_of_pokemons = {};
              };
  
    car il est déjà initialisé dans le header:

              std::vector<pokemon*> array_of_pokemons;


* Pour la classe **pokedex** :
  * Le design pattern Singleton est correctement implémenté.
  * La classe **pokedex** hérite de la classe **set_of_pokemon** qui possède un attribut :
    
                  std::vector<pokemon*> array_of_pokemons;
    
    La classe **pokedex** n'utilise pas cet attribu hérité et en défini un nouveau :
                  
                  std::vector<pokemon> pokemons_list;
    Peut être qu'il serait intéressant de réutiliser array_of_pokemon.


* Pour la classe **pokemon_team** : 
  * On peut ajouter et supprimmer des pokemons à l'équipe, le nombre de pokemon est bien vérifié.
  * Dans la méthode **remove_pokemon**, il faudrait vérifier que le pokemon à supprimmer fait bien partie de l'équipe avant de le faire.

* Pour la classe **game_engine** :
  * Pour le choix du pokemon starter, lorsqu'on rentre un nombre différent de 1, 2 ou 3 on peut bien resaisir la bonne valeur. Je ne sais pas si c'est important mais peut être qu'il faudrait vérifier qu'on rentre bien un int.
  * Dans la méthode **select_starter_pokemon** les pokemons starters ne sont pas vraiment choisis au hasard comme indiqué dans la méthode.

----------------
## Points positifs
* Le code est très clair seulement en le lisant.
* Le découpage des classes est également pertinent, chaque classe correspond à un objet et les héritages utilisés sont appropriés.
* Les fonctionnalités implémentés fonctionnent normalement.