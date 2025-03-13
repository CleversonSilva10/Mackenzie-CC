
-- Nome: Cleverson Pereira da Silva - TIA: 32198531
-- Professor: Antonio Luiz Basile
-- Turma: [05N]

rev :: [Int] -> [Int]
rev [] = []
rev xs = reverse xs

main :: IO()
main = do
    let lista = [1,2,3,4,5]
    let invertido = rev lista
    print invertido
