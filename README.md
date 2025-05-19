# Maquina-de-Turing
 
 ## Esse algoritmo é capaz de fazer reconhecer uma especificação de uma Máquina de Turing e verificar geração de palavras.

 Este repositório contém um algoritmo que simula uma Máquina de Turing. O algoritmo foi todo implementado em C. A máquina é baseada em estrutura, porém as transições foram implementadas com estrutura de lista encadeada. O repositório ainda contém três arquivos de teste.
 
 ### O formato da especificação deve ser feita da seguinte forma:
 
 - 1ª linha: Q=ɑ -> Q representa numeros de estados.
 - 2ª linha: F={qɣ,qθ,...,qm} -> F representa estados finais.
 - 3ª linha: alfabeto={a,b,...,z} -> alfabeto que pode ser lido pela maquina (em minúsculo).
 - 4ª linha: (qɑ, x)=(qβ,X,E/D) -> especificação das transições, onde:
     - qɑ -> estado atual.
     - x -> símbolo lido.
     - qβ -> próximo estado.
     - X -> símbolo a ser escrito.
     - E/D -> movimento na fita (esquerda ou direita).
  
      ### **Exemplo de especificação:**
   
           Q=5
           F={q4}
           alfabeto={a,b,X,Y}
           (q0,a)=(q1,X,D)
           (q0,Y)=(q2,Y,D)
           (q1,a)=(q1,a,D)
           (q1,Y)=(q1,Y,D)
           (q1,b)=(q3,Y,E)
           (q3,a)=(q3,a,E)
           (q3,Y)=(q3,Y,E)
           (q3,X)=(q0,X,D)
           (q2,Y)=(q2,Y,D)
           (q2,b)=(q4,Y,D)
           (q2,$)=(q4,$,E)
