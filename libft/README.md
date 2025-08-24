# Libftv2
La Libftv2 est la lib que j'utilise réelement pour mon cursus, celle-ci contient en plus les projets du premier cercle à savoir `ft_printf` et `get_next_line` mais également diverse fonctions que j'ai codé en plus. 

## FONCTIONS DE BASE

#### Fonction `isalpha`
- `int isalpha(int c);` : Vérifie si le caractère `c` est une lettre alphabétique.

#### Fonction `isdigit`
- `int isdigit(int c);` : Vérifie si le caractère `c` est un chiffre décimal.

#### Fonction `isalnum`
- `int isalnum(int c);` : Vérifie si le caractère `c` est une lettre alphabétique ou un chiffre décimal.

#### Fonction `isascii`
- `int isascii(int c);` : Vérifie si le caractère `c` est un caractère ASCII (0-127).

#### Fonction `isprint`
- `int isprint(int c);` : Vérifie si le caractère `c` est imprimable (un caractère visible).

#### Fonction `strlen`
- `size_t strlen(const char *s);` : Calcule la longueur de la chaîne de caractères `s`.

#### Fonction `memset`
- `void *memset(void *s, int c, size_t n);` : Remplit les `n` premiers octets de la mémoire pointée par `s` avec la valeur `c`.

#### Fonction `bzero`
- Cette fonction est obsolète. Il est recommandé d'utiliser `memset` pour effacer une zone de mémoire.

#### Fonction `memcpy`
- `void *memcpy(void *dest, const void *src, size_t n);` : Copie `n` octets depuis la mémoire source `src` vers la mémoire de destination `dest`.

#### Fonction `memmove`
- `void *memmove(void *dest, const void *src, size_t n);` : Copie `n` octets depuis la mémoire source `src` vers la mémoire de destination `dest`, même si les zones se chevauchent.

#### Fonction `strlcpy`
- `size_t strlcpy(char *dest, const char *src, size_t size);` : Copie jusqu'à `size` caractères depuis la chaîne source `src` vers la chaîne de destination `dest`, en garantissant la null-termination.

#### Fonction `strlcat`
- `size_t strlcat(char *dest, const char *src, size_t size);` : Concatène jusqu'à `size` caractères depuis la chaîne source `src` à la chaîne de destination `dest`, en garantissant la null-termination.

#### Fonction `toupper`
- `int toupper(int c);` : Convertit le caractère `c` en majuscule s'il est une lettre minuscule.

#### Fonction `tolower`
- `int tolower(int c);` : Convertit le caractère `c` en minuscule s'il est une lettre majuscule.

#### Fonction `strchr`
- `char *strchr(const char *s, int c);` : Recherche la première occurrence du caractère `c` dans la chaîne `s` et renvoie un pointeur vers cette occurrence.

#### Fonction `strrchr`
- `char *strrchr(const char *s, int c);` : Recherche la dernière occurrence du caractère `c` dans la chaîne `s` et renvoie un pointeur vers cette occurrence.

#### Fonction `strncmp`
- `int strncmp(const char *s1, const char *s2, size_t n);` : Compare les `n` premiers caractères des chaînes `s1` et `s2` et renvoie un entier indiquant leur relation (plus petit, égal, ou plus grand).

#### Fonction `memchr`
- `void *memchr(const void *s, int c, size_t n);` : Recherche la première occurrence du caractère `c` dans les `n` premiers octets de la mémoire pointée par `s` et renvoie un pointeur vers cette occurrence.

#### Fonction `memcmp`
- `int memcmp(const void *s1, const void *s2, size_t n);` : Compare les `n` premiers octets des zones de mémoire pointées par `s1` et `s2` et renvoie un entier indiquant leur relation (plus petit, égal, ou plus grand).

#### Fonction `strnstr`
- `char *strnstr(const char *haystack, char *needle, size_t len);` : Recherche la première occurrence de la sous-chaîne `needle` dans la chaîne `haystack`, mais au maximum dans les `len` premiers caractères de `haystack`.

#### Fonction `atoi`
- `int atoi(const char *str);` : Convertit la chaîne de caractères `str` en un entier.

#### Fonction `calloc`
- `void *calloc(size_t nmemb, size_t size);` : Alloue de la mémoire pour un tableau de `nmemb` éléments, chacun de `size` octets, et les initialise à zéro.

#### Fonction `strdup`
- `char *strdup(const char *s);` : Duplique la chaîne de caractères `s` en allouant de la mémoire pour une nouvelle chaîne et la copiant.

---
---
---

## FONCTIONS SUPPLÉMENTAIRES

#### Fonction `ft_substr`
- `char *ft_substr(char const *s, unsigned int start, size_t len);` : Alloue et retourne une nouvelle chaîne de caractères qui est une sous-chaîne de `s`, commençant à l'index `start` et ayant une longueur maximale de `len`.

#### Fonction `ft_strjoin`
- `char *ft_strjoin(char const *s1, char const *s2);` : Alloue et retourne une nouvelle chaîne de caractères résultant de la concaténation des chaînes `s1` et `s2`.

#### Fonction `ft_strtrim`
- `char *ft_strtrim(char const *s1, char const *set);` : Alloue et retourne une nouvelle chaîne de caractères après avoir retiré les caractères présents dans `set` en début et en fin de la chaîne `s1`.

#### Fonction `ft_split`
- `char **ft_split(char const *s, char c);` : Alloue et retourne un tableau de chaînes de caractères résultant de la découpe de la chaîne `s` en fonction du caractère `c`.

#### Fonction `ft_itoa`
- `char *ft_itoa(int n);` : Alloue et retourne une nouvelle chaîne de caractères représentant l'entier `n`.

#### Fonction `ft_strmapi`
- `char *ft_strmapi(char const *s, char (*f)(unsigned int, char));` : Applique la fonction `f` à chaque caractère de la chaîne `s` en utilisant son index et retourne une nouvelle chaîne de caractères.

#### Fonction `ft_putchar_fd`
- `void ft_putchar_fd(char c, int fd);` : Écrit le caractère `c` dans le descripteur de fichier `fd`.

#### Fonction `ft_putstr_fd`
- `void ft_putstr_fd(char *s, int fd);` : Écrit la chaîne de caractères `s` dans le descripteur de fichier `fd`.

#### Fonction `ft_putendl_fd`
- `void ft_putendl_fd(char *s, int fd);` : Écrit la chaîne de caractères `s` suivie d'un saut de ligne dans le descripteur de fichier `fd`.

#### Fonction `ft_putnbr_fd`
- `void ft_putnbr_fd(int n, int fd);` : Écrit l'entier `n` suivi d'un saut de ligne dans le descripteur de fichier `fd`.

---
---
---

## FONCTIONS BONUS

#### Fonction `ft_lstnew`
- `t_list *ft_lstnew(void *content);` : Alloue et retourne un nouvel élément de liste initialisé avec le contenu `content`.

#### Fonction `ft_lstadd_front`
- `void ft_lstadd_front(t_list **lst, t_list *new);` : Ajoute l'élément `new` au début de la liste `lst`.

#### Fonction `ft_lstsize`
- `int ft_lstsize(t_list *lst);` : Compte le nombre d'éléments dans la liste `lst`.

#### Fonction `ft_lstlast`
- `t_list *ft_lstlast(t_list *lst);` : Retourne le dernier élément de la liste `lst`.

#### Fonction `ft_lstadd_back`
- `void ft_lstadd_back(t_list **lst, t_list *new);` : Ajoute l'élément `new` à la fin de la liste `lst`.

#### Fonction `ft_lstdelone`
- `void ft_lstdelone(t_list *lst, void (*del)(void*));` : Supprime l'élément `lst` en utilisant la fonction `del` pour libérer le contenu.

#### Fonction `ft_lstclear`
- `void ft_lstclear(t_list **lst, void (*del)(void*));` : Supprime et libère la mémoire de tous les éléments de la liste `lst`, en utilisant la fonction `del` pour libérer le contenu.

#### Fonction `ft_lstiter`
- `void ft_lstiter(t_list *lst, void (*f)(void*));` : Applique la fonction `f` à chaque élément de la liste `lst`.

#### Fonction `ft_lstmap`
- `t_list *ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*));` : Applique la fonction `f` à chaque élément de la liste `lst` pour créer une nouvelle liste, en utilisant la fonction `del` pour libérer le contenu en cas d'erreur.

