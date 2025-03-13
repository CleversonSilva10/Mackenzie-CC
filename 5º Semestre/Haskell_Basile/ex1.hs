
-- Nome: Cleverson Pereira da Silva - TIA: 32198531
-- Professor: Antonio Luiz Basile
-- Turma: [05N]

tot3 :: [Int] -> [Int]
tot3 [] = []
tot3 xs = sum (take 3 xs) : tot3 (drop 3 xs)

main :: IO ()
main = do
    let lista = [1,1,1,2,2,2,3,3,3,4]
    let x = tot3 lista
    print x
