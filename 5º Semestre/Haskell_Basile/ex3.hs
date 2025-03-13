
-- Nome: Cleverson Pereira da Silva - TIA: 32198531
-- Professor: Antonio Luiz Basile
-- Turma: [05N]

ult :: [Int] -> Int
ult [] = error "Lista Vazia"
ult xs = last xs

main :: IO()
main = do
    let lista = [1,2,3,4,5]
    let x = ult lista
    print x
