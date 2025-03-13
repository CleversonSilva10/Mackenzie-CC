
-- Nome: Cleverson Pereira da Silva - TIA: 32198531
-- Professor: Antonio Luiz Basile
-- Turma: [05N]


delk :: [a] -> Int -> [a]
delk xs k
    | k <= 0 = error "K>0"
    | otherwise = delk' xs k
  where
    delk' [] _ = []
    delk' xs 1 = delk' (tail xs) k
    delk' (x:xs) i = x : delk' xs (i-1)

main :: IO ()
main = do
    let x = "anonimamentes"
    let k = 3
    let resultado = delk x k
    print resultado
