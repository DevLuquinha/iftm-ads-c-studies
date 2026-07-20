# 🎓 Searching and Sorting Algorithms in C - 3rd Semester

> **Course:** Searching and Sorting Algorithms (Pesquisa e Ordenação de Dados)  
> **Program:** Computer Systems Analysis and Development (ADS)  
> **Institution:** Federal Institute of Triângulo Mineiro (IFTM)  
> **Semester:** 3rd Period - 2026/1  
> **Professor:** Guilherme Rodrigues de Melo

This branch contains all implementations, exercises, assignments, and exams developed during the **Searching and Sorting Algorithms** course. The repository is organized to show my learning progression, starting from basic trees and sorting algorithms to advanced multi-way indexing structures like B-Trees, B+ Trees, and B* Trees in C.

---

## 📚 Topics Covered

- ✅ Binary Search Trees (BST) & AVL Trees
- ✅ Balanced Multi-way Indexing Trees (B, B+, B* Trees)
- ✅ Classic Sorting Algorithms
- ✅ Sequential and Binary Search Algorithms
- ✅ Algorithm Complexity Analysis (Big O)
- ✅ Custom Data Structures Integration (Doubly Linked Lists for Tree Nodes)

---

## 📂 Repository Structure

### 01-binary-tree
Introduction to Binary Search Trees (BST) in C:
- Dynamic node allocation and structure creation.
- Recursive key insertion and search.
- Pre-order traversal representation.

### 02-binary-tree-assignment-01
Comprehensive BST implementation containing core utility functions:
- **Tree Height:** Recursive calculation of maximum tree depth.
- **Max Value Finder:** Locating the largest key.
- **Full Tree Checker:** Validating if the tree is completely filled.
- **Node Deletion:** Complete implementation handling deletion of nodes with zero, one, or two children.
- **Traversals:** Pre-order, In-order, and Post-order representations.

### 03-avl-tree & 04-avl-tree-study
Self-balancing AVL tree implementations demonstrating dynamic balancing:
- Balance factor calculation based on sub-tree heights.
- **Single Rotations:** Left Rotation (`rotateLeft`) and Right Rotation (`rotateRight`).
- **Double Rotations:** Left-Right and Right-Left rotations.

### 05-avl-tree-assignment-02
Advanced AVL tree operations and validations:
- **Tree Identity (`isSameTree`):** Verifies if two trees are structurally identical and share the same keys.
- **Strict Tree Verification (`isStrict`):** Verifies if every node has either zero or two children.
- **Minimum Value Search:** Iterative retrieval of the smallest element.

### 06-b-tree-study & 07-b-tree-assignment-05
Implementation of multi-way B-Trees of order $m$ utilizing custom doubly linked lists (`listadupla`) to manage keys inside each node:
- **Immediate Predecessor:** Locating the immediate predecessor (`get_ant_imediato`) of a target value.
- **Element Counter:** Recursive counting of keys in the tree.
- **Tree Height:** Height measurement of the B-Tree structure.
- **Max Finder:** Retrieving the maximum key.

### 08-b+-tree-assignment-06
Implementation of the B+ Tree index structure where keys are duplicated in leaf nodes:
- Search and lookup operations.
- **Occupation Factor (`get_fator_ocupacao`):** Computes tree capacity utilization.
- **Leaf Sum (`get_soma_folhas`):** Traverses the sequentially linked leaves to sum all stored values.

### 09-b-star-tree-assigment-07
Practical implementation of a B* Tree of order $m$:
- Order $m$ insertion logic.
- **Visual Display (`imprime_arvore_visual`):** Hierarchical visual printing of B* tree nodes by level on the terminal.

### 10-b-plus-exam
Practical examination demonstrating mastery of B+ Trees:
- Key summation across the entire tree (`somaChaves`).
- **Range Queries (`exibirValores`):** Searches for a starting value and returns a sequential range of keys directly from the linked leaf nodes.

### 11-sorting-algorithms
Collection of classic sorting algorithms implemented in C:
- **Bubble Sort:** Basic O(N²) comparison-based sort.
- **Insertion Sort:** Efficient O(N²) online sorting for small lists.
- **Selection Sort:** O(N²) selection-based sorting.
- **Quick Sort:** High-performance O(N log N) divide-and-conquer sorting with dual-index partitioning.

### 12-searching-algorithms
Search algorithms optimized for linear sequences:
- **Linear Search:** Simple sequential search.
- **Sentinel Search:** Optimized linear search that sets a sentinel value at the end of the array to eliminate boundary checks.
- **Binary Search:** O(log N) search on sorted arrays.

---

## 📊 Learning Statistics

| Category | Count | Complexity |
|----------|-------|------------|
| **Tree Structures (BST, AVL)** | 5 | ⭐⭐⭐ Advanced |
| **Multi-way Trees (B, B+, B*)** | 5 | ⭐⭐⭐⭐ Expert |
| **Sorting Algorithms** | 4 | ⭐⭐ Intermediate |
| **Searching Algorithms** | 3 | ⭐ Basic |
| **Practical Assignments** | 5 | ⭐⭐⭐⭐ Expert |
| **Exams** | 1 | ⭐⭐⭐⭐ Expert |
| **Total Implementations** | **17+** | |

---

## 🛠️ Technical Skills Developed

### Data Structures & Indexing
- ✅ Dynamic memory management and allocation (`malloc`, `free`).
- ✅ Implementation of self-balancing algorithms (AVL Rotations).
- ✅ Design of index-optimized disk structures (B-Tree variants).
- ✅ Custom integration of helper structures (linked lists nested within tree nodes).

### Algorithm Design & Optimization
- ✅ Time complexity awareness (Big O notation).
- ✅ Array manipulation and sorting techniques.
- ✅ Sentinel-based search optimization.
- ✅ Hierarchical rendering of data structures in the console.

---

## 💻 Development Environment

- **Language:** C (C11 standard)
- **IDE:** Code::Blocks / Visual Studio Code
- **Compiler:** GCC (GNU Compiler Collection)
- **OS:** Windows / Linux
- **Version Control:** Git

---

## 📚 Key Takeaways

1. **Self-Balancing Logic:** Understanding rotations in AVL trees showed me how to maintain O(log N) operations even in worst-case insertion scenarios.
2. **Database Indexing Foundations:** Implementing B, B+, and B* Trees from scratch made me appreciate how relational databases manage disk I/O and large datasets.
3. **Optimizing Searches:** Sentinel search demonstrated how minor code details (like reducing branch conditions) can optimize CPU cycles.
4. **Dividing to Conquer:** Implementing Quick Sort reinforced the power of recursive partitioning for sorting large datasets.

---

## 📫 Contact

**GitHub:** [@DevLuquinha](https://github.com/DevLuquinha)

---

<details>
  <summary>🇧🇷 Versão em Português</summary>

# 🎓 Algoritmos de Pesquisa e Ordenação em C - 3º Período

> **Disciplina:** Pesquisa e Ordenação de Dados  
> **Curso:** Análise e Desenvolvimento de Sistemas (ADS)  
> **Instituição:** Instituto Federal do Triângulo Mineiro (IFTM)  
> **Período:** 3º Período - 2026/1  
> **Professor:** Guilherme Rodrigues de Melo

Esta branch contém todas as implementações, exercícios, trabalhos e provas desenvolvidos durante a disciplina de **Pesquisa e Ordenação de Dados**. O repositório está organizado para demonstrar a minha progressão de aprendizado, partindo de estruturas de árvores básicas e algoritmos de ordenação até estruturas avançadas de indexação como Árvores B, B+ e B* em C.

---

## 📚 Tópicos Abordados

- ✅ Árvores Binárias de Busca (ABB) & Árvores AVL
- ✅ Árvores de Indexação Balanceadas (Árvores B, B+ e B*)
- ✅ Algoritmos Clássicos de Ordenação
- ✅ Algoritmos de Pesquisa Sequencial e Binária
- ✅ Análise de Complexidade de Algoritmos (Notação Big O)
- ✅ Integração de Estruturas Customizadas (Listas Duplamente Encadeadas para Nós de Árvore)

---

## 📂 Estrutura do Repositório

### 01-binary-tree
Introdução às Árvores Binárias de Busca (ABB) em C:
- Alocação dinâmica de nós e criação de estruturas.
- Inserção e busca recursiva de chaves.
- Representação por percurso em Pré-Ordem.

### 02-binary-tree-assignment-01
Implementação abrangente de ABB contendo funções de utilidade essenciais:
- **Altura da Árvore:** Cálculo recursivo da profundidade máxima.
- **Maior Valor:** Busca pelo nó com a maior chave.
- **Árvore Cheia:** Validação se a árvore está completamente cheia.
- **Remoção de Nós:** Implementação completa tratando remoção de nós com zero, um ou dois filhos.
- **Percursos:** Representações em Pré-Ordem, Em-Ordem e Pós-Ordem.

### 03-avl-tree & 04-avl-tree-study
Implementações de Árvores AVL demonstrando balanceamento dinâmico:
- Cálculo do fator de balanceamento baseado na altura das subárvores.
- **Rotações Simples:** Rotação à Esquerda (`rotateLeft`) e Rotação à Direita (`rotateRight`).
- **Rotações Duplas:** Rotações Esquerda-Direita e Direita-Esquerda.

### 05-avl-tree-assignment-02
Operações avançadas e validações em Árvores AVL:
- **Identidade de Árvores (`isSameTree`):** Verifica se duas árvores são estruturalmente idênticas e possuem as mesmas chaves.
- **Verificação de Árvore Estrita (`isStrict`):** Verifica se cada nó possui zero ou dois filhos.
- **Busca de Menor Valor:** Busca iterativa do menor elemento.

### 06-b-tree-study & 07-b-tree-assignment-05
Implementação de Árvores B multi-vias de ordem $m$ utilizando listas duplamente encadeadas (`listadupla`) para gerenciar as chaves internas de cada nó:
- **Antecessor Imediato:** Localização do antecessor imediato (`get_ant_imediato`) de um valor alvo.
- **Contador de Elementos:** Contagem recursiva de chaves na árvore.
- **Altura da Árvore:** Medição da altura da estrutura da Árvore B.
- **Maior Elemento:** Recuperação da maior chave.

### 08-b+-tree-assignment-06
Implementação da estrutura de índice de Árvore B+ onde as chaves são duplicadas nas folhas:
- Operações de busca e localização.
- **Fator de Ocupação (`get_fator_ocupacao`):** Computa a utilização da capacidade total da árvore.
- **Soma das Folhas (`get_soma_folhas`):** Percorre as folhas sequencialmente encadeadas para somar todos os valores armazenados.

### 09-b-star-tree-assigment-07
Implementação prática de uma Árvore B* de ordem $m$:
- Lógica de inserção de ordem $m$.
- **Exibição Visual (`imprime_arvore_visual`):** Impressão visual hierárquica por níveis dos nós da árvore B* no terminal.

### 10-b-plus-exam
Prova prática demonstrando o domínio de Árvores B+:
- Soma de chaves em toda a árvore (`somaChaves`).
- **Consultas por Intervalo (`exibirValores`):** Busca por um valor inicial e retorna um intervalo sequencial de chaves diretamente a partir das folhas encadeadas.

### 11-sorting-algorithms
Coleção de algoritmos clássicos de ordenação implementados em C:
- **Bubble Sort:** Ordenação básica por comparação de complexidade O(N²).
- **Insertion Sort:** Ordenação eficiente por inserção de complexidade O(N²) para pequenos conjuntos de dados.
- **Selection Sort:** Ordenação O(N²) baseada em seleção do menor elemento.
- **Quick Sort:** Ordenação O(N log N) de alta performance utilizando divisão e conquista com partição de índice duplo.

### 12-searching-algorithms
Algoritmos de busca otimizados para sequências lineares:
- **Linear Search:** Busca sequencial simples.
- **Sentinel Search:** Busca sequencial otimizada com inserção de sentinela no fim do vetor para eliminar checagens de limite.
- **Binary Search:** Busca binária O(log N) em vetores ordenados.

---

## 📊 Estatísticas de Aprendizagem

| Categoria | Quantidade | Complexidade |
|----------|-----------|--------------|
| **Estruturas de Árvores (ABB, AVL)** | 5 | ⭐⭐⭐ Avançado |
| **Árvores Multi-vias (B, B+, B*)** | 5 | ⭐⭐⭐⭐ Especialista |
| **Algoritmos de Ordenação** | 4 | ⭐⭐ Intermediário |
| **Algoritmos de Busca** | 3 | ⭐ Básico |
| **Trabalhos Práticos** | 5 | ⭐⭐⭐⭐ Especialista |
| **Provas** | 1 | ⭐⭐⭐⭐ Especialista |
| **Total de Implementações** | **17+** | |

---

## 🛠️ Habilidades Técnicas Desenvolvidas

### Estruturas de Dados & Indexação
- ✅ Gerenciamento e alocação dinâmica de memória (`malloc`, `free`).
- ✅ Implementação de algoritmos de balanceamento dinâmico (Rotações AVL).
- ✅ Design de estruturas de índice otimizadas para disco (variantes de Árvores B).
- ✅ Integração personalizada de estruturas auxiliares (listas encadeadas aninhadas em nós de árvore).

### Design & Otimização de Algoritmos
- ✅ Consciência de complexidade de tempo (notação Big O).
- ✅ Técnicas de ordenação e manipulação de vetores.
- ✅ Otimização de buscas utilizando sentinelas.
- ✅ Renderização hierárquica de estruturas de dados no console.

---

## 💻 Ambiente de Desenvolvimento

- **Linguagem:** C (padrão C11)
- **IDE:** Code::Blocks / Visual Studio Code
- **Compilador:** GCC (GNU Compiler Collection)
- **SO:** Windows / Linux
- **Controle de Versão:** Git

---

## 📚 Principais Aprendizados

1. **Lógica de Autobalanceamento:** Compreender rotações em árvores AVL me ensinou como garantir operações O(log N) mesmo em cenários desfavoráveis de inserção.
2. **Fundamentos de Indexação de Banco de Dados:** Implementar Árvores B, B+ e B* do zero me fez valorizar como os bancos de dados relacionais gerenciam E/S de disco e grandes volumes de dados.
3. **Otimização de Pesquisas:** A busca com sentinela demonstrou como detalhes simples no código (como reduzir checagens condicionais) podem otimizar ciclos de CPU.
4. **Dividir para Conquistar:** A implementação do Quick Sort reforçou o poder da partição recursiva para ordenação de grandes volumes de dados.

---

## 📫 Contato

**GitHub:** [@DevLuquinha](https://github.com/DevLuquinha)
</details>