## Questão 1

Suponha que temos dois algoritmos $T_1$ e $T_2$ para resolver um determinado problema,
com os seguintes tempos de execução:

* $T_1(n) = 625n$;
* $T_2(n) = n^2$.

Responda:
1. Qual é a complexidade assintótica de cada algoritmo?
2. Para quais valores de $n$ o algoritmo $T_1$​ é mais eficiente que o $T_2$​, e para quais valores$ $T_2$​ se torna mais eficiente que $T_1$​?

## Questão 2
O custo computacional $T_i(n)$ de diversos algoritmos é mostrado abaixo.\
Qual a complexidade de cada algoritmo? Ponha-os em ordem crescente de complexidade.
* $T_1(n)    = nlog(n)+log(n)$;
* $T_2(n)    = 2n + n^3 + 25$;
* $T_3(n,k)  = n+k$ onde $k \le n$
* $T_4(n)    = n + log(n)$;
* $T_5(n)    = 100n log(n) + n^3 + 100n$;
* $T_6(n)    = 0.01n log(n) + n (log(n))^2$;
* $T_7(n)    = 2n + n^{0.5} + 0.5n^{1.25}$;
* $T_8(n)    = 0.01n + 100n^2$;
* $T_9(n)    = 100n + 0.01n^2$;
* $T_{10}(n) = T(n) = 2T(n-1)+2$ para $n > 1$ e $T(1)=O(1)$; **Dica**: `método da árvore de recursão`

## Questão 3

Calcule a complexidade dos algoritmos abaixo:

1. Loops em sequência
    ```c
    int a = 0, b = 0;
    for (i = 0; i < n; i++) {
        a = a + i;
    }
    for (j = 0; j < m; j++) {
        b = b + j;
    }
    ```

2. Loop com condicionais
    ```c
    float what2(int *arr, int n) {
        int a = 0;
        for (int i = 0; i < n; i++) {
            if(arr[i] > 10) {
                for (int j = 0; j < n; j++) {
                    a += n / 2;
                }
            } else {
                printf("ok :(")
            }
        }
    }
    ```

3. Loops duplo
    ```c
    int a = 0;
    for (int i = 0; i < n; i++) {
        for (int j = n; j > i; j--) {
            a += i + j;
        }
    }
    ```

4. Loops duplo com constantes
    ```c
    float what4(int *arr, int n) {
        int a = 0;
        for (int i = 0; i < 1000; i++) {
            for (int j = 0; j < 5000; j++) {
                a += i + j;
            }
        }
    }
    ```

5. Loops com crescimento em progressão geométrica
    ```c
    int a = 0;
    for (int i = n/2; i <= n; i++) {
        for (int j = 2; j <= n; j = j * 2) {
            a += i + j;
        }
    }
    ```

6. Loop com crescimento logarítmico
    ```c
    int a = 0, i = n;
    while (i > 0) {
        a += i;
        i /= 2;
    }
    ```

7. Loop duplo com redução logarítmica
    ```c
    int a = 0, i = n;
    while (i > 0) {
        for (int j = 0; j < i; j++) {
            a += i;
        }
        i /= 2;
    }
    ```

7. Soma dos elementos de um vetor
    ```c
    float soma(float *arr, int n) {
    	float total = 0;
    	for (int i = 0; i < n; i++) {
    		total += arr[i];
        }
    	return total;
    }
    ```

8. Busca sequencial
    ```c
    int buscaSequencial(int *arr, int n, int x) {
    	for (int i = 0; i < n; i++){
    		if (arr[i] == x) {
    			return i;
            }
    	}
    	return -1;
    }
    ```

9. Busca binária
    ```c
    int buscaBinaria(int *arr, int x, int i, int j) {
        if (i >= j) {
            return ‐1;
        }

    	int m = (i + j) / 2;
    	if (arr[m] == x) {
            return m;
        } else if ( x < arr[m] ) {
            return buscaBinaria (arr, x, i, m‐1);
        } else {
    		return buscaBinaria (arr, x, m+1, j);
        }
    }
    ```

10. Multiplicação de matrizes
    ```c
    void multiplicacaiMatriz(float **a, float **b, int n, int p, int m, float **x) {
    	for (int i = 0; i < n; i++) {
    		for (int j = 0; j < m; j++) {
    			x[i][j] = 0.0;
    			for (int k = 0; k < p; k++) {
                    x[i][j] += a[i][k] * b[k][j];
                }
    		}
    	}
    }
    ```

## Questão 4 (Extra)

Dada uma lista de números inteiros, queremos encontrar a subsequência contígua de soma máxima.
Ou seja, dado um array de inteiros $A = [a_1, a_2, ..., a_n]$, encontre os índices $i$ e $j$ tal que a soma $a_i+a_{i+1}+...+a_j$​ seja máxima.
Exemplo:

Para a sequência:
$$A=[−2,1,−3,4,−1,2,1,−5,4]$$

A subsequência contígua de soma máxima é $4,−1,2,1$ com soma $6$, e está nos índices $3$ a $6$ (indexação começando em 0).
Itens:
1. Proponha um algoritmo que resolva o problema com complexidade $O(n^3)$.
2. Proponha um algoritmo que resolva o problema com complexidade $O(n^2)$.
3. Existe um algoritmo mais eficiente que $O(n^2)$? Se sim, implemente-o e justifique sua complexidade. Se não, justifique por que não é possível obter uma solução mais eficiente.