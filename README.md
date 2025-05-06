# Maquina-de-Turing
 
 ## Esse algoritmo é capaz de fazer reconhecer uma especificação de uma Máquina de Turing e verificar geração de palavras.
 
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
