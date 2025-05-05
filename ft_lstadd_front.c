// En libft.c
#include "libft.h"

void ft_lstadd_front(t_list **lst, t_list *new)
{
    if (new != NULL)
    {
        new->next = *lst;  // Apuntamos el siguiente del nuevo nodo al nodo que estaba al frente
        *lst = new;        // Hacemos que el puntero de la lista apunte al nuevo nodo
    }
}
#include "libft.h"
#include <stdio.h>

int main()
{
    t_list *head = NULL;  // La lista empieza vacía
    t_list *new_node1;
    t_list *new_node2;
    t_list *new_node3;
    
    // Creamos 3 nodos con diferentes contenidos
    new_node1 = ft_lstnew("Primer Nodo");
    new_node2 = ft_lstnew("Segundo Nodo");
    new_node3 = ft_lstnew("Tercer Nodo");
    
    // Agregamos los nodos al principio de la lista
    ft_lstadd_front(&head, new_node1); // "Primer Nodo"
    ft_lstadd_front(&head, new_node2); // "Segundo Nodo"
    ft_lstadd_front(&head, new_node3); // "Tercer Nodo"

    // Imprimimos la lista para verificar el orden
    t_list *current = head;
    while (current != NULL)
    {
        printf("Contenido: %s\n", (char *)current->content);
        current = current->next;
    }

    // Liberamos la memoria de la lista
    current = head;
    while (current != NULL)
    {
        t_list *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
