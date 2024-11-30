# include<stdlib.h>
int main ( )
{
int return_value ;
// retourne 127 si le shell ne peut pas s ’executer
//retourne 1 en cas d’erreur autrement retoure le code de la commande /
return_value=system (" ls l /" ) ;
return return_value ;
}
