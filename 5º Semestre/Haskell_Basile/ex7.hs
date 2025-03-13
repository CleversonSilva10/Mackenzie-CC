
-- Nome: Cleverson Pereira da Silva - TIA: 32198531
-- Professor: Antonio Luiz Basile
-- Turma: [05N]

totk :: Num a => [a] -> Int -> [a]
totk [] _ = []
totk xs k = sum (take k xs) : totk (drop k xs) k

main :: IO()
main = do
    let lista = [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
    let k = 5
    let resultado = totk lista k
    print resultado
