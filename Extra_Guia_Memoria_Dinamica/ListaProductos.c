#include "ListaProductos.h"
#include <stdio.h>


list* new_List(void)
{

	list* auxList;
	auxList = (list*) malloc(sizeof(list));
	auxList->size = 0;
	auxList->reservedSize = 0;
	auxList->p_elements = NULL;

	auxList->append = append; // referencio a la funcion append
	auxList->get = get; // referencio a la funcion get
	return auxList;

}


void* get(list* p_list,int index)
{
	if (p_list->size > index)
	{
		return p_list->p_elements[index];
	}
	return NULL;
}

void append(list* p_list, void* element)
{
	if (p_list->size == p_list->reservedSize)
	{
		resizeUp(p_list);
	}
	p_list->p_elements[p_list->size] = element;
	p_list->size++;
}

int resizeUp(list *p_list)
{
	/* Redimensionamos el puntero */
	int newSize;

	newSize = sizeof(void*) * (p_list->reservedSize + INCREMENT_SIZE);

	void *tmp_ptr = realloc(p_list->p_elements, newSize);

	if (tmp_ptr == NULL) {
		/* Error: tomar medidas necesarias */
		return 0;
	}
	else {
		/* Reasignación exitosa. Asignar memoria a ptr */
		p_list->reservedSize = p_list->reservedSize + INCREMENT_SIZE;
		p_list->p_elements = tmp_ptr;
		return 1;
	}

}
