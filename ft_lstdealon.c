#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
}
#include "libft.h"
#include <stdio.h>

int main(void)
{
    // Crear algunos nodos de prueba
    char *str1 = (char *)malloc(6 * sizeof(char));
    char *str2 = (char *)malloc(6 * sizeof(char));

    if (!str1 || !str2)
    {
        printf("Error de memoria.\n");
        return 1;
    }

    str1 = "Hola";
    str2 = "Mundo";

    // Crear los nodos
    t_list *node1 = ft_lstnew(str1);
    t_list *node2 = ft_lstnew(str2);

    if (!node1 || !node2)
    {
        printf("Error al crear los nodos.\n");
        return 1;
    }

    // Añadir los nodos a la lista
    ft_lstadd_front(&node1, node2);

    // Eliminar un nodo de la lista
    ft_lstdelone(node2, del_content);  // Eliminar el nodo2
    printf("Nodo 2 eliminado correctamente.\n");

    // Comprobamos que el nodo1 sigue existiendo
    if (node1)
        printf("Nodo 1 sigue existiendo: %s\n", (char *)node1->content);

    // Liberar el nodo1
    ft_lstdelone(node1, del_content);  // Eliminar el nodo1
    printf("Nodo 1 eliminado correctamente.\n");

    return 0;
}
