cat("\nNome: Cleverson Pereira da Silva - TIA: 32198531\n")


cat("\nExercicio 1 - Binomial\n")
n <- 15
p <- 0.4

# A --------------------------------------
resultado <- sum(dbinom(10:n, n, p))
cat(paste("a) P(X≥10) =", resultado, "\n"))
#-----------------------------------------

# B --------------------------------------
resultado <- pbinom(10, n, p) - pbinom(8, n, p)
cat(paste("b) P(8<X≤10) =", resultado, "\n"))
#-----------------------------------------

# C --------------------------------------
prob_A <- pbinom(2,n,p)
prob_B <- sum(dbinom(11:n, n, p))
resultado <- prob_A+prob_B
cat(paste("c) P(X<2 ou X≥11) =", resultado, "\n"))
# --------------------------------------

# D --------------------------------------
resultado <- sum(dbinom(11:n,n,p))+sum(dbinom(14:n,n,p))
cat(paste("d) P(X≥11ouX>13) =", resultado))
# --------------------------------------

# E --------------------------------------
resultado <- sum(dbinom(4:5, n, p))
cat(paste("\ne) P(X>3 e X<6) =", resultado))
# --------------------------------------

# F --------------------------------------
resultado <-  qbinom(0.25, 15, 0.4)
cat(paste("\nf) Primeiro Quartil =", resultado, "\n\n"))

cat("Exercicio 2 - Distribuição Poisson")

# A --------------------------------------
resultado <-  1-ppois(0, 1)
cat(paste("\na) P(X≥1) =", resultado))
# --------------------------------------

# B --------------------------------------
resultado <- sum(dpois(0:2,1))
cat(paste("\nb) P(X≤2) =", resultado))
# --------------------------------------

# C --------------------------------------
resultado <- sum(dpois(2:4,1))
cat(paste("\nc) P(2≤X≤4) =", resultado))
# --------------------------------------

# d --------------------------------------
resultado <- sum(dpois(0:1,1))
cat(paste("\nd) P(X<1) =", resultado))
# --------------------------------------

# E --------------------------------------
resultado <- qpois(0.75, 1)
cat(paste("\ne) Obter o terceiro quartil =", resultado))
# --------------------------------------

cat("\n\nExercicio 3 - Distribuição HiperGeométrica")
M <- 10
N <- 5
n <- 4

# A --------------------------------------
resultado <- dhyper(2,M,N,n)
cat(paste("\na) P(𝑋=2) =", resultado))
# --------------------------------------

# B --------------------------------------
resultado <- phyper(1,M,N,n)
cat(paste("\nb) P(𝑋≤1) =", resultado))
# --------------------------------------

# C --------------------------------------
resultado <- sum(dhyper(1:4,M,N,n))
cat(paste("\nc) P(𝑋>0) =", resultado))
# --------------------------------------

# D --------------------------------------
resultado <- qhyper(0.45,M,N,n)
cat(paste("\nd)Quantil 45 =", resultado))
# --------------------------------------

cat("\n\nExercicio 4 - Distribuição Normal")

media <- 90
desvio <- 10

# A --------------------------------------
resultado <-  pnorm(115, media, desvio)
cat(paste("\na) P(𝑋≤115) =", resultado))
# --------------------------------------

# B --------------------------------------
prob_A <- pnorm(80, media, desvio)
resultado <- 1-prob_A
cat(paste("\nb) P(𝑋≥80) =", resultado))
# --------------------------------------

# C --------------------------------------
resultado <- pnorm(110, media, desvio) - pnorm(85, media, desvio)
cat(paste("\nc) P(85≤𝑋≤110) =", resultado))
# --------------------------------------

# D --------------------------------------
resultado <- dnorm(95, media, desvio)
cat(paste("\nd) P(X=95) =", resultado))
# --------------------------------------

# E --------------------------------------
cat("\ne) ")
resultado <- rnorm(10, media, desvio)
cat(resultado)
# --------------------------------------

cat("\n\nExercicio 5 - Distribuição Geométrica")

p <- 0.45

# A --------------------------------------
resultado <- dgeom(3, p)
cat(paste("\na) P(𝑋=3) =", resultado))
# --------------------------------------

# B --------------------------------------
prob_A <- pgeom(2,p)
resultado <- 1-prob_A
cat(paste("\nb) P(𝑋≥3) =", resultado))
# --------------------------------------

# C --------------------------------------
resultado <- pgeom(1, p)
cat(paste("\nc) P(𝑋<2)", resultado))
# --------------------------------------

# D --------------------------------------
resultado <- pgeom(4, p) - pgeom(2, p)
cat(paste("\nd) P(2<X≤4)", resultado))
# --------------------------------------

# E --------------------------------------
cat("\ne) ")
resultado <- rgeom(5, p)
cat(resultado)
# --------------------------------------