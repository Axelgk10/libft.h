#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_obj;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_obj = ft_lstnew(f(lst->content));
		if (!new_obj)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_obj);
		lst = lst->next;
	}
	return (new_list);
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
    str1 = "hola";
    str2 = "mundo";
    str3 = "adios";

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
    ft_lstadd_back(&node1, node2);
    ft_lstadd_back(&node1, node3);

    // Imprimir los contenidos de la lista original
    printf("Lista original:\n");
    ft_lstiter(node1, print_content);  //
