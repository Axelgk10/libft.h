#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*i;

	i = malloc(sizeof(t_list));
	if (!i)
	{
		return (NULL);
	}
	i->content = content;
	i->next = NULL;
	return (i);
}
#include "libft.h"
#include <stdio.h> // Para printf

int main()
{
    t_list *new_node;
    char *str = "Contenido del nodo";

    // Creamos un nuevo nodo con contenido
    new_node = ft_lstnew((void *)str);

    // Verificamos si el nodo se creó correctamente
    if (new_node)
    {
        printf("Nodo creado con contenido: %s\n", (char *)new_node->content);
        printf("Siguiente nodo: %p\n", new_node->next); // Debería ser NULL
    }
    else
    {
        printf("Error al crear el nodo.\n");
    }

    // Liberamos la memoria asignada para el nodo
    free(new_node);

    return 0;
}
