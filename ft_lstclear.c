void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!lst || !*lst || !del)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
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

    // Imprimir los contenidos de los nodos antes de eliminar
    printf("Lista antes de eliminar los nodos:\n");
    t_list *tmp = node1;
    while (tmp)
    {
        printf("%s\n", (char *)tmp->content);
        tmp = tmp->next;
    }

    // Eliminar todos los nodos de la lista
    ft_lstclear(&node1, del_content);

    // Imprimir un mensaje para confirmar que la lista está vacía
    if (!node1)
        printf("Lista eliminada correctamente.\n");
    else
        printf("Error: La lista no se ha vaciado correctamente.\n");

    return 0;
}
