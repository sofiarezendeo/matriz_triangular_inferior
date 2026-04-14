#include <stdio.h>
#include <stdlib.h>
#include "triangular_inferior.h"

int ti_inicializa(TriangularInferior *m, int n) {
    m->n    = n;
    m->dados = (double *) malloc(n * (n + 1) / 2 * sizeof(double));
    if (m->dados == NULL) {
        printf("Erro: falha de alocacao de memoria\n");
        return 0;
    }
    for (int k = 0; k < n * (n + 1) / 2; k++)
        m->dados[k] = 0.0;
    return 1;
}

void ti_libera(TriangularInferior *m) {
    free(m->dados);
    m->dados = NULL;
    m->n     = 0;
}

void ti_set(TriangularInferior *m, int i, int j, double v) {
    if (j > i) return; 
    int k = i * (i + 1) / 2 + j;
    m->dados[k] = v;
    /* IMPLEMENTE ESTA FUNÇÃO */
}

double ti_get(const TriangularInferior *m, int i, int j) {
    if (j > i) return 0.0; 
    int k = i * (i + 1) / 2 + j;
    return m->dados[k];
    /* IMPLEMENTE ESTA FUNÇÃO */
}

int ti_le(TriangularInferior *m, int n) {
    if (!ti_inicializa(m, n)) return 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++) {
            double v;
            scanf("%lf", &v);
            ti_set(m, i, j, v);
        }
    return 1;
}

void ti_imprime(const TriangularInferior *m) {
    for (int i = 0; i < m->n; i++) {
        for (int j = 0; j < m->n; j++) {
            if (j > 0) printf(" ");
            printf("%.0f", ti_get(m, i, j));
        }
        printf("\n");
    }
}

void ti_imprime_transposta(const TriangularInferior *m) {
    for (int i = 0; i < m->n; i++) {
        for (int j = 0; j < m->n; j++) {
            if (j > 0) printf(" ");
            printf("%.0f", ti_get(m, j, i));
        }
        printf("\n");
    }
    /* IMPLEMENTE ESTA FUNÇÃO */
}
