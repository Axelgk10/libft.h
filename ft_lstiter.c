void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		f(tmp->content);
		tmp = tmp->next;
	}
}
#include "libft.h"
#include <stdio.h>

int main(void)
{
    // Crear algunos nodos de prueba
    char *str1 = (char *)malloc(6 * sizeof(char));
    char *str2 = (char *)malloc(6 * sizeof(char));
    char *str3 = (char *)malloc(6 * sizeof(char));

    if (!str1 || !str2 || !str3)
    {
        printf("Error de memoria.\n");
        return 1;
    }

    // Asignar valores a las cadenas
    str1 = "Hola";
    str2 = "Mundo";
    str3 = "Adiós";

    // Crear los nodos
    t_list *node1 = ft_lstnew(str1);
    t_list *node2 = ft_lstnew(str2);
    t_list *node3 = ft_lstnew(str3);

    if (!node1 || !node2 || !node3)
    {
        printf("Error al crear los nodos.\n");
        return 1;
    }

    // Añadir los nodos a la lista
    ft_lstadd_front(&node1, node2);
    ft_lstadd_front(&node1, node3);

    // Aplicar ft_lstiter para imprimir el contenido de todos los nodos
    printf("Contenido de la lista:\n");
    ft_lstiter(node1, print_content);  // Imprime todos los contenidos de la lista

    // Limpiar la lista después de usarla
    ft_lstclear(&node1, del_content);
    printf("Lista eliminada correctamente.\n");

    return 0;
}
