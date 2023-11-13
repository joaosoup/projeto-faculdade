#ifndef GERENCIAMENTO_OBRAS_H
#define GERENCIAMENTO_OBRAS_H

#include "obras.h"

#define MAX_OBRAS 10

void incluirObra(struct Obra obras[], int *numObras);
void alterarObra(struct Obra obras[], int numObras);
void consultarObra(struct Obra obras[], int numObras);
void excluirObra(struct Obra obras[], int *numObras);

#endif
