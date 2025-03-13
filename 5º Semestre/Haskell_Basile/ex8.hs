
-- Nome: Cleverson Pereira da Silva - TIA: 32198531
-- Professor: Antonio Luiz Basile
-- Turma: [05N]

trok2 :: [a] -> [a]
trok2 [] = []
trok2 [x] = [x]
trok2 (x:y:xs) = y : x : trok2 xs

main :: IO ()
main = do
    let minhaLista = [1,2,3,4,5,6,7]
    let resultado = trok2 minhaLista
    print resultado
