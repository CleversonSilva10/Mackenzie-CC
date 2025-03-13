cat(paste("\nNome: Cleverson Pereira da Silva - TIA: 32198531\n"))

# EXERCICIO 1
cat(paste("\nExercicio 1\n"))
cat(paste("\nA) B-A\n\n"))
A <- matrix(c(1,-2,3,0),nrow = 2, byrow = TRUE)
B <- matrix(c(2,1,-1,4),nrow = 2, byrow = TRUE)
C <- B-A
C

cat(paste("\n\nB) A+2B \n"))
A <- matrix(c(1,-2,3,0),nrow = 2, byrow = TRUE)
B <- matrix(c(2,1,-1,4),nrow = 2, byrow = TRUE)
C <- A+2*B
C

cat(paste("\n\nC) D*E \n"))
D <- matrix(c(-1,0,2),nrow = 1, byrow = TRUE)
E <- matrix(c(3,1,2),nrow = 3, ncol = 1)
C <- D%*%E
C
#---------------------------------------------------

# EXERCICIO 2
cat(paste("\nExercicio 2\n"))
cat(paste("\nA) C = A–B \n"))
A <- matrix(c(0.5,2,3,0,-1,5),nrow = 2, ncol = 3)
B <- matrix(c(-3/2,0,4,2,6,3),nrow = 2, ncol = 3)
C <- A-B
C
#---------------------------------------------------

# EXERCICIO 3
cat(paste("\nExercicio 3\n"))
cat(paste("\nA) C = 2A + BT\n"))
A <- matrix(c(1,-2,3,0),nrow = 2, ncol = 2)
B <- matrix(c(2,1,-1,4),nrow = 2, ncol = 2)
C <- 2*A + t(B)
C
#---------------------------------------------------

# EXERCICIO 4
cat(paste("\nExercicio 4\n"))
cat(paste("\nA) C = AX\n"))
A <- matrix(c(2,1,4,5,-3,2,-1,6,3),nrow = 3, ncol = 3)
B <- matrix(c(7,8,9),nrow = 3, ncol = 1)
C <- A%*%B
C
#---------------------------------------------------

# EXERCICIO 5
cat(paste("\nExercicio 5\n"))
cat(paste("\nA) Calcule A + B\n"))
A <- matrix(c(1, 0, 2, -1, 2, 5, 2, 1, 4), nrow=3, byrow=TRUE)
B <- matrix(c(2, 1, 4, -1, -1, -1, 5, 3, 2), nrow=3, byrow=TRUE)
C <- A+B
C

cat(paste("\nB) Calcule A–B\n"))
A <- matrix(c(1, 0, 2, -1, 2, 5, 2, 1, 4), nrow=3, byrow=TRUE)
B <- matrix(c(2, 1, 4, -1, -1, -1, 5, 3, 2), nrow=3, byrow=TRUE)
C <- A-B
C

cat(paste("\nC)Matriz transposta da matriz A\n"))
A <- matrix(c(1, 0, 2, -1, 2, 5, 2, 1, 4), nrow=3, byrow=TRUE)
C <- t(A)
C

cat(paste("\nD) Obtenha a matriz inversa da matriz A;\n"))
A <- matrix(c(1, 0, 2, -1, 2, 5, 2, 1, 4), nrow=3, byrow=TRUE)
C <- solve(A)
C

cat(paste("\nE)Calcule P = AB\n"))
A <- matrix(c(1, 0, 2, -1, 2, 5, 2, 1, 4), nrow=3, byrow=TRUE)
B <- matrix(c(2, 1, 4, -1, -1, -1, 5, 3, 2), nrow=3, byrow=TRUE)
P <- A%*%B
P

cat(paste("\nF)Renomear as colunas\n"))
colnames(P) <- c("A", "B", "C")
rownames(P) <- c("L1", "L2", "L3")
P

cat(paste("\nG)Obtenha o elemento P(L3, b)\n"))
P["L3", "B"]


