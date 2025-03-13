#Nome: Cleverson Pereira da Silva - TIA: 32198531
#Nome: Gustavo Teixeira dos Santos - TIA: 32197020


cat(paste("\nExercicio 1\n\n"))
A <- matrix(c(0.65, 0.2, 0.15, 0.6, 0.15, 0.25, 0.5, 0.1, 0.4), nrow=3, byrow=TRUE)
colnames(A) <- c("M1", "M2", "M3")
rownames(A) <- c("M1", "M2", "M3")
cat(paste("---- Matriz Transição -----\n"))
A
cat(paste("----------------------------"))

cat(paste("\nB) Obtenha 𝑷𝟐 𝐞 𝑷𝟑\nP2\n"))
P_2 <- A%*%A
P_3 <- A%*%A%*%A
P_2
cat(paste("\nP3\n"))
P_3
cat(paste("----------------------------\n"))

cat(paste("C)\n"))
PI_ZERO <- matrix(c(1,0,0), nrow=1, byrow=TRUE)
Resultado <- PI_ZERO%*%P_3
rownames(Resultado) <- c("L1")
Resultado
cat(paste("----------------------------\n"))

# EXERCICIO 2

A <- matrix(c(0.3, 0.1, 0.4, 0.2, 0.1, 0.3, 0.4, 0.2, 0.2, 0.1, 0.3, 0.4, 0.3, 0.3, 0.3, 0.1), nrow=4, byrow=TRUE)
cat(paste("\n"))
colnames(A) <- 0:3
rownames(A) <- 0:3

PI_ZERO <- matrix(c(0.2,0.3,0.3,0.2), nrow=1, byrow=TRUE)
colnames(PI_ZERO) <- 0:3
rownames(PI_ZERO) <- 0:0

P_2 <- A%*%A
P_3 <- A%*%A%*%A
P_4 <- A%*%A%*%A%*%A

cat(paste("\nExercicio 2\n\n"))
cat(paste("---- PI ZERO -----\n"))
PI_ZERO
cat(paste("--------------------"))

cat(paste("\n---- Matriz Transição -----\n"))
A
cat(paste("----------------------------"))

#A
cat(paste("\nA)Determine a distribuição de probabilidade de 𝜋(3)\n\n"))
Resultado <- PI_ZERO%*%P_3
rownames(Resultado) <- c("L1")
Resultado

#B
cat(paste("----------------------------"))
cat(paste("\nB)Calcule a matriz de probabilidade de transição de ordem 2, isto é, 𝑃2\n\n"))
P_2
cat(paste("----------------------------"))

#C
cat(paste("----------------------------"))
cat(paste("\nC) Calcule a probabilidade da cadeia estar no estado 3 depois de 4 transições.\n\n"))
Resultado <- PI_ZERO%*%P_4
Resultado[4]
cat(paste("----------------------------"))